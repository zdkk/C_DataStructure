//algo8-2.c 检验bo8-1.h（有序表部分）的程序
#include "../c1.h"
#include "func8-2.h"
#include "c8-1.h"
#include "c8-2.h"
#include "bo8-1.h"

int main(void)
{
	SSTable st;
	int i;
	KeyType s;
	Create_OrdFromFile(&st, "f8-2.txt");
	printf("有序表为：\n");
	Traverse(st, Visit);
	printf("\n");
	printf("请输入待查找数据的关键字：");
	InputFromKey(&s);
	i = Search_Bin(st, s);
	if (i)
		printf("%d是第%d个数据的关键字\n", st.elem[i].key, i);
	else
		printf("未找到\n");
	Destroy(&st);
	
	return 0;
}
/*
-------------------------
有序表为：
5 13 19 21 37 56 64 75 80 88 92
请输入待查找数据的关键字：37
37是第5个数据的关键字
--------------------------
*/
