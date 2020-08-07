//bo3-2.h
//链队列基本操作（9个）

void InitQueue(LinkQueue *Q)
{
	//操作结果：构造一个空队列
	Q->front = (QueuePtr)malloc(sizeof(QNode));	//生成头结点 
	if(!Q->front)
		exit(OVERFLOW);
	Q->rear = Q->front;							//队列尾指针指向头结点 
	Q->front->next = NULL;						//头结点指针域置为NULL 
} 

void DestroyQueue(LinkQueue *Q)
{
	//初始条件：Q存在
	//操作结果：销毁Q
	while(Q->front)							//Q->front不为空
	{
	 	Q->rear = Q->front->next;			//Q->rear指向Q->front的下一结点
		free(Q->front);						//释放Q->front指向的结点
		Q->front = Q->rear;					//Q->front指向下一结点 
	} 
}

void ClearQueue(LinkQueue *Q)
{
	//初始条件：Q存在
	//操作结果：清空Q
	DestroyQueue(Q);						//销毁队列Q 
	InitQueue(Q); 							//重新构造队列Q 
}

Status QueueEmpty(LinkQueue Q)
{
	//初始条件：Q存在
	//操作结果：判断Q是否为空队列，如果是，返回TRUE；否则返回FALSE
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE; 
}

int QueueLength(LinkQueue Q)
{
	//初始条件：Q存在
	//操作结果：返回队列Q的长度
	int i=0;	//计数器初始化0
	QueuePtr p = Q.front->next;	//p指向首元结点 
	while(p != NULL)				//p所指结点不为空 
	{
		i++;						//计数器加一 
		p = p->next;				//p指向下一结点 
	} 
	return i; 
}

Status GetHead(LinkQueue Q, QElemType *e)
{
	//操作结果：若队列不为空，用e返回Q的头元素，并返回OK；否则返回ERROR
	QueuePtr p;
	if(QueueEmpty(Q))		//队列为空 
		return ERROR;		//返回ERROR
	
	p = Q.front->next;		//p指向首元结点
	*e = p->data;			//用e返回队头元素 
	return OK;
}

void EnQueue(LinkQueue *Q, QElemType e)
{
	//操作结果：向队尾插入元素e
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)		//分配存储空间失败
		exit(OVERFLOW);
	p->data = e;	//将e赋给新结点数据元素
	p->next = NULL;	//新结点指针域置为NULL 
	Q->rear->next = p;	//原队尾结点的指针指向新结点 
	Q->rear = p;		//尾指针指向新结点 
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
	//若队列不为空，用e返回队头元素，并返回OK；否则返回ERROR
	QueuePtr p = Q->front->next;	//p指向队头结点
	if(QueueEmpty(*Q))				//p为空，返回ERROR 
		return ERROR; 
	
	*e = p->data;				//用e返回队头结点数据元素 
	Q->front->next = p->next;	//头结点的指针指向p的下一结点
	if(p == Q->rear)			//队列只有一个结点
	{
		Q->rear = Q->front;		//队尾指针指向头结点(空队列)	
	} 
	free(p);					//释放p结点 
	return OK;  
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{
	//从队头到队尾依次对Q中每个结点数据元素调用函数visit 
	QueuePtr p = Q.front->next;	//p指向队头结点
	while(p)							//p非空
	{
		(*visit)(p->data);			//对p所指结点数据元素调用visit()函数
		p = p->next;				//p指向下一结点	
	} 
	printf("\n");
}
























