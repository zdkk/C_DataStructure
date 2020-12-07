//bo8-2.h �����������Ļ�������(4��)�������㷨9.5(b)���㷨9.6~�㷨9.8

Status SearchBST(BiTree *T, KeyType key, BiTree f, BiTree *p)
{
	//�ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ������ҳɹ�����p����ָ�������Ԫ�ؽ���ָ�룬������TRUE
	//����ָ��pָ�����·���Ϸ��ʵ����һ����㣬������FALSE��ָ��fָ��T��˫�ף����ʼ����ֵΪNULL
	if (*T == NULL)	//*TΪ��ָ��
	{
		*p = f;		//δ�ҵ���*pָ��˫�׽��f
		return FALSE;	
	}
	else if EQ((*T)->data.key, key)//��ǰ���*T�Ĺؼ��ֵ���key
	{
		*p = *T;	//�ҵ��� *pָ��ǰ���*T 
		return TRUE;	
	}
	else if LT(key, (*T)->data.key)
		return SearchBST(&(*T)->lchild, key, *T, p);
	else
		return SearchBST(&(*T)->rchild, key, *T, p); 
}
Status InsertBST(BiTree *T, ElemType e)
{
	//��������������Tû�йؼ��ֵ���e.key��Ԫ�أ�����e������TRUE�����򷵻�FALSE 
	BiTree p, s;
	
	if (SearchBST(T, e.key, NULL, &p) == FALSE)	//���Ҳ��ɹ�������룬��ʱpָ�����·���Ϸ��ʵ����һ����� 
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		
		if (p == NULL)	//ԭ����������Ϊ����
			*T = s;
		else if LT(e.key, p->data.key)	//�ؼ���С��˫�׽��ؼ��֣����������
			p->lchild = s;
		else
			p->rchild = s; 
		return TRUE;
	}
	else
		return FALSE;
}
void Delete(BiTree *p)
{
	//�Ӷ�����������ɾ��p��ָ��㣬���ؽ��������������	�㷨9.8
	BiTree s, q = *p;	//qָ���ɾ�����
	
	if ((*p)->rchild == NULL)	//��ɾ�����û����������ֻ���ؽ���������û��������Ҳ��������֧��
	{
		*p = (*p)->lchild;
		free(q);	
	}
	else if ((*p)->lchild == NULL)	//��ɾ�����û����������ֻ���ؽ�������
	{
		*p = (*p)->rchild;
		free(q);	
	}
	else			//��ɾ�����������������������ǽ������������Ĺؼ��ֽ������Ԫ�ط��ڵ�ǰ��� 
	{
		s = (*p)->lchild;	//sָ���ɾ����������
		while (s->rchild)	//s���Һ���
		{
			q = s;
			s = s->rchild;	
		}		//s�����ߵ���ͷ��sָ���ɾ������ǰ���ڵ㣬qָ��s��˫�׽�㣨ʼ�գ���
		(*p)->data = s->data; 
		if (q == (*p))	//��ɾ����������û��������
			q->lchild = s->lchild;
		else			//��ɾ������������������ 
			q->rchild = s->lchild;
		free(s);
	}
}
Status DeleteBST(BiTree *T, KeyType key)
{
	//������������T�д��ڹؼ��ֵ���key������Ԫ��ʱɾ��������Ԫ�����ڽ�㲢����TRUE�����򷵻�FALSE �㷨9.7 
	if ((*T) == NULL)	//��Ϊ��
		return FALSE;
	else
	{
		if EQ(key, (*T)->data.key)	//�ؼ��ֵ��ڵ�ǰ���Ĺؼ���
		{
			Delete(T);				//ɾ���ý�㣬��ʱ�������һ��ָ�����ָ���ָ�룬��ָ�����ָ��Ϊ˫�׽�����/��ָ�루��� 
			return TRUE;	
		}
		else if LT(key, (*T)->data.key)//�ؼ���С�ڵ�ǰ���ؼ���
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key); 
	}
}




















