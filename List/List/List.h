class List
{
public:
	List(int size);                                   //�������Ա�
	~List();                                          //�ͷſռ�
	void ClearList();                                 //������Ա�
	bool ListEmpty();                                 //���Ա��п�
	int ListLength();                                 //��ȡ��ǰ���Ա�ĳ���
	bool GetElem(int i, int *e);                      //��ȡ��i��Ԫ�أ�����e��
	int LocateElem(int *e);                           //��ȡֵ����e��Ԫ�ص�λ��
	bool PriorElem(int *currentElem, int *preElem);   //��ȡָ��Ԫ�ص�ǰ��
    bool NextElem(int *currentElem, int *nextElem);   //��ȡָ��Ԫ�صĺ��
    bool ListInsert(int i, int *e);                   //�ڵ�i��λ�ò���Ԫ��
    bool ListDelete(int i, int *e);                   //ɾ����i��λ�õ�Ԫ��
    void ListTraverse(); 

private:
	int *m_pList;                                     //ָ��洢���Ա���ڴ�
	int m_iSize;                                      //���Ա��С
	int m_iLength;                                    //��ǰ���Ա���
};