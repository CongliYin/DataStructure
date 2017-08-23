/****************************************************************************/
/*
  栈类：验证以下功能
     Stack(int size);                      //构造函数，分配内存，初始化栈空间，设置栈容量(size不变)，栈顶
	 ~Stack();                             //析构函数，释放空间
	 bool stackEmpty();                    //栈判空，为空返回true，非空返回false
	 bool stackFull();                     //栈判满，为满返回true，非满返回false
	 void clearStack();                    //清空栈中数据
	 int stackLength();                    //获取栈中现有元素个数
	 void push(char element);              //元素入栈，栈顶上升
	 char pop(char &element);              //元素出栈，栈顶下降
	 void stackTraverse();                 //遍历栈中所有元素

*/
/***************************************************************************/

#include<stdio.h>
#include<iostream>
#include"stdlib.h"
#include"Stack.h"
using namespace std;

int main()
{
	Stack *pStack = new Stack(5);

	//入栈
	pStack->push('h');                                //底
	pStack->push('e');
	pStack->push('l');
	pStack->push('l');
	pStack->push('o');                                //顶

	//遍历
	pStack->stackTraverse(true);

	//出栈
	char elem = 0;
	pStack->pop(elem);
	cout << elem << endl;

	//再次遍历
	pStack->stackTraverse(true);


	//判空
	if(pStack->stackEmpty())
	{
		cout << "栈为空" << endl;
	}

	//判满
	if(pStack->stackFull())
	{
		cout << "栈为满" << endl;
	}

	//栈现有元素的数量
	cout << pStack->stackLength() << endl;

	
	//清空
	pStack->clearStack();


	delete pStack;
	pStack = NULL;
	system("pause");
	return 0;
}