class List
{
public:
	List(int size);                                   //创建线性表
	~List();                                          //释放空间
	void ClearList();                                 //清空线性表
	bool ListEmpty();                                 //线性表判空
	int ListLength();                                 //获取当前线性表的长度
	bool GetElem(int i, int *e);                      //获取第i个元素，放入e中
	int LocateElem(int *e);                           //获取值等于e的元素的位置
	bool PriorElem(int *currentElem, int *preElem);   //获取指定元素的前驱
    bool NextElem(int *currentElem, int *nextElem);   //获取指定元素的后继
    bool ListInsert(int i, int *e);                   //在第i个位置插入元素
    bool ListDelete(int i, int *e);                   //删除第i个位置的元素
    void ListTraverse(); 

private:
	int *m_pList;                                     //指向存储线性表的内存
	int m_iSize;                                      //线性表大小
	int m_iLength;                                    //当前线性表长度
};