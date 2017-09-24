/*
#include<vector>
#include<iostream>
#include"Node.h"
class Graph
{
public:
	Graph(int capacity);        //构造函数
	~Graph();                   //析构函数
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);        //为无向图设置邻接矩阵

private:
	int m_iCapacity;            //图中能够容纳的结点数量
	int m_iNodeCount;           //目前的结点数量
	Node *m_pNodeArray;         //存放顶点的数组指针
	int *m_pMatrix;             //存放邻接矩阵的指针
};

Graph::Graph(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];                               //分配大小存放结点，一个数组
	m_pMatrix = new int[m_iCapacity * m_iCapacity];                     //分配大小存放邻接矩阵
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));      //将邻接矩阵的元素都置为0
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