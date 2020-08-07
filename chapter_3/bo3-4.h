//bo3-4.h
//ѭ�����У��洢�ṹ��c3-3.h���壩�Ļ�������9��

void InitQueue(SqQueue *Q)
{
	//����һ���ն��� 
	Q->base = (QElemType *)malloc(sizeof(QElemType) * MAX_QSIZE);	
	if(!Q->base)	//��̬����ʧ��
		exit(OVERFLOW);
	Q->front = Q->rear = 0; 
} 

void DestroyQueue(SqQueue *Q)
{
	//�������������Q
	if(Q->base)		//����Q����
		free(Q->base);	//�ͷ�Q->baseָ��Ĵ洢��Ԫ
	Q->base = NULL;
	Q->front = Q->rear = 0; 
}

void ClearQueue(SqQueue *Q)
{
	//�����������ն���Q
	Q->front = Q->rear = 0; 
}

Status QueueEmpty(SqQueue Q)
{
	//��QΪ�ն��У�����TRUE�����򷵻�FALSE
	if(Q.front == Q.rear)		//����Ϊ�յı�־ 
		return TRUE;
	else
		return FALSE; 
}

int QueueLength(SqQueue Q)
{
	//���ض��г���
	return (Q.rear + MAX_QSIZE - Q.front) % MAX_QSIZE; 
}

Status GetHead(SqQueue Q, QElemType *e)
{
	//��������������в�Ϊ�գ�����ͷ�������Ԫ�ظ���e������OK�����򷵻�ERROR
	if(QueueEmpty(Q))
		return FALSE;
	*e = *(Q.base+Q.front);
	return OK;
}

Status EnQueue(SqQueue *Q, QElemType e)
{
	//�������������Ԫ��e��Q��β
	if((Q->rear+1)%MAX_QSIZE == Q->front)	//�����������޷����� 
		return ERROR; 
	Q->base[Q->rear] = e;						//��e�嵽��β 
	Q->rear = (Q->rear+1)%MAX_QSIZE;		//��βָ���һ 
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
	//���������ɾ����ͷԪ��
	if(Q->rear == Q->front)
		return ERROR;		//����Ϊ��
	
	*e = Q->base[Q->front];//����ͷԪ�ظ���e
	Q->front = (Q->front + 1) % MAX_QSIZE; //�ƶ���ͷָ��
	return OK; 
} 

void QueueTraverse(SqQueue Q, void(*visit)(QElemType))
{
	//�����������ͷ��β���ζԶ���Q��ÿ��Ԫ�ص��ú���visit
	int i = Q.front;	//i���ָ���ͷԪ��
	while(i != Q.rear)	//iָ�����Q�е�Ԫ��
	{
		(*visit)(*(Q.base+i));//��i��ָԪ�ص���visit����
		i = (i + 1) % MAX_QSIZE;	//iָ����һԪ�� 
	}
	printf("\n"); 
}
