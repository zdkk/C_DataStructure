//algo1-3.cpp
//�Ľ��㷨 
//����1 - 1/x + 1/(x*x)...

#include "c1.h"
int main(void)
{
	timeb t1, t2;
	long t;
	double x, sum = 1, sum1 = 1;
	int i, j, n;
	
	printf("������x n");
	scanf("%lf %d", &x, &n);
	ftime(&t1);		//��õ�ǰʱ��
	for(i=1; i<=n; i++)
	{
//		sum1 = 1;
//		for(j=1; j<=i; j++)	//�м����ѭ��������ÿһ��Ĵ�С 
//		{
//			sum1 = sum1 * (-1.0 / x);
//		}
		sum1 *= (-1.0/x);
		sum += sum1;
	} 
	ftime(&t2);		//��õ�ǰʱ��
	t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
	printf("sum = %lf, ��ʱ%ld����\n", sum, t);
	
	return 0;
 } 
