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

// Función para construir el árbol de Huffman
void buildHuffmanTree(TreeNode *&root)
{
    while (root != nullptr && root->parent != nullptr)
    {
        TreeNode *node1 = extractMinHeap(root);
        TreeNode *node2 = extractMinHeap(root);

        if (node1 == nullptr || node2 == nullptr)
            break;

        TreeNode *internalNode = createNode('\0', node1->probability + node2->probability);
        internalNode->left = node1;
        internalNode->right = node2;

        MinHeapInsert(root, internalNode);
    }
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

// Función para obtener el código de Huffman para un símbolo específico
string getHuffmanString(TreeNode *root, char c)
{
    if (root != nullptr)
    {
        if (root->symbol == c)
        {
            if (c == ' ')
                return "\n";  // Return newline for space
            else
                return root->huffmanCode;
        }
        string left = getHuffmanString(root->left, c);
        if (!left.empty())
        {
            return left;
        }
        string right = getHuffmanString(root->right, c);
        if (!right.empty())
        {
            return right;
        }
    }
    return "";
}

// Función para decodificar una cadena de Huffman
string decodeHuffmanString(TreeNode *root, const string &huffmanString)
{
    string decodedString;
    TreeNode *currentNode = root;
    for (char bit : huffmanString)
    {
        if (bit == '0')
            currentNode = currentNode->left;
        else // bit == '1'
            currentNode = currentNode->right;

        // Si es un nodo hoja
        if (currentNode->left == nullptr && currentNode->right == nullptr)
        {
            decodedString += currentNode->symbol;
            currentNode = root; // Volver a la raíz para el próximo carácter
        }
    }
    return decodedString;
}


void MinHeapInserts(TreeNode *&root)
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


int Menu(){
    TreeNode* root = nullptr;
    MinHeapInserts(root);
    buildHuffmanTree(root);
    generateHuffmanCodes(root);
    string userInput = "";
    bool textoIngresado = false;
    string huffmanString = "";
    bool algoritmoHuffmanAplicado = false;

    cout << "\n----- Codigo Elaborado Por : -----\n";
    cout << "\n----- William Pineda 00225919 : -----\n";
    while (true)
    {
        cout << "\n----- Menu de Operaciones -----\n"
             << "1. Ingresar Texto\n"
             << "2. Consultar Texto\n"
             << "3. Aplicar Algoritmo de Huffman\n"
             << "4. Consultar Texto Modificado\n"
             << "5. Salir\n"
             << "Seleccione una opción: ";

        int opcion;
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion)
        {
        case 1:
                cout << "\n";
                if (textoIngresado) {
                 cout << "Ya hay un texto almacenado, Tome en Cuenta que Esta Sobreescribiendo el Texto: " << endl;
                    textoIngresado = false;  // Reiniciar el indicador
                    algoritmoHuffmanAplicado = false;
                    huffmanString = "";  // Reiniciar el indicador
                }
                cout << "Por Favor Ingresa Un texto: ";
                getline(cin, userInput);
                textoIngresado = true; // Actualizar el indicador
                algoritmoHuffmanAplicado = false;
                cout << "\n";
                break;
            break;
        case 2:
                cout << "\n";
                if (textoIngresado) {
                    cout << "Texto almacenado: " << userInput << endl;
                } else {
                    cout << "No hay un texto almacenado aún. Por favor, ingresa un texto primero." << endl;
                }
                cout << "\n";
            break;
        case 3:
                cout << "\n";
                if (textoIngresado && !algoritmoHuffmanAplicado) {
                    // Print Huffman string for each character in the input
                    cout << "Codigos de Huffman:" << endl;

                    for (char c : userInput)
                    {
                        cout << "Simbolo: " << c << ", Codigo Huffman: " << getHuffmanString(root, c) << endl;
                    }
                    for (char c : userInput)
                    {
                        huffmanString += getHuffmanString(root, c);
                    }
                    cout << "\n";
                    // Print the concatenated Huffman string
                    cout << "Cadena Cifrada de Huffman: "<< "\n" << huffmanString << endl;
                    algoritmoHuffmanAplicado = true;
                } else if (!textoIngresado) {
                    cout << "No hay un texto almacenado aún. ingresa un texto primero para poder aplicar el Algoritmo de Huffman" << endl;
                } else {
                    cout << "El algoritmo de Huffman ya se aplicó al texto, Si desea Visualizarlo Seleccione la Opcion 4" << endl;
                }
                cout << "\n";
            break;
        case 4: 
                cout << "\n";
                if (textoIngresado) {
                        if(algoritmoHuffmanAplicado == true){
                            cout << "Cadena de Huffman Concatenada: "<< huffmanString << endl;
                            cout << "Texto Decifrado: " << userInput.c_str() << endl;
                        } else {
                            cout << "Es Necesario Aplicar el Algoritmo de Huffman al Texto para acceder a esta opcion "<<endl;
                        }
                } else {
                    cout << "No hay un texto almacenado aún. Por favor, ingresa un texto primero." << endl;
                }
                cout << "\n";
            break;
        case 5:
            cout<<"Saliendo del programa"<<endl;
            return 0; // Salir del programa
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
}

int main(){
    Menu();
    return 0;
}