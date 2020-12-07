//bo6-2.h	���������洢�ṹ��c6-1.h���壩�Ļ�������18���������㷨6.2-6.4
Status BiTreeEmpty(BiTree T)
{
	//��ʼ������������T����
	//�����������TΪ�ն�����������TRUE�����򷵻�FALSE
	return T ? FALSE : TRUE;  
}
int BiTreeDepth(BiTree T)
{
	//��ʼ������������T����
	//�������������T�����
	int i, j;
	if (!T)
		return 0;	//�������Ϊ0
	i = BiTreeDepth(T->lchild);	//iΪ��������ȣ����������Ϊ�գ���iΪ0
	j = BiTreeDepth(T->rchild);	//jΪ��������ȣ����������Ϊ�գ���jΪ0
	return i > j ? i+1 : j+1; 	//T�����Ϊ����������������еĴ��߼�һ 
}
TElemType Root(BiTree T)
{
	if (BiTreeEmpty(T))	//������Ϊ��
		return Nil;		//���ء��ա� 
	else				//��������Ϊ�� 
		return T->data; //���ظ��ڵ��ֵ 
}
TElemType Value(BiTree p)
{
	//��ʼ������������T���ڣ�pָ��T��ĳ�����
	//�������������p��ָ����ֵ
	return p->data; 
}
void Assign(BiTree p,TElemType value)
{
	//��ʼ������������T���ڣ�pָ��T��ĳ�����
	//�����������p��ָ��㸳ֵΪvalue 
	p->data = value;
}

typedef BiTree QElemType;	//�������Ԫ��Ϊ��������ָ������
#include "../chapter_3/c3-2.h"	//������
#include "../chapter_3/bo3-2.h"	//�����еĻ�������
BiTree Point(BiTree T, TElemType s)
{
	//��ʼ������������T����
	//�������������T��ָ��Ԫ��ֵΪs�Ľ���ָ��
	LinkQueue q;
	QElemType a;
	if(T)	//�ǿ���
	{
		InitQueue(&q);	//��ʼ������
		EnQueue(&q, T);	//��ָ�����
		while (!QueueEmpty(q))	//���в�Ϊ��
		{
			DeQueue(&q, &a);	//���ӣ�����Ԫ�ظ���a
			if (a->data == s)	//a��ָ���ֵΪs
			{
				DestroyQueue(&q);	//���ٶ���
				return a;			//����a	
			}
			if (a->lchild)			//������
				EnQueue(&q, a->lchild);	//�������
			if (a->rchild)			//���Һ���
				EnQueue(&q, a->rchild);	//�Һ������ 
		}
		DestroyQueue(&q);			//���ٶ��� 
	}
	return NULL;					//��������û��Ԫ��ֵΪs�Ľ�� 
}
TElemType LeftChild(BiTree T, TElemType e)
{
	//��ʼ������������T���ڣ�e��T��ĳ�����Ԫ��ֵ
	//�������������e������Ԫ��ֵ����e�����ӣ��򷵻ؿ�
	BiTree a;
	if(T)	//�ǿ���
	{
		a = Point(T, e);	//a��ָ����e��ָ��
		if (a && a->lchild)	//T�д��ڽ��e��e��������
			return a->lchild->data;	//����e�����ӵ�ֵ	
	}
	return Nil;				//����������ء��ա� 
}
TElemType RightChild(BiTree T, TElemType e)
{
	//��ʼ������������T���ڣ�e��T��ĳ�����Ԫ��ֵ
	//�������������e���Һ���Ԫ��ֵ����e���Һ��ӣ��򷵻ؿ�
	BiTree a;
	if(T)	//�ǿ���
	{
		a = Point(T, e);	//a��ָ����e��ָ��
		if (a && a->rchild)	//T�д��ڽ��e��e�����Һ���
			return a->rchild->data;	//����e���Һ��ӵ�ֵ	
	}
	return Nil;				//����������ء��ա� 
}
Status DeleteChild(BiTree p, int LR)
{
	//��ʼ������������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1
	//�������������LRΪ0��1ɾ��T��p��ָ�������������
	if (p)	//p�ǿ�
	{
		if(LR == 0)	//ɾ��������
			ClearBiTree(&p->lchild);	//���p��ָ����������
		else if(LR == 1)	//ɾ��������
			ClearBiTree(&p->rchild);	//���p��ָ����������
		return OK;
	}
	return ERROR;			//pΪ�շ���ERROR 
}
void PostOrderTraverse(BiTree T, void(* Visit)(TElemType))
{
	//��ʼ������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
	//����������������T����T��ÿ�������ú���Visitһ���ҽ�һ��
	if (T)	//T�ǿ�
	{
		PostOrderTraverse(T->lchild, Visit);	//�Ⱥ������������
		PostOrderTraverse(T->rchild, Visit);	//�ٺ������������
		(* Visit)(T->data);						//�����ʸ����	
	}
}
void LevelOrderTraverse(BiTree T, void(* Visit)(TElemType))
{
	//��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
	//�������������ݹ����T�����ö��У���ÿ�������ú���Visitһ���ҽ�һ��
	LinkQueue q;
	QElemType a;
	if (T)	//T�ǿ�
	{
		InitQueue(&q);		//��ʼ��������
		EnQueue(&q, T);		//��ָ�������
		while (!QueueEmpty(q))	//���зǿ�
		{
			DeQueue(&q, &a);	//����Ԫ�أ�ָ�룩������a
			if (a->lchild)		//���ӷǿ�
				EnQueue(&q, a->lchild);	//�������
			if (a->rchild)		//�Һ��ӷǿ�
				EnQueue(&q, a->rchild);	//�Һ������
			(* Visit)(a->data);	//����a��ָ���		 
		}
		printf("\n");
		DestroyQueue(&q);		//���ٶ���q 
	} 
}
void CreateBiTree(BiTree *T)	//�㷨6.4 
{
	//�������������������еĽ��ֵ����Ϊ�ַ����ͻ����ͣ����������ж��壩
	//������������ʾ�Ķ�����T������Nil��ʾ�գ��ӣ���
	TElemType ch;
	scanf(form,&ch);	//�������ֵ
	if (ch == Nil)		//���ֵΪ��
		*T = NULL;		
	else				//���ֵ�ǿ�
	{
		*T = (BiTree)malloc(sizeof(BiTNode));	//���ɸ����
		if (!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;//��ֵ����T��ָ���
		CreateBiTree(&(*T)->lchild);			//�ݹ鹹�������� 
		CreateBiTree(&(*T)->rchild); 			//�ݹ鹹�������� 
	}
}
TElemType Parent(BiTree T, TElemType e)
{
	//��ʼ������������T���ڣ�e��T��ĳ�����
	//�����������e�ǷǸ��ڵ㣬�򷵻�����˫�ף����򷵻ء��ա�
	LinkQueue q;
	QElemType a;
	if (T)	//�ǿ���
	{
		InitQueue(&q);	//��ʼ������
		EnQueue(&q, T);	//����ָ�����
		while (!QueueEmpty(q))	//���в�Ϊ��
		{
			DeQueue(&q, &a);	//���ӣ�����Ԫ�ظ�ֵ��a
			if (a->lchild && a->lchild->data == e || a->rchild && a->rchild->data == e)	//�ҵ�e
				return a->data;	//����˫��ֵ
			else				//δ�ҵ�e
			{
				if (a->lchild)	//a������
					EnQueue(&q, a->lchild);	//����ָ�����
				if (a->rchild)	//a���Һ���
					EnQueue(&q, a->rchild);	//�Һ���ָ�����	
			}	
		} 
	}
	return Nil;		//��Ϊ�ջ�δ�ҵ�e 
}

TElemType LeftSibling(BiTree T, TElemType e)		//�˺����е����� 
{
	//��ʼ������������T���ڣ�e��T��ĳ�����
	//�������������e�����ֵܡ���e��T�����ӻ������ֵܣ����ء��ա�
	TElemType a;
	BiTree p;
	if (T)	//�ǿ���
	{
		a = Parent(T,e);	//aΪe��˫��
		if (a != Nil)		//�ҵ�e��˫��
		{
			p = Point(T, a);	//pΪָ����a��ָ��
			if (p->lchild && p->rchild && p->rchild->data == e)	//p�������Һ������Һ�����e
				return p->lchild->data;							//����p�����ӣ�e�����ֵܣ�	
		}
	}
	return Nil;					//����������ء��ա� 
}
TElemType RightSibling(BiTree T, TElemType e)		//�˺����е����� 
{
	//��ʼ������������T���ڣ�e��T��ĳ�����
	//�������������e�����ֵܡ���e��T���Һ��ӻ������ֵܣ����ء��ա�
	TElemType a;
	BiTree p;
	if (T)	//�ǿ���
	{
		a = Parent(T,e);	//aΪe��˫��
		if (a != Nil)		//�ҵ�e��˫��
		{
			p = Point(T, a);	//pΪָ����a��ָ��
			if (p->lchild && p->rchild && p->lchild->data == e)	//p�������Һ������Һ�����e
				return p->rchild->data;							//����p�����ӣ�e�����ֵܣ�	
		}
	}
	return Nil;					//����������ء��ա� 
}

Status InsertChild(BiTree p, int LR, BiTree c)
{
	//��ʼ������������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1���ǿն�����c��T���ཻ��������Ϊ��
	//�������������LRΪ0��1������cΪT��p��ָ���������������p��ָ����ԭ��������������Ϊc��������
	if (p)	//p�ǿ�
	{
		if (LR == 0)	//�Ѷ�����c��Ϊp��ָ����������
		{
			c->rchild = p->lchild;	//p��ָ����ԭ��������Ϊc��������
			p->lchild = c;			//������c��Ϊp��������	
		}
		else			//�Ѷ�����c��Ϊp��ָ���������� 
		{
			c->rchild = p->rchild;	//p��ָ����ԭ��������Ϊc��������
			p->rchild = c;			//������c��Ϊp�������� 
		}
		return OK;
	}
	return ERROR;					//pΪ�� 
}

typedef BiTree SElemType;	//����ջԪ��Ϊ��������ָ������
#include "../chapter_3/c3-1.h"	//˳��ջ
#include "../chapter_3/bo3-1.h"	//˳��ջ�Ļ������� 

void InOrderTraverse1(BiTree T, void(* Visit)(TElemType))	//�㷨6.3 
{
	//���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú��� 
	//�������������T�ķǵݹ��㷨��ʹ��ջ������ÿ������Ԫ�ص��ú���Visit
	SqStack S;
	InitStack(&S);	 //��ʼ��ջS
	while (T || !StackEmpty(S))	//��������T��Ϊ�ջ�ջ�ǿ�
	{
		if (T)	//�������ǿ�
		{
			//��ָ���ջ������������
			Push(&S, T);			//��ָ����ջ 
			T = T->lchild;		//Tָ�������� 
		}
		else	//��ָ���ջ�����ʸ��ڵ㣬���������� 
		{
			Pop(&S, &T);			//��ջ��ָ��
			(*Visit)(T->data);	//���ʸ��ڵ�
			T = T->rchild;		//Tָ�����Һ��� 
		}
	}
	printf("\n");
	DestroyStack(&S);			//����ջS 
}
void InOrderTraverse2(BiTree T, void(* Visit)(TElemType))	//�㷨6.2 
{
	//���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú��� 
	//�������������T�ķǵݹ��㷨��ʹ��ջ������ÿ������Ԫ�ص��ú���Visit
	SqStack S;
	BiTree p;
	InitStack(&S);
	Push(&S,T);	//��ָ���ջ�������Ƿ�Ϊ��
	while (!StackEmpty(S))	//S�ǿ�
	{
		while (GetTop(S, &p) && p)	//ջ��Ԫ�ز�Ϊ��ָ��
			Push(&S, p->lchild);		//�����ߵ���ͷ����ջ����ָ��
		Pop(&S, &p);					//��ָ���ջ
		if (!StackEmpty(S))			//���ʽ�㣬����һ��
		{
			Pop(&S, &p);				//����ջ��Ԫ�أ��ǿ�ָ�룩
			(*Visit)(p->data);		//���ʸոյ����Ľ�㣨Ŀǰջ��Ԫ�ص����ӣ�
			Push(&S, p->rchild);		//��ջ�Һ���ָ��	
		}	
	}
	printf("\n");
	DestroyStack(&S);				//����ջS 
}
int NodeCount(BiTree T)
{
	//������������ض�����T�н�����
	if (!T)	//TΪ��
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1; 
}
int NodeCount_0(BiTree T)
{
	//ͳ�����ж�Ϊ0�Ľ�㣨��Ҷ��㣩����
	if (T)	//T�ǿ�
	{
		if (T->lchild == NULL && T->rchild == NULL)
			return 1;
		else
			return NodeCount_0(T->lchild) + NodeCount_0(T->rchild);
	}
	else
		return 0; 
}
int NodeCount_1(BiTree T)
{
	//ͳ�����ж�Ϊ1�Ľ�����
	if (T)	//T�ǿ�
	{
		if ((T->lchild && T->rchild == NULL) || (T->lchild == NULL && T->rchild))
			return 1 + NodeCount_1(T->lchild) + NodeCount_1(T->rchild);
		else
			return NodeCount_1(T->lchild) + NodeCount_1(T->rchild);
	}
	else
		return 0; 
}
int NodeCount_2(BiTree T)
{
	//ͳ�����ж�Ϊ2�Ľ�����
	if (T)	//T�ǿ�
	{
		if (T->lchild && T->rchild)
			return 1 + NodeCount_2(T->lchild) + NodeCount_2(T->rchild);
		else
			return NodeCount_2(T->lchild) + NodeCount_2(T->rchild);
	}
	else
		return 0; 
}













