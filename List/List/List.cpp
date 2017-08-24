#include"List.h"
#include<iostream>
using namespace std;

List::List(int size)
{
	m_iSize = size;
	//申请空间
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

//获取第i个元素的值存入e中
bool List::GetElem(int i, int *e)
{
	if(i < 0 || i >= m_iSize)
		return false;
	*e = m_pList[i];
	return true;
}

//确定值为e的元素的位置，找不到位置返回-1
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

//获取当前元素的前驱
bool List::PriorElem(int *currentElem, int *preElem)
{
	//先确定当前元素的位置
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

//获取当前元素的后继
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

 //在第i个位置插入元素，第i个位置之后的元素全部后移
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

 //删除第i个位置的元素，第i 个位置的元素全部前移
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