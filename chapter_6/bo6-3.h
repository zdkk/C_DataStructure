//bo6-3.h ���Ķ�����������-�ֵܣ��洢�ṹ��c6-2.h���壩�Ļ�������(16��) 
#define ClearTree DestroyTree	//���߲�����ͬ
void InitTree(CSTree *T)
{
	//����������������T 
	* T = NULL;	
}
void DestroyTree(CSTree * T)
{
	//��ʼ��������T���ڣ����������������T
	if (*T) //�ǿ��� 
	{
		DestroyTree(&(*T)->firstchild);	//�ݹ�����T�ĳ���Ϊ���ڵ������
		DestroyTree(&(*T)->nextsibling);//�ݹ�����T����һ���ֵ�Ϊ���ڵ������
		free(*T);	//�ͷŸ��ڵ�
		*T = NULL; 
	} 
}

typedef CSTree QElemType;	//�������Ԫ������Ϊ ����-�ֵܶ��������ָ������
#include "../chapter_3/c3-2.h"	//����LinkQueue���ͣ������У�
#include "../chapter_3/bo3-2.h"	//LinkQueue���͵Ļ�������
void CreateTree(CSTree * T)
{
	char c[20];	//��ʱ��ź��ӽ�㣨�費����20������ֵ����һ�������ӽ�㲻����20�� 
	CSTree p, p1;
	LinkQueue q;
	int i, m;
	
	InitQueue(&q);	//��ʼ������q
	printf("��������ڵ�����(�ַ���, #Ϊ��)");
	scanf("%c", &c[0]);	//������ڵ��ֵ��֮���ֵ������
	while (getchar() != '\n')
		continue;
	if (c[0] != Nil)	//�ǿ���
	{
		*T = (CSTree)malloc(sizeof(CSNode));	//�������ڵ�
		if (!(*T))
		{
			fprintf(stderr, "�������ڵ�ʧ�ܣ��˳�����\n");
			exit(OVERFLOW);
		}
		(*T)->data = c[0];						//���ڵ㸳ֵ
		(*T)->nextsibling = NULL;				//���ڵ�û����һ���ֵܣ���ֵNULL
		EnQueue(&q, *T);						//��Ӹ��ڵ��ָ��	
		while (!QueueEmpty(q))				//���в�Ϊ��
		{
			DeQueue(&q, &p);						//����һ������ָ��
			printf("�밴����˳��������%c�����к���: ", p->data);
			//����ȫ��gets���� 
			gets(c);	 						//���������к�����Ϊ�ַ������� 
			m = strlen(c);						//�ӽ�����Ϊm
			if (m > 0)							//�к���
			{
				p1 = p->firstchild = (CSTree)malloc(sizeof(CSNode));	//�������ӽ��
				if (!p1)
				{
					fprintf(stderr, "���ӽ�㴴��ʧ��,�����˳�\n");
					exit(OVERFLOW);
				}
				p1->data = c[0];				//�����ӽ�㸳ֵ
				EnQueue(&q, p1);				//���p1����ָ��
				for (i = 1; i < m; i++)			//���ڳ����������������
				{
					p1->nextsibling = (CSTree)malloc(sizeof(CSNode));	//������һ���ֵܽ��
					p1 = p1->nextsibling;		//p1ָ����һ���ֵܽ�� 
					if (!p1)
					{
						fprintf(stderr, "�ֵܽ�㴴��ʧ��,�����˳�\n");
						exit(OVERFLOW);
					}
					p1->data = c[i];			//��p1��ָ��㸳ֵ 
					EnQueue(&q, p1);			//���p1����ָ��	
				}
				p1->nextsibling = NULL;			//���һ���ӽ��û����һ���ֵ� 
			}//endif(m>0)
			else
				p->firstchild = NULL;			//û���ӽ�� 
		}//end while
	}//endif(c[0] = Nil)								//���� 
}
Status TreeEmpty(CSTree T)
{
	//��ʼ��������T���ڣ����Ѿ�ִ�й�InitTree����CreateTree 
	//�������������TΪ����������TRUE�����򷵻�FALSE
	if (T)
		return FALSE;
	else
		return TRUE; 
}
int TreeDepth(CSTree T)
{
	//��ʼ��������T����
	//�������������T�����
	CSTree p;
	int depth, max = 0;
	
	if (!T)	//�ݹ���������������ǿ��������Ϊ0 
		return 0; 
	for (p = T->firstchild; p; p = p->nextsibling)	//����T��ָ���������ӽ�� 
	{
		//��������ȵ����ֵ
		depth = TreeDepth(p);	//�ݹ����ӽ������depth
		if (depth > max)
			max = depth; 
	}
	return max + 1;				//������� = ����������ֵ + 1�� 
}
TElemType Value(CSTree p)
{
	//����p��ָ����ֵ
	return p->data; 
}
TElemType Root(CSTree T)
{
	//��ʼ��������T����
	//�������������T�ĸ�
	if (T)	//���ڵ�ǿ�
		return T->data;
	else
		return Nil; 
}
CSTree Point(CSTree T, TElemType s)
{
	//���ض�����������-�ֵܣ���T��ָ��Ԫ��ֵΪs�Ľ���ָ��
	LinkQueue q;
	QElemType a;
	
	if (T)	//�ǿ���
	{
		InitQueue(&q);			//��ʼ������
		EnQueue(&q, T);			//���ڵ�ָ�����
		while (!QueueEmpty(q))	//���в�Ϊ��
		{
			DeQueue(&q, &a);	//���ӣ�����Ԫ�ظ�ֵ��a	
			if (a->data == s)	//�ҵ�Ԫ��ֵΪs�Ľ�� 
				return a; 		//����ָ�����ָ��
			if (a->firstchild)	//�г���
				EnQueue(&q, a->firstchild);	//���ָ���ӵ�ָ�� 
			if (a->nextsibling)	//����һ���ֵ�
				EnQueue(&q, a->nextsibling); //���ָ����һ���ֵܵ�ָ�� 
		}	
	} 
	return NULL;
}

Status Assign(CSTree T, TElemType cur_e, TElemType value)
{
	//��ʼ��������T����,cur_e�����н���ֵ
	//�����������cur_eΪvalue 
	CSTree p;
	
	if (T)	//�ǿ���
	{
		p = Point(T, cur_e);
		if (p)	//p��Ϊ��
		{
			p->data = value; 
			return OK;
		}
	}
	return ERROR;		//���ջ�δ�ҵ�ָ����� 
} 
TElemType Parent(CSTree T, TElemType cur_e)
{
	//��ʼ��������T���ڣ�cur_e��T��ĳ�����
	//�����������cur_e��T�ķǸ���㣬�򷵻�����˫�ף����򷵻ء��ա�
	CSTree p, t;
	LinkQueue q;
	
	InitQueue(&q);	//��ʼ������
	if (T)			//���ǿ� 
	{
		if (Value(T) == cur_e)	//�����ֵΪcur_e
			return Nil;
		EnQueue(&q, T);			//�����ָ�����
		while (!QueueEmpty(q))
		{
			DeQueue(&q, &p);	//����Ԫ�أ�ָ�룩����p
			if (p->firstchild)	//p��ָ����г���
			{
				if (Value(p->firstchild) == cur_e)	//��������Ϊcur_e
					return Value(p);
				t = p;								//˫��ָ�븳��t
				p = p->firstchild;					//pָ����
				EnQueue(&q, p);						//����ָ�����
				while (p->nextsibling)				//p����һ���ֵ�
				{
					p = p->nextsibling;
					if (Value(p) == cur_e)			//��һ���ֵ�����Ϊcur_e 
						return Value(t);			//����˫�׵�ֵ
					EnQueue(&q, p);					//�����һ���ֵ� 
				}		
			} 
		} 
	}
	return Nil;										//û�ҵ������� 
}
TElemType LeftChild(CSTree T, TElemType cur_e)
{
	//��ʼ��������T����
	//������������cur_e��T�ķ�Ҷ��㣬�������� �����ӣ� ���򷵻ء��ա� 
	CSTree p;
	
	p = Point(T, cur_e);
	if (p && p->firstchild)
		return Value(p->firstchild);
	else
		return Nil;
}
TElemType RightSibling(CSTree T, TElemType cur_e)
{
	//��ʼ��������T���ڣ�cur_e������ĳ������ֵ
	//�����������cur_e��������ֵܣ��򷵻��������ֵܽ���ֵ�����򷵻ء��ա�
	CSTree p;
	
	p = Point(T, cur_e);
	if (p && p->nextsibling)
		return Value(p->nextsibling);
	else
		return Nil;
}
Status InsertChild(CSTree *T, CSTree p, int i, CSTree c)
{
	//��ʼ��������T���ڣ�pָ��T��ĳ����㣬1<=i<=p��ָ���Ķ�+1, �ǿ���c��T���ཻ
	//�������������cΪT��p���ĵ�i����������Ϊp��ָ���ĵ�ַ����ı䣬��p����Ҫ�����ַ
	int j;
	CSTree q;
	
	if (*T)		//T�ǿ�
	{
		if (i == 1)	//����cΪp�ĳ��� 
		{
			c->nextsibling = p->firstchild;		//p��ԭ������c�����ֵ� 
			p->firstchild = c;					//p�ĳ���ָ��ָ��c 
		}	
		else		//c����p�ĳ���
		{
			q = p->firstchild;					//qָ��p�ĳ��ӽ��
			j = 2;
			while (q && j < i)					//�ҵ�c�Ĳ���㲢��qָ��
			{
				q = q->nextsibling;
				j++;	
			}
			if (j == i)							//�ҵ�����λ��
			{
				c->nextsibling = q->nextsibling;//c�����ֵ�ָ��p��ԭ��i������
				q->nextsibling = c;				//��p�в���c��Ϊp�ĵ�i������	
			} 
			else
				return ERROR;
		}
		return OK;
	}
	else
		return ERROR;
}
Status DeleteChild(CSTree *T, CSTree p, int i)
{
	//��ʼ��������T���ڣ�pָ��T��ĳ����㣬1 <= i <= p��ָ���Ķ���
	//���������ɾ��T��p��ָ���ĵ�i������
	CSTree b, q;
	int j;
	
	if (*T)	//T�ǿ�
	{
		if (i == 1)	//ɾ������
		{
			b = p->firstchild;		//bָ��p�ĳ��ӽ��
			p->firstchild = b->nextsibling;	//p��ԭ���ӳ�Ϊ����
			b->nextsibling = NULL;
			DestroyTree(&b);		//����bָ���ԭ���ӽ������ 
		}	
		else	//ɾ���ǳ��� 
		{
			q = p->firstchild;		//qָ���ӽ��
			j = 2;
			while (q && j < i)		//�ҵ���i������
			{
				q = q->nextsibling;
				j++;
			}
			if (j == i)	//�ҵ���i������ 
			{
				b = q->nextsibling;	//bָ���ɾ������
				q->nextsibling = b->nextsibling;
				b->nextsibling = NULL;
				DestroyTree(&b); 
			}
			else
				return ERROR;
		}
		return OK;
	}
	return ERROR;
}

void PostOrderTraverse(CSTree T, void (* Visit)(TElemType))
{
	//�����������-�ֵܶ�������ṹ����T
	CSTree p;
	
	if (T)
	{
		if (T->firstchild)	//�г���
		{
			PostOrderTraverse(T->firstchild, Visit);	//�������������
			p = T->firstchild->nextsibling;				//pָ���ӵ���һ���ֵ�
			while (p)									//������һ���ֵ�
			{
				PostOrderTraverse(p, Visit);			//���������һ���ֵ�����
				p = p->nextsibling;	
			}
		}
		Visit(Value(T));								//�����ʸ��ڵ� 
	}
}
void LevelOrderTraverse(CSTree T, void (* Visit)(TElemType))
{
	//�����������-�ֵܶ�������ṹ����T
	CSTree p;
	LinkQueue q;
	
	InitQueue(&q);	//��ʼ������
	if (T)			//���ǿ�
	{
		Visit(Value(T));
		EnQueue(&q, T);		//��Ӹ����ָ��
		while (!QueueEmpty(q))
		{
			DeQueue(&q, &p);	//����һ������ָ��
			if (p->firstchild)	//p�г���
			{
				Visit(Value(p->firstchild));
				EnQueue(&q, p->firstchild);	//���ӽ��ָ�����
				p = p->firstchild->nextsibling;
				while (p)					//����һ���ֵ�
				{
					Visit(Value(p));		//���ʸý��
					EnQueue(&q, p);			//����ֵܽ��
					p = p->nextsibling;		//pָ����һ���ֵܽ��	
				}
			}	
		}	
	}
	printf("\n");
}













































