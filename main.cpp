#include<iostream>
#include"BiTree.h"
using namespace std;

void main()
{
	char data[20] = "ABCDEG000F00H";
	BiTree<char> tree(data, 13);
	cout << "ǰ��";
	tree.PreOrder(tree.root);
	cout << "\n����";
	tree.InOrder(tree.root);
	cout << "\n����";
	tree.PostOrder(tree.root);
	cout << "\n����";
	tree.LevelOrder(tree.root);
	//cout << "\n���������" << tree.GetTotalNode(tree.GetRoot()) << endl;
}
