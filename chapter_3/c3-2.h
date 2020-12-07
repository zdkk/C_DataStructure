//c3-2.h
//单链队列 - 队列的链式存储结构
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct LinkQueue
{
	QueuePtr front, rear; 	//队头队尾指针 
}LinkQueue;
