#include<iostream>
using namespace std;
#define MAXSIZE 10
template<class T>
struct BiNode//这里采用的是二叉链表法
{
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
};
template<class T>
class BiTree
{
private:
	void Create(BiNode<T> *&R, T data[], int i,int n); //创建   思考：这里为什么要用二级指针捏
	void Release(BiNode<T> *R);//释放
public:
	BiNode<T> *root;//思考：根节点为什么是公有的？
	BiTree() :root(NULL) {} //空树
	BiTree(T data[],int n);
	void PreOrder(BiNode<T>*R);//前序
	void InOrder(BiNode<T>*R);//中序
	void PostOrder(BiNode<T>*R);//后序
	void LevelOrder(BiNode<T>*R);//层序
	~BiTree();
};
template <class T>
void BiTree<T>::Create(BiNode<T>* &R, T data[], int i, int n) //创建二叉树
{ //R当前要建立的根节点指针，i当前根节点编号  n表示最后一个叶子结点的编号
	//R的类型：指针的引用
	if ((i <= n) && (data[i - 1] != '0'))
	{
		R = new BiNode<T>;					//1、建立根结点
		R->data = data[i - 1];
		R->lchild = NULL;
		R->rchild = NULL;

		Create(R->lchild, data, 2 * i, n);		//2、建立左子树
		Create(R->rchild, data, 2 * i + 1, n);//3、建立右子树
	}
}
template<class T>
BiTree<T>::BiTree(T data[],int n)
{
	Create(root, data, 1,n);
}
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *Root)
{
	if (Root != NULL)
	{
		cout << Root->data;//结点
		PreOrder(Root->lchild);//左子树
		PreOrder(Root->rchild);//右子树
	}
}
template<class T>
void BiTree<T>::InOrder(BiNode<T>*Root)
{
	if (Root != NULL)
	{
		InOrder(Root->lchild);//左子树
		cout << Root->data;//结点
		InOrder(Root->rchild);//右子树
	}
}
template<class T>
void BiTree<T>::PostOrder(BiNode<T> *Root)
{
	if (Root != NULL)
	{
		PostOrder(Root->lchild);//左子树
		PostOrder(Root->rchild);//右子树
		cout << Root->data;//结点
	}
}
template<class T>
void BiTree<T>::LevelOrder(BiNode<T> *R)
{
	BiNode<T> *queue[MAXSIZE];
	int f = 0, r = 0;    //初始化空队列
	if (R != NULL)	queue[++r] = R;//根结点入队
	while (f != r)
	{
		BiNode<T> *p = queue[++f];//队头元素出队
		cout << p->data;//出队打印
		if (p->lchild != NULL) queue[++r] = p->lchild;//左孩子入队
		if (p->rchild != NULL) queue[++r] = p->rchild;//右孩子入队
	}
}
template<class T>
void BiTree<T>::Release(BiNode<T> *R)//由于析构函数是不可以有形参的，只能单独写一个函数来释放空间
{
	if (R != NULL)
	{
		Release(R->lchild);
		Release(R->rchild);
		delete R;
	}
}
template<class T>
BiTree<T>::~BiTree()
{
	Release(root);
}