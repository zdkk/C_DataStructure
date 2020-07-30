//bo2-2.h
//����ͷ�ڵ�ĵ�����Ļ���������12���������㷨2.8-2.10

void InitList(LinkList *L)
{
	//�������������һ������ͷ�ڵ�Ŀյĵ�����L 
	*L = (LinkList)malloc(sizeof(LNode));	//����ͷ�ڵ㣬��ʹLָ��ýڵ�
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;	
} 

void DestroyList(LinkList *L)
{
	//��ʼ������L�Ѿ�����
	//�������������L
	LNode *p = *L, *q;
	while(p)	//Lָ��ڵ㣨�ǿգ� 
	{
		q = p;
		p = p->next;
		free(q);
	}
	*L = NULL;
}

void ClearList(LinkList *L)
{
	//��ʼ������L����
	//�����������L��Ϊ��
	LNode *p = (*L)->next;		//pָ����Ԫ��� 
	(*L)->next = NULL;			//ͷ�ڵ�ָ������� 
	DestroyList(&p);		//����p��ָ������� 
}

Status ListEmpty(LinkList L)
{
	//��ʼ������L����
	//�����������LΪ�ձ�����TRUE�����򷵻�FALSE
	if(L->next)		//�ǿ� 
		return FALSE;
	else
		return TRUE; 
}

int ListLength(LinkList L)
{
	int i = 0;		//��ʼ��������Ϊ0
	LNode *p = L->next;	//pָ����Ԫ���
	while (p)	//δ��ĩβ 
	{
		i++;	//��������һ 
		p = p->next;	//pָ����һ����� 
	} 
	return i;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
	//��ʼ������L���ڣ�1<=i<=ListLength(L)
	//�������������i��Ԫ�ش���ʱ����e���ؽ��������OK�����򷵻�ERROR
	int j = 1;			//��������ʼֵΪ1 
	LNode *p = L->next; //pָ����Ԫ���
	
	while(p && j<i)		//˳ָ�������ң�ֱ��pָ���i���ڵ��pΪNULL����i����㲻���ڣ� 
	{
		j++;
		p = p->next;
	} 
	if(!p || j>i)		//��i���ڵ㲻����
		return ERROR;
	
	*e = p->data;
	return OK; 
}

int LocateElem(LinkList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
	//��ʼ������L���ڣ�compare()������Ԫ���ж�����������Ϊ1������Ϊ0��
	//�������������L�е�һ����e�����ϵcompare()������Ԫ�ص�λ����������Ԫ�ز������򷵻�0
	int i = 0;			//��������ʼ��Ϊ0 
	LNode *p = L->next; //pָ����Ԫ���
	while(p)			//δ��ĩβ 
	{
		i++;	//��������һ	
		if((*compare)(p->data, e))	//�ҵ���һ����������������Ԫ�� 
			return i;				//������λ�� 
		p = p->next; 				//pָ����һ����� 
	} 
	return 0;						//����������������Ԫ�أ�����0 
	 
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	//��ʼ������L����
	//�����������cur_e��L������Ԫ���Ҳ��ǵ�һ��������pre_e��������ǰ��������OK
		//�������ʧ�ܣ�pre_e�޶��壬����ERROR
	LNode *p = L->next, *q;	//pָ����Ԫ���
	
	while(p && p->next)		//pָ��Ľ���к��
	{
		q = p->next;
		if(q->data == cur_e)	//p�ĺ��Ϊcur_e
		{
			*pre_e = p->data;	//��p��ָ��������Ԫ�ظ�ֵ��*pre_e 
			return OK;			//����OK 
		}
		p = q; 					//p�ĺ�̽������Ԫ�ز�����cur_e,p���� 
	} 
	return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	//��ʼ������L����
	//��������� ��cur_e��L������Ԫ���Ҳ������һ��������next_e�������ĺ�̣�����OK
		//�������ʧ�ܣ�next_e�޶��壬����ERROR
	LNode *p = L->next;		//pָ����Ԫ���
	
	while (p && p->next)	//p��ָ����к��
	{ 
		if (p->data == cur_e)	//pָ��Ľ��ֵΪcur_e
		{
			*next_e = p->next->data;
			return OK;
		 } 
		p = p->next;
	 } 
	return ERROR;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	//��ʼ������L���ڣ�1<=i<=ListLength(L)+1
	//�����������i�Ϸ�����ָ��λ�ô�����Ԫ��e����OK�����򷵻�ERROR
	int j = 0;	//��������ʼ��0
	LNode *p = *L, *q;	//pָ��ͷ�ڵ� 
	
	while(p && j<(i-1))	//Ѱ�ҵ�i-1�����
	{
		j++;
		p = p->next;
	}
	if(!p && j>(i-1))	//i���Ϸ�
		return ERROR;
	
	q = (LNode *)malloc(sizeof(LNode));
	if(!q)	//����洢�ռ�ʧ��
		return OVERFLOW;
	q->data = e;
	q->next = p->next;
	p->next = q; 
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	//��ʼ������L���ڣ�1<=i<=ListLength(L)
	//�����������i����ɾ����i��Ԫ�ز���ֵ��e������OK�����򷵻�ERROR
	int j = 0;	//��������ʼ��0
	LNode *p = *L, *s;	//pָ��ͷ�ڵ�
	while(p->next && j<(i-1))	//Ѱ�ҵ�i-1���ڵ㣬����pָ����ǰ��
	{
		p = p->next;
		j++;
	}
	if(!p->next || j>i-1)	//i���Ϸ�
		return ERROR;
	
	s = p->next;		//sָ��Ҫɾ���Ľ��
	*e = s->data;		//��Ҫɾ���Ľ���Ԫ��ֵ����*e
	
	p->next = s->next;	//p�ĺ��ָ��ָ��Ҫɾ��������һ�� 
	free(s);			//�ͷ�Ҫ��ɾ���Ľ�� 
	return OK; 			//ɾ���ɹ� 
}

void ListTraverse(LinkList L, void(* visit)(ElemType))
{
	//��ʼ������L����
	//������������ζ�L��ÿ������Ԫ�ص���visit()����
	LNode *p = L->next;		//pָ����Ԫ���
	while(p)				//pָ��Ľ����� 
	{
		(* visit)(p->data);	//��pָ��Ľ�������Ԫ�ص���visit���� 
		p = p->next;		//pָ����һ����� 
	} 
	printf("\n");
}










