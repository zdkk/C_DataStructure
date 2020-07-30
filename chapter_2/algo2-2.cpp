//algo2-2.cpp
//��LinkList��SqList���ͷֱ�ʵ���㷨2.1���㷨2.2

#include "../c1.h"
typedef int ElemType;	//����ElemTypeΪ����
#define Sq				//��SqListʵ��ѡ����У���LinkList������ע��
#ifdef Sq
	#include "c2-1.h"		//�������Ա�Ķ�̬����˳��洢�ṹ 
	#include "bo2-1.h"		//�������� 
	typedef SqList List;	//���������������ListΪSqList����
	#define printer print1	//ListTraverse()�õ���ͬ���͵��������
#else
	#include "c2-2.h"		//�������Ա�ĵ�����洢�ṹ 
	#include "bo2-2.h"		//�������� 
	typedef LinkList List	//���������������ListΪLinkList����
	#define printer print	//Listtraverse()�õ���ͬ���͵��������
#endif
#include "func2-2.h"		//����equal(),comp(),print(),print1(),print2()���� 
#include "func2-1.h" 		//�����㷨2.1��2.2

int main(void)
{
	List La, Lb, Lc;
	int j, b[7] = {2,6,8,9,11,15,20};
	
	InitList(&La);	//�����ձ����ɹ�������˳�
	for (j=1; j<=5; j++)	//��La�в���5��Ԫ�أ�����Ϊ1��2��3��4��5
		ListInsert(&La, j, j);
	printf("La = ");
	ListTraverse(La, printer);	//���La������
	
	InitList(&Lb);
	for(j=1; j<=5; j++)		//��Lb�в���5��Ԫ�أ�����Ϊ2��4��6��8��10
		ListInsert(&Lb, j, 2*j);
	printf("Lb = ");
	ListTraverse(Lb, printer);	//���Lb������
	
	Union(&La,Lb);				//�����㷨2.1����Lb������������Ԫ�ز���La�����ı�Lb 
	printf("new La = ");
	ListTraverse(La, printer);	//����µ�La������
	
	ClearList(&Lb);				//���Lb 
	for(j=1; j<=7; j++)			//��Lb�����²�������b[]��7��Ԫ��
		ListInsert(&Lb, j, b[j-1]);
	printf("Lb = ");
	ListTraverse(Lb, printer);	//���Lb������
	MergeList(La, Lb, &Lc);		//�����㷨2.2�������±�Lc�����ı�La��Lb
	printf("Lc = ");
	ListTraverse(Lc, printer);	//���Lc������ 
	
	return 0; 	 
}
 
