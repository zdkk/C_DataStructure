//bo2-1.h
//˳��洢�����Ա�˳��洢�ṹ��c2-1.h���壩�Ļ���������12���������㷨2.3-2.6

void InitList(SqList *L)	//�㷨2.3
{
	//�������������һ���յ�˳���L
	L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if(!L->elem)					//�洢�ռ����ʧ�� 
		exit(OVERFLOW);
	L->length = 0;					//�ձ���Ϊ0 
	L->listsize = LIST_INIT_SIZE;	//��ʼ�洢����	
} 

void DestroyList(SqList *L)
{
	//��ʼ������˳���L�Ѿ�����
	//����������������Ա�L
	free(L->elem);		//�ͷ�L->elem��ָ�Ĵ洢�ռ� 
	L->elem = NULL;		//L->elem����ָ���κδ洢��Ԫ 
	L->length = 0;
	L->listsize = 0; 
 } 
void ClearList(SqList *L)
{
	//��ʼ���������Ա�L�Ѿ�����
	//�����������L��Ϊ�ձ�
	L->length = 0;
	return; 
}

Status ListEmpty(SqList L)
{
	//��ʼ���������Ա�L�Ѿ�����
	//�����������LΪ�ձ�����TRUE�����򷵻�FALSE
	if(L.listsize == 0)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L)
{
	//��ʼ���������Ա�L�Ѿ�����
	//�������������L������Ԫ�صĸ���
	return L.length; 
}

Status GetElem(SqList L, int i, ElemType *e)
{
	//��ʼ������˳���L�Ѿ����ڣ�1<=i<=ListLength(L)
	//�����������e����L�е�i������Ԫ�ص�ֵ
	if(i<1 || i>L.length)
		return ERROR;
	*e = L.elem[i-1];
	return OK; 
}

int LocateElem(SqList L, ElemType e, Status(* compare)(ElemType, ElemType))
//������һ��ָ�����compare����ָ���������ָ�򷵻�ֵ����Ϊ Status �ͣ���������ElemType�����ĺ���. 
{
	//��ʼ������˳���L�Ѿ����ڣ�compare()������Ԫ���ж�����������Ϊ1������Ϊ0��
	//�������������L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��
	//������������Ԫ�ز����ڣ��򷵻�0
	int i = 1;	//i�ĳ�ʼֵΪ��һ��Ԫ�ص�λ��
	ElemType *p = L.elem;	//p�ĳ�ʼֵΪ��һ��Ԫ�صĴ洢λ��
	
	while (i<=L.length && !((*compare)(*p,e)))	//(*compare)(*p,e)��ͨ������ָ�����compare��������compare�ǵ����ߴ������ĺ���ָ�� 
	{
		i++;
		p++;
	}
	if(i <= L.length)	//�ҵ������ϵ������Ԫ��
		return i;
	else				//δ�ҵ������ϵ������Ԫ�� 
		return 0; 
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
	//��ʼ������L�Ѿ�����
	//�����������cur_e��L������Ԫ���Ҳ��ǵ�һ������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
	int i = 2;					//�ӵڶ���Ԫ�ؿ�ʼ 
	ElemType *p = L.elem + 1;	//pָ��ڶ���Ԫ��
	
	while (i<=L.length && (*p)!=cur_e)
	{
		i++;	//��������1 
		p++;	//pָ����һԪ�� 
	}
	if(i<=L.length)	//�ҵ���cur_eԪ�أ�����pָ���� 
	{
		p--;			//pָ��cur_eǰһ��Ԫ�� 
		*pre_e = *p;	//��pre_e����pָ���Ԫ�� 
		return OK;
	}
	else
		return ERROR;
	 
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
	//��ʼ������L�Ѿ�����
	//�����������cur_e��L������Ԫ���Ҳ������һ������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶���
	int i = 1;
	ElemType *p = L.elem;
	
	while (i<=L.length-1 && (*p)!=cur_e)
	{
		p++;
		i++;
	}
	if (i == L.length)
		return ERROR;
	else
	{
		p++;
		*next_e = *p;
		return OK;
	}
}

Status ListInsert(SqList *L, int i, ElemType e)	//�㷨2.4 
{
	//��ʼ������L�Ѿ����ڣ�1<=i<=ListLength(*L)+1
	//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e,L�ĳ��ȼ�1
	ElemType *newbase, *q, *p;
	
	if(i<1 || i>L->length+1)		//����λ�ò��Ϸ� 
		return ERROR;
	
	if(L->length == L->listsize)	//��ǰ�洢�ռ����������ӷ��䣬�޸�
	{
		newbase = (ElemType *)realloc(L->elem, (L->listsize+LIST_INCREMENT)*sizeof(ElemType));
		if(!newbase)	//�洢����ʧ��
			exit(OVERFLOW);
		L->elem = newbase;	//�޸�L->elem�ĵ�ַ
		L->listsize += LIST_INCREMENT;	//���Ӵ洢����	
	}	
	
	q = L->elem + i -1;		//qΪ����λ��
	for(p=L->elem+L->length-1; p>=q; p--)
	{
		*(p+1) = *p;
	}
	*q = e; 
	L->length++;	//����һ 
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)	//�㷨2.5 
{
	//��ʼ������L���ڣ�1<=i<=ListLength(*L)
	//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�һ 
	ElemType *p, *q;
	
	if(i<1 || i>L->length)		//iֵ���Ϸ� 
		return ERROR;
	
	p = L->elem + i - 1;		//pΪҪɾ��Ԫ�ص�ָ��
	*e = *p;					//��e���ؽ���ɾ��Ԫ�ص�ֵ 
	q = L->elem + L->length -1;	//qָ���βԪ�� 
	for(; p<q; p++)
	{
		*p = *(p+1);
	}
	
	L->length--;				//����һ
	return OK; 
}

void ListTraverse(SqList L, void(* visit)(ElemType *))
{
	//��ʼ������L�Ѿ�����
	//������������ζ�L��ÿ������Ԫ�ص���visit������visit���������޸�Ԫ�ص�ֵ�� 
	ElemType *p = L.elem;
	int i;
	
	for(i=0; i<L.length; i++)
	{
		(*visit)(p+i);
	}
	printf("\n");
}












