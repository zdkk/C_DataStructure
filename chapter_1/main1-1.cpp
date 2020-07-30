//main1-1.cpp

# include "../c1.h"
typedef int ElemType;
//typedef float ElemType
#include "c1-1.h"
#include "bo1-1.h"
#include "func1-1.h"

int main(void)
{
	Triplet T;
	ElemType m;
	Status i;
	
	i = InitTriplet(&T,5,7,9);
	printf("���ó�ʼ��������i = %d(1:�ɹ�)��T������ֵΪ��", i);
	PrintT(T);
	
	i = Get(T, 2, &m);
	if(i == OK){
		printf("T�ĵ�2��ֵΪ");
		PrintE(m);
	} 
	
	i = Put(T, 2, 3);
	if(i == OK){
		printf("��T�ĵڶ���ֵ��Ϊ3��T������ֵΪ��");
		PrintT(T);
	}
	
	i = IsAscending(T);
	printf("����������Ժ�����i = %d(0:�� 1����)\n", i);
	
	i = IsDescending(T);
	printf("���ý�����Ժ�����i = %d(0:�� 1����)\n", i);
	
	if((i = Max(T, &m)) == OK){
		printf("T�����ֵΪ");
		PrintE(m);
	}
	
	if((i = Min(T, &m)) == OK){
		printf("T����СֵΪ");
		PrintE(m);
	}
	
	DestroyTriplet(&T);
	printf("����T��, T = %u\n", T);
	
	
	return 0;
}
