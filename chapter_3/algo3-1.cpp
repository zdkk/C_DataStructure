//algo3-1.cpp
//�����㷨3.1�ĳ���
#define N 8			//�����ת���Ľ���N(2-9) 
typedef int SElemType;	//����ջԪ������Ϊ���� 
#include "../c1.h"		 
#include "c3-1.h"		//����˳��ջ 
#include "bo3-1.h"		//˳��ջ�Ļ������� 
 
void converse()	//�㷨3.1
{
	//�������������������κ�һ���Ǹ�ʮ������������ӡ��������ֵ��N������
	SqStack s;
	unsigned n;	//�Ǹ�����
	SElemType e;
	InitStack(&s);	//��ʼ��ջ
	printf("��ʮ������nת���� %d�������������룺n(>=0) = ", N);
	scanf("%u", &n);
	while(n)	//��n��Ϊ0
	{
		e = n % N;
		Push(&s, e);	//��ջn����N��������N���Ƶĵ�λ�� 
		n = n / N;	
	}
	while(!StackEmpty(s))	//ջ��Ϊ��
	{
		Pop(&s, &e);	//����ջ��Ԫ�ظ���e 
		printf("%d", e);//���e 
	} 
	printf("\n");
} 
int main(void)
{
	converse();
	return 0;	
} 
