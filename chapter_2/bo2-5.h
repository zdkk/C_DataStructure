//bo2-5
//��̬�������ݽṹ��c2-3.h���壩�Ļ�������13��������2.13-2.16

#define DestroyList ClearList	//DestroyList��ClearList������ͬ
int Malloc(SLinkList space)	//�㷨2.15
{
	//����������ǿգ��򷵻ط���Ľ���±꣨��������� ��һ����㣩�����򷵻�0
	int i = space[0].cur;	//��������ĵ�һ�����λ��
	if(i)					//��������ǿ� 
	{
		space[0].cur = space[i].cur;	//���������ͷ���ָ��ԭ��������ĵڶ������ 
	}	
	return i;
} 

void Free(SLinkList space, int k)	//�㷨2.16
{
	//���±�Ϊk�Ŀ��н����յ����������У���Ϊ��������ĵ�һ����㣩
	space[k].cur = space[0].cur;	//���ս����α�ָ��������ĵ�һ����� 
	space[0].cur = k;				//���������ͷ���ָ���»��յĽ�� 
} 

void InitList(SLinkList L)			//�㷨2.14 
{
	//�������������һ��������L����ͷΪL�����һ����ԪL[MAX_SIZE - 1],���൥Ԫ����һ������������ͷΪL�ĵ�һ����ԪL[0]��0��ʾ��ָ��
	L[MAX_SIZE - 1].cur = 0;	//��L�����һ����Ԫ��Ϊ�������ͷ��� 
	int i;
	
	for(i=0; i<MAX_SIZE-2; i++)	//�����൥Ԫ������L[0]Ϊͷ���ı������� 
		L[i].cur = i+1;
	L[i].cur = 0;
}

void ClearList(SLinkList L)
{
	//��ʼ������L�Ѿ�����
	//�����������L��Ϊ�ձ�
	//ʵ�ַ�ʽ������������β���ĺ��ָ������������Ԫ��㣬����������ͷ���ָ������� 
	int j, i = L[0].cur;	//iָ����������Ԫ���
	while(i)	//δ����������β�ڵ�
	{
		j = i;			//jָ��ǰ�ڵ� 
		i = L[i].cur;	//iָ����һ��� 
	} 
	L[j].cur = L[MAX_SIZE-1].cur;	//�������Ԫ���ӵ���������β��
	L[MAX_SIZE-1].cur = 0;			//������� 
}

Status ListEmpty(SLinkList L)
{
	//��L�ǿձ���TRUE�����򷵻�FALSE
	if(L[MAX_SIZE-1].cur)			//����ǿգ�����FALSE 
		return FALSE;
	else							//���򷵻�TRUE 
		return TRUE; 
}

int ListLength(SLinkList L)
{
	//����L������Ԫ�ظ���
	int i = 0;
	int j = L[MAX_SIZE - 1].cur;	//jָ��������Ԫ��� 
	while(j)		//δ������ĩβ 
	{
		i++;		//��������һ 
		j = L[j].cur;//jָ����һ����� 
	}
	return i; 
}

Status GetElem(SLinkList L, int i, ElemType *e)
{
	//��e����L�е�i��Ԫ�ص�ֵ������OK�����򷵻�ERROR
	int j = 1, k = L[MAX_SIZE-1].cur;	//kָ����Ԫ���
	
	while (k && j<i)	//˳ʱ�������ң�ֱ��kָ���i������kΪ�գ���i����㲻���ڣ�
	{
		k = L[k].cur;	//kָ����һ���
		j++;			//��������һ 
	}
	if(!k || j>i)		//i���Ϸ�
		return ERROR;
	*e = L[k].data;		//����i��Ԫ�ص�ֵ����*e 
	return OK; 
}

int LocateElem(SLinkList L, ElemType e)	//�㷨2.13
{
	//�ھ�̬����L�в��ҵ�һ��ֵΪe��Ԫ�ء����ҵ�����������L�е�λ�򣬷��򷵻�0
	int i = L[MAX_SIZE-1].cur;	//iָ����Ԫ���
	
	while(i)	//iָ��ǿս��
	{
		if(L[i].data == e)	//���iָ��Ľ������Ԫ�ص�ֵΪe��������λ�� 
			return i;
		i = L[i].cur;		//����iָ����һ��� 
	}	
	return 0;				//û�ҵ�������0 
}

Status PriorElem(SLinkList L, ElemType cur_e, ElemType *pre_e)
{
	//��ʼ������L����
	//�����������cur_e��L������Ԫ���Ҳ��ǵ�һ������pre_e��������ǰ��������OK���������ʧ�ܣ�pre_e�޶��壬����ERROR 
	int i = L[MAX_SIZE-1].cur, j;		//iָ����Ԫ��� 
	while(i && L[i].cur)				//iָ��Ľ���Լ�i�ĺ�̽�㲻Ϊ�� 
	{
		j = L[i].cur;					//jָ��i�ĺ�̽��
		if(L[j].data == cur_e)			//jָ���������Ԫ�ص���cur_e
		{
			*pre_e = L[i].data;			//��iָ��Ľ�������Ԫ�ظ�ֵ��*pre_e 
			return OK;
		}
		i = j;							//iָ����һ��� 
	}
	return ERROR; 
}

Status NextElem(SLinkList L, ElemType cur_e, ElemType *next_e)
{
	//��ʼ������L����
	//�����������cur_e��L������Ԫ���Ҳ������һ������next_e�������ĺ�̣�����OK���������ʧ�ܣ�next_e�޶��壬����ERROR 
	int i = L[MAX_SIZE - 1].cur;		//iָ����Ԫ���
	while(i && L[i].cur)				//iָ��Ľ���Լ�i�ĺ�̽�㲻Ϊ��
	{
		if(L[i].data == cur_e)			//iָ���������Ԫ�ص���cur_e 
		{
			*next_e = L[L[i].cur].data;	//��i�ĺ�̽������Ԫ�ظ���*next_e
			return OK;	 
		}
		i = L[i].cur;					//iָ���̽�� 
	}
	return ERROR; 
}

Status ListInsert(SLinkList L, int i, ElemType e)
{
	//��ʼ������L����
	//�����������L�е�i(1<=i<=ListLength(L)+1)��������Ԫ��e���ɹ�����OK�����򷵻�ERROR 
	int j = 0;	//��������ʼ��0
	int k = MAX_SIZE - 1;	//kָ��ͷ���
	int r = Malloc(L);		//����ռ�
	if(!r)	//û�пռ���ã�����ʧ�� 
		return ERROR;
	L[r].data = e;			//Ϊ�·����������Ԫ�ظ�ֵe 
	
	while (k && j<i-1)		//˳ʱ�������ң�ֱ��kָ���i-1������kΪ�գ���i-1����㲻���ڣ�
	{
		k = L[k].cur;
		j++;
	}
	if (!k || j>i-1)		//i������
		return ERROR;
	
	L[r].cur  =L[k].cur;	//r�ĺ��ָ��ָ��k�ĺ�̽��
	L[k].cur = r;			//k�ĺ�̽��ָ��r 
	return OK; 
}

Status ListDelete(SLinkList L, int i, ElemType *e)
{
	//��ʼ������L����
	//�����������i����(1<=i<=ListLength(L)),��e���ص�i���������Ԫ�أ�����OK�����򷵻�ERROR
	int j = 0;	//��������ʼ��0
	int k = MAX_SIZE - 1;	//kָ��ͷ���
	int r;
	
	while(L[k].cur && j<i-1)	//Ѱ�ҵ�i-1���ڵ㣬����kָ����ǰ��
	{
		k =L[k].cur;			//kָ����һ��� 
		j++;					//��������һ 
	} 
	if(!L[k].cur || j>i-1)		//i������
		return ERROR;
	
	r = L[k].cur;				//rָ���ɾ�����
	*e = L[r].data;				//��e���ش�ɾ���������Ԫ��
	L[k].cur = L[r].cur;		//��ɾ�����ǰ��ָ���ɾ�������
	Free(L, r);					//���մ�ɾ����� 
	return OK; 
}

void ListTraverse(SLinkList L, void(*visit)(ElemType))
{
	//��ʼ������L����
	//������������ζ�Lÿ����������Ԫ�ص���visit����
	int i = L[MAX_SIZE-1].cur;	//iָ����Ԫ���
	while(i)					//iָ��ǿս��
	{
		(*visit)(L[i].data);	//�Ե�ǰ�������Ԫ�ص���visit���� 
		i = L[i].cur;			//iָ����һ��� 
	} 
	printf("\n");
 } 





	 












