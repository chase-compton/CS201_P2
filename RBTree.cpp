#include <iostream>

using namespace std;

template <class keyType, class valueType>
class Node
{
public:
    keyType key;
    valueType value;

    Node<keyType, valueType> *left;
    Node<keyType, valueType> *right;
    Node<keyType, valueType> *parent;

    bool color;

    int itemsLeft;

    Node()
    {
        color = true;
    }

    Node(keyType k, valueType v)
    {
        key = k;
        value = v;

        left = nullptr;
        right = nullptr;
        parent = nullptr;

        color = false;

        itemsLeft = 0;
    }

    Node(keyType k, valueType v, bool c)
    {
        key = k;
        value = v;

        left = nullptr;
        right = nullptr;
        parent = nullptr;

        color = c;

        itemsLeft = 0;
    }

    void print()
    {
        cout << "Key: " << key << " Value: " << value << " Color: " << color << " Items: " << itemsLeft << endl;
    }
};

template <class keyType, class valueType>
class RBTree
{
public:
    Node<keyType, valueType> *root;

    int size;

    RBTree()
    {
        root = new Node<keyType, valueType>();
        size = 0;
    }

    RBTree(keyType k[], valueType v[], int s)
    {
        // gonna loop through and insert one by one
    }

    RBTree(const RBTree &rhs)
    {

    }

    RBTree &operator=(const RBTree &rhs)
    {
        return *this;
    }

    ~RBTree()
    {
        delete root;
    }

    valueType *search(keyType k)
    {

    }

    void insert(keyType k, valueType v)
    {

    }

    int remove(keyType k)
    {

    }

    int rank(keyType k)
    {

    }

    keyType select(int pos)
    {

    }

    keyType *predecessor(keyType k)
    {

    }

    int size()
    {

    }

    void preorder()
    {

    }

    void inorder()
    {

    }

    void postorder()
    {

    }

    void print(int k)
    {

    }





};

int main()
{
    Node<int, int> test;
    test.print();
    Node<int, int> test2(1, 2);
    test2.print();
    Node<int, int> test3(3, 4, true);
    test3.print();
    test.left = &test2;
    test.left->print();
    RBTree<int, int> treeTest;
    treeTest.root->print();
};
