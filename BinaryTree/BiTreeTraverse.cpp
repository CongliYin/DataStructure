


//������������C����ʵ�֣���C++�е�ʵ�ָ���
//����һ��Node���ͣ��ṹ�壩�Ľ�㣬���������

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	//����
	char data;
	//����ָ��
	struct Node *LChild;
	//�Һ���ָ��
	struct Node *RChild;
}BiTNode, *BiTree; //�����б�
//����Ǳ����б�
//BiTNode, *BiTree;

//����һ�ö�����
int creatBinaryTree(BiTree &root)
{
	char data;

	//���������������һ����㣨�ַ�������#����ʾ����
	scanf("%c", &data);

	if(data == '#')
	{
		root = NULL;
	}
	else
	{
		//����ռ��Ž��
		root = (BiTree)malloc(sizeof(Node));

		//���ɸ��ڵ�
		root->data = data;

		//����������
		creatBinaryTree(root->LChild);

		//����������
		creatBinaryTree(root->RChild);
	}
	return 0;
}

//����ڵ�
void visit(BiTree root)
{
	if(root->data != '#')
	{
		printf("%c ", root->data);
	}
}

//�������
void PreorderTraverse(BiTree root)
	{
		if(root != NULL)
		{
			visit(root);
			PreorderTraverse(root->LChild);
			PreorderTraverse(root->RChild);
		}
	}

//�������
void InorderTraverse(BiTree root)
	{
		if(root != NULL)
		{
			
			InorderTraverse(root->LChild);
			visit(root);
			InorderTraverse(root->RChild);
		}
	}

//�������
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






