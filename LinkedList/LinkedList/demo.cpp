#include<iostream>
#include"List.h"
//#include"Node.h"      //�����ظ�����
using namespace std;

/****************************************************************************************/
/*���������������*/


int main()
{
	//��ջ��ʵ��������
	Node node1;
	node1.data = 3;
	Node node2;
	node2.data = 4;
	Node node3;
	node3.data = 5;
	Node node4;
	node4.data = 6;
	Node node5;
	node5.data = 7;

	Node node6;
	Node node7;
	Node node8;
	node8.data = 3;

	Node pre;
	Node next;

	//�Ӷ���ʵ��������
	List *pList = new List;

	/*
	//��ͷ���������
	pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	*/

	
	//��β���������
	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node4);
	

	//�ڵ�i��λ�ò�����
	//pList->ListInsert(0,&node5);
	pList->ListInsert(1,&node5);

	//ɾ����㱣����node6��
	pList->ListDelete(1,&node6);
	cout << "node6: " <<  node6.data << endl;

	//��������
	pList->ListTraverse();
	
	//������
	cout << "length: " << pList->ListLength() << endl;

	//ȡ�����Ϊ1��Ԫ�ط���node7��
	pList->GetElem(1,&node7);
	cout << "node7: " <<  node7.data << endl;

	//���غ�node8��������ȵĽ���λ��
	cout << "node8: " << pList->LocateElem(&node8) << endl;

	//ǰ��
	pList->PriorElem(&node2, &pre);
	cout << "pre: " << pre.data <<endl;

	//���
	pList->NextElem(&node2,&next);
	cout << "next:" <<next.data <<endl;

	//���
	pList->ClearList();

	//�п�
	pList->ListEmpty();

	//�ٴα�������
	pList->ListTraverse();

	delete pList;
	pList = NULL;
	system("pause");
	return 0;
}