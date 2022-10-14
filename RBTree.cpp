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
        size = 0;
    }

    Node(keyType k, valueType v)
    {
        key = k;
        value = v;

        left = nullptr;
        right = nullptr;
        parent = nullptr;

        color = red;

        size = 1;
    }

    Node(keyType k, valueType v, bool c)
    {
        key = k;
        value = v;

        left = nullptr;
        right = nullptr;
        parent = nullptr;

        color = c;

        size = 1;
    }

    Node(keyType k, valueType v, bool c, Node<keyType, valueType> *l, Node<keyType, valueType> *r, Node<keyType, valueType> *p, int s)
    {
        key = k;
        value = v;

        left = l;
        right = r;
        parent = p;

        color = c;

        size = s;
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
        // same as assignment
    }

    RBTree &operator=(const RBTree &rhs)
    {
        // idk maybe traversal copy
        return *this;
    }

    ~RBTree()
    {
        // maybe delete through a traversal
        delete root;
    }

    valueType *search(keyType k)
    {
        return &(nodeSearch(root, k)->value);
    }

    Node<keyType, valueType> *nodeSearch(Node<keyType, valueType> *node, keyType k)
    {
        if (node == nil)
        {
            return nullptr;
        }
        if (node->key == k)
        {
            return node;
        }
        if (node->key > k)
        {
            return nodeSearch(node->left, k);
        }
        else
        {
            return nodeSearch(node->right, k);
        }
    }

    void insert(keyType k, valueType v)
    {
        Node<keyType, valueType> *z = new Node<keyType, valueType>(k, v);
        Node<keyType, valueType> *y = nil;
        Node<keyType, valueType> *x = root;

        while (x != nil)
        {
            x->size++;
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

        y->size = x->size;
        x->size = x->left->size + x->right->size + 1;
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

        y->size = x->size;
        x->size = x->left->size + x->right->size + 1;
    }

    int remove(keyType k)
    {
        Node<keyType, valueType> *z = nodeSearch(root, k);

        if (z == nullptr)
        {
            return 0;
        }

        Node<keyType, valueType> *x = nil;
        Node<keyType, valueType> *y = z;
        bool y_original_color = y->color;

        if (z->left == nil)
        {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == nil)
        {
            x = z->left;
            transplant(z, z->left);
        }
        else
        {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;

            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (y_original_color == black)
        {
            deleteFixUp(x);
        }
        return 1;
    }

    void transplant(Node<keyType, valueType> *u, Node<keyType, valueType> *v)
    {
        if (u->parent == nil)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteFixUp(Node<keyType, valueType> *x)
    {
        while (x != root && x->color == black)
        {
            if (x == x->parent->left)
            {
                Node<keyType, valueType> *w = x->parent->right;
                if (w->color == red)
                {
                    w->color = black;
                    x->parent->color = red;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == black and w->right->color == black)
                {
                    w->color = red;
                    x = x->parent;
                    continue;
                }
                else if (w->right->color == black)
                {
                    w->left->color = black;
                    w->color = red;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = black;
                w->right->color = black;
                leftRotate(x->parent);
                x = root;
            }
            else
            {
                Node<keyType, valueType> *w = x->parent->left;
                if (w->color == red)
                {
                    w->color = black;
                    x->parent->color = red;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == black and w->left->color == black)
                {
                    w->color = red;
                    x = x->parent;
                    continue;
                }
                else if (w->left->color == black)
                {
                    w->right->color = black;
                    w->color = red;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = black;
                w->left->color = black;
                rightRotate(x->parent);
                x = root;
            }
        }
        x->color = black;
    }

    int rank(keyType k)
    {
        Node<keyType, valueType> *node = nodeSearch(root, k);
        if (node == nullptr)
        {
            return 0;
        }
        return rankHelper(node, k);
    }

    int rankHelper(Node<keyType, valueType> *node, keyType k)
    {
        int r = node->left->size + 1;
        Node<keyType, valueType> *y = node;

        while (y != root)
        {
            if (y == y->parent->right)
            {
                r = r + y->parent->left->size + 1;
            }
            y = y->parent;
        }
        return r;
    }

    keyType select(int pos)
    {
        return selectHelper(root, pos);
    }

    keyType selectHelper(Node<keyType, valueType> *node, int pos)
    {
        int r = node->left->size + 1;

        if (pos == r)
        {
            return node->key;
        }
        else if (pos < r)
        {
            return selectHelper(node->left, pos);
        }
        return selectHelper(node->right, pos - r);
    }

    keyType *successor(keyType k)
    {
        Node<keyType, valueType> *node = nodeSearch(root, k);

        if (node->right != nil)
        {
            return &(minimum(node->right)->key);
        }

        Node<keyType, valueType> *y = node->parent;

        while (y != nil && node == y->right)
        {
            node = y;
            y = y->parent;
        }
        if (y == nil)
        {
            return nullptr;
        }
        return &(y->key);
    }

    keyType *predecessor(keyType k)
    {
        Node<keyType, valueType> *node = nodeSearch(root, k);

        if (node->left != nil)
        {
            return &(maximum(node->left)->key);
        }

        Node<keyType, valueType> *y = node->parent;

        while (y != nil && node == y->left)
        {
            node = y;
            y = y->parent;
        }
        if (y == nil)
        {
            return nullptr;
        }
        return &(y->key);
    }

    Node<keyType, valueType> *minimum(Node<keyType, valueType> *node)
    {
        while (node->left != nil)
        {
            node = node->left;
        }
        return node;
    }

    Node<keyType, valueType> *maximum(Node<keyType, valueType> *node)
    {
        while (node->right != nil)
        {
            node = node->right;
        }
        return node;
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

    void printHelper(Node<keyType, valueType> *node, int k)
    {
    }
};
