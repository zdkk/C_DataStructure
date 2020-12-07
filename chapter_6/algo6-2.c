//algo6-2.c	��շ�������	ʵ���㷨6-12�ĳ���
#include "../c1.h"
#include "c6-3.h"		//�շ������ͺշ�������Ĵ洢�ṹ 
#include "func6-2.h" 	//�ں�min()��select()����

void HuffmanCoding(HuffmanTree * HT, HuffmanCode * HC, int * w, int n)
{
	//w���n���ַ���Ȩֵ(��>0),����շ�����HT�������n���ַ��ĺշ�������HC
	unsigned cdlen;
#include "func6-3.h"	//�㷨6-12��ǰ�벿�֣�����Ϊ�㷨6.13��ջ�ǵݹ�����շ���������շ������� 
	
	*HC = (HuffmanCode)malloc(sizeof(char *) * (n + 1));	//����n���ַ������ͷָ������([0]����) 
	cd = (char *)malloc(n * sizeof(char));	//���������Ĺ����ռ�
	c = m;	//m = 2 * n - 1;�����һ����㣬Ҳ���Ǹ���㿪ʼ
	cdlen = 0;	//�볤��ʼֵΪ0
	for (i = 1; i <= m; i++)
		(*HT)[i].weight = 0;	//����벻��ҪȨֵ���������״̬��־λ��0��ʾ���Һ��Ӷ�����������
	while (c)	//�տ�ʼc���ڸ������ţ�ѭ��������ʱ��cΪ0��������ʵ�Ҷ���ĺ�����
	{
		if ((*HT)[c].weight == 0)	//��ǰ������Һ��Ӷ�δ������
		{	//���� 
			(*HT)[c].weight = 1;	//1Ϊ���ӱ����ʣ��Һ���δ�����ʵı��
			if ((*HT)[c].lchild != 0)	//�����ӣ����ý�㲻��Ҷ�ӽڵ�
			{
				c = (*HT)[c].lchild;	//��cΪ��������ţ���Ҷ�ӷ���ǰ��һ����
				cd[cdlen++] = '0';		//��֧����Ϊ0	
			}
			else if((*HT)[c].rchild == 0)//���cΪҶ�ӽڵ㣬��¼��Ҷ�����ַ��ı��� 
			{
				(*HC)[c] = (char *)malloc(sizeof(char) * (cdlen + 1));
				cd[cdlen] = '\0';		//��Ӵ������� 
				strcpy((*HC)[c], cd);	//���Ʊ��봮 
			}
		}//endif((*HT)[c].weight == 0)
		else if((*HT)[c].weight == 1)	//���ӱ����ʹ����Һ���û��
		{	//���� 
			(*HT)[c].weight = 2;	//���Һ��Ӿ������ʹ��ı��
			if ((*HT)[c].rchild != 0)	//���Һ��ӣ�����Ҷ��㣩
			{
				c = (*HT)[c].rchild;	//��cΪ���Һ�����ţ���Ҷ��㷽��ǰ��һ��
				cd[cdlen++] = '1';		//�ҷ�֧����Ϊ1	
			}
		}
		else	//���Һ��Ӿ������ʹ���(*HT)[c].weight == 2���������㷽�����һ��
		{
			c = (*HT)[c].parent;
			cdlen--;	
		}
	}
	free(cd);
}
#include "func6-4.h"
