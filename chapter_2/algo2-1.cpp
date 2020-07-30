//algo2-1.cpp	实现算法2.7
#include "../c1.h"
typedef int ElemType;	//定义ElemType为整型 
#include "c2-1.h"		//线性表的顺序存储结构 
#include "bo2-1.h"		//线性表的顺序存储结构的基本操作 
#include "func2-2.h"	//包括equal(),comp,print(),print1(),和print2()函数

void MergeList(SqList La, SqList Lb, SqList *Lc)
{
	/*
		已知顺序线性表La和Lb的元素按值得非递减排列
		归并La和Lb得到Lc，Lc的元素也按照值非递减排列(不改变La和Lb) 
	*/	
	ElemType *pa, *pa_last, *pb, *pb_last, *pc;
	pa = La.elem;	//pa指向La的第一个元素
	pb = Lb.elem;	//pb指向Lb的第一个元素
	
	//手动初始化Lc，为了方便长度的确定 
	Lc->listsize = La.length + Lb.length;
	Lc->length = Lc->listsize;
	Lc->elem = (ElemType *)malloc(sizeof(ElemType) * Lc->listsize);
	if(!Lc->elem)		//存储空间分配失败 
		exit(OVERFLOW);	
	
	pa_last = La.elem + La.length - 1;	//pa_last指向La的最后一个元素
	pb_last = Lb.elem + Lb.length - 1;  //pb_last指向Lb的最后一个元素
	pc = Lc->elem;
	
	while (pa<=pa_last && pb<=pb_last)	//La和Lb均有元素未归并 
	{
		if(*pa < *pb)	//归并La 
		{
			*pc = *pa;
			pc++;
			pa++;
		}
		else			//归并Lb 
		{
			*pc = *pb;
			pc++;
			pb++;
		}
	} 
	while (pa <= pa_last)	//La未归并完
	{
		*pc = *pa;
		pc++;
		pa++;
	}
	while (pb <= pb_last)	//Lb未归并完
	{
		*pc = *pb;
		pc++;
		pb++;
	} 
	return;
} 

 int main(void)
 {
	SqList La, Lb, Lc;
	int j;
 	
	InitList(&La);	//创建空表La
	for(j=1; j<=5; j++)		//在La中插入5个元素，依次为1，2，3，4，5
		ListInsert(&La, j, j);
	
	printf("La = ");	//输出La内容 
 	ListTraverse(La, print1);
 	
 	InitList(&Lb);	//创建空表Lb
	for(j=1; j<=5; j++)		//在Lb中插入5个元素，依次为2，4，6，8，10
		ListInsert(&Lb, j, j*2);
	
	printf("Lb = ");	//输出Lb内容 
 	ListTraverse(Lb, print1);
 	
 	//合并La和Lb到Lc
	 MergeList(La, Lb, &Lc);
	printf("Lc = ");	//输出Lc内容 
 	ListTraverse(Lc, print1);
 	
	return 0;
}
