#include"List.h"
#include <iostream>
using namespace std;
//#include"Node.h"

/************************************************************************/
/*List类各成员函数的实现*/

List::List()
{
	//申请一个空间存放结点
	m_pList = new Node;                 
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

//清空链表
void List::ClearList()
{
	//将当前结点指向头结点的next
	Node *currentNode = m_pList->next;
	//如果当前结点不为空，就删除，直到当前结点为空
	while(currentNode != NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	//将头结点的next置为空
	m_pList->next = NULL; 
}

List::~List()
{
	//先清空链表，只剩下头结点
	ClearList();
	//删除头结点，释放内存
	delete m_pList;
	m_pList = NULL;
}


//判断链表是否为空：只需判断链表的当前长度m_iLength是否为0
bool List::ListEmpty()
{
	if(m_iLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//获取链表的当前长度：直接返回当前长度m_iLength
int List::ListLength()
{
	return m_iLength;
}

//插入结点到头结点之后
bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;
	Node *newNode = new Node;
	if(newNode == NULL)
	{
		return false;
	}
	//先处理数据域
	newNode->data = pNode->data;
	//再处理前面的结点
	m_pList->next = newNode;
	//最后处理自己的指针
	newNode->next = temp;
	//链表长度增加1
	m_iLength++;
	return true;
}

//插入结点到尾节点之后
bool List::ListInsertTail(Node *pNode)
{
	//遍历链表找到最后一个结点
	Node *currentNode = m_pList;
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	//为插入的结点申请空间
	Node *newNode = new Node;
	if(newNode == NULL)
	{
		return false;
	}
	//先处理数据域
	newNode->data = pNode->data;
	//再处理自己的指针
	newNode->next = NULL;
	//最后处理前面的结点
	currentNode->next = newNode;
	//链表长度增加1
	m_iLength++;
	return true;
}

//在第i个位置插入结点
bool List::ListInsert(int i, Node *pNode)
{
	if(i < 0 || i > m_iLength)
	{
		return false;
	}
	Node *newNode = new Node;
	if(newNode == NULL)
	{
		return false;
	}
	//遍历找到第i个结点
	Node *currentNode = m_pList;
	for(int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}

	//先处理数据域
	newNode->data = pNode->data;
	//再处理自己的指针
	newNode->next = currentNode->next;
	//最后处理前面的结点
	currentNode->next = newNode;
	//链表长度增加1
	m_iLength++;
	return true;
}

bool List::ListDelete(int i,Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	//遍历找到第i个结点和前一个结点
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for(int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	} 

	//先处理数据域
	pNode->data = currentNode->data;
	//再处理自己的指针删除
	currentNodeBefore->next = currentNode->next;
	//删除结点
	delete currentNode;
	currentNode = NULL;
	//链表长度减1
	m_iLength--;
	return true;
}

//获取第i个结点的值复制给pNode
bool List::GetElem(int i, Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	//遍历找到第i个结点
	Node *currentNode = m_pList;
	//Node *currentNodeBefore = NULL;
	for(int k = 0; k <= i; k++)
	{
		//currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	} 
	pNode->data = currentNode->data;
	return true;
}

//返回第一个值等于pNode的值的位置
//在链表中，头结点不是位置为0的结点，头结点的下一个结点才是
int List::LocateElem(Node *pNode)
{
	//找到头结点
	Node *currentNode = m_pList;
	//保存位置的变量
	int count = 0;
	//遍历链表找到值
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if(currentNode->data == pNode->data)
		{
			return count;
		}
		count++;
	}
	//若未找到，返回-1
	return -1;
}

//寻找currentNode结点的前驱
bool List::PriorElem(Node *currentNode, Node *preNode)
{
	//获取头结点
	Node *currentNodeNew = m_pList;
	//定义当前结点的前一个结点
	Node *currentNodeBefore = NULL;

	//遍历链表
	while(currentNodeNew->next != NULL)
	{
		currentNodeBefore = currentNodeNew;
		currentNodeNew = currentNodeNew->next;
		//若找到当前结点currentNode
		if(currentNode->data == currentNodeNew->data)
		{
			//若当前结点的前驱为头结点，返回false
			if(currentNodeBefore == m_pList)
			{
				return false;
			}
			//将前驱的值给preNode的数据域
			preNode->data = currentNodeBefore->data;
			return true;
		}
	}
	return false;
}

//寻找currentNode的后继
bool List::NextElem(Node *currentNode, Node *nextNode)
{
	//获取头结点
	Node *currentNodeNew = m_pList;
	//遍历链表
	while(currentNodeNew->next != NULL)
	{
		currentNodeNew = currentNodeNew->next;
		if(currentNodeNew->data == currentNode->data)
		{
			if(currentNodeNew->next == NULL)
			{
				return false;
			}
			//将找到的结点的next的值赋值给nextNode的数据域
			nextNode->data = currentNodeNew->next->data;
			return true;
		}
	}
	return false;
}

//遍历链表
void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}

}