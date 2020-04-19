#include<iostream>
using namespace std;
#define MAXSIZE 10
template<class T>
struct BiNode//������õ��Ƕ�������
{
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
};
template<class T>
class BiTree
{
private:
	void Create(BiNode<T> *&R, T data[], int i,int n); //����   ˼��������ΪʲôҪ�ö���ָ����
	void Release(BiNode<T> *R);//�ͷ�
public:
	BiNode<T> *root;//˼�������ڵ�Ϊʲô�ǹ��еģ�
	BiTree() :root(NULL) {} //����
	BiTree(T data[],int n);
	void PreOrder(BiNode<T>*R);//ǰ��
	void InOrder(BiNode<T>*R);//����
	void PostOrder(BiNode<T>*R);//����
	void LevelOrder(BiNode<T>*R);//����
	~BiTree();
};
template <class T>
void BiTree<T>::Create(BiNode<T>* &R, T data[], int i, int n) //����������
{ //R��ǰҪ�����ĸ��ڵ�ָ�룬i��ǰ���ڵ���  n��ʾ���һ��Ҷ�ӽ��ı��
	//R�����ͣ�ָ�������
	if ((i <= n) && (data[i - 1] != '0'))
	{
		R = new BiNode<T>;					//1�����������
		R->data = data[i - 1];
		R->lchild = NULL;
		R->rchild = NULL;

		Create(R->lchild, data, 2 * i, n);		//2������������
		Create(R->rchild, data, 2 * i + 1, n);//3������������
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
		cout << Root->data;//���
		PreOrder(Root->lchild);//������
		PreOrder(Root->rchild);//������
	}
}
template<class T>
void BiTree<T>::InOrder(BiNode<T>*Root)
{
	if (Root != NULL)
	{
		InOrder(Root->lchild);//������
		cout << Root->data;//���
		InOrder(Root->rchild);//������
	}
}
template<class T>
void BiTree<T>::PostOrder(BiNode<T> *Root)
{
	if (Root != NULL)
	{
		PostOrder(Root->lchild);//������
		PostOrder(Root->rchild);//������
		cout << Root->data;//���
	}
}
template<class T>
void BiTree<T>::LevelOrder(BiNode<T> *R)
{
	BiNode<T> *queue[MAXSIZE];
	int f = 0, r = 0;    //��ʼ���ն���
	if (R != NULL)	queue[++r] = R;//��������
	while (f != r)
	{
		BiNode<T> *p = queue[++f];//��ͷԪ�س���
		cout << p->data;//���Ӵ�ӡ
		if (p->lchild != NULL) queue[++r] = p->lchild;//�������
		if (p->rchild != NULL) queue[++r] = p->rchild;//�Һ������
	}
}
template<class T>
void BiTree<T>::Release(BiNode<T> *R)//�������������ǲ��������βεģ�ֻ�ܵ���дһ���������ͷſռ�
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