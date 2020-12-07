//algo6-1.c	��շ�������	ʵ���㷨6-12�ĳ���
#include "../c1.h"
#include "c6-3.h"		//�շ������ͺշ�������Ĵ洢�ṹ 
#include "func6-2.h" 	//�ں�min()��select()����

void HuffmanCoding(HuffmanTree * HT, HuffmanCode * HC, int * w, int n)
{
	//w���n���ַ���Ȩֵ(��>0),����շ�����HT�������n���ַ��ĺշ�������HC
	int start;
	unsigned f;
#include "func6-3.h"	//�㷨6-12��ǰ�벿�֣������Ǵ�Ҷ�ӵ���������ÿ���ַ��ĺշ�������
	
	*HC = (HuffmanCode)malloc(sizeof(char *) * (n + 1));	//����n���ַ������ͷָ������([0]����) 
	cd = (char *)malloc(n * sizeof(char));	//���������Ĺ����ռ�
	cd[n - 1] = '\0';						//���������
	for (i = 1; i <= n; i++)
	{
		//����ַ���շ�������
		start = n - 1;	//���������λ��
		for (c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)//��Ҷ�ӵ������������
			if((*HT)[f].lchild == c)	//c����˫�׵�����
				cd[--start] = '0';		//��Ҷ�����������0
			else	//c����˫�׵��Һ���
				cd[--start] = '1';
		(*HC)[i] = (char *)malloc(sizeof(char) * (n - start));
		strcpy((*HC)[i], &cd[start]);	//��cd���Ʊ��봮��HC 
	}
	free(cd);
}
#include "func6-4.h"
