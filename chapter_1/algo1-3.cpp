//algo1-3.cpp
//改进算法 
//计算1 - 1/x + 1/(x*x)...

#include "c1.h"
int main(void)
{
	timeb t1, t2;
	long t;
	double x, sum = 1, sum1 = 1;
	int i, j, n;
	
	printf("请输入x n");
	scanf("%lf %d", &x, &n);
	ftime(&t1);		//求得当前时间
	for(i=1; i<=n; i++)
	{
//		sum1 = 1;
//		for(j=1; j<=i; j++)	//中间这个循环用于求每一项的大小 
//		{
//			sum1 = sum1 * (-1.0 / x);
//		}
		sum1 *= (-1.0/x);
		sum += sum1;
	} 
	ftime(&t2);		//求得当前时间
	t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
	printf("sum = %lf, 用时%ld毫秒\n", sum, t);
	
	return 0;
 } 
