#include <iostream>
#include "BSTNode.h"
#include <cstdlib>
using namespace std;

int main() {
	BST<int> drzewo;
	for (int i = 0; i < 20; i++) {
		drzewo.insert(std::rand());
	}

	drzewo.BSTPrint();
	drzewo.SumNode();
	cout << drzewo.MaksBST()->Data << endl;
	cout << drzewo.MinBST()->Data<< endl;

	system("pause");
	return 0;
}