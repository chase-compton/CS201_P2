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
    void print()
    {
        cout << "Key: " << key << " Value: " << value << " Color: " << color << endl;
    }
};

int main(){
    Node 

}