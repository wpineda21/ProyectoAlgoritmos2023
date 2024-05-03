#include <iostream>

using namespace std;

// Definición de la estructura del nodo del árbol
struct TreeNode
{
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    char symbol;
    double probability;
};

// Funcion para crear un nuevo nodo con el símbolo y la probabilidad 
TreeNode* createNode(char symbol, double probability)
{
    TreeNode* node = new TreeNode;
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    node->symbol = symbol;
    node->probability = probability;
    return node;
}

// Función para intercambiar dos nodos
void swap(TreeNode* &a, TreeNode* &b)
{
    TreeNode* temp = a;
    a = b;
    b = temp;
}

// Función para mantener la propiedad de min-heap después de la inserción
void MinHeapMinimum(TreeNode* node)
{
    if (node->parent != nullptr && node->probability < node->parent->probability)
    {
        swap(node, node->parent);
        MinHeapMinimum(node->parent);
    }
}

// Función para insertar un nodo en el montículo
void MinHeapInsert(TreeNode* &root, TreeNode* node, TreeNode* parent = nullptr)
{
    if (root == nullptr)
    {
        root = node;
        root->parent = parent;
    }
    else if (node->probability < root->probability)
    {
        // Insertar el nuevo nodo como raíz y ajustar los enlaces
        node->left = root->left;
        node->right = root;
        if (node->left != nullptr)
            node->left->parent = node;
        root->left = nullptr;
        root->parent = node;
        root = node;
    }
    else
    {
        // Insertar el nodo en el subárbol izquierdo recursivamente
        MinHeapInsert(root->left, node, root);
    }
    // Mantener la propiedad de min-heap después de la inserción
    MinHeapMinimum(node);
}

// Función para extraer el nodo con la menor probabilidad del montículo
TreeNode* extractMinHeap(TreeNode* &root)
{
    if (root == nullptr)
        return nullptr;

    // Guardar el nodo mínimo
    TreeNode* minNode = root;

    // Ajustar los enlaces para extraer el nodo mínimo
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

    // Limpiar enlaces del nodo mínimo
    minNode->left = nullptr;
    minNode->right = nullptr;

    return minNode;
}
//Declaracion de Alfabetos
void MinHeapInsertsAlphabet(TreeNode *&root)
{
    TreeNode* nodeA = createNode('a', 0.15);
    TreeNode* nodeB = createNode('b', 0.12);
    TreeNode* nodeC = createNode('c', 0.71);
    TreeNode* nodeD = createNode('d', 0.39);
    TreeNode* nodeE = createNode('e', 0.32);
    TreeNode* nodeF = createNode('f', 0.70);
    TreeNode* nodeG = createNode('g', 0.33);
    TreeNode* nodeH = createNode('h', 0.73);
    TreeNode* nodeI = createNode('i', 0.5);
    TreeNode* nodeJ = createNode('j', 0.10);
    TreeNode* nodeK = createNode('k', 0.90);
    TreeNode* nodeL = createNode('l', 0.72);
    TreeNode* nodeM = createNode('m', 0.73);
    TreeNode* nodeN = createNode('n', 0.94);
    TreeNode* nodeO = createNode('o', 0.94);
    TreeNode* nodeP = createNode('p', 0.07);
    TreeNode* nodeQ = createNode('q', 0.84);
    TreeNode* nodeR = createNode('r', 0.46);
    TreeNode* nodeS = createNode('s', 0.04);
    TreeNode* nodeT = createNode('t', 0.01);
    TreeNode* nodeU = createNode('u', 0.66);
    TreeNode* nodeV = createNode('v', 0.32);
    TreeNode* nodeW = createNode('w', 0.51);
    TreeNode* nodeX = createNode('x', 0.98);
    TreeNode* nodeY = createNode('y', 0.62);
    TreeNode* nodeZ = createNode('z', 0.41);
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
//  lógica del negocio
int BussinesLogic()
{
    TreeNode* root = nullptr;
    MinHeapInsertsAlphabet(root);

    TreeNode* minNode = extractMinHeap(root);
    if (minNode != nullptr)
    {
        cout << "Compilacion Correcta: " << endl;
        cout << "Mostrando el valor Con Menor Probabilidad del Monticulo : " << endl;
        cout << "Simbolo: " << minNode->symbol << ", Probabilidad: " << minNode->probability << endl;
        cout << "Fin Etapa II" << endl;
        cout << "\n" << endl;
    }

    return 0;
}

// Función principal 
int main()
{
    BussinesLogic();
    return 0;
}
