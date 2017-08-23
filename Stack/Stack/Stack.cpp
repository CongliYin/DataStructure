#include<iostream>
#include<stdio.h>
#include"Stack.h"
using namespace std;

Stack::Stack(int size)
{
	m_iSize = size;
	m_pBuffer = new char[size];                                 //����ռ䣬��СΪsize
	m_iTop = 0;                                                 //ջ��Ϊ0����Ϊ��ջ
}

Stack::~Stack()
{
	delete []m_pBuffer;
	m_pBuffer = NULL;
}

bool Stack::stackEmpty()
{
	if(m_iTop == 0)                                             //if(0 == m_iTop)�Ƽ�ʹ�ã������﷨ 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Stack::stackFull()
{
	if(m_iTop == m_iSize)                                      //if(m_iTop >= m_iSize) Ҳ��
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack::clearStack()
{
	m_iTop = 0;                                                //ջ��Ԫ����Ч����Ԫ�ػḲ�ǵ���Ԫ��
}

int Stack::stackLength()
{
	return m_iTop;
}

bool Stack::push(char element)                                 //������
{
	if(stackFull())
	{
		return false;
	}
	m_pBuffer[m_iTop] = element;
	m_iTop++;                                                  //��һ��Ҫ��ջ��λ��
	return true;
}
 
bool Stack::pop(char &element)                                 //�Ƽ�bool����
{
	if(stackEmpty())
	{
		return false;
	}
	m_iTop--;                                                  //��֤top����Ԫ��
	element = m_pBuffer[m_iTop];                              
	//m_iTop--;
	return true;
}

/*
char Stack::pop()                                              //char���͵ĳ�ջ
{
	if(stackEmpty())
	{
		throw 1;
	}
	m_iTop--;                                                  //��֤top����Ԫ��
	return m_pBuffer[m_iTop];
}
*/

void Stack::stackTraverse(bool isFromButtom)                  //��ջ��Ԫ�ؽ�Ϊ����ʱ����Ҫʹ��visit()�������� 
{
	if (isFromButtom)
	{
		for(int i = 0; i < m_iTop; i++)                       //��ջ����ջ������
		{
			cout << m_pBuffer[i] << endl;
		}
	}
	else
	{
		for(int i = m_iTop; i >= 0; i--)                      //��ջ����ջ�ױ���
		{
			cout << m_pBuffer[i] << endl;
		}
	}
}