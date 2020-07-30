//algo2-2.cpp
//用LinkList和SqList类型分别实现算法2.1和算法2.2

#include "../c1.h"
typedef int ElemType;	//定义ElemType为整型
#define Sq				//用SqList实现选择此行，用LinkList将此行注释
#ifdef Sq
	#include "c2-1.h"		//采用线性表的动态分配顺序存储结构 
	#include "bo2-1.h"		//基本操作 
	typedef SqList List;	//定义抽象数据类型List为SqList类型
	#define printer print1	//ListTraverse()用到不同类型的输出函数
#else
	#include "c2-2.h"		//采用线性表的单链表存储结构 
	#include "bo2-2.h"		//基本操作 
	typedef LinkList List	//定义抽象数据类型List为LinkList类型
	#define printer print	//Listtraverse()用到不同类型的输出函数
#endif
#include "func2-2.h"		//包括equal(),comp(),print(),print1(),print2()函数 
#include "func2-1.h" 		//包括算法2.1和2.2

int main(void)
{
	List La, Lb, Lc;
	int j, b[7] = {2,6,8,9,11,15,20};
	
	InitList(&La);	//创建空表。不成功程序会退出
	for (j=1; j<=5; j++)	//在La中插入5个元素，依次为1，2，3，4，5
		ListInsert(&La, j, j);
	printf("La = ");
	ListTraverse(La, printer);	//输出La的内容
	
	InitList(&Lb);
	for(j=1; j<=5; j++)		//在Lb中插入5个元素，依次为2，4，6，8，10
		ListInsert(&Lb, j, 2*j);
	printf("Lb = ");
	ListTraverse(Lb, printer);	//输出Lb的内容
	
	Union(&La,Lb);				//调用算法2.1，将Lb中满足条件的元素插入La，不改变Lb 
	printf("new La = ");
	ListTraverse(La, printer);	//输出新的La的内容
	
	ClearList(&Lb);				//清空Lb 
	for(j=1; j<=7; j++)			//在Lb中重新插入数组b[]的7个元素
		ListInsert(&Lb, j, b[j-1]);
	printf("Lb = ");
	ListTraverse(Lb, printer);	//输出Lb的内容
	MergeList(La, Lb, &Lc);		//调用算法2.2，生成新表Lc，不改变La和Lb
	printf("Lc = ");
	ListTraverse(Lc, printer);	//输出Lc的内容 
	
	return 0; 	 
}
 
