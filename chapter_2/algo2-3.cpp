//algo2-3.cpp
//实现算法2.11和2.12
#include "../c1.h"
typedef int ElemType;	//定义ElemType为整型
#include "c2-2.h"		//采用线性表的单链表存储结构 
#include "bo2-2.h"		//基本操作
#include "func2-2.h"	//包括equal(),comp(),print(),print1(),print2()函数

void CreateList(LinkList *L, int n)
{
	//操作结果：头插法，输入n个元素的值，建立带头节点的单链表L
	int i;
	LNode *p;
	InitList(L);	//初始化单链表 
	printf("请输入%d个数据\n", n);
	for(i=n; i>0; i--)
	{
		p = (LNode *)malloc(sizeof(LNode));	//生成新结点 
		scanf("%d", &p->data);				//给新结点输入元素值 
		p->next = (*L)->next;				//将新结点插入表头 
		(*L)->next = p;						//头节点的指针指向新节点 
	}
	 
}
void CreateList1(LinkList *L, int n)
{
	//操作结果：尾插法，输入n个元素的值，建立带头节点的单链表L
	int i;
	LNode *p, *q;
	InitList(L);		//初始化链表 
	q = (*L);			//q指向尾结点 
	printf("请输入%d个数据\n", n);
	for (i=n; i>0; i--)
	{
		p = (LNode *)malloc(sizeof(LNode));	//生成新结点 
		scanf("%d", &p->data);				//给新结点输入元素值
		p->next = q->next;					//将新结点插入表尾 
		q->next = p;
		q = p;
	}
}

void MergeList(LinkList La, LinkList Lb, LinkList *Lc)
{
	//已知线性表La和Lb中的数据元素按值非递减排列
	//归并La，Lb得到新的线性表Lc，Lc的数据元素也按照非递减排列（不改变La和Lb）
	LNode *p, *q, *r, *t;
	p = La->next;	//p指向La首元结点 
	q = Lb->next;	//q指向Lb首元结点
	InitList(Lc);	//初始化Lc
	t = *Lc;		//t指向Lc头节点（相当于尾结点） 
	
	
	while (p && q)	//p,q都不为空
	{
		if(p->data <= q->data)	//归并La中元素
		{
			r = (LNode *)malloc(sizeof(LNode));
			r->data = p->data;
			r->next = t->next;	//插入新元素到Lc
			t->next = r;
			t =r;				//t指向尾结点 
			p = p->next;		//p指向下一结点 
		}	
		else					//归并Lb中元素 
		{
			r = (LNode *)malloc(sizeof(LNode));
			r->data = q->data;
			r->next = t->next;	//插入新元素到Lc
			t->next = r;
			t =r;				//t指向尾结点
			q = q->next;		//q指向下一结点 
		}
	} 
	while(p)	//p不为空，归并p
	{
		r = (LNode *)malloc(sizeof(LNode));
			r->data = p->data;
			r->next = t->next;	//插入新元素到Lc
			t->next = r;
			t =r;				//t指向尾结点 
			p = p->next;		//p指向下一结点 
	}
	while(q)	//q不为空，归并q
	{
		r = (LNode *)malloc(sizeof(LNode));
		r->data = q->data;
		r->next = t->next;	//插入新元素到Lc
		t->next = r;
		t =r;				//t指向尾结点
		q = q->next;		//q指向下一结点
	} 
}

int main(void)
{
	int n = 5;
	LinkList La, Lb, Lc;
	printf("按非递减顺序，");
	CreateList1(&La, n);	//根据输入顺序，正序建立线性表
	printf("La = ");
	ListTraverse(La, print);	//输出链表La的内容
	
	printf("按非递增顺序，");
	CreateList(&Lb, n);		//根据输入顺序，逆序建立线性表
	printf("Lb = ");
	ListTraverse(Lb, print);	//输出链表Lb的内容 
	
	MergeList(La,Lb,&Lc);		//按非递减顺序合并La和Lb得到Lc
	printf("Lc = ");
	ListTraverse(Lc , print);	//输出链表Lc的内容 
	
	return 0;
}
