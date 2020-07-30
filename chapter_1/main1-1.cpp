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
	printf("调用初始化函数后，i = %d(1:成功)。T的三个值为：", i);
	PrintT(T);
	
	i = Get(T, 2, &m);
	if(i == OK){
		printf("T的第2个值为");
		PrintE(m);
	} 
	
	i = Put(T, 2, 3);
	if(i == OK){
		printf("将T的第二个值改为3后，T的三个值为：");
		PrintT(T);
	}
	
	i = IsAscending(T);
	printf("调用升序测试函数后，i = %d(0:否 1：是)\n", i);
	
	i = IsDescending(T);
	printf("调用降序测试函数后，i = %d(0:否 1：是)\n", i);
	
	if((i = Max(T, &m)) == OK){
		printf("T中最大值为");
		PrintE(m);
	}
	
	if((i = Min(T, &m)) == OK){
		printf("T中最小值为");
		PrintE(m);
	}
	
	DestroyTriplet(&T);
	printf("销毁T后, T = %u\n", T);
	
	
	return 0;
}
