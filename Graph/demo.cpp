#include<iostream>
#include"Graph.h"

using namespace std;

int main()
{
	Graph *pGraph = new Graph(8);

	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	Node *pNodeG = new Node('G');
	Node *pNodeH = new Node('H');

	//�����ڽӾ����ֵ���洢ͼ��ԭ���ڽӾ���ȫΪ0�����ڰ�һЩ����Ϊ1����������ڽӹ�ϵ��������ͼ
	pGraph->setValueToMatrixForUndirectedGraph(0,1,1);
	pGraph->setValueToMatrixForUndirectedGraph(0,3,1);
	pGraph->setValueToMatrixForUndirectedGraph(1,2,1);
	pGraph->setValueToMatrixForUndirectedGraph(1,5,1);
	pGraph->setValueToMatrixForUndirectedGraph(3,6,1);
	pGraph->setValueToMatrixForUndirectedGraph(3,7,1);
	pGraph->setValueToMatrixForUndirectedGraph(6,7,1);
	pGraph->setValueToMatrixForUndirectedGraph(2,4,1);
	pGraph->setValueToMatrixForUndirectedGraph(4,5,1);

	return 0;
}