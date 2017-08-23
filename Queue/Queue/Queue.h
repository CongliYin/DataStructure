//���ζ�����

//#ifndef Queue_H
//#define Queue_H 

class Queue
{
public:
	//���캯������ʼ�����У��������Ԫ�ض�Ϊ�򵥵���������
	//C++ʵ��                   //C����ʵ��

	Queue(int QueueCapacity);   //InitQueue(&Q)       ��������
	virtual ~Queue();           //DestroyQueue(&Q)    ���ٶ���
	void ClearQueue();          //ClearQueue(&Q)      ��ն���
	bool QueueEmpty() const;    //QueueEmpty(Q)       �ж϶����Ƿ�Ϊ��
	bool QueueFull() const;     //QueueFull(Q)        �ж϶����Ƿ�Ϊ��
	int QueueLength() const;    //QueueLength(Q)      ���г���
	bool EnQueue(int element);  //EnQueue(&Q,element) ��Ԫ�����
	bool DeQueue(int &element); //DeQueue(&Q,&element)��Ԫ�س���
	void QueueTraverse();       //QueueTranverse(Q)   ��������
private:
	int *m_pQueue;              //��������ָ��
	int m_iQueueLen;            //����Ԫ�صĸ���
	int m_iQueueCapacity;       //���е���������
	int m_iHead;
	int m_iTail;
};


//#endif