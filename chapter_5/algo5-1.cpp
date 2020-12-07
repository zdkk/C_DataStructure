//algo5-1.cpp �䳤��������ʵ��
#include "../c1.h"
typedef int ElemType;	//����ElemTypeΪ����
ElemType Max(int num, ...)
{
	//...��ʾ�䳤������λ���βα�����ǰ�����������һ���̶�����
	va_list ap;		//����ap�Ǳ䳤���������ͣ�C���Ե��������ͣ�����stdarg.h��	
	int i;
	ElemType m, n;
	
	if(num < 1)
		exit(OVERFLOW);
	va_start(ap,num);	//apָ��̶�����num�����ʵ�α�
	m = va_arg(ap, ElemType);	//��ȡap��ָ���ʵ�Σ�������ΪElemType�����丳ֵ��m��ap�Զ�����
	for (i = 1; i<num; i++)
	{
		n = va_arg(ap, ElemType);	//���ζ�ȡap��ָ��ʵ�Σ����丳��n��ap�Զ�����
		if (m < n)
			m = n;	
	}
	va_end(ap); 					//��va_start()��ԣ������Ա䳤������Ķ�ȡ��ap����ָ��䳤������ 
	return m;
}
int main(void)
{
	printf("1.���ֵΪ %d\n", Max(4, 7, 9, 5, 8));	//��4�����������ֵ��ap���ָ��7
	printf("2.���ֵΪ %d\n", Max(3, 17, 36, 25, 70));	//���������������ֵ��ap���ָ��17
	
	return 0; 
}
/*
------------------------------------
1.���ֵΪ 9
2.���ֵΪ 36
------------------------------------
��Ȼ�ڶ���printf��Max�������˳���3���������һ����û�б����������Է������ֵ36 
*/
