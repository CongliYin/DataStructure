#include"Queue.h"
#include<iostream>
using namespace std;

Queue::Queue(int QueueCapacity)
{
	m_iQueueCapacity = QueueCapacity;      //队列容量，初始化时给定
	m_pQueue = new int[m_iQueueCapacity];  //申请空间
	m_iHead = 0;                           //队列头的位置
	m_iTail = 0;                           //队列尾的位置
	m_iQueueLen = 0;                       //队列初始长度
}

Queue::~Queue()
{
	delete []m_pQueue;                     //
	m_pQueue = NULL;                       //释放空间
}

void Queue::ClearQueue()                   //清空队列只需将头尾、长度置为0
{
	m_iHead = 0;                           
	m_iTail = 0;
	m_iQueueLen = 0;
}

bool Queue::QueueEmpty() const             //判断队列是否为空：队列长度等于0即为空
{
	if(m_iQueueLen == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

	//m_iQueueLen == 0 ? true : false;
}

bool Queue::QueueFull() const             //判断队列是否为满：队列长度等于队列申请的空间 即为满
{
	if(m_iQueueLen == m_iQueueCapacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Queue::QueueLength() const            //求队列的长度 
{
	return m_iQueueLen;
}

bool Queue::EnQueue(int element)               //元素入队：先判断队列是否未满
{
	if(QueueFull())
	{
		return false;
	}

	else
	{
		m_pQueue[m_iTail] = element;            //将入队元素的值赋给队尾
		m_iTail++;                              //队尾后移 1
		m_iTail = m_iTail % m_iQueueCapacity;   //队尾的下标变成 m_iTail % m_iQueueCapacity
		m_iQueueLen++;                          //队列长度加 1
		return true;
	}
}

bool Queue::DeQueue(int &element)               //元素出队：先判断队列是否为空
{
	if(QueueEmpty())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];            //将要出队的队列头的值赋给给定的变量
		m_iHead++;                              //队列头后移 1
		m_iHead = m_iHead % m_iQueueCapacity;   //头的下标更新为 m_iHead % m_iQueueCapacity
		m_iQueueLen--;                          //队列长度减 1
		return true;
	}
}

void Queue::QueueTraverse()                                //遍历对列打印出各元素的值
{
	for(int i = m_iHead; i < m_iQueueLen + m_iHead; i++)   //i 从头开始访问，直到访问完所有元素，长度为m_iQueueLen + m_iHead
	{
		cout<< m_pQueue[i % m_iQueueCapacity] << endl;
	}
}