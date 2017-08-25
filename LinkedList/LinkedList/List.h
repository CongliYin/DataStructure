#include"Node.h"

class List
{
public:
	List();                                    //构造函数
	~List();                                   //析构函数
	void ClearList();                          //清空链表
	bool ListEmpty();                          //链表判空
	int ListLength();                          //链表长度
	bool GetElem(int i, Node *pNode);          //获取第i个元素，存入结点pNode
	int LocateElem(Node *pNode);               //获取数据域和结点pNode相等的结点
	bool PriorElem(Node *currentNode, Node *preNode); //前驱
	bool NextElem(Node *currentNode, Node *nextNode); //后继
	void ListTraverse();                              //遍历链表
	bool ListInsertHead(Node *pNode);                 //插入元素到头结点之后
	bool ListInsertTail(Node *pNode);                 //插入元素到尾节点之后
	bool ListInsert(int i, Node *pNode);              //插入元素到第i个位置
	bool ListDelete(int i, Node *pNode);              //删除第i个位置的元素

private:
	Node *m_pList;
	int m_iLength;
	

};