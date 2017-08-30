
//˼·��

//ʹ��STL�е�stack��������ջ��s1��s2��s1������ջ��s2�����ջ��
//������ӣ�ʹ��STL�е�stack�ᶯ̬�����ڴ棬��˲��ص���ջ����������������ʱ��ֱ�ӽ�Ԫ����s1ջ���ɣ�
//���г��ӣ�����ʱ��Ҫs2��ջ�����Ҫ�ж�s2�Ƿ�Ϊ�գ�
//          ��s2Ϊ�գ���s1��Ԫ��һһ��ջ����s2ջ�У���ʱs2�Ѳ�Ϊ��,��ô���г���ֻ�轫s2��ջ���ɣ�
//          ��Ȼ�����s1��s2��Ϊ�գ������ʧ�ܡ�

#include<stack>
using namespace std;

class MyQueue
{
public:
	stack<int> s1;
	stack<int> s2;

	//��ӣ�ֱ��s1��ջ����
	bool EnQueue(int elem)
	{
		s1.push(elem);
		return true;
	}

	//���ӣ���s2Ϊ�գ��轫s1�е�Ԫ��һһ��ջ����s2�У��ٽ�s2��ջ
	//      ��s2����Ϊ�գ�ֱ�ӽ�s2��ջ
	bool DeQueue()
	{
		if(s1.empty() && s2.empty())
		{
			return false;
		}
		if(s2.empty())
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		if(!s2.empty())
		{
			s2.pop();
			return true;
		}
	}
};

int main()
{
	MyQueue q;

	//���
	for(int i = 0; i < 10; i++)
	{
		q.EnQueue(i);
	}

	//����
	for(int i = 0; i < 5; i++)
	{
		q.DeQueue();
	}

	system("pause");
	return 0;

}