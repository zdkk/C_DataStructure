//algo8-3.c	��̬���ұ���̬�����Ĳ����������㷨9.3��9.4
#include "../c1.h"
#include "func8-3.h"	//��������Ԫ�����͵Ķ����Լ������Ĳ��� 
#include "c8-1.h"		//��̬���ұ��˳��洢�ṹ
#include "c8-2.h"		//��������ֵ�͹ؼ��ֵıȽϵ�Լ��
#include "bo8-1.h"		//��̬���ұ�˳����������ĵĻ���������7����
typedef ElemType TElemType;	//�����������Ԫ������Ϊ����Ԫ������
#include "../chapter_6/c6-1.h"//��������Ĵ洢�ṹ
#include "../chapter_6/bo6-1.h"//��������Ļ�������
#define N 100			//��̬���ұ������������sw[]�����õ�

Status SecondOptimal(BiTree * T, ElemType R[], int sw[], int low, int high)
{
	//�������R[low-high]�����ۼ�Ȩֵ��sw(����sw[0]=0)�ݹ鹹����Ų�����T	�㷨9.3
	//���㷨�ǽ������Ų����������ǹ����ٶȱ����Ŷ�������ö�
	//���㷨�ĺ����ǵݹ鹹����Ŷ�������ÿ�εĸ���㶼��**��ǰ�����������Ȩֵ����С�Ľ��** 
	int j, i = low;		//����С��Piֵ����ţ���ֵ��Ϊ��low == high(��������һ��Ԫ��)ʱ��ֵ
	double dw = sw[high] + sw[low - 1];	//����ʽ9-13�еĹ̶���
	double min = fabs(dw - sw[low] - sw[low-1]);	//��Pi����Сֵ����ֵ��Ϊ��low==highʱ��ֵ����ʵ��һ����
	//double min = fabs(sw[high] - sw[low]);
	//����high �Ƿ����low������ |sw[high] - sw[low]| = |sw[high] + sw[low-1] - sw[low] - sw[low-1]||dw - sw[low] - sw[low-1]|
	
	for (j = low + 1; j <= high; j++)		//��low��highʱ��ѡ����С�ġ�Piֵ
		if (fabs(dw - sw[j] - sw[j-1]) < min)	//�ҵ�С��min��ֵ
		{
			i = j;	//��������С��Piֵ�����
			min = fabs(dw - sw[j] - sw[j-1]);	//���¡�Pi����Сֵ	
		}
	if (!(*T = (BiTree)malloc(sizeof(BiTNode))))//���ɽ��ʧ��
		return ERROR;
	(*T)->data = R[i];								//����С��Piֵ������Ԫ�ظ���������������
	if (i == low)								//����С��Piֵ���������С���
		(*T)->lchild = NULL;						//��������Ϊ��
	else										//����С��Piֵ����Ų�����С���
		SecondOptimal(&(*T)->lchild, R, sw, low, i-1);//�ݹ鹹����Ų���������
	if (i == high)
		(*T)->rchild = NULL;
	else
		SecondOptimal(&(*T)->rchild, R, sw, i+1, high);//�ݹ鹹����Ų���������
	return OK; 
}

void FindSW(int sw[], SSTable ST)
{
	//���������ST�еĸ�����Ԫ�ص�Weight�����ۼ�Ȩֵ����sw, CreateSOSTree()����
	int i;
	sw[0] = 0;	//�ñ߽�ֵ
	printf("\nsw = 0");
	
	for (i = 1; i <= ST.length; i++)	//��С��������ۼ�Ȩֵ [i] = [i-1]+[i]Ȩֵ	
	{
		sw[i] = sw[i-1] + ST.elem[i].weight;
		printf("%5d", sw[i]);
	}
}

typedef BiTree SOSTree;		//���Ų��������ö�������Ĵ洢�ṹ
void CreateSOSTree(SOSTree * T, SSTable ST)
{
	//�������ST����һ�ô��Ų�����T��ST������Ԫ�غ���Ȩ��weight�� �㷨9.4
	int sw[N + 1];	//�ۼ�Ȩֵ����
	if (ST.length == 0)	//ST�ǿձ�
		*T = NULL;		//���Ų�����TΪ��	
	else	//ST�ǿ�
	{
		FindSW(sw, ST);	//���������ST�и�����Ԫ�ص�weight�����ۼ�Ȩֵ��sw
		SecondOptimal(T, ST.elem, sw, 1, ST.length);
		//�������ST[1-ST.length]����Ȩֵ��sw������sw[0] == 0���ݹ鹹����Ų�����T	
	}
}
Status Search_SOSTree(SOSTree *t, KeyType key)
{
	//�ڴ��Ų�����T�в������ؼ��ֵ���key��Ԫ�ء��ҵ��򷵻�OK��Tָ���Ԫ�أ����򷵻�FALSE
	SOSTree T = *t;
	while (T)	//T�ǿ�
	{
		if (T->data.key == key)
		{
			*t = T;
			return OK;
		}
		else if (T->data.key > key)
			T = T->lchild;
		else
			T = T->rchild;	
	}
	return FALSE;	//Ҫ���ҵ�Ԫ�ز����� 
}

int main(void)
{
	SSTable st;
	SOSTree t;
	SOSTree ret;
	Status i;
	KeyType s;
	
	Create_OrdFromFile(&st, "f8-3.txt");	//�������ļ������ǽ���̬���ұ�st
	printf("		");
	Traverse(st, Visit);
	CreateSOSTree(&t, st);				//�������st������Ų�����t
	printf("\n����������ҵ��ַ���");
	InputKey(&s);						//���̼���������ַ�
	ret = t;
	i = Search_SOSTree(&ret, s);		//�ڴ��Ų������ϲ��ҹؼ��ֵ���s��Ԫ��
	if (i)	//�ҵ�
		printf("%c ��Ȩֵ��%d\n", s, t->data.weight);
	else
		printf("���в����ڸ��ַ�\n");
	DestroyBiTree(&t);	//������ϣ��ݻٴ��Ų�����t
	Destroy(&st);		//������ϣ��ݻ������st 

	return 0;
}
/*
--------------------
                (A, 1)(B, 1)(C, 2)(D, 5)(E, 3)(F, 4)(G, 4)(H, 3)(I, 5)
sw = 0    1    2    4    9   12   16   20   23   28
����������ҵ��ַ���G
G ��Ȩֵ��4
--------------------
*/























