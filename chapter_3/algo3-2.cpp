//algo3-2.cpp
//�޸��㷨3.1�ĳ��� ʮ����->ʮ������ 
typedef int SElemType;	//����ջԪ������Ϊ���� 
#include "../c1.h"		 
#include "c3-1.h"		//����˳��ջ 
#include "bo3-1.h"		//˳��ջ�Ļ������� 
 
void converse()	//�㷨3.1���޸� 
{
	//�������������������κ�һ���Ǹ�ʮ������������ӡ��������ֵ��ʮ��������
	SqStack s;
	unsigned n;	//�Ǹ�����
	SElemType e;
	InitStack(&s);	//��ʼ��ջ
	printf("��ʮ������nת����ʮ���������������룺n(>=0) = ");
	scanf("%u", &n);
	while(n)	//��n��Ϊ0
	{
		e = n % 16;
		Push(&s, e);	//��ջn����16��������N���Ƶĵ�λ�� 
		n = n / 16;	
	}
	while(!StackEmpty(s))	//ջ��Ϊ��
	{
		Pop(&s, &e);	//����ջ��Ԫ�ظ���e 
		if(e < 10)
			printf("%d", e);
		else
			printf("%c",e+55);
	} 
	printf("\n");
} 
int main(void)
{
	converse();
	return 0;	
} 
