//algo8-2.c ����bo8-1.h��������֣��ĳ���
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
	printf("�����Ϊ��\n");
	Traverse(st, Visit);
	printf("\n");
	printf("��������������ݵĹؼ��֣�");
	InputFromKey(&s);
	i = Search_Bin(st, s);
	if (i)
		printf("%d�ǵ�%d�����ݵĹؼ���\n", st.elem[i].key, i);
	else
		printf("δ�ҵ�\n");
	Destroy(&st);
	
	return 0;
}
/*
-------------------------
�����Ϊ��
5 13 19 21 37 56 64 75 80 88 92
��������������ݵĹؼ��֣�37
37�ǵ�5�����ݵĹؼ���
--------------------------
*/
