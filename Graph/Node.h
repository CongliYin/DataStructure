//������

class Node
{
public:
	//���캯��
	Node(char data = 0);

	//����
	char m_cData;

	//���嶥���Ƿ񱻷��ʹ�
	bool m_bIsVisited;
};

//���캯����ʵ��
Node::Node(char data)
{
	m_cData = data;
	m_bIsVisited = false;
}
