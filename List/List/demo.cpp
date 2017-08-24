#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"List.h"
using namespace std;

/***********************************************************************************/
/*线性表

  3 5 7 2 9 1 8

  C语言表达: 没有BOOL类型，宏定义BOOL代替BOOL类型
  BOOL InitList(List **list);                                                  //创建线性化，初始化
  void DestroyList(List *list);                                                //销毁线性表，释放空间
  void ClearList(List *list);                                                  //清空线性表
  BOOL ListEmpty(List *list);                                                  //线性表判空
  int ListLength(List *list);                                                  //获取线性表当前的长度
  BOOL GetElem(List *list, int i, Elem *e);                                    //获取指定元素
  int LocateElem(List *list, Elem *e);                                         //获取第一个满足e的元素位置

  BOOL PriorElem(List *list, Elem *currentElem, Elem *preElem);                //获取指定元素的前驱
  BOOL NextElem(List *list, Elem *currentElem, Elem *nextElem);                //获取指定元素的后继
  BOOL ListInsert(List *list, int i, Elem *e);                                 //在第i个位置插入元素
  BOOL ListDelete(List *list, int i, Elem *e);                                 //删除第i个位置的元素
  void ListTraverse(List *list);                                               //遍历线性表

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

	

	//顺序插入测试
	list1->ListInsert(0,&e1);
	list1->ListInsert(1,&e2);
	list1->ListInsert(2,&e3);
	list1->ListInsert(3,&e4);
	list1->ListInsert(4,&e5);
	list1->ListInsert(5,&e6);

	list1->ListTraverse();
	
	//线性表长度
	cout << "长度"<< list1->ListLength() << endl;

	
	//取元素
	int t = 0;
	list1->GetElem(3,&t);
	cout << "t:" << t << endl;
	
	
	//取位置
	int b = 9;
	cout << list1->LocateElem(&b) << endl;
	
	
	//取前驱
	//int t = 0;
	list1->PriorElem(&e4, &t);
	cout << "t:" << t << endl;
	

	//取后继
	//int t = 0;
	list1->NextElem(&e4, &t);
	cout << "t:" << t << endl;
	

	
	//中间插入测试
	list1->ListInsert(3,&e7);

	
	//顺序表遍历
	list1->ListTraverse();

	
	//线性表长度
	cout << "长度"<< list1->ListLength() << endl;

	//删除元素
	int temp = 0;
	list1->ListDelete(0, &temp);
	cout << "#" << temp <<endl;

	
	//线性表判空
	if(!list1->ListEmpty())
	{
		cout << "非空" << endl;
	}

	//删除元素之后再次遍历
	list1->ListTraverse();


	//清空线性表
	list1->ClearList();

	//清空元素之后再次遍历
	list1->ListTraverse();

	//清空元素之后再次线性表判空
	if(list1->ListEmpty())
	{
		cout << "空" << endl;
	}
	
	
	delete list1;
	list1 = NULL;
	system("pause");
	return 0;
}