//algo5-1.cpp 变长参数表编程实例
#include "../c1.h"
typedef int ElemType;	//定义ElemType为整型
ElemType Max(int num, ...)
{
	//...表示变长参数表，位于形参表的最后，前面必须至少有一个固定参数
	va_list ap;		//定义ap是变长参数表类型（C语言的数据类型），在stdarg.h中	
	int i;
	ElemType m, n;
	
	if(num < 1)
		exit(OVERFLOW);
	va_start(ap,num);	//ap指向固定参数num后面的实参表
	m = va_arg(ap, ElemType);	//读取ap所指向的实参，其类型为ElemType，将其赋值给m，ap自动后移
	for (i = 1; i<num; i++)
	{
		n = va_arg(ap, ElemType);	//依次读取ap所指的实参，将其赋给n，ap自动后移
		if (m < n)
			m = n;	
	}
	va_end(ap); 					//与va_start()配对，结束对变长参数表的读取，ap不再指向变长参数表 
	return m;
}
int main(void)
{
	printf("1.最大值为 %d\n", Max(4, 7, 9, 5, 8));	//在4个数中求最大值，ap最初指向7
	printf("2.最大值为 %d\n", Max(3, 17, 36, 25, 70));	//在三个数中求最大值，ap最初指向17
	
	return 0; 
}
/*
------------------------------------
1.最大值为 9
2.最大值为 36
------------------------------------
虽然第二句printf中Max函数传了超过3个数，最后一个并没有被读到，所以返回最大值36 
*/
