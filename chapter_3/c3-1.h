//c3-1.h
//ջ��˳��洢�ṹ
#define STACK_INIT_SIZE 10	//�洢�ռ��ʼ������
#define STACK_INCREMENT 2	//�洢�ռ��������
typedef struct SqStack
{
	SElemType *base;	//�ڹ���ǰ�����ٺ�baseֵΪNULL 
	SElemType *top;		//ջ��ָ��	
	int stacksize;		//��ǰջ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}SqStack;

