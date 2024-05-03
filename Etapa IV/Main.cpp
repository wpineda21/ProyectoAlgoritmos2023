#include <iostream>

using namespace std;

// Estructura para representar un nodo del árbol de Huffman
struct TreeNode
{
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    char symbol;
    double probability;
    string huffmanCode;
};

// Función para crear un nuevo nodo con el símbolo y la probabilidad dados
TreeNode *createNode(char symbol, double probability)
{
    TreeNode *node = new TreeNode;
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    node->symbol = symbol;
    node->probability = probability;
    return node;
}

// Función para intercambiar dos nodos
void swap(TreeNode *&a, TreeNode *&b)
{
    TreeNode *temp = a;
    a = b;
    b = temp;
}

// Función para mantener la propiedad de min-heap después de la inserción
void MinHeapMinimum(TreeNode *node)
{
    if (node->parent != nullptr && node->probability < node->parent->probability)
    {
        swap(node, node->parent);
        MinHeapMinimum(node->parent);
    }
}

// Función para insertar un nodo en el min-heap
void MinHeapInsert(TreeNode *&root, TreeNode *node)
{
    if (root == nullptr)
    {
        root = node;
    }
    else if (node->probability > root->probability)
    {
        node->left = root;
        root->parent = node;
        root = node;
    }
    else
    {
        MinHeapInsert(root->right, node);
        if (root->right != nullptr)
        {
            root->right->parent = root;
        }
    }
}

// Función para extraer el nodo con la menor probabilidad del min-heap
TreeNode *extractMinHeap(TreeNode *&root)
{
    if (root == nullptr)
        return nullptr;

    TreeNode *minNode = root;
    if (root->left != nullptr)
    {
        root->left->parent = nullptr;
        root = root->left;
    }
    else if (root->right != nullptr)
    {
        root->right->parent = nullptr;
        root = root->right;
    }
    else
    {
        root = nullptr;
    }
    minNode->left = nullptr;
    minNode->right = nullptr;
    return minNode;
}

// Función para generar los códigos de Huffman para cada símbolo
void generateHuffmanCodes(TreeNode *root, string currentCode = "")
{
    if (root != nullptr)
    {
        if (root->symbol != '\0')
        {
            root->huffmanCode = currentCode;
        }
        generateHuffmanCodes(root->left, currentCode + "1"); // Invertir 0 y 1 aquí
        generateHuffmanCodes(root->right, currentCode + "0");
    }
}

// Función para construir el árbol de Huffman
void buildHuffmanTree(TreeNode *&root)
{
    // Construir el árbol de Huffman
    while (root->parent != nullptr)
    {
        TreeNode *node1 = extractMinHeap(root);
        TreeNode *node2 = extractMinHeap(root);

        TreeNode *internalNode = createNode('\0', node1->probability + node2->probability);
        internalNode->left = node1;
        internalNode->right = node2;

        MinHeapInsert(root, internalNode);
    }
}

// Función para imprimir los códigos de Huffman
void printHuffmanCodes(TreeNode *root)
{
    if (root != nullptr)
    {
        if (root->symbol != '\0')
        {
            cout << "Simbolo: " << root->symbol << ", Codigo Huffman: " << root->huffmanCode << endl;
        }
        printHuffmanCodes(root->left);
        printHuffmanCodes(root->right);
    }
}


void MinHeapInsertsAlphabet(TreeNode *&root){
    TreeNode *nodeA = createNode('a', 0.15);
    TreeNode *nodeB = createNode('b', 0.12);
    TreeNode *nodeC = createNode('c', 0.71);
    TreeNode *nodeD = createNode('d', 0.39);
    TreeNode *nodeE = createNode('e', 0.32);
    TreeNode *nodeF = createNode('f', 0.70);
    TreeNode *nodeG = createNode('g', 0.33);
    TreeNode *nodeH = createNode('h', 0.73);
    TreeNode *nodeI = createNode('i', 0.50);
    TreeNode *nodeJ = createNode('j', 0.10);
    TreeNode *nodeK = createNode('k', 0.90);
    TreeNode *nodeL = createNode('l', 0.72);
    TreeNode *nodeM = createNode('m', 0.73);
    TreeNode *nodeN = createNode('n', 0.94);
    TreeNode *nodeO = createNode('o', 0.94);
    TreeNode *nodeP = createNode('p', 0.07);
    TreeNode *nodeQ = createNode('q', 0.84);
    TreeNode *nodeR = createNode('r', 0.46);
    TreeNode *nodeS = createNode('s', 0.04);
    TreeNode *nodeT = createNode('t', 0.01);
    TreeNode *nodeU = createNode('u', 0.66);
    TreeNode *nodeV = createNode('v', 0.32);
    TreeNode *nodeW = createNode('w', 0.51);
    TreeNode *nodeX = createNode('x', 0.98);
    TreeNode *nodeY = createNode('y', 0.62);
    TreeNode *nodeZ = createNode('z', 0.41);
    TreeNode* nodeBlank = createNode(' ', 0.99);

    MinHeapInsert(root, nodeA);
    MinHeapInsert(root, nodeB);
    MinHeapInsert(root, nodeC);
    MinHeapInsert(root, nodeD);
    MinHeapInsert(root, nodeE);
    MinHeapInsert(root, nodeF);
    MinHeapInsert(root, nodeG);
    MinHeapInsert(root, nodeH);
    MinHeapInsert(root, nodeI);
    MinHeapInsert(root, nodeJ);
    MinHeapInsert(root, nodeK);
    MinHeapInsert(root, nodeL);
    MinHeapInsert(root, nodeM);
    MinHeapInsert(root, nodeN);
    MinHeapInsert(root, nodeO);
    MinHeapInsert(root, nodeP);
    MinHeapInsert(root, nodeQ);
    MinHeapInsert(root, nodeR);
    MinHeapInsert(root, nodeS);
    MinHeapInsert(root, nodeT);
    MinHeapInsert(root, nodeU);
    MinHeapInsert(root, nodeV);
    MinHeapInsert(root, nodeW);
    MinHeapInsert(root, nodeX);
    MinHeapInsert(root, nodeY);
    MinHeapInsert(root, nodeZ);
    MinHeapInsert(root, nodeBlank);
}
int BussinesLogic()
{
    TreeNode *root = nullptr;

    MinHeapInsertsAlphabet(root);//Ingresamos Los Simbolos de Alfabeto
    buildHuffmanTree(root); //Construimos Codigos de huffman
    generateHuffmanCodes(root);// Generamo códigos de Huffman

    //códigos de Huffman
    cout << "Compilacion Correcta" << endl;
    cout << "A continuacion se mostraran Los Codigos de Huffman: " << endl;
    printHuffmanCodes(root);
    cout << "Fin Etapa IV" << endl;
    cout << "\n" << endl;

    return 0;
}

int main(){
    BussinesLogic();
    return 0;
}