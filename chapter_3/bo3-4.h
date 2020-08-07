//bo3-4.h
//循环队列（存储结构由c3-3.h定义）的基本操作9个

void InitQueue(SqQueue *Q)
{
	//构造一个空队列 
	Q->base = (QElemType *)malloc(sizeof(QElemType) * MAX_QSIZE);	
	if(!Q->base)	//动态分配失败
		exit(OVERFLOW);
	Q->front = Q->rear = 0; 
} 

void DestroyQueue(SqQueue *Q)
{
	//操作结果：销毁Q
	if(Q->base)		//队列Q存在
		free(Q->base);	//释放Q->base指向的存储单元
	Q->base = NULL;
	Q->front = Q->rear = 0; 
}

void ClearQueue(SqQueue *Q)
{
	//操作结果：清空队列Q
	Q->front = Q->rear = 0; 
}

Status QueueEmpty(SqQueue Q)
{
	//若Q为空队列，返回TRUE，否则返回FALSE
	if(Q.front == Q.rear)		//队列为空的标志 
		return TRUE;
	else
		return FALSE; 
}

int QueueLength(SqQueue Q)
{
	//返回队列长度
	return (Q.rear + MAX_QSIZE - Q.front) % MAX_QSIZE; 
}

Status GetHead(SqQueue Q, QElemType *e)
{
	//操作结果：若队列不为空，将队头结点数据元素赋给e，返回OK；否则返回ERROR
	if(QueueEmpty(Q))
		return FALSE;
	*e = *(Q.base+Q.front);
	return OK;
}

Status EnQueue(SqQueue *Q, QElemType e)
{
	//操作结果：插入元素e到Q队尾
	if((Q->rear+1)%MAX_QSIZE == Q->front)	//队列已满，无法插入 
		return ERROR; 
	Q->base[Q->rear] = e;						//将e插到队尾 
	Q->rear = (Q->rear+1)%MAX_QSIZE;		//队尾指针加一 
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
	//操作结果：删除队头元素
	if(Q->rear == Q->front)
		return ERROR;		//队列为空
	
	*e = Q->base[Q->front];//将队头元素赋给e
	Q->front = (Q->front + 1) % MAX_QSIZE; //移动队头指针
	return OK; 
} 

void QueueTraverse(SqQueue Q, void(*visit)(QElemType))
{
	//操作结果：从头到尾依次对队列Q中每个元素调用函数visit
	int i = Q.front;	//i最初指向队头元素
	while(i != Q.rear)	//i指向队列Q中的元素
	{
		(*visit)(*(Q.base+i));//对i所指元素调用visit函数
		i = (i + 1) % MAX_QSIZE;	//i指向下一元素 
	}
	printf("\n"); 
}
