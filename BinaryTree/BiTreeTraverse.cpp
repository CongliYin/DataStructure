


//二叉树遍历的C语言实现，比C++中的实现更简单
//定义一个Node类型（结构体）的结点，更容易理解

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	//数据
	char data;
	//左孩子指针
	struct Node *LChild;
	//右孩子指针
	struct Node *RChild;
}BiTNode, *BiTree; //变量列表
//这个是变量列表
//BiTNode, *BiTree;

//建立一棵二叉树
int creatBinaryTree(BiTree &root)
{
	char data;

	//先序输入二叉树的一个结点（字符），‘#’表示空树
	scanf("%c", &data);

	if(data == '#')
	{
		root = NULL;
	}
	else
	{
		//申请空间存放结点
		root = (BiTree)malloc(sizeof(Node));

		//生成根节点
		root->data = data;

		//构造左子树
		creatBinaryTree(root->LChild);

		//构造右子树
		creatBinaryTree(root->RChild);
	}
	return 0;
}

//输出节点
void visit(BiTree root)
{
	if(root->data != '#')
	{
		printf("%c ", root->data);
	}
}

//先序遍历
void PreorderTraverse(BiTree root)
	{
		if(root != NULL)
		{
			visit(root);
			PreorderTraverse(root->LChild);
			PreorderTraverse(root->RChild);
		}
	}

//中序遍历
void InorderTraverse(BiTree root)
	{
		if(root != NULL)
		{
			
			InorderTraverse(root->LChild);
			visit(root);
			InorderTraverse(root->RChild);
		}
	}

//后序遍历
void PostorderTraverse(BiTree root)
	{
		if(root != NULL)
		{
			
			PostorderTraverse(root->LChild);
			PostorderTraverse(root->RChild);
			visit(root);
		}
	}

int main()
{
	BiTree T;
	creatBinaryTree(T);
	PreorderTraverse(T);
	InorderTraverse(T);
	PostorderTraverse(T);
	
	/*Node *root1 = NULL;
	PreorderTraverse(root1);
	InorderTraverse(root1);
	PostorderTraverse(root1);*/

	//system("pause");
	return 0;
}






