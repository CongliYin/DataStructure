#include"Queue.h"
#include<iostream>
using namespace std;

Queue::Queue(int QueueCapacity)
{
	m_iQueueCapacity = QueueCapacity;      //������������ʼ��ʱ����
	m_pQueue = new int[m_iQueueCapacity];  //����ռ�
	m_iHead = 0;                           //����ͷ��λ��
	m_iTail = 0;                           //����β��λ��
	m_iQueueLen = 0;                       //���г�ʼ����
}

Queue::~Queue()
{
	delete []m_pQueue;                     //
	m_pQueue = NULL;                       //�ͷſռ�
}

void Queue::ClearQueue()                   //��ն���ֻ�轫ͷβ��������Ϊ0
{
	m_iHead = 0;                           
	m_iTail = 0;
	m_iQueueLen = 0;
}

bool Queue::QueueEmpty() const             //�ж϶����Ƿ�Ϊ�գ����г��ȵ���0��Ϊ��
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

bool Queue::QueueFull() const             //�ж϶����Ƿ�Ϊ�������г��ȵ��ڶ�������Ŀռ� ��Ϊ��
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

int Queue::QueueLength() const            //����еĳ��� 
{
	return m_iQueueLen;
}

bool Queue::EnQueue(int element)               //Ԫ����ӣ����ж϶����Ƿ�δ��
{
	if(QueueFull())
	{
		return false;
	}

	else
	{
		m_pQueue[m_iTail] = element;            //�����Ԫ�ص�ֵ������β
		m_iTail++;                              //��β���� 1
		m_iTail = m_iTail % m_iQueueCapacity;   //��β���±��� m_iTail % m_iQueueCapacity
		m_iQueueLen++;                          //���г��ȼ� 1
		return true;
	}
}

bool Queue::DeQueue(int &element)               //Ԫ�س��ӣ����ж϶����Ƿ�Ϊ��
{
	if(QueueEmpty())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];            //��Ҫ���ӵĶ���ͷ��ֵ���������ı���
		m_iHead++;                              //����ͷ���� 1
		m_iHead = m_iHead % m_iQueueCapacity;   //ͷ���±����Ϊ m_iHead % m_iQueueCapacity
		m_iQueueLen--;                          //���г��ȼ� 1
		return true;
	}
}

void Queue::QueueTraverse()                                //�������д�ӡ����Ԫ�ص�ֵ
{
	for(int i = m_iHead; i < m_iQueueLen + m_iHead; i++)   //i ��ͷ��ʼ���ʣ�ֱ������������Ԫ�أ�����Ϊm_iQueueLen + m_iHead
	{
		cout<< m_pQueue[i % m_iQueueCapacity] << endl;
	}
}