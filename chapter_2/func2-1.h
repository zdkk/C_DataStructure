//func2-1.h

void Union(List *La, List Lb){	//�㷨2.1 
	//��������Lb�е�����La�е�����Ԫ�ز��뵽��La�У����ı��Lb��
	ElemType e;
	int La_len, Lb_len;
	int i;
	
	La_len  = ListLength(*La);
	Lb_len = ListLength(Lb);
	
	for(i=1; i<=Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if(!LocateElem(*La, e, equal))
			ListInsert(La, ++La_len, e);	
	}	
	return;
}

void MergeList(List La, List Lb, List *Lc)	//�㷨2.2 
{
	//��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ���շǵݼ����У����ı�La��Lb��
	int i = 1, j = 1, k = 0;
	int La_len, Lb_len;
	ElemType ai, bj;
	
	InitList(Lc);		//�����ձ�Lc
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	while(i<=La_len && j<=Lb_len)
	{
		GetElem(La, i, &ai);
		GetElem(Lb, j, &bj);
		if(ai <= bj)
		{
			ListInsert(Lc, ++k, ai);
			i++;
		}
		else
		{
			ListInsert(Lc, ++k, bj);
			j++;	
		}		
	}
	while(i<=La_len)
	{
		GetElem(La, i, &ai);
		ListInsert(Lc, ++k, ai);
		i++;
	}
	while(j<=Lb_len)
	{
		GetElem(Lb, j, &bj);
		ListInsert(Lc, ++k, bj);
		j++;
	}
	return;
}
