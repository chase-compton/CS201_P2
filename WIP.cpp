#include <iostream>

using namespace std;

template <class typeOne, class typeTwo>
class Node
{
public:
	typeOne key;
	typeTwo value;

	Node<typeOne, typeTwo> *left;
	Node<typeOne, typeTwo> *right;
	Node<typeOne, typeTwo> *parent;

	bool color;

	int itemsLeft;

	Node()
	{
		color = true;
	}

	Node(typeOne k, typeTwo v)
	{
		key = k;
		value = v;

		left = nullptr;
		right = nullptr;
		parent = nullptr;

		color = false;

		itemsLeft = 0;
	}

	Node(typeOne k, typeTwo v, bool c)
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

template <class typeOne, class typeTwo>
class RBTree
{
public:
	Node<typeOne, typeTwo> *root;
	Node<typeOne, typeTwo> *nil;
	int size;

	RBTree()
	{
		size = 0;
	}

	RBTree(typeOne k[], typeTwo v[], int s)
	{
		//gonna loop through and insert one by one
	}

	RBTree &operator=(const RBTree &rhs)
	{
		
	}

	~RBTree()
	{
		delete root;
		delete nil;
	}
};

int main()
{
	Node<int, int> test;
	test.print();
	Node<int, int> test2 (1,2);
	test2.print();
	Node<int, int> test3 (3,4, true);
	test3.print();
	test.left = &test2;
	test.left->print();
};
