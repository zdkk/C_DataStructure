//func2-1.h

void Union(List *La, List Lb){	//算法2.1 
	//将所有在Lb中但不在La中的数据元素插入到表La中（不改变表Lb）
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

void MergeList(List La, List Lb, List *Lc)	//算法2.2 
{
	//已知线性表La和Lb中的数据元素按值非递减排列
	//归并La，Lb得到新的线性表Lc，Lc的数据元素也按照非递减排列（不改变La和Lb）
	int i = 1, j = 1, k = 0;
	int La_len, Lb_len;
	ElemType ai, bj;
	
	InitList(Lc);		//创建空表Lc
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
