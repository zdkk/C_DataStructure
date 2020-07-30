//bo2-7.h 
//��ͷ����˫��ѭ������Ļ���������14���� ����2.18��2.19

void InitList(DuLinkList *L)
{
	//�������������˫��ѭ������
	*L = (DuLNode *)malloc(sizeof(DuLNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = (*L)->prior = (*L); 
} 

void ClearList(DuLinkList *L)
{
	//��ʼ������L����
	//�����������L��Ϊ�ձ�
	DuLNode *p = (*L)->next;	//pָ����Ԫ���
	
	while (p != (*L))			//pδָ��ͷ���
	{
		p = p->next;			//pָ����һ��� 
		free(p->prior);			//�ͷ�p��ǰ����� 
	} 
	p->next = p->prior = p;		//ͷ��������ָ�����ָ������ 
}

void DestroyList(DuLinkList *L)
{
	//��ʼ������L����
	//�������������L
	ClearList(L);	//������� 
	free(*L);		//�ͷ�ͷ���
	(*L) = NULL;	//*L��ָ���κδ洢��Ԫ 
}

Status ListEmpty(DuLinkList L)
{
	//��ʼ������L����
	//�����������LΪ�շ���TRUE�����򷵻�FALSE
	if(L->next == L && L->prior == L)
		return TRUE;
	else
		return FALSE; 
}

int ListLength(DuLinkList L)
{
	//��ʼ������L����
	//�������������L��Ԫ�ظ�������LΪ�գ�����0
	DuLNode *p = L->next;		//pָ����Ԫ���
	int i = 0;			//��������ʼ��0
	
	while(p != L)		//p��ָ��ͷ���
	{
		i++;
		p = p->next;
	}
	return i; 
}

Status GetElem(DuLinkList L, int i, ElemType *e)
{
	//��ʼ������L����
	//�������������i��Ԫ�ش���ʱ����*e������ֵ������OK�����򷵻�ERROR
	int j = 1;		//��ʱ����ʼ��1
	DuLNode *p = L->next;	//pָ����Ԫ��� 
	
	while (p!=L && j<i)		//˳ָ������ң�ֱ��pָ���i��Ԫ�ػ�pָ��ͷ��� 
	{
		p = p->next;
		j++;
	}
	if(p==L || j>i)		//i������
		return ERROR;
	
	*e = p->data;		//ȡ��i�����ֵ����*e
	return OK; 
}

int LocateElem(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	//��ʼ������L����
	//�������������L�е�һ����e����compare��ϵ��Ԫ��λ����������������Ԫ�أ�����0
	int i = 1;				//��������ʼ��1 
	DuLNode *p = L->next; 	//pָ����Ԫ���
	
	while (p!=L)			//p��ָ��ͷ���
	{
		if((*compare)(p->data, e))
			return i;
		i++;				//��������һ 
		p = p->next;		//pָ����һ��� 
	} 
	return 0; 
}

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType *pre_e)
{
	//��ʼ������L����
	//�����������L�д��ڽ������Ԫ�ص���cur_e�Ҳ�����Ԫ��㣬����ǰ���������Ԫ�ظ���*pre_e,����OK������pre_e�޶��壬����ERROR
	DuLNode *p = L->next->next;	//pָ��ڶ������ 
	
	while (p != L)		//p��ָ��ͷ���
	{
		if(p->data == cur_e)	//p��ָ�������Ԫ��ֵ����cur_e 
		{
			*pre_e = p->prior->data;	//��p��ǰ���������Ԫ�ظ���pre_eָ��ı���
			return OK; 
		}
		p = p->next;			//pָ����һ��� 
	} 
	return ERROR;
}

Status NextElem(DuLinkList L, ElemType cur_e, ElemType *next_e)
{
	//��ʼ������L����
	//�����������L�д��ڽ������Ԫ�ص���cur_e�Ҳ���β��㣬�����̽������Ԫ�ظ���*next_e,����OK������next_e�޶��壬����ERROR
	DuLNode *p = L->next;	//pָ����Ԫ���
	
	while (p->next != L)	//p�ĺ�̽�㲻ָ��ͷ���
	{
		if(p->data == cur_e)	//pָ��Ľ������Ԫ��ֵΪcur_e
		{
			*next_e = p->next->data;
			return OK;
		}
		p = p->next; 
	}
	return ERROR; 
}

DuLinkList GetElemP(DuLinkList L, int i)	//����
{
	//��ʼ������L����
	//������������ص�i��Ԫ�صĵ�ַ��iΪ0��ʾ����ͷ����ַ�����򷵻�NULL
	DuLNode *p = L; 	//pָ��ͷ���
	int j;
	
	if(i<0 || i>ListLength(L))
		return NULL;
	
	for (j=0; j<i; j++)
	{
		p = p->next;	//pָ����һ���	
	}	
	return p; 
 } 

Status ListInsert(DuLinkList *L, int i, ElemType e)
{
	//��ʼ������L����
	//�����������i������L�е�i�����ǰ��������Ԫ��Ϊe���½�㣬����OK�����򷵻�ERROR
	int j;
	DuLNode *p, *s;
	
	p = GetElemP(*L, i-1);		//��ȡ��i-1������ָ��
	if(!p)						//��pΪNULL
		return ERROR;
		
	s = (DuLNode *)malloc(sizeof(DuLNode));
	if(!s)	//����洢�ռ�ʧ��
		exit(OVERFLOW);
	s->data = e;
	
	s->prior = p;		//�½��p��ǰ��ָ��ָ��p��� 
	s->next = p->next;	//�½����ָ��ָ��p�ĺ�̽��
	p->next->prior = s;	//p��ԭ��̽���ǰ��ָ��ָ���½�� 
	p->next = s; 		//p�ĺ��ָ��ָ���½��
	return OK; 
}

Status ListDelete(DuLinkList *L, int i, ElemType *e)
{
	//��ʼ������L����
	//�����������i�Ϸ���1<=i<=n)��ɾ����i����㲢��������Ԫ�ظ���eָ��ı���������OK�����򷵻�ERROR
	DuLNode *p = GetElemP(*L, i);		//��ȡ��i���ڵ�ָ�� 
	
	if(p == NULL)						//��i����㲻���� 
		return ERROR;
	
	*e = p->data;
	p->prior->next = p->next;			//p��ǰ�����ĺ��ָ��ָ��p�ĺ�̽�� 
	p->next->prior = p->prior;			//p�ĺ�̽���ǰ��ָ��ָ��p��ǰ����� 
	free(p);							//�ͷ�p���
	return OK; 
}

void ListTraverse(DuLinkList L, void(*visit)(ElemType))
{
	//��ʼ������L����
	//�����������ͷ�������������ÿ���������Ԫ�ص��ú���visit()
	DuLNode *p = L->next;	//pָ����Ԫ���
	while (p != L)			//p��ָ��ͷ���
	{
		(*visit)(p->data);	
		p = p->next;
	} 
	printf("\n");
}

void ListTraverseBack(DuLinkList L, void(*visit)(ElemType))
{
	//��ʼ������L����
	//�����������ͷ�������������ÿ���������Ԫ�ص��ú���visit()
	DuLNode *p = L->prior;	//pָ����Ԫ���
	while (p != L)			//p��ָ��ͷ���
	{
		(*visit)(p->data);	
		p = p->prior;
	} 
	printf("\n");
}














