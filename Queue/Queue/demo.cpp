#include <iostream>
#include<stdlib.h>
#include"Queue.h"

using namespace std;

//    C++ʵ�ֻ��ζ��У���֤Queue.cpp�к�������ȷ��

int main()
{
	Queue *p = new Queue(4);

	//����Ԫ��
	p->EnQueue(10);
	p->EnQueue(12);
	p->EnQueue(16);
	p->EnQueue(18);
	//�޷��ٲ���
	//p->EnQueue(20);
	p->QueueTraverse();
	cout << endl;

	//����
	int e = 0;
	p->DeQueue(e);
	cout << e <<endl;

	//��������
	p->DeQueue(e);
	cout << endl;
	cout << e <<endl;

	cout << endl;
	p->QueueTraverse();

	//��ն���
	p->ClearQueue();
	p->QueueTraverse();
	cout << endl;

	//���²������
	p->EnQueue(20);
	p->EnQueue(30);
	p->QueueTraverse();
	cout << endl;

	delete p;
	p = NULL;
	
	system("pause");
	return 0;
}