// func2-2.h �������õĺ���
Status equal(ElemType c1, ElemType c2)
{ 
	//�ж�����Ԫ���Ƿ���� 
	if(c1==c2)
		return TRUE;
	else
		return FALSE;
}
int comp(ElemType a, ElemType b)
{ 
	// �Ƚ�����Ԫ�ص�ֵ����ȷ���0��a>b����1��a<b����-1 
	if(a==b)
		return 0;
	else
		return (a-b)/abs(a-b);
}
void print(ElemType c)
{ 
	//��ʮ�������͸�ʽ��ӡԪ��c��ֵ 
 	printf("%d ", c);
}
void print1(ElemType *c)
{ 
	// ��ʮ�������͸�ʽ��ӡԪ��*c��ֵ
	printf("%d ", *c);
}
void print2(ElemType c)
{ 
	//���ַ��͸�ʽ��ӡԪ��c��ֵ 
	printf("%c ", c);
}

