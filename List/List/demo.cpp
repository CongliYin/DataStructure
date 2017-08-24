#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"List.h"
using namespace std;

/***********************************************************************************/
/*���Ա�

  3 5 7 2 9 1 8

  C���Ա��: û��BOOL���ͣ��궨��BOOL����BOOL����
  BOOL InitList(List **list);                                                  //�������Ի�����ʼ��
  void DestroyList(List *list);                                                //�������Ա��ͷſռ�
  void ClearList(List *list);                                                  //������Ա�
  BOOL ListEmpty(List *list);                                                  //���Ա��п�
  int ListLength(List *list);                                                  //��ȡ���Ա�ǰ�ĳ���
  BOOL GetElem(List *list, int i, Elem *e);                                    //��ȡָ��Ԫ��
  int LocateElem(List *list, Elem *e);                                         //��ȡ��һ������e��Ԫ��λ��

  BOOL PriorElem(List *list, Elem *currentElem, Elem *preElem);                //��ȡָ��Ԫ�ص�ǰ��
  BOOL NextElem(List *list, Elem *currentElem, Elem *nextElem);                //��ȡָ��Ԫ�صĺ��
  BOOL ListInsert(List *list, int i, Elem *e);                                 //�ڵ�i��λ�ò���Ԫ��
  BOOL ListDelete(List *list, int i, Elem *e);                                 //ɾ����i��λ�õ�Ԫ��
  void ListTraverse(List *list);                                               //�������Ա�

*/
/************************************************************************************/


int main()
{
	int e1 = 3;
	int e2 = 5;
	int e3 = 7;
	int e4 = 2;
	int e5 = 9;
	int e6 = 1;
	int e7 = 8;
	

	List *list1 = new List(10);

	

	//˳��������
	list1->ListInsert(0,&e1);
	list1->ListInsert(1,&e2);
	list1->ListInsert(2,&e3);
	list1->ListInsert(3,&e4);
	list1->ListInsert(4,&e5);
	list1->ListInsert(5,&e6);

	list1->ListTraverse();
	
	//���Ա���
	cout << "����"<< list1->ListLength() << endl;

	
	//ȡԪ��
	int t = 0;
	list1->GetElem(3,&t);
	cout << "t:" << t << endl;
	
	
	//ȡλ��
	int b = 9;
	cout << list1->LocateElem(&b) << endl;
	
	
	//ȡǰ��
	//int t = 0;
	list1->PriorElem(&e4, &t);
	cout << "t:" << t << endl;
	

	//ȡ���
	//int t = 0;
	list1->NextElem(&e4, &t);
	cout << "t:" << t << endl;
	

	
	//�м�������
	list1->ListInsert(3,&e7);

	
	//˳������
	list1->ListTraverse();

	
	//���Ա���
	cout << "����"<< list1->ListLength() << endl;

	//ɾ��Ԫ��
	int temp = 0;
	list1->ListDelete(0, &temp);
	cout << "#" << temp <<endl;

	
	//���Ա��п�
	if(!list1->ListEmpty())
	{
		cout << "�ǿ�" << endl;
	}

	//ɾ��Ԫ��֮���ٴα���
	list1->ListTraverse();


	//������Ա�
	list1->ClearList();

	//���Ԫ��֮���ٴα���
	list1->ListTraverse();

	//���Ԫ��֮���ٴ����Ա��п�
	if(list1->ListEmpty())
	{
		cout << "��" << endl;
	}
	
	
	delete list1;
	list1 = NULL;
	system("pause");
	return 0;
}