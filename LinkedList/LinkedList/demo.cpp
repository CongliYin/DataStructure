#include<iostream>
#include"List.h"
//#include"Node.h"      //不能重复定义
using namespace std;

/****************************************************************************************/
/*单链表各函数测试*/


int main()
{
	//从栈中实例化对象
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

	//从堆中实例化对象
	List *pList = new List;

	/*
	//在头结点后插入结点
	pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	*/

	
	//在尾结点后插入结点
	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node4);
	

	//在第i个位置插入结点
	//pList->ListInsert(0,&node5);
	pList->ListInsert(1,&node5);

	//删除结点保存在node6中
	pList->ListDelete(1,&node6);
	cout << "node6: " <<  node6.data << endl;

	//遍历链表
	pList->ListTraverse();
	
	//链表长度
	cout << "length: " << pList->ListLength() << endl;

	//取出序号为1的元素放入node7中
	pList->GetElem(1,&node7);
	cout << "node7: " <<  node7.data << endl;

	//返回和node8数据域相等的结点的位置
	cout << "node8: " << pList->LocateElem(&node8) << endl;

	//前驱
	pList->PriorElem(&node2, &pre);
	cout << "pre: " << pre.data <<endl;

	//后继
	pList->NextElem(&node2,&next);
	cout << "next:" <<next.data <<endl;

	//清空
	pList->ClearList();

	//判空
	pList->ListEmpty();

	//再次遍历链表
	pList->ListTraverse();

	delete pList;
	pList = NULL;
	system("pause");
	return 0;
}