#include<iostream>
#include<stdio.h>
#include"Stack.h"
using namespace std;

Stack::Stack(int size)
{
	m_iSize = size;
	m_pBuffer = new char[size];                                 //申请空间，大小为size
	m_iTop = 0;                                                 //栈顶为0，即为空栈
}

Stack::~Stack()
{
	delete []m_pBuffer;
	m_pBuffer = NULL;
}

bool Stack::stackEmpty()
{
	if(m_iTop == 0)                                             //if(0 == m_iTop)推荐使用，会检查语法 
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
	if(m_iTop == m_iSize)                                      //if(m_iTop >= m_iSize) 也可
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
	m_iTop = 0;                                                //栈中元素无效，新元素会覆盖掉旧元素
}

int Stack::stackLength()
{
	return m_iTop;
}

bool Stack::push(char element)                                 //先判满
{
	if(stackFull())
	{
		return false;
	}
	m_pBuffer[m_iTop] = element;
	m_iTop++;                                                  //下一个要入栈的位置
	return true;
}
 
bool Stack::pop(char &element)                                 //推荐bool类型
{
	if(stackEmpty())
	{
		return false;
	}
	m_iTop--;                                                  //保证top中有元素
	element = m_pBuffer[m_iTop];                              
	//m_iTop--;
	return true;
}

/*
char Stack::pop()                                              //char类型的出栈
{
	if(stackEmpty())
	{
		throw 1;
	}
	m_iTop--;                                                  //保证top中有元素
	return m_pBuffer[m_iTop];
}
*/

void Stack::stackTraverse(bool isFromButtom)                  //当栈中元素较为复杂时，需要使用visit()函数访问 
{
	if (isFromButtom)
	{
		for(int i = 0; i < m_iTop; i++)                       //从栈底向栈顶遍历
		{
			cout << m_pBuffer[i] << endl;
		}
	}
	else
	{
		for(int i = m_iTop; i >= 0; i--)                      //从栈顶向栈底遍历
		{
			cout << m_pBuffer[i] << endl;
		}
	}
}