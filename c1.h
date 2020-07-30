//c1.h
# include <string.h>		//字符串头文件
# include <ctype.h>			//字符函数头文件
# include <malloc.h>		//malloc函数等
# include <limits.h>		//INT_MAX等 
# include <stdio.h>			//标准输入输出头文件 
# include <stdlib.h>		//atoi(),exit()等
# include <io.h>			//eof() 
# include <math.h>			//数学函数头文件
# include <sys/timeb.h>		//ftime() 
# include <stdarg.h>		//用于存取变长参数表

//函数结果状态码
#define TRUE 1
#define ERROR 0
#define OK 1
#define FALSE 0
// #define INFEASIBLE -1 没用到
// #define OVERFLOW -2	在math.h中已经定义过OVERFLOW的值为3 
typedef int Status;
typedef int Boolean;
