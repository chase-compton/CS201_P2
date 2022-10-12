#include <iostream>
using namespace std;
#include "RBTree.cpp"

int main(){
	string K[10] = {"A","B","C","D","E","F","G","H","I","K"};
	int V[10] = {10,9,8,7,6,5,4,3,2,1};
	
	RBTree<string,int> T1, T2(K,V,10);
	
	for(int i=0; i<10; i++) T1.insert(K[i],V[i]);

	T1.inorder();
	T1.preorder();
	T1.postorder();

	cout<<endl;

	T2.inorder();
	T2.preorder();
	T2.postorder();
	return 0;
}