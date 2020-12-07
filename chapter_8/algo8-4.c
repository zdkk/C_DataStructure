//algo8-4.c	����bo8-2.h�ĳ���
#include "../c1.h"
#include "func8-5.h"
#include "c8-2.h"
typedef ElemType TElemType;	//�����������Ԫ������Ϊ����Ԫ������
#include "../chapter_6/c6-1.h"		//��������Ĵ洢�ṹ
#include "func8-4.h"		//�����㷨9.5(a)��bo6-2.h
#include "bo8-2.h"			//�����㷨9.5(b)���㷨9.6~9.8
int main(void)
{
	BiTree dt, p;
	int i, n;
	KeyType j;
	ElemType r;
	Status k;
	FILE *f;
	
	f = fopen("f8-4.txt", "r");
	fscanf(f, "%d", &n);
	InitDSTable(&dt);	//����ն���������dt
	for (i = 0; i < n; i++)
	{
		InputFromFile(f, &r);
		k = InsertBST(&dt, r);
		if (!k)	//����ʧ��
			printf("����������dt���Ѿ����ڹؼ��ֵ���%d�Ľ�㣬��(%d, %d)�޷����뵽dt�С�\n",
				r.key, r.key, r.others);	
	}
	fclose(f);
	printf("�����������������dt��\n");
	TraverseDSTable(dt, Visit);
	printf("\n�����������������dt��\n");
	PreOrderTraverse(dt, Visit);
	printf("\n����������ҵĹؼ��ֵ�ֵ�� ");
	InputFromKey(&j);
	p = searchBST(dt, j);
	if (p)
	{
		printf("dt�д��ڹؼ���Ϊ%d�Ľ�㡣", j);
		DeleteBST(&dt, j);
		printf("ɾ���˽��������������������dt:\n");
		TraverseDSTable(dt, Visit);
		printf("\n�����������������dt��\n");
		PreOrderTraverse(dt, Visit);
		printf("\n");
	}
	else
		printf("dt�в����ڹؼ���Ϊ%d�Ľ�㡣\n", j);
	DestroyDSTable(&dt);
	
	return 0;
} 
