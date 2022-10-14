#include <iostream>
using namespace std;
#include "RBTree.cpp"

int main()
{
	string K[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "K"};
	int V[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	RBTree<string, int> T1, T2(K, V, 10);

	for (int i = 0; i < 10; i++)
		T1.insert(K[i], V[i]);
	// T1 and T2 should be identical trees

	cout << *(T2.search("C")) << endl;
	// Should output 8

	cout << T1.rank("C") << endl;
	// Should output 3

	cout << T1.select(3) << endl;
	// Should output C

	T2.preorder();
	// Should output "D B A C F E H G I K\n"
	// as a string. There should be a single
	// newline after any of the order
	// method calls

	T2.inorder();
	// Should output	A B C D E F G H I K\n

	cout << T2.remove("D") << endl;
	// Should output 1

	T2.preorder();
	// Should output F C B A E H G I K\n

	T2.inorder();
	// Should output	A B C E F G H I K\n

	cout << T2.remove("H") << endl;
	// Should output 1

	T2.preorder();
	// Should output F C B A E H G I K\n

	T2.inorder();
	// Should output	A B C E F G H I K\n

	cout << T2.remove("H") << endl;
	// Should output 1

	T2.preorder();
	// Should output F C B A E H G I K\n

	T2.inorder();
	// Should output	A B C E F G H I K\n

	cout << *(T1.successor("A")) << endl;
	// Should output D

	cout << *(T1.predecessor("A")) << endl;
	// Should output B

	
	return 0;
}