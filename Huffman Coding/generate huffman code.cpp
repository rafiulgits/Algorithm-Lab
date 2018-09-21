/*
    Huffman coding generate a tree with the frequencies of the characters.
    The tree is a binary tree where (left node value < right node value)
    Traverse code formula:
        From root to next left node pick '0' and add with traverse code
        From root to next right node pick '1' and add with traverse code

                            root
                        0           1
                    0       1   0       1
    This traverse code is actually the Huffman code for a character of a dataset
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

const char IDENTIFIER = '|';
/*
    Node structure will carry the node character for and its frequency;
    left and right pointer will carry the corresponding left and right node
    of the generated tree.
*/
struct Node
{
    char data;
    unsigned frequency;

    Node *left, *right;

    /*
        Default constructor for a Node structure object with 2 arguments.
        Initially every node does not have any corresponding left or right
        node, so initial them with 'NULL'
    */
    Node(char data, unsigned frequency)
    {
        this->data = data;
        this->frequency = frequency;

        left = right = NULL;
    }
};

/*
    To compare between Node objects a compare structure made; where
    compare between them by their frequencies.
    To generate Huffman code tree, less frequencies nodes come first.
*/
struct compare
{
    bool operator()(Node *n1, Node *n2)
    {
        return (n1->frequency > n2->frequency); // minimum node first logic
    }
};

void huffmanTreeGenerate(char dataSet[], unsigned freqSet[], int len);
void displayHuffmanCode(Node *root, string code);

int main()
{
    char dataSet[] = {'a','b','c','d','e','f','g','h','p','x'};
    unsigned freqSet[] = {5,9,12,13,30,45,12,35,45,26};

    int len = sizeof(dataSet) / sizeof(dataSet[0]);

    huffmanTreeGenerate(dataSet, freqSet, len);

    return 0;
}

/*
    :::::::::: function defining area ::::::::::::::
*/
void huffmanTreeGenerate(char dataSet[], unsigned freqSet[], int len)
{
    /*
        custom priority queue for create a min heap. this priority queue
        will return its next smallest value as top,
    */
    priority_queue<Node*,vector<Node*>, compare> heap;

    /*
        push all dataset and frequency set into this queue for generate a min heap
    */
    for(int i=0; i<len; i++)
    {
        heap.push(new Node(dataSet[i], freqSet[i]));
    }

    /*
        Left node structure will get first top value from the priority queue and pop it from queue
        Right node structure will get second top value from the priority queue and pop it from queue
        Top node will create with the addition of the left and right node and push into this queue

        this system will happen until the priority queue has only one element the mother root.
    */
    Node *left, *right, *top;
    while(heap.size() != 1)
    {
        left = heap.top(); heap.pop();
        right = heap.top(); heap.pop();

        /*
            New Top node will created with the additional value of right and left node frequencies
            and an identifier character. This identifier character will help this program to
            identify a node whether this node has any child or not.
        */
        top = new Node(IDENTIFIER,left->frequency+right->frequency);
        top->left = left;
        top->right = right;

        heap.push(top);
    }

    displayHuffmanCode(heap.top(), ""); // call for display with mother root
}
void displayHuffmanCode(Node *root, string code)
{
    /*
        >If current root node is NULL it means tree traverse finished; so return.

        >If current root node data is a regular character instead of identifier character
        that means this root does not have any child; so print out the character and the
        traversal code which is the Huffman code of the corresponding character

        ->recursively call the current node's left node and right node for traverse
    */
    if(! root || root == NULL)
        return;
    if(root->data != IDENTIFIER)
        cout << root->data <<" : "<< code << endl;
    displayHuffmanCode(root->left,code+"0");
    displayHuffmanCode(root->right,code+"1");
}
