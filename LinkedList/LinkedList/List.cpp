#include"List.h"
#include <iostream>
using namespace std;
//#include"Node.h"

/************************************************************************/
/*List�����Ա������ʵ��*/

List::List()
{
	//����һ���ռ��Ž��
	m_pList = new Node;                 
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

//�������
void List::ClearList()
{
	//����ǰ���ָ��ͷ����next
	Node *currentNode = m_pList->next;
	//�����ǰ��㲻Ϊ�գ���ɾ����ֱ����ǰ���Ϊ��
	while(currentNode != NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	//��ͷ����next��Ϊ��
	m_pList->next = NULL; 
}

List::~List()
{
	//���������ֻʣ��ͷ���
	ClearList();
	//ɾ��ͷ��㣬�ͷ��ڴ�
	delete m_pList;
	m_pList = NULL;
}


//�ж������Ƿ�Ϊ�գ�ֻ���ж�����ĵ�ǰ����m_iLength�Ƿ�Ϊ0
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

//��ȡ����ĵ�ǰ���ȣ�ֱ�ӷ��ص�ǰ����m_iLength
int List::ListLength()
{
	return m_iLength;
}

//�����㵽ͷ���֮��
bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;
	Node *newNode = new Node;
	if(newNode == NULL)
	{
		return false;
	}
	//�ȴ���������
	newNode->data = pNode->data;
	//�ٴ���ǰ��Ľ��
	m_pList->next = newNode;
	//������Լ���ָ��
	newNode->next = temp;
	//����������1
	m_iLength++;
	return true;
}

//�����㵽β�ڵ�֮��
bool List::ListInsertTail(Node *pNode)
{
	//���������ҵ����һ�����
	Node *currentNode = m_pList;
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	//Ϊ����Ľ������ռ�
	Node *newNode = new Node;
	if(newNode == NULL)
	{
		return false;
	}
	//�ȴ���������
	newNode->data = pNode->data;
	//�ٴ����Լ���ָ��
	newNode->next = NULL;
	//�����ǰ��Ľ��
	currentNode->next = newNode;
	//����������1
	m_iLength++;
	return true;
}

//�ڵ�i��λ�ò�����
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
	//�����ҵ���i�����
	Node *currentNode = m_pList;
	for(int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}

	//�ȴ���������
	newNode->data = pNode->data;
	//�ٴ����Լ���ָ��
	newNode->next = currentNode->next;
	//�����ǰ��Ľ��
	currentNode->next = newNode;
	//����������1
	m_iLength++;
	return true;
}

bool List::ListDelete(int i,Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	//�����ҵ���i������ǰһ�����
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for(int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	} 

	//�ȴ���������
	pNode->data = currentNode->data;
	//�ٴ����Լ���ָ��ɾ��
	currentNodeBefore->next = currentNode->next;
	//ɾ�����
	delete currentNode;
	currentNode = NULL;
	//�����ȼ�1
	m_iLength--;
	return true;
}

//��ȡ��i������ֵ���Ƹ�pNode
bool List::GetElem(int i, Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	//�����ҵ���i�����
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

//���ص�һ��ֵ����pNode��ֵ��λ��
//�������У�ͷ��㲻��λ��Ϊ0�Ľ�㣬ͷ������һ��������
int List::LocateElem(Node *pNode)
{
	//�ҵ�ͷ���
	Node *currentNode = m_pList;
	//����λ�õı���
	int count = 0;
	//���������ҵ�ֵ
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if(currentNode->data == pNode->data)
		{
			return count;
		}
		count++;
	}
	//��δ�ҵ�������-1
	return -1;
}

//Ѱ��currentNode����ǰ��
bool List::PriorElem(Node *currentNode, Node *preNode)
{
	//��ȡͷ���
	Node *currentNodeNew = m_pList;
	//���嵱ǰ����ǰһ�����
	Node *currentNodeBefore = NULL;

	//��������
	while(currentNodeNew->next != NULL)
	{
		currentNodeBefore = currentNodeNew;
		currentNodeNew = currentNodeNew->next;
		//���ҵ���ǰ���currentNode
		if(currentNode->data == currentNodeNew->data)
		{
			//����ǰ����ǰ��Ϊͷ��㣬����false
			if(currentNodeBefore == m_pList)
			{
				return false;
			}
			//��ǰ����ֵ��preNode��������
			preNode->data = currentNodeBefore->data;
			return true;
		}
	}
	return false;
}

//Ѱ��currentNode�ĺ��
bool List::NextElem(Node *currentNode, Node *nextNode)
{
	//��ȡͷ���
	Node *currentNodeNew = m_pList;
	//��������
	while(currentNodeNew->next != NULL)
	{
		currentNodeNew = currentNodeNew->next;
		if(currentNodeNew->data == currentNode->data)
		{
			if(currentNodeNew->next == NULL)
			{
				return false;
			}
			//���ҵ��Ľ���next��ֵ��ֵ��nextNode��������
			nextNode->data = currentNodeNew->next->data;
			return true;
		}
	}
	return false;
}

//��������
void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}

}