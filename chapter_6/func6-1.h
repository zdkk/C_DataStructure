//func6-1.c	�����������룬����������ָ���������ͣ����������ĺ���
#include "../c1.h"
#if CHAR					//CHARֵΪ1�������Ϊ�ַ��� 
	typedef char TElemType;	//������Ԫ������Ϊ�ַ���
	TElemType Nil = '#';	//���ַ�'#'Ϊ�գ���Ҫ�����н��ֵ������#��
	#define form "%c"		//��������ĸ�ʽΪ%c
#else 						//CHARֵΪ0�������Ϊ����
	typedef int TElemType;
	TElemType Nil = 0;
	#define form "%d"
#endif

void Visit(TElemType e)
{
	printf(form" ", e);		//����CHARΪ1ʱ�����ַ���ʽ�����CHARΪ0ʱ�������͸�ʽ��� 
} 
