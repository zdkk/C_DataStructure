//bo3-2.h
//�����л���������9����

void InitQueue(LinkQueue *Q)
{
	//�������������һ���ն���
	Q->front = (QueuePtr)malloc(sizeof(QNode));	//����ͷ��� 
	if(!Q->front)
		exit(OVERFLOW);
	Q->rear = Q->front;							//����βָ��ָ��ͷ��� 
	Q->front->next = NULL;						//ͷ���ָ������ΪNULL 
} 

void DestroyQueue(LinkQueue *Q)
{
	//��ʼ������Q����
	//�������������Q
	while(Q->front)							//Q->front��Ϊ��
	{
	 	Q->rear = Q->front->next;			//Q->rearָ��Q->front����һ���
		free(Q->front);						//�ͷ�Q->frontָ��Ľ��
		Q->front = Q->rear;					//Q->frontָ����һ��� 
	} 
}

void ClearQueue(LinkQueue *Q)
{
	//��ʼ������Q����
	//������������Q
	DestroyQueue(Q);						//���ٶ���Q 
	InitQueue(Q); 							//���¹������Q 
}

Status QueueEmpty(LinkQueue Q)
{
	//��ʼ������Q����
	//����������ж�Q�Ƿ�Ϊ�ն��У�����ǣ�����TRUE�����򷵻�FALSE
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE; 
}

int QueueLength(LinkQueue Q)
{
	//��ʼ������Q����
	//������������ض���Q�ĳ���
	int i=0;	//��������ʼ��0
	QueuePtr p = Q.front->next;	//pָ����Ԫ��� 
	while(p != NULL)				//p��ָ��㲻Ϊ�� 
	{
		i++;						//��������һ 
		p = p->next;				//pָ����һ��� 
	} 
	return i; 
}

Status GetHead(LinkQueue Q, QElemType *e)
{
	//��������������в�Ϊ�գ���e����Q��ͷԪ�أ�������OK�����򷵻�ERROR
	QueuePtr p;
	if(QueueEmpty(Q))		//����Ϊ�� 
		return ERROR;		//����ERROR
	
	p = Q.front->next;		//pָ����Ԫ���
	*e = p->data;			//��e���ض�ͷԪ�� 
	return OK;
}

void EnQueue(LinkQueue *Q, QElemType e)
{
	//������������β����Ԫ��e
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)		//����洢�ռ�ʧ��
		exit(OVERFLOW);
	p->data = e;	//��e�����½������Ԫ��
	p->next = NULL;	//�½��ָ������ΪNULL 
	Q->rear->next = p;	//ԭ��β����ָ��ָ���½�� 
	Q->rear = p;		//βָ��ָ���½�� 
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
	//�����в�Ϊ�գ���e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
	QueuePtr p = Q->front->next;	//pָ���ͷ���
	if(QueueEmpty(*Q))				//pΪ�գ�����ERROR 
		return ERROR; 
	
	*e = p->data;				//��e���ض�ͷ�������Ԫ�� 
	Q->front->next = p->next;	//ͷ����ָ��ָ��p����һ���
	if(p == Q->rear)			//����ֻ��һ�����
	{
		Q->rear = Q->front;		//��βָ��ָ��ͷ���(�ն���)	
	} 
	free(p);					//�ͷ�p��� 
	return OK;  
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{
	//�Ӷ�ͷ����β���ζ�Q��ÿ���������Ԫ�ص��ú���visit 
	QueuePtr p = Q.front->next;	//pָ���ͷ���
	while(p)							//p�ǿ�
	{
		(*visit)(p->data);			//��p��ָ�������Ԫ�ص���visit()����
		p = p->next;				//pָ����һ���	
	} 
	printf("\n");
}
























