//algo2-1.cpp	ʵ���㷨2.7
#include "../c1.h"
typedef int ElemType;	//����ElemTypeΪ���� 
#include "c2-1.h"		//���Ա��˳��洢�ṹ 
#include "bo2-1.h"		//���Ա��˳��洢�ṹ�Ļ������� 
#include "func2-2.h"	//����equal(),comp,print(),print1(),��print2()����

void MergeList(SqList La, SqList Lb, SqList *Lc)
{
	/*
		��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�÷ǵݼ�����
		�鲢La��Lb�õ�Lc��Lc��Ԫ��Ҳ����ֵ�ǵݼ�����(���ı�La��Lb) 
	*/	
	ElemType *pa, *pa_last, *pb, *pb_last, *pc;
	pa = La.elem;	//paָ��La�ĵ�һ��Ԫ��
	pb = Lb.elem;	//pbָ��Lb�ĵ�һ��Ԫ��
	
	//�ֶ���ʼ��Lc��Ϊ�˷��㳤�ȵ�ȷ�� 
	Lc->listsize = La.length + Lb.length;
	Lc->length = Lc->listsize;
	Lc->elem = (ElemType *)malloc(sizeof(ElemType) * Lc->listsize);
	if(!Lc->elem)		//�洢�ռ����ʧ�� 
		exit(OVERFLOW);	
	
	pa_last = La.elem + La.length - 1;	//pa_lastָ��La�����һ��Ԫ��
	pb_last = Lb.elem + Lb.length - 1;  //pb_lastָ��Lb�����һ��Ԫ��
	pc = Lc->elem;
	
	while (pa<=pa_last && pb<=pb_last)	//La��Lb����Ԫ��δ�鲢 
	{
		if(*pa < *pb)	//�鲢La 
		{
			*pc = *pa;
			pc++;
			pa++;
		}
		else			//�鲢Lb 
		{
			*pc = *pb;
			pc++;
			pb++;
		}
	} 
	while (pa <= pa_last)	//Laδ�鲢��
	{
		*pc = *pa;
		pc++;
		pa++;
	}
	while (pb <= pb_last)	//Lbδ�鲢��
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
 	
	InitList(&La);	//�����ձ�La
	for(j=1; j<=5; j++)		//��La�в���5��Ԫ�أ�����Ϊ1��2��3��4��5
		ListInsert(&La, j, j);
	
	printf("La = ");	//���La���� 
 	ListTraverse(La, print1);
 	
 	InitList(&Lb);	//�����ձ�Lb
	for(j=1; j<=5; j++)		//��Lb�в���5��Ԫ�أ�����Ϊ2��4��6��8��10
		ListInsert(&Lb, j, j*2);
	
	printf("Lb = ");	//���Lb���� 
 	ListTraverse(Lb, print1);
 	
 	//�ϲ�La��Lb��Lc
	 MergeList(La, Lb, &Lc);
	printf("Lc = ");	//���Lc���� 
 	ListTraverse(Lc, print1);
 	
	return 0;
}
