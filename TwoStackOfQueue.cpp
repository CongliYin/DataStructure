
//思路：

//使用STL中的stack创建两个栈，s1和s2，s1负责入栈，s2负责出栈；
//队列入队：使用STL中的stack会动态分配内存，因此不必担心栈满的情况，所以入队时，直接将元素入s1栈即可；
//队列出队：出队时需要s2出栈，因此要判定s2是否为空；
//          若s2为空，则将s1中元素一一出栈进入s2栈中，此时s2已不为空,那么队列出队只需将s2出栈即可；
//          当然，如果s1和s2均为空，则出队失败。

#include<stack>
using namespace std;

class MyQueue
{
public:
	stack<int> s1;
	stack<int> s2;

	//入队：直接s1进栈即可
	bool EnQueue(int elem)
	{
		s1.push(elem);
		return true;
	}

	//出队：若s2为空，需将s1中的元素一一出栈进入s2中，再将s2出栈
	//      若s2本身不为空，直接将s2出栈
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

	//入队
	for(int i = 0; i < 10; i++)
	{
		q.EnQueue(i);
	}

	//出队
	for(int i = 0; i < 5; i++)
	{
		q.DeQueue();
	}

	system("pause");
	return 0;

}