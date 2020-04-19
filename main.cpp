#include<iostream>
#include"BiTree.h"
using namespace std;

void main()
{
	char data[20] = "ABCDEG000F00H";
	BiTree<char> tree(data, 13);
	cout << "前序：";
	tree.PreOrder(tree.root);
	cout << "\n中序：";
	tree.InOrder(tree.root);
	cout << "\n后序：";
	tree.PostOrder(tree.root);
	cout << "\n层序：";
	tree.LevelOrder(tree.root);
	//cout << "\n结点总数：" << tree.GetTotalNode(tree.GetRoot()) << endl;
}
