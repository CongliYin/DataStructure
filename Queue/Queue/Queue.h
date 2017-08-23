//环形队列类

//#ifndef Queue_H
//#define Queue_H 

class Queue
{
public:
	//构造函数：初始化队列，假设队列元素都为简单的整型数据
	//C++实现                   //C语言实现

	Queue(int QueueCapacity);   //InitQueue(&Q)       创建队列
	virtual ~Queue();           //DestroyQueue(&Q)    销毁队列
	void ClearQueue();          //ClearQueue(&Q)      清空队列
	bool QueueEmpty() const;    //QueueEmpty(Q)       判断队列是否为空
	bool QueueFull() const;     //QueueFull(Q)        判断队列是否为满
	int QueueLength() const;    //QueueLength(Q)      队列长度
	bool EnQueue(int element);  //EnQueue(&Q,element) 新元素入队
	bool DeQueue(int &element); //DeQueue(&Q,&element)首元素出队
	void QueueTraverse();       //QueueTranverse(Q)   遍历队列
private:
	int *m_pQueue;              //队列数组指针
	int m_iQueueLen;            //队列元素的个数
	int m_iQueueCapacity;       //队列的数组容量
	int m_iHead;
	int m_iTail;
};


//#endif