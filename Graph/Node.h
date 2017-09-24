//定义结点

class Node
{
public:
	//构造函数
	Node(char data = 0);

	//数据
	char m_cData;

	//定义顶点是否被访问过
	bool m_bIsVisited;
};

//构造函数的实现
Node::Node(char data)
{
	m_cData = data;
	m_bIsVisited = false;
}
