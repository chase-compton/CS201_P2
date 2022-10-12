#include <iostream>
#define black false
#define red true
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

    int size;

    Node()
    {
        color = black;
    }

    Node(keyType k, valueType v)
    {
        key = k;
        value = v;

        left = nullptr;
        right = nullptr;
        parent = nullptr;

        color = red;

        size = 0;
    }

    Node(keyType k, valueType v, bool c)
    {
        key = k;
        value = v;

        left = nullptr;
        right = nullptr;
        parent = nullptr;

        color = c;

        size = 0;
    }

    Node(keyType k, valueType v, bool c, Node<keyType, valueType> *l, Node<keyType, valueType> *r, Node<keyType, valueType> *p)
    {
        key = k;
        value = v;

        left = l;
        right = r;
        parent = p;

        color = c;

        size = 0;
    }
};

template <class keyType, class valueType>
class RBTree
{
public:
    Node<keyType, valueType> *root;
    Node<keyType, valueType> *nil;

    RBTree()
    {
        nil = new Node<keyType, valueType>();
        root = nil;
    }

    RBTree(keyType k[], valueType v[], int s)
    {
        nil = new Node<keyType, valueType>();
        root = nil;

        for (int i = 0; i < s; i++)
        {
            insert(k[i], v[i]);
        }
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
        Node<keyType, valueType> *z = new Node<keyType, valueType>(k, v);
        Node<keyType, valueType> *y = nil;
        Node<keyType, valueType> *x = root;

        while (x != nil)
        {
            y = x;
            if (z->key < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == nil)
        {
            root = z;
        }
        else if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
        z->left = nil;
        z->right = nil;
        insertFixUp(z);
    }

    void insertFixUp(Node<keyType, valueType> *z)
    {
        while (z->parent->color == red)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node<keyType, valueType> *y = z->parent->parent->right;
                if (y->color == red)
                {
                    z->parent->color = black;
                    y->color = black;
                    z->parent->parent->color = red;
                    z = z->parent->parent;
                    continue;
                }
                else if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                rightRotate(z->parent->parent);
            }
            else
            {
                Node<keyType, valueType> *y = z->parent->parent->left;
                if (y->color == red)
                {
                    z->parent->color = black;
                    y->color = black;
                    z->parent->parent->color = red;
                    z = z->parent->parent;
                    continue;
                }
                else if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                leftRotate(z->parent->parent);
            }
        }
        root->color = black;
    }

    void leftRotate(Node<keyType, valueType> *x)
    {
        Node<keyType, valueType> *y = x->right;
        x->right = y->left;

        if (y->left != nil)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nil)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node<keyType, valueType> *x)
    {
        Node<keyType, valueType> *y = x->left;
        x->left = y->right;

        if (y->right != nil)
        {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nil)
        {
            root = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
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
        return root->size;
    }

    void preorder()
    {
        preorderHelper(root);
        cout << endl;
    }

    void preorderHelper(Node<keyType, valueType> *node)
    {
        if (node == nil)
            return;
        cout << node->key << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void inorder()
    {
        inorderHelper(root);
        cout << endl;
    }

    void inorderHelper(Node<keyType, valueType> *node)
    {
        if (node == nil)
            return;
        inorderHelper(node->left);
        cout << node->key << " ";
        inorderHelper(node->right);
    }

    void postorder()
    {
        postorderHelper(root);
        cout << endl;
    }

    void postorderHelper(Node<keyType, valueType> *node)
    {
        if (node == nil)
            return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->key << " ";
    }

    void print(int k)
    {
    }
};
