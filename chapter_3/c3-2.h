//c3-2.h
//�������� - ���е���ʽ�洢�ṹ
typedef struct QNode
{
	QElemType data;
	QNode *next;
}*QueuePtr;

typedef struct LinkQueue
{
	QueuePtr front, rear; 	//��ͷ��βָ�� 
}LinkQueue;
