

#include<vector>
#include<iostream>
#include"Node.h"
using namespace std;

class Graph
{
public:
	Graph(int capacity);        //构造函数
	~Graph();                   //析构函数
	void resetNode();           //重置图中结点是否被访问过
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);        //为无向图设置邻接矩阵
	void DepthFirstSearch(int nodeInedx);               //深度优先搜索
	void BreadthFirstSearch(int nodeIndex);             //广度优先搜索
	void BreadthFirstSearchImpl(vector<int> preVec);    //广度优先搜索的实现
private:
	int m_iCapacity;            //图中能够容纳的结点数量
	int m_iNodeCount;           //目前的结点数量
	Node *m_pNodeArray;         //存放顶点的数组指针
	int *m_pMatrix;             //存放邻接矩阵的指针
};

//构造函数的实现
Graph::Graph(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];                               //分配大小存放结点，一个数组
	m_pMatrix = new int[m_iCapacity * m_iCapacity];                     //分配大小存放邻接矩阵
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));      //将邻接矩阵的元素都置为0
}

//析构函数的实现
Graph::~Graph()
{
	delete []m_pNodeArray;
	delete []m_pMatrix;
}

//将图中结点全部置为未被访问的状态
void Graph::resetNode()
{
	for(int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

//构建图，
bool Graph::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
	return true;
}

//深度优先遍历
void Graph::DepthFirstSearch(int nodeIndex)
{
	//先访问当前传入的结点
	m_pNodeArray[nodeIndex].m_cData;
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	for(int i = 0; i < m_iCapacity; i++)
	{
		//m_pMatrix[nodeIndex * m_iCapacity + i 为邻接矩阵的nodeIndex行，i列的值
		if(m_pMatrix[nodeIndex * m_iCapacity + i] == 1 && m_pNodeArray[i].m_bIsVisited == false)
		{
			DepthFirstSearch(i);
		}
	}
}

//广度优先搜索
void Graph::BreadthFirstSearch(int nodeIndex)
{
	resetNode();

	//访问当前顶点
	m_pNodeArray[nodeIndex].m_cData;
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	//将当前顶点存入数组
	vector<int> curVec;
	curVec.push_back(nodeIndex);

	BreadthFirstSearchImpl(curVec);

	/*vector<int> nextVec;

	for(int j = 0; j < curVec.size(); j++)
	{
		for(int k = 0; k < m_iCapacity; k++)
		{
			if(m_pMatrix[curVec[j] * m_iCapacity + k] == 1 && m_pNodeArray[k].m_bIsVisited == false)
			{
				m_pNodeArray[k].m_cData;
				m_pNodeArray[k].m_bIsVisited = true;
				nextVec.push_back(k);
			}
		}
	}*/

	
}

void Graph::BreadthFirstSearchImpl(vector<int> preVec)
{
	//int value = 0;
	vector<int> curVec;

	for(int j = 0; j < preVec.size(); j++)
	{
		for(int k = 0; k < m_iCapacity; k++)
		{
			if(m_pMatrix[preVec[j] * m_iCapacity + k] == 1 && m_pNodeArray[k].m_bIsVisited == false)
			{
				m_pNodeArray[k].m_cData;
				m_pNodeArray[k].m_bIsVisited = true;
				curVec.push_back(k);
			}
		}
	}
	if(curVec.size() == 0)
	{
		return;
	}
	else
	{
		BreadthFirstSearchImpl(curVec);
	}
}