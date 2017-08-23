//Stack类的定义 


class Stack
 {
 public:
	 Stack(int size);                      //构造函数，分配内存，初始化栈空间，设置栈容量(size不变)，栈顶
	 ~Stack();                             //析构函数，释放空间
	 bool stackEmpty();                    //栈判空，为空返回true，非空返回false
	 bool stackFull();                     //栈判满，为满返回true，非满返回false
	 void clearStack();                    //清空栈中数据
	 int stackLength();                    //获取栈中现有元素个数
	 bool push(char element);              //元素入栈，栈顶上升
	 bool pop(char &element);              //元素出栈，栈顶下降
	 //char Stack::pop()                   //元素出栈的另一种定义
	 void stackTraverse(bool isFromButtom);//遍历栈中所有元素

 public:
	 char *m_pBuffer;                      //栈空间指针，使用new开辟新的栈空间，用这个指针指向这段空间
	 int m_iSize;                          //栈容量，等于size的值，不变
	 int m_iTop;                           //栈顶，也代表栈中现有的元素个数
 };