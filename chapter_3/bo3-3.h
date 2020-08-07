//bo3-3.h
//�õ�����Ļ�������ʵ�ֶ��У��洢�ṹ��c3-2.h���壩�Ļ�������9��

typedef QElemType ElemType;		//���嵥����Ԫ������Ϊ���е�Ԫ������ 
#define LinkList QueuePtr		//���嵥���������Ϊ��Ӧ�������е�����
#define LNode QNode
# include "../chapter_2/bo2-2.h"//������Ļ�������

void InitQueue(LinkQueue *Q)
{
	//�������������һ���ն���
	InitList(&Q->front);		//��Q->frontΪָ�룬������������õ��������������
	Q->rear = Q->front;			//Q->rearҲָ��ͷ��� 
} 

void DestroyQueue(LinkQueue *Q)
{
	//������������ٶ���Q
	DestroyList(&Q->front);		//����Q->frontΪͷָ�����������Q->frontΪ��
	Q->rear = NULL;				//Q->rearҲ��Ϊ�� 
}

void ClearQueue(LinkQueue *Q)
{
	//�����������ն���
	ClearList(&Q->front);		//�����Q->frontΪͷָ�������
	Q->rear = Q->front;			//Q->rearҲָ��ն��е�ͷ��� 
}

Status QueueEmpty(LinkQueue Q)
{
	//����������ж�Q�Ƿ�Ϊ�գ����򷵻�TRUE�����򷵻�FALSE
	return ListEmpty(Q.front);
}

int QueueLength(LinkQueue Q)
{
	//����������ض��г���
	return ListLength(Q.front); 
}

Status GetHead(LinkQueue Q, QElemType *e)
{
	//��������������в�Ϊ�գ�����ͷ�������Ԫ�ظ���e������OK�����򷵻�ERROR
	return GetElem(Q.front, 1, e); 
}

void EnQueue(LinkQueue *Q, QElemType e)
{
	//�����������Q��β����Ԫ��e
	ListInsert(&Q->front,ListLength(Q->front)+1, e); 
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
	//��������������в�Ϊ�գ�����ͷ�������Ԫ�ظ���e��ɾ���ý�㣬����OK�����򷵻�ERROR
	if(Q->front->next == Q->rear)	//������ֻ��һ��Ԫ��
		Q->rear = Q->front;			//���βָ��ָ��ͷ��� 
	return ListDelete(&Q->front, 1, e); 
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{
	//����������Ӷ�ͷ����β���ζԶ���Q�е�Ԫ�ص��ú���visit()
	ListTraverse(Q.front,visit); 
}







 
