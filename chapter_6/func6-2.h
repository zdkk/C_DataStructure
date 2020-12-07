//func6-2.h algo6-1.c��algo6-2.cҪ���õ���������
#define Order	//����Order
int min(HuffmanTree t, int i)
{
	//������������غշ�����t��ǰi�������Ȩֵ��С�����ĸ��ڵ����
	//����select()����
	int j, m;
	unsigned int k = UINT_MAX;	//k��ȡ��СȨֵ����ֵȡֵΪ��С�ڿ��ܵ�ֵ���޷������͵����ֵ��
	
	for (j = 1; j <= i; j++)	//����ǰi�����
	{
		if (t[j].weight < k && t[j].parent == 0)	//t[j]��ȨֵС��k���Ǹ��ڵ�
		{
			k = t[j].weight;						//t[j]��Ȩֵ����t
			m = j;									//��Ÿ���m 
		}
	}
	t[m].parent = 1;	//��ѡ�еĸ����˫�׸���0ֵ��������β��Ҹý��
	return m;			//���ظ��ڵ� 
}
void select(HuffmanTree t, int i, int *s1, int *s2)
{
	//�ںշ�������ǰt�������ѡ������Ȩֵ��С�����ĸ��ڵ���ţ�s1Ϊ������Ž�С��
#ifdef Order	//������������ж�����Order,��ִ������һ�γ���
	int j;
#endif
	*s1 = min(t, i);	//Ȩֵ��С�ĸ������� 
	*s2 = min(t, i);	//Ȩֵ�ڶ�С�ĸ�������
#ifdef Order
	if (*s1 > *s2)
	{
		//����
		j = *s1;
		*s1 = *s2;
		*s2 = j; 
	}
#endif 
}
