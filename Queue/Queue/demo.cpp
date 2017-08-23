#include <iostream>
#include<stdlib.h>
#include"Queue.h"

using namespace std;

//    C++实现环形队列，验证Queue.cpp中函数的正确性

int main()
{
	Queue *p = new Queue(4);

	//插入元素
	p->EnQueue(10);
	p->EnQueue(12);
	p->EnQueue(16);
	p->EnQueue(18);
	//无法再插入
	//p->EnQueue(20);
	p->QueueTraverse();
	cout << endl;

	//出队
	int e = 0;
	p->DeQueue(e);
	cout << e <<endl;

	//继续出队
	p->DeQueue(e);
	cout << endl;
	cout << e <<endl;

	cout << endl;
	p->QueueTraverse();

	//清空队列
	p->ClearQueue();
	p->QueueTraverse();
	cout << endl;

	//重新插入队列
	p->EnQueue(20);
	p->EnQueue(30);
	p->QueueTraverse();
	cout << endl;

	delete p;
	p = NULL;
	
	system("pause");
	return 0;
}