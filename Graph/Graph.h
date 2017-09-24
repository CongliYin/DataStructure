

#include<vector>
#include<iostream>
#include"Node.h"
using namespace std;

class Graph
{
public:
	Graph(int capacity);        //���캯��
	~Graph();                   //��������
	void resetNode();           //����ͼ�н���Ƿ񱻷��ʹ�
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);        //Ϊ����ͼ�����ڽӾ���
	void DepthFirstSearch(int nodeInedx);               //�����������
	void BreadthFirstSearch(int nodeIndex);             //�����������
	void BreadthFirstSearchImpl(vector<int> preVec);    //�������������ʵ��
private:
	int m_iCapacity;            //ͼ���ܹ����ɵĽ������
	int m_iNodeCount;           //Ŀǰ�Ľ������
	Node *m_pNodeArray;         //��Ŷ��������ָ��
	int *m_pMatrix;             //����ڽӾ����ָ��
};

//���캯����ʵ��
Graph::Graph(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];                               //�����С��Ž�㣬һ������
	m_pMatrix = new int[m_iCapacity * m_iCapacity];                     //�����С����ڽӾ���
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));      //���ڽӾ����Ԫ�ض���Ϊ0
}

//����������ʵ��
Graph::~Graph()
{
	delete []m_pNodeArray;
	delete []m_pMatrix;
}

//��ͼ�н��ȫ����Ϊδ�����ʵ�״̬
void Graph::resetNode()
{
	for(int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

//����ͼ��
bool Graph::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
	return true;
}

//������ȱ���
void Graph::DepthFirstSearch(int nodeIndex)
{
	//�ȷ��ʵ�ǰ����Ľ��
	m_pNodeArray[nodeIndex].m_cData;
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	for(int i = 0; i < m_iCapacity; i++)
	{
		//m_pMatrix[nodeIndex * m_iCapacity + i Ϊ�ڽӾ����nodeIndex�У�i�е�ֵ
		if(m_pMatrix[nodeIndex * m_iCapacity + i] == 1 && m_pNodeArray[i].m_bIsVisited == false)
		{
			DepthFirstSearch(i);
		}
	}
}

//�����������
void Graph::BreadthFirstSearch(int nodeIndex)
{
	resetNode();

	//���ʵ�ǰ����
	m_pNodeArray[nodeIndex].m_cData;
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	//����ǰ�����������
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