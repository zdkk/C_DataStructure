//bo3-3.h
//用单链表的基本操作实现队列（存储结构由c3-2.h定义）的基本操作9个

typedef QElemType ElemType;		//定义单链表元素类型为队列的元素类型 
#define LinkList QueuePtr		//定义单链表的类型为相应的链队列的类型
#define LNode QNode
# include "../chapter_2/bo2-2.h"//单链表的基本操作

void InitQueue(LinkQueue *Q)
{
	//操作结果：构造一个空队列
	InitList(&Q->front);		//以Q->front为指针，构造空链表（调用单链表基本操作）
	Q->rear = Q->front;			//Q->rear也指向头结点 
} 

void DestroyQueue(LinkQueue *Q)
{
	//操作结果：销毁队列Q
	DestroyList(&Q->front);		//销毁Q->front为头指针的链表，且置Q->front为空
	Q->rear = NULL;				//Q->rear也置为空 
}

void ClearQueue(LinkQueue *Q)
{
	//操作结果：清空队列
	ClearList(&Q->front);		//清空以Q->front为头指针的链表
	Q->rear = Q->front;			//Q->rear也指向空队列的头结点 
}

Status QueueEmpty(LinkQueue Q)
{
	//操作结果：判断Q是否为空，是则返回TRUE，否则返回FALSE
	return ListEmpty(Q.front);
}

int QueueLength(LinkQueue Q)
{
	//操作结果返回队列长度
	return ListLength(Q.front); 
}

Status GetHead(LinkQueue Q, QElemType *e)
{
	//操作结果：若队列不为空，将队头结点数据元素赋给e，返回OK；否则返回ERROR
	return GetElem(Q.front, 1, e); 
}

void EnQueue(LinkQueue *Q, QElemType e)
{
	//操作结果：在Q队尾插入元素e
	ListInsert(&Q->front,ListLength(Q->front)+1, e); 
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
	//操作结果：若队列不为空，将队头结点数据元素赋给e并删除该结点，返回OK；否则返回ERROR
	if(Q->front->next == Q->rear)	//队列中只有一个元素
		Q->rear = Q->front;			//令队尾指针指向头结点 
	return ListDelete(&Q->front, 1, e); 
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{
	//操作结果：从队头到队尾依次对队列Q中的元素调用函数visit()
	ListTraverse(Q.front,visit); 
}







 
