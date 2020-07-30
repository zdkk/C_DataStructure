//algo2-3.cpp
//ʵ���㷨2.11��2.12
#include "../c1.h"
typedef int ElemType;	//����ElemTypeΪ����
#include "c2-2.h"		//�������Ա�ĵ�����洢�ṹ 
#include "bo2-2.h"		//��������
#include "func2-2.h"	//����equal(),comp(),print(),print1(),print2()����

void CreateList(LinkList *L, int n)
{
	//���������ͷ�巨������n��Ԫ�ص�ֵ��������ͷ�ڵ�ĵ�����L
	int i;
	LNode *p;
	InitList(L);	//��ʼ�������� 
	printf("������%d������\n", n);
	for(i=n; i>0; i--)
	{
		p = (LNode *)malloc(sizeof(LNode));	//�����½�� 
		scanf("%d", &p->data);				//���½������Ԫ��ֵ 
		p->next = (*L)->next;				//���½������ͷ 
		(*L)->next = p;						//ͷ�ڵ��ָ��ָ���½ڵ� 
	}
	 
}
void CreateList1(LinkList *L, int n)
{
	//���������β�巨������n��Ԫ�ص�ֵ��������ͷ�ڵ�ĵ�����L
	int i;
	LNode *p, *q;
	InitList(L);		//��ʼ������ 
	q = (*L);			//qָ��β��� 
	printf("������%d������\n", n);
	for (i=n; i>0; i--)
	{
		p = (LNode *)malloc(sizeof(LNode));	//�����½�� 
		scanf("%d", &p->data);				//���½������Ԫ��ֵ
		p->next = q->next;					//���½������β 
		q->next = p;
		q = p;
	}
}

void MergeList(LinkList La, LinkList Lb, LinkList *Lc)
{
	//��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ���շǵݼ����У����ı�La��Lb��
	LNode *p, *q, *r, *t;
	p = La->next;	//pָ��La��Ԫ��� 
	q = Lb->next;	//qָ��Lb��Ԫ���
	InitList(Lc);	//��ʼ��Lc
	t = *Lc;		//tָ��Lcͷ�ڵ㣨�൱��β��㣩 
	
	
	while (p && q)	//p,q����Ϊ��
	{
		if(p->data <= q->data)	//�鲢La��Ԫ��
		{
			r = (LNode *)malloc(sizeof(LNode));
			r->data = p->data;
			r->next = t->next;	//������Ԫ�ص�Lc
			t->next = r;
			t =r;				//tָ��β��� 
			p = p->next;		//pָ����һ��� 
		}	
		else					//�鲢Lb��Ԫ�� 
		{
			r = (LNode *)malloc(sizeof(LNode));
			r->data = q->data;
			r->next = t->next;	//������Ԫ�ص�Lc
			t->next = r;
			t =r;				//tָ��β���
			q = q->next;		//qָ����һ��� 
		}
	} 
	while(p)	//p��Ϊ�գ��鲢p
	{
		r = (LNode *)malloc(sizeof(LNode));
			r->data = p->data;
			r->next = t->next;	//������Ԫ�ص�Lc
			t->next = r;
			t =r;				//tָ��β��� 
			p = p->next;		//pָ����һ��� 
	}
	while(q)	//q��Ϊ�գ��鲢q
	{
		r = (LNode *)malloc(sizeof(LNode));
		r->data = q->data;
		r->next = t->next;	//������Ԫ�ص�Lc
		t->next = r;
		t =r;				//tָ��β���
		q = q->next;		//qָ����һ���
	} 
}

int main(void)
{
	int n = 5;
	LinkList La, Lb, Lc;
	printf("���ǵݼ�˳��");
	CreateList1(&La, n);	//��������˳�����������Ա�
	printf("La = ");
	ListTraverse(La, print);	//�������La������
	
	printf("���ǵ���˳��");
	CreateList(&Lb, n);		//��������˳�����������Ա�
	printf("Lb = ");
	ListTraverse(Lb, print);	//�������Lb������ 
	
	MergeList(La,Lb,&Lc);		//���ǵݼ�˳��ϲ�La��Lb�õ�Lc
	printf("Lc = ");
	ListTraverse(Lc , print);	//�������Lc������ 
	
	return 0;
}
