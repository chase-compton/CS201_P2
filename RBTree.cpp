#include <iostream>

using namespace std;

template <class typeOne, class typeTwo>
class Node
{
    typeOne key;
    typeTwo value;
    int color;
    Node left;
    Node right;
    Node parent;

public:
    
    void print()
    {
        cout << "Key: " << key << " Value: " << value << " Color: " << color << endl;
    }
};

template <class type>
class CircularDynamicArray
{
protected:
    int size;
    int cap;
    int front;
    type *array;
    type outOfbounds;

public:
    CircularDynamicArray()
    {
        size = 0;
        cap = 2;
        array = new type[cap];
        front = 0;
    }

    CircularDynamicArray(int s)
    {
        size = s;
        cap = s;
        array = new type[cap];
        front = 0;
    }

    CircularDynamicArray(const CircularDynamicArray &rhs)
    {
        size = rhs.size;
        cap = rhs.cap;
        array = new type[cap];
        for (int i = 0; i < size; i++)
        {
            array[i] = *(rhs.array + ((rhs.front + i) % cap));
        }
        front = 0;
    }

    CircularDynamicArray &operator=(const CircularDynamicArray &rhs)
    {
        size = rhs.size;
        cap = rhs.cap;
        type *tempArray = new type[cap];
        for (int i = 0; i < size; i++)
        {
            tempArray[i] = *(rhs.array + ((front + i) % cap));
        }
        delete[] array;
        array = tempArray;
        front = 0;
        return *this;
    }

    ~CircularDynamicArray()
    {
        delete[] array;
    }
};