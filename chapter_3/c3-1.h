//c3-1.h
//栈的顺序存储结构
#define STACK_INIT_SIZE 10	//存储空间初始分配量
#define STACK_INCREMENT 2	//存储空间分配增量
typedef struct SqStack
{
	SElemType *base;	//在构造前和销毁后，base值为NULL 
	SElemType *top;		//栈顶指针	
	int stacksize;		//当前栈已分配的存储空间，以元素为单位 
}SqStack;

