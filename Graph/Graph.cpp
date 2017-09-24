/*
#include<vector>
#include<iostream>
#include"Node.h"
class Graph
{
public:
	Graph(int capacity);        //���캯��
	~Graph();                   //��������
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);        //Ϊ����ͼ�����ڽӾ���

private:
	int m_iCapacity;            //ͼ���ܹ����ɵĽ������
	int m_iNodeCount;           //Ŀǰ�Ľ������
	Node *m_pNodeArray;         //��Ŷ��������ָ��
	int *m_pMatrix;             //����ڽӾ����ָ��
};

Graph::Graph(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];                               //�����С��Ž�㣬һ������
	m_pMatrix = new int[m_iCapacity * m_iCapacity];                     //�����С����ڽӾ���
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));      //���ڽӾ����Ԫ�ض���Ϊ0
}

Graph::~Graph()
{
	delete []m_pNodeArray;
	delete []m_pMatrix;
}

bool Graph::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
}
*/