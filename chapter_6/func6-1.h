//func6-1.c	利用条件编译，在主程序中指定结点的类型，访问树结点的函数
#include "../c1.h"
#if CHAR					//CHAR值为1结点类型为字符型 
	typedef char TElemType;	//定义树元素类型为字符型
	TElemType Nil = '#';	//设字符'#'为空（即要求所有结点值都不是#）
	#define form "%c"		//输入输出的格式为%c
#else 						//CHAR值为0结点类型为整型
	typedef int TElemType;
	TElemType Nil = 0;
	#define form "%d"
#endif

void Visit(TElemType e)
{
	printf(form" ", e);		//定义CHAR为1时，以字符格式输出；CHAR为0时，以整型格式输出 
} 
