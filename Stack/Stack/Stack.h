//Stack��Ķ��� 


class Stack
 {
 public:
	 Stack(int size);                      //���캯���������ڴ棬��ʼ��ջ�ռ䣬����ջ����(size����)��ջ��
	 ~Stack();                             //�����������ͷſռ�
	 bool stackEmpty();                    //ջ�пգ�Ϊ�շ���true���ǿշ���false
	 bool stackFull();                     //ջ������Ϊ������true����������false
	 void clearStack();                    //���ջ������
	 int stackLength();                    //��ȡջ������Ԫ�ظ���
	 bool push(char element);              //Ԫ����ջ��ջ������
	 bool pop(char &element);              //Ԫ�س�ջ��ջ���½�
	 //char Stack::pop()                   //Ԫ�س�ջ����һ�ֶ���
	 void stackTraverse(bool isFromButtom);//����ջ������Ԫ��

 public:
	 char *m_pBuffer;                      //ջ�ռ�ָ�룬ʹ��new�����µ�ջ�ռ䣬�����ָ��ָ����οռ�
	 int m_iSize;                          //ջ����������size��ֵ������
	 int m_iTop;                           //ջ����Ҳ����ջ�����е�Ԫ�ظ���
 };