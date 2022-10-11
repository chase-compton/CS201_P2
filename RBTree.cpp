#include <iostream>

using namespace std;

template <class typeOne, class typeTwo>
class Node
{
protected:
    typeOne key;
    typeTwo value;
    int color;
    Node *left;
    Node *right;
    Node *parent;

public:
    Node()
    {
        key = 1;
        value = "Default Node";
        color = 1;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    Node(typeOne k, typeTwo v, int c, Node *l, Node *r, Node *p)
    {
        key = k;
        value = v;
        color = c;
        left = l;
        right = r;
        parent = p;
    }

    Node(const Node &rhs)
    {
        key = rhs.key;
        value = rhs.value;
        color = rhs.color;
        left = rhs.left;
        right = rhs.right;
        parent = rhs.parent;
        cout<<"yo"<<endl;
    }

    Node &operator=(const Node &rhs)
    {
        key = rhs.key;
        value = rhs.value;
        color = rhs.color;
        left = rhs.left;
        right = rhs.right;
        parent = rhs.parent;
        return *this;
    }

    ~Node()
    {
        cout << "Deleted" << endl;
    }

    void print()
    {
        cout << "Key: " << key << " Value: " << value << " Color: " << color << endl;
    }
};

template <class typeOne, class typeTwo>
class RBTree
{
protected:
    Node<typeOne, typeTwo> root;
    Node<int, int> nil;

public:
    RBTree()
    {
        nil = Node<int, int>(0, 0, 0, nullptr, nullptr, nullptr);
        // root = nil;
        // nil.print();
        // root.print();
    }
};

int main()
{
    Node<int, string> test;
    test.print();
    Node test2 = test;
    test2.print();
};
