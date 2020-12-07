//algo8-1.c ����bo8-1.h(����˳�����)�ĳ���
#include "../c1.h"
#include "func8-1.h"	//��������Ԫ�����Ͷ��弰���� 
#include "c8-1.h" 		//������̬���ұ��˳��洢�ṹ
#include "c8-2.h"		//������������ֵ�͹ؼ��ֱȽϵĺ궨��
#include "bo8-1.h"		//��̬���ұ�Ļ�������

char * s_gets(char * st, int n)
{
	char * ret;
	char *find;
	
	ret = fgets(st, n, stdin);
	if (ret)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret;
	
}
int main(void)
{
	SSTable st;
	int i;
	KeyType s;
	char filename[13];	//�洢�����ļ���������·����
	
	printf("�����������ļ����� ");
	s_gets(filename, 13);
	Create_SeqFromFile(&st, filename);	//�������ļ�����˳��̬���ұ�st
	for (i = 1; i <= st.length; i++)
		st.elem[i].total = st.elem[i].Politics + st.elem[i].Chinese + st.elem[i].English +st.elem[i].Math + st.elem[i].Physics
		+ st.elem[i].Chemistry + st.elem[i].Biology;
	printf("׼��֤�� ����    ���� ���� ���� ��ѧ ���� ��ѧ ���� �ܷ�\n");
	Traverse(st, Visit);
	puts("������������˵�׼��֤�ţ�");
	InputFromKey(&s);
	i = Search_Seq(st, s);	//�ھ�̬���ұ��в��Һ��йؼ���s��������
	if (i)	//�ҵ�
		Visit(st.elem[i]);
	else
		printf("δ�ҵ�\n");
	Destroy(&st); 
	
	return 0;
}
/*
�����������ļ����� f8-1.txt
׼��֤�� ����    ���� ���� ���� ��ѧ ���� ��ѧ ���� �ܷ�
179328   何方�?   85    89    98   100    93    80    47   592
179325   陈华      85    86    88   100    92    90    45   586
179326   陆华      78    75    90    80    95    88    37   543
179327   张平      82    80     8    98    84    96    40   488
179324   赵晓�?   76    85    94    57    77    69    44   502
������������˵�׼��֤�ţ�
179326
179326   陆华      78    75    90    80    95    88    37   543
*/
