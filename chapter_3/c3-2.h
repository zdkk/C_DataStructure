//c3-2.h
//�������� - ���е���ʽ�洢�ṹ
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct LinkQueue
{
	QueuePtr front, rear; 	//��ͷ��βָ�� 
}LinkQueue;
