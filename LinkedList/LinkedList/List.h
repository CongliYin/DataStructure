#include"Node.h"

class List
{
public:
	List();                                    //���캯��
	~List();                                   //��������
	void ClearList();                          //�������
	bool ListEmpty();                          //�����п�
	int ListLength();                          //������
	bool GetElem(int i, Node *pNode);          //��ȡ��i��Ԫ�أ�������pNode
	int LocateElem(Node *pNode);               //��ȡ������ͽ��pNode��ȵĽ��
	bool PriorElem(Node *currentNode, Node *preNode); //ǰ��
	bool NextElem(Node *currentNode, Node *nextNode); //���
	void ListTraverse();                              //��������
	bool ListInsertHead(Node *pNode);                 //����Ԫ�ص�ͷ���֮��
	bool ListInsertTail(Node *pNode);                 //����Ԫ�ص�β�ڵ�֮��
	bool ListInsert(int i, Node *pNode);              //����Ԫ�ص���i��λ��
	bool ListDelete(int i, Node *pNode);              //ɾ����i��λ�õ�Ԫ��

private:
	Node *m_pList;
	int m_iLength;
	

};