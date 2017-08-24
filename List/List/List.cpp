#include"List.h"
#include<iostream>
using namespace std;

List::List(int size)
{
	m_iSize = size;
	//����ռ�
	m_pList = new int[m_iSize];                                                
	m_iLength = 0;
}

List::~List()
{
	delete []m_pList;
	m_pList = NULL;
}

void List::ClearList()
{
	m_iLength = 0;
}

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

int List::ListLength()
{
	return m_iLength;
}

//��ȡ��i��Ԫ�ص�ֵ����e��
bool List::GetElem(int i, int *e)
{
	if(i < 0 || i >= m_iSize)
		return false;
	*e = m_pList[i];
	return true;
}

//ȷ��ֵΪe��Ԫ�ص�λ�ã��Ҳ���λ�÷���-1
int List::LocateElem(int *e)
{
	for(int i = 0; i < m_iLength; i++)
	{
		if(m_pList[i] == *e)
		{
			return i;
		}
	}
	return -1;
}

//��ȡ��ǰԪ�ص�ǰ��
bool List::PriorElem(int *currentElem, int *preElem)
{
	//��ȷ����ǰԪ�ص�λ��
	int temp = LocateElem(currentElem);
	if(temp == -1)
	{
		return false;
	}
	else if(temp == 0)
	{
		return false;
	}
	else
	{
		*preElem = m_pList[temp - 1];
		return true;
	}
}

//��ȡ��ǰԪ�صĺ��
 bool List::NextElem(int *currentElem, int *nextElem)
 {
	 int temp = LocateElem(currentElem);
	 if(temp == -1)
	 {
		 return false;
	 }
	 else if(temp == m_iLength - 1)
	 {
		 return false;
	 }
	 else
	 {
		 *nextElem = m_pList[temp + 1];
		 return true;
	 }
 }

 //�ڵ�i��λ�ò���Ԫ�أ���i��λ��֮���Ԫ��ȫ������
 bool List::ListInsert(int i, int *e)
 {
	 if(i < 0 ||i > m_iLength)
	 {
		 return false;
	 }

	 for(int k = m_iLength - 1; k >= i; k--)
	 {
		 m_pList[k + 1] = m_pList[k];
	 }
	 m_pList[i] = *e;

	 m_iLength ++;
	 return true;
 }

 //ɾ����i��λ�õ�Ԫ�أ���i ��λ�õ�Ԫ��ȫ��ǰ��
 bool List::ListDelete(int i, int *e)
 {
	 if(i < 0 || i >= m_iLength)
	 {
		 return false;
	 }

	 *e = m_pList[i];
	 for(int k = i + 1; k < m_iLength; k++)
	 {
		 m_pList[k - 1] = m_pList[k];
	 }

	 m_iLength--;
	 return true;
 }

 void List::ListTraverse()
 {
	 for(int i = 0; i < m_iLength; i++)
	 {
		 cout << m_pList[i] << " ";
	 }
	 cout << endl;
 }