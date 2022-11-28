#include <iostream>
#include <cstdlib>
#define black false
#define red true
using namespace std;

//Node Class
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
    //Default Constructor
    Node()
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        color = black;
        size = 0;
    }

    //Key and Value Constructor
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

    ~Node()
    {
        if (left->size != 0)
            delete left;
        if (right->size != 0)
            delete right;
    }
};


template <class keyType, class valueType>
class RBTree
{
public:
    Node<keyType, valueType> *root;
    Node<keyType, valueType> *nil;

    int count = 0;
    //Default Constructor
    RBTree()
    {
        nil = new Node<keyType, valueType>();
        root = nil;
    }
    //Array Constructor
    RBTree(keyType k[], valueType v[], int s)
    {
        nil = new Node<keyType, valueType>();
        root = nil;

        for (int i = 0; i < s; i++)
        {
            insert(k[i], v[i]);
        }
    }
    //Copy Constructor
    RBTree(const RBTree &rhs)
    {
        if (rhs.root != rhs.nil)
        {
            nil = new Node<keyType, valueType>();
            root = nil;
            root = copyHelper(rhs.root, nil, nil);
        }
        else
        {
            nil = new Node<keyType, valueType>();
            root = nil;
        }
        count = rhs.count;
    }
    //Assignment Op
    RBTree &operator=(const RBTree &rhs)
    {
        if (rhs.root != rhs.nil)
        {
            nil = new Node<keyType, valueType>();
            root = nil;
            root = copyHelper(rhs.root, nil, nil);
        }
        else
        {
            nil = new Node<keyType, valueType>();
            root = nil;
        }
        count = rhs.count;
        return *this;
    }
    //Helper function that recursively copies the nodes
    Node<keyType, valueType> *copyHelper(const Node<keyType, valueType> *rhs, Node<keyType, valueType> *newNil, Node<keyType, valueType> *p)
    {
        if (rhs->size == 0)
        {
            return newNil;
        }
        Node<keyType, valueType> *copy = new Node<keyType, valueType>();
        copy->key = rhs->key;
        copy->value = rhs->value;
        copy->color = rhs->color;
        copy->size = rhs->size;
        copy->parent = p;
        copy->left = copyHelper(rhs->left, newNil, copy);
        copy->right = copyHelper(rhs->right, newNil, copy);
        return copy;
    }
    //Destructors
    ~RBTree()
    {
        delete root;
    }

    //search function that calls node search
    valueType *search(keyType k)
    {
        Node<keyType, valueType> *node = nodeSearch(root, k);
        if (node == nil)
        {
            return NULL;
        }
        return &(node->value);
    }
    //node search which is used internally to make other functions easier. Done recursively
    Node<keyType, valueType> *nodeSearch(Node<keyType, valueType> *node, keyType k)
    {
        if (node == nil)
        {
            return nil;
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

    //Insertion which follows normal Binary Tree insert but with fix up being called at the end
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

    //Fix up after insertion
    void insertFixUp(Node<keyType, valueType> *z)
    {
        //loop in order to continue up the tree if needed
        while (z->parent->color == red)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node<keyType, valueType> *y = z->parent->parent->right;
                //Case 1
                if (y->color == red)
                {
                    z->parent->color = black;
                    y->color = black;
                    z->parent->parent->color = red;
                    z = z->parent->parent;
                }
                else
                {
                    //Case 2
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }
                    //Case 3
                    z->parent->color = black;
                    z->parent->parent->color = red;
                    rightRotate(z->parent->parent);
                }
            }
            //symetric code from above
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
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = black;
                    z->parent->parent->color = red;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = black;
    }

    //Left rotate which is used in fix ups
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
        x->size = x->right->size + x->left->size + 1;
    }
    //Right rotate which is used in fix ups
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
        x->size = x->right->size + x->left->size + 1;
    }

    //Delete function
    int remove(keyType k)
    {
        //searches for node
        Node<keyType, valueType> *z = nodeSearch(root, k);
        if (z == nil)
        {
            return 0;
        }
        //if node exsists continue
        Node<keyType, valueType> *x = nil;
        Node<keyType, valueType> *y = z;
        bool y_original_color = y->color;

        //decrements size in order to maintain ranks
        Node<keyType, valueType> *cur = y;
        while (cur->parent != nil)
        {
            cur = cur->parent;
            cur->size--;
        }

        if (z->right == nil)
        {
            x = z->left;
            transplant(z, z->left);
        }
        else if (z->left == nil)
        {

            x = z->right;
            transplant(z, z->right);
        }
        else
        {

            y = maximum(z->left);
            y_original_color = y->color;
            x = y->left;
            cur = y;
            //loop to maintain sizes as well
            while (cur != z)
            {

                cur = cur->parent;
                cur->size--;
            }

            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->left);
                y->left = z->left;
                y->left->parent = y;
            }
            transplant(z, y);
            y->size = z->size;
            y->right = z->right;
            y->right->parent = y;
            y->color = z->color;
        }
        if (y_original_color == black)
        {
            deleteFixUp(x);
        }

        return 1;
    }
    //swap function
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
                //case 1
                if (w->color == red)
                {
                    w->color = black;
                    x->parent->color = red;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                //case 2
                if (w->left->color == black && w->right->color == black)
                {
                    w->color = red;
                    x = x->parent;
                }
                else
                {
                    //case 3
                    if (w->right->color == black)
                    {
                        w->left->color = black;
                        w->color = red;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    //case 4
                    w->color = x->parent->color;
                    x->parent->color = black;
                    w->right->color = black;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            //symteric code from above
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
                if (w->right->color == black && w->left->color == black)
                {

                    w->color = red;
                    x = x->parent;
                }
                else
                {
                    if (w->left->color == black)
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
        }
        x->color = black;
    }

    int rank(keyType k)
    {
        //finds the node with search
        Node<keyType, valueType> *node = nodeSearch(root, k);
        if (node == nil)
        {
            return 0;
        }
        //uses rankhelper to find its rank
        return rankHelper(node);
    }

    int rankHelper(Node<keyType, valueType> *node)
    {
        //finds where node would be in a in order traversal essentially
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
    //selects node at pos
    keyType select(int pos)
    {
        if (pos <= 0 || pos > root->size)
        {
            return NULL;
        }
        return selectHelper(root, pos);
    }
    //uses root and pos inorder to find the node
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

    //old function I thought would be useful but didn't use it 
    Node<keyType, valueType> *nodeSelect(Node<keyType, valueType> *node, int pos)
    {
        if (pos > root->size)
        {
            return nil;
        }

        int r = node->left->size + 1;

        if (pos == r)
        {
            return node;
        }
        else if (pos < r)
        {
            return nodeSelect(node->left, pos);
        }
        return nodeSelect(node->right, pos - r);
    }

    keyType *successor(keyType k)
    {
        Node<keyType, valueType> *node = nodeSearch(root, k);

        if (node == nil)
        {
            return NULL;
        }

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
            return NULL;
        }
        return &(y->key);
    }

    keyType *predecessor(keyType k)
    {
        Node<keyType, valueType> *node = nodeSearch(root, k);

        if (node == nil)
        {
            return NULL;
        }

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
            return NULL;
        }

        return &(y->key);
    }

    Node<keyType, valueType> *minimum(Node<keyType, valueType> *node)
    {
        //finds left most node/min
        while (node->left != nil)
        {
            node = node->left;
        }
        return node;
    }

    Node<keyType, valueType> *maximum(Node<keyType, valueType> *node)
    {
        //finds right most node/max
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

    //all my print functions essentailly work the same way

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

    //for print k, I keep a count of how many printed and stop when reached the count
    void printk(int k)
    {
        printkHelper(root, k);
        cout << endl;
        count = 0;
    }

    void printkHelper(Node<keyType, valueType> *node, int k)
    {
        if (node == nil || count >= k)
        {
            return;
        }
        printkHelper(node->left, k);
        if (count < k)
        {
            cout << node->key << " ";
        }
        count++;
        printkHelper(node->right, k);
    }
};
