/****************************************************************************/
/*
  ջ�ࣺ��֤���¹���
     Stack(int size);                      //���캯���������ڴ棬��ʼ��ջ�ռ䣬����ջ����(size����)��ջ��
	 ~Stack();                             //�����������ͷſռ�
	 bool stackEmpty();                    //ջ�пգ�Ϊ�շ���true���ǿշ���false
	 bool stackFull();                     //ջ������Ϊ������true����������false
	 void clearStack();                    //���ջ������
	 int stackLength();                    //��ȡջ������Ԫ�ظ���
	 void push(char element);              //Ԫ����ջ��ջ������
	 char pop(char &element);              //Ԫ�س�ջ��ջ���½�
	 void stackTraverse();                 //����ջ������Ԫ��

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

	//��ջ
	pStack->push('h');                                //��
	pStack->push('e');
	pStack->push('l');
	pStack->push('l');
	pStack->push('o');                                //��

	//����
	pStack->stackTraverse(true);

	//��ջ
	char elem = 0;
	pStack->pop(elem);
	cout << elem << endl;

	//�ٴα���
	pStack->stackTraverse(true);


	//�п�
	if(pStack->stackEmpty())
	{
		cout << "ջΪ��" << endl;
	}

	//����
	if(pStack->stackFull())
	{
		cout << "ջΪ��" << endl;
	}

	//ջ����Ԫ�ص�����
	cout << pStack->stackLength() << endl;

	
	//���
	pStack->clearStack();


	delete pStack;
	pStack = NULL;
	system("pause");
	return 0;
}