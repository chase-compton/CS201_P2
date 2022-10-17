#include <iostream>
using namespace std;
#include "RBTree.cpp"

int main()
{

	RBTree<int, int> X;
	RBTree<int, int> Y;

	for (int i = 1; i < 30; i++)
	{
		X.insert(i, i);
		if (X.rank(i) != i)
			cout << "Rank error" << endl;
		if (X.select(i) != i)
			cout << "Select error" << endl;
		if (*(X.search(i)) != i)
			cout << "Search error" << endl;
	}

	Y = X;

	cout << "X " << X.nil << "|" << X.root << endl;
	cout << "X " << X.nil << "|" << X.root->parent << endl;
    cout << "X " << X.nil << "|" << X.root->left->left->left->left << endl;
    cout << "X " << X.nil << "|" << X.root->right->right->right->right->right->right->right << endl;
    cout << "Y " << Y.nil << "|" << Y.root << endl;
    cout << "Y " << Y.nil << "|" << Y.root->parent << endl;
    cout << "Y " << Y.nil << "|" << Y.root->left->left->left->left << endl;
    cout << "Y " << Y.nil << "|" << Y.root->right->right->right->right->right->right->right << endl;



	X.preorder();
	X.inorder();
	X.printk(X.size());
	for (int i = 1; i < 30; i++)
	{
		cout << X.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	Y.preorder();
	Y.inorder();
	Y.printk(Y.size());
	for (int i = 1; i < 30; i++)
	{
		cout << Y.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	for (int i = 1; i < 30; i++)
	{
		if (Y.rank(i) != i)
			cout << "Rank error" << endl;
		if (Y.select(i) != i)
			cout << "Select error" << endl;
		if (*(Y.search(i)) != i)
			cout << "Search error" << endl;
	}
	cout << endl
		 << "--------------------------" << endl;

	X.remove(1);
	X.preorder();
	X.inorder();
	X.printk(X.size());
	for (int i = 1; i < 30; i++)
	{
		cout << X.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	Y.remove(1);
	Y.preorder();
	Y.inorder();
	Y.printk(Y.size());
	for (int i = 1; i < 30; i++)
	{
		cout << Y.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	X.remove(25);
	X.preorder();
	X.inorder();
	X.printk(X.size());
	for (int i = 1; i < 30; i++)
	{
		cout << X.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	Y.remove(25);
	Y.preorder();
	Y.inorder();
	Y.printk(Y.size());
	for (int i = 1; i < 30; i++)
	{
		cout << Y.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	X.remove(13);
	X.preorder();
	X.inorder();
	X.printk(X.size());
	for (int i = 1; i < 30; i++)
	{
		cout << X.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	Y.remove(13);
	Y.preorder();
	Y.inorder();
	Y.printk(Y.size());
	for (int i = 1; i < 30; i++)
	{
		cout << Y.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	X.remove(21);
	X.preorder();
	X.inorder();
	X.printk(X.size());
	for (int i = 1; i < 30; i++)
	{
		cout << X.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	Y.remove(21);
	Y.preorder();
	Y.inorder();
	Y.printk(Y.size());
	for (int i = 1; i < 30; i++)
	{
		cout << Y.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	X.remove(8);
	X.preorder();
	X.inorder();
	X.printk(X.size());
	for (int i = 1; i < 30; i++)
	{
		cout << X.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;
	

	Y.remove(8);
	Y.preorder();
	Y.inorder();
	Y.printk(Y.size());
	for (int i = 1; i < 30; i++)
	{
		cout << Y.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	X.remove(16);
	X.preorder();
	X.inorder();
	X.printk(X.size());
	for (int i = 1; i < 30; i++)
	{
		cout << X.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	Y.remove(16);
	Y.preorder();
	Y.inorder();
	Y.printk(Y.size());
	for (int i = 1; i < 30; i++)
	{
		cout << Y.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	X.remove(20);
	X.preorder();
	X.inorder();
	X.printk(X.size());
	for (int i = 1; i < 30; i++)
	{
		cout << X.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;

	Y.remove(20);
	Y.preorder();
	Y.inorder();
	Y.printk(Y.size());
	for (int i = 1; i < 30; i++)
	{
		cout << Y.select(i) << " ";
	}
	cout << endl
		 << "--------------------------" << endl;


	return 0;

}