//c3-3.h
//���е�˳��洢�ṹ��ѭ�����У�
#define MAX_QSIZE 5		//�����г���
struct SqQueue
{
	QElemType *base;	//��ʼ���Ķ�̬����洢�ռ�
	int front;			//ͷָ�룬�����в�Ϊ�գ�ָ���ͷԪ��
	int rear;			//βָ�룬�����в�Ϊ�գ�ָ���βԪ�ص���һ��λ��	
};

