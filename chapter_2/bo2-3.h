//bo2-3.h
//����ͷ���ĵ������ֻ���������9����
#define DestroyList ClearList	//û��ͷ���ĵ�������պ�������ͬ���Ĳ���
void InitList(LinkList *L)
{
	//�������������һ���յ����Ա�L
	*L = NULL;	
} 

void ClearList(LinkList *L)
{
	//��ʼ������L�Ѿ�����
	//�����������L�ÿ� 
	LNode *p = *L, *q;
	while(p)		//*L��Ϊ�� 
	{
		q = p;		//qָ����Ԫ��� 
		p = p->next;	//pָ����һ��� ���µ���Ԫ��㣩 
		free(q);		//�ͷ�q��㣨��Ԫ��㣩 
	}
	*L = NULL;
}

Status ListEmpty(LinkList L)
{
	//��ʼ������L����
	//�����������LΪ�ձ�����TRUE�����򷵻�FALSE 
	if(L)
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{
	//��ʼ������L�Ѿ�����
	//�������������L������Ԫ�ظ���
	int i = 0;	//��������ֵΪ0
	LNode *p = L;	//pָ����Ԫ���
	while(p)	//pָ��Ľ�㣨��Ϊ�գ�
	{
		i++;
		p = p->next;
	}
	return i; 
}

Status GetElem(LinkList L, int i, ElemType *e)
{
	//��ʼ������L���ڣ�LΪ����ͷ���ĵ������ͷָ�� 
	//�������������i��Ԫ�ش���ʱ����ֵ����*e������OK�����򷵻�FALSE
	int j = 1;		//��������ֵΪ0 
	LNode *p = L; 	//pָ����Ԫ���
	if(i<1)	//iֵ���Ϸ�
		return ERROR;
	while(p && j<i)		//δ����i��Ԫ�أ�Ҳδ����β
	{
		j++;
		p = p->next;	
	} 
	if(j==i && p)		//���ڵ�i��Ԫ��
	{
		*e = p->data;
		return OK;
	}
	return ERROR;		//�����ڵ�i��Ԫ�ط���ERROR 
}

int LocateElem(LinkList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
	//��ʼ������L���ڣ�LΪָ����Ԫ���ĵ�����ͷָ�룬compare()������Ԫ���ж�����������Ϊ1������Ϊ0
	//�������������L�е�һ�������ϵcompare()������Ԫ�ص�λ�򣬲������򷵻�0
	int j = 1;
	LNode *p = L;
	while(p)	//p��Ϊ��
	{
		if((*compare)(p->data, e))	//�жϵ�ǰp��ָ���������Ԫ���Ƿ��������� 
			return j;				//���㷵�ص�ǰ���λ�� 
		j++;						//��������һ 
		p = p->next;				//pָ����һ��� 
	}
	return 0;		//����������Ԫ�ز����ڷ���0 
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	//��ʼ������L���ڣ�L��ָ��������Ԫ����ͷָ�롣�ڵ�i ��λ��֮ǰ����Ԫ��e
	//�����������i�Ϸ���1<=i<=n+1��,��i��λ�ò���Ԫ��e������OK�����򷵻�ERROR
	int j = 1;		//��������ʼ��1 
	LNode *p = *L, *s;	//pָ����Ԫ��� 
	if(i<1)			//i���Ϸ�
		return ERROR;
	 
	s = (LNode *)malloc(sizeof(LNode));
	if(!s)	//����洢�ռ�ʧ��
		exit(OVERFLOW); 
	s->data = e;	//s������ֵe
	
	if(i==1)	//���ڱ�ͷ
	{
		s->next = *L;	//�½��ָ��ԭ��Ԫ��� 
		*L = s;			//�½���Ϊ��Ԫ��� 
	} 
	else
	{
		//����L����λ��
		while(p && j<i-1)	//Ѱ�ҵ�i-1�����
		{
			j++;
			p = p->next;	
		}
		if(!p)	//i���ڱ���һ
			return ERROR;
		
		s->next = p->next;	//�½��ָ��ԭ��i�����
		p->next = s;		//ԭ��i-1�����ָ���½�� 
	}
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	//��ʼ�������ڲ���ͷ���ĵ�����L�С�
	//�����������iֵ�Ϸ���1<=i<=ListLength(L)����ɾ����i�������*e������ֵ������OK�����򷵻�ERROR
	int j = 1;
	LNode *p = *L, *q;
	
	if(!(*L))		//LΪ�ձ�,�����ڿ���ɾ����Ԫ�� 
		return ERROR;
	if(i==1)	//ɾ����Ԫ���
	{
		*L = p->next;		//*Lָ��ڶ������ 
		*e = p->data;		//����ɾ���Ľ������Ԫ��ֵ����*e 
		free(p);			//ɾ�����ͷŽ�� 
	}
	else
	{
		//ɾ���������
		while(p->next && j<i-1)	 //Ѱ�ҵ�i����㲢��pָ����ǰ��
		{
			p = p->next;
			j++;	
		}
		if(!(p->next) || j>i-1)			//i���Ϸ� 
			return ERROR; 
		q = p->next;			//qָ���ɾ����� 
		*e = q->data;			//����ɾ���������Ԫ�ظ�ֵ��*e 
		p->next = q->next;		//��ɾ������ǰ��ָ���ɾ�����ĺ�� 
		free(q);				//�ͷŴ�ɾ����� 
	} 	
	return OK;
}

void ListTraverse(LinkList L, void(* visit)(ElemType))
{
	//��ʼ������L����
	//�����������visit()������ÿ���������Ԫ�ؽ��в���
	LNode *p = L;		//pָ����Ԫ��� 
	
	while (p)			//p��ָ������ 
	{
		(*visit)(p->data);	//��p��ָ��������Ԫ�ص��ú���visit() 
		p = p->next;		//pָ����һ��� 
	}
	printf("\n");
}












