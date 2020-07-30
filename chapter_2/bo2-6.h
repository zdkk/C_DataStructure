//bo2-6.h
//����βָ��ĵ�ѭ������ 12���������� 

void InitList(LinkList *L)
{
	//�������������һ���յ�ѭ������
	(*L) = (LinkList)malloc(sizeof(LNode));	//����ͷ��㣬Lָ��ý�� 
	if(!(*L))	//�洢����ʧ�� 
		exit(OVERFLOW); 
	(*L)->next = (*L);	//ͷָ���ָ����ָ��ͷ��� 
}

void ClearList(LinkList *L)
{
	//��ʼ������L����
	//�����������L���
	LNode *p, *q;
	 (*L) = (*L)->next;	//(*L)ָ��ͷ��� 
	p = (*L)->next;		//pָ����Ԫ���
	while(p != (*L))			//p��ָ��ͷ��� 
	{
		q = p;				//qָ��p��� 
		p = p->next;		//pָ����һ��� 
		free(q);			//�ͷ�q��� 
	} 
	(*L)->next = (*L);		//ͷ����ָ����ָ��ͷ��� 
}

void DestroyList(LinkList *L)
{
	//��ʼ������L����
	//�������������L
	ClearList(L);		//���L 
	free(*L);			//�ͷ�ͷ��� 
	(*L) = NULL;		//L��ΪNULL 
}

Status ListEmpty(LinkList L)
{
	//��ʼ������L����
	//�����������LΪ�շ���TRUE�����򷵻�FALSE
	
	if(L->next == L)
		return TRUE;
	else
		return FALSE; 
}

int ListLength(LinkList L)
{
	//��ʼ������L����
	//�������������L������Ԫ�صĸ���
	int i = 0;	//��������ʼ��0
	LNode *p = L->next;	//pָ��ͷ���
	
	while (p != L)		//δ��ĩβ 
	{
		i++;
		p = p->next;
	}
	return i; 
}

Status GetElem(LinkList L, int i, ElemType *e)
{
	//��ʼ������L����
	//�����������i��������i���������Ԫ�ظ���*e,����OK�����򷵻�ERROR
	
	int j = 1;	//j��ʼ��Ϊ1
	LNode *p = L->next->next;	//pָ����Ԫ���
	
	while (p!=L->next && j<i)	//˳ָ�������ң�ֱ��pָ���i������p�ٴ�ָ��ͷ��㣨��i����㲻���ڣ� 
	{
		p = p->next;
		j++;
	}
	if(p==L->next || j>i)	//i������
		return ERROR;
	
	*e = p->data;
	return OK;
}

int LocateElem(LinkList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
	//��ʼ������L����
	//�������������L�е�һ����e����compare��ϵ������Ԫ�ص�λ�򣬲������򷵻�0
	
	int i = 1;			//��������ʼ��0 
	LNode *p = L->next->next; //pָ��ͷ���
	
	while(p != L->next)	//p��ָ��ͷ���
	{
		if((*compare)(p->data, e))	//p��ָ���Ԫ�غ�e�����ϵcompare 
			return i;
		i++;
		p = p->next;	
	} 
	return 0;				//û�ҵ�����������Ԫ�أ�����0�� 
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	//��ʼ������L����
	//�����������L�д��ڽ������Ԫ�ص���cur_e�Ҳ��ǵ�һ����㣬����ǰ���������Ԫ�ظ���pre_e,����OK�����򷵻�ERROR
	LNode *p, *q;
	p = L->next->next;	//pָ����Ԫ���
	
	while (p!=L->next && p->next!=L->next)	//p��p�ĺ�̽�㶼��ָ��ͷ���
	{
		q = p->next;				//qָ��p�ĺ�̽�� 
		if(q->data == cur_e)		//qָ��Ľ������Ԫ�ص���cur_e
		{
			*pre_e = p->data;
			return OK;
		}	
		p = q;						//pָ����һ��� 
	} 
	return ERROR;
 } 
 
 Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	//��ʼ������L����
	//��������� ��cur_e��L������Ԫ���Ҳ������һ��������next_e�������ĺ�̣�����OK
		//�������ʧ�ܣ�next_e�޶��壬����ERROR
	LNode *p = L->next->next;		//pָ����Ԫ���
	
	while (p!=L->next && p->next!=L->next)	//p��ָ����к��
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
	//��ʼ������L����
	//�����������i����1<=i<=ListLength(L)+1����L�е�i�����ǰ�����㣬������Ԫ��Ϊe������OK�����򷵻�ERROR
	LNode *p = (*L)->next, *s;		//pָ��ͷ���
	int j = 0;						//��������ʼ��0 
	if(i<1 || i>ListLength(*L)+1)	//iֵ���Ϸ�
		return ERROR;
	
	while(j<i-1)					//Ѱ�ҵ�i-1����� 
	{
		j++;
		p = p->next;
	}
	
	s = (LNode*)malloc(sizeof(LNode));
	if(!s)	//����洢ʧ��
		exit(OVERFLOW);
	s->data = e;
	s->next = p->next;				//�½��ָ��ԭ��i�����
	p->next = s;					//ԭ��i-1�����ָ���½��
	if(p == *L)						//�������λ���Ǳ�β
	{
		*L = s;						//Lָ���µ�β���	
	} 
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	//��ʼ������L���ڣ�1<=i<=ListLength(L)
	//�����������i����ɾ����i��Ԫ�ز���ֵ��e������OK�����򷵻�ERROR
	int j = 0;			//��������ʼ��0 
	LNode *p, *q;	
	p = (*L)->next;		//pָ��ͷ��� 
	
	while(p->next!=(*L)->next && j<i-1)	//Ѱ�ҵ�i-1���ڵ㣬����pָ����ǰ��
	{
		p = p->next;
		j++;
	}
	if(p->next ==(*L)->next || j>i)	//i������
		return ERROR;
	
	q = p->next;		//qָ���ɾ�����
	p->next = q->next;	//��ɾ�����ǰ�����ĺ��ָ��ָ���ɾ�����ĺ�̽��
	*e = q->data;		//����ɾ�����ֵ����*e 
	if(q == *L)			//��ɾ�������β���
		*L =  p;		//*Lָ���µı�β���
	free(q); 			//�ͷŴ�ɾ�����
	return OK; 
}

void ListTraverse(LinkList L, void(*visit)(ElemType))
{
	//��ʼ������L����
	//������������ζ�L��ÿ������Ԫ�ص���visit()����
	LNode *p = L->next->next;		//pָ����Ԫ���
	while(p != L->next)				//p��ָ��ͷ��� 
	{
		(* visit)(p->data);	//��pָ��Ľ�������Ԫ�ص���visit���� 
		p = p->next;		//pָ����һ����� 
	} 
	printf("\n");
}







