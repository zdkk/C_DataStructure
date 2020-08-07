//algo3-2.cpp
//修改算法3.1的程序 十进制->十六进制 
typedef int SElemType;	//定义栈元素类型为整型 
#include "../c1.h"		 
#include "c3-1.h"		//采用顺序栈 
#include "bo3-1.h"		//顺序栈的基本操作 
 
void converse()	//算法3.1的修改 
{
	//操作结果：对于输入的任何一个非负十进制整数，打印输出与其等值的十六进制数
	SqStack s;
	unsigned n;	//非负整数
	SElemType e;
	InitStack(&s);	//初始化栈
	printf("将十进制数n转换成十六进制数，请输入：n(>=0) = ");
	scanf("%u", &n);
	while(n)	//当n不为0
	{
		e = n % 16;
		Push(&s, e);	//入栈n除以16的余数（N进制的低位） 
		n = n / 16;	
	}
	while(!StackEmpty(s))	//栈不为空
	{
		Pop(&s, &e);	//弹出栈顶元素赋给e 
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
