//bo6-1.h	���������4�����������������㷨6.1��func8-4.h�ȵ���
#define ClearBiTree DestroyBiTree	//��պ����ٶ������Ĳ���һ��
void InitBiTree(BiTree *T)
{
	//�������������ն����� 
	*T = NULL;	
} 

void DestroyBiTree(BiTree *T)
{
	//��ʼ������������T����
	//������������ٶ�����T
	if(*T)	//�ǿ���
	{
		if ((*T)->lchild)			//�������ǿ� 
			DestroyBiTree(&((*T)->lchild));	//�ݹ�����������
		if ((*T)->rchild)			//�������ǿ� 
			DestroyBiTree(&((*T)->rchild));	//�ݹ�����������
		free(*T);					//�ͷŸ��ڵ� 
		*T = NULL;					//��ָ�븳NULL 
	} 
}

void PreOrderTraverse(BiTree T, void(* Visit)(TElemType))	//6.1 
{
	//��ʼ������������T���ڣ�Visit�Ƕ�ÿ���������ĺ���
	//�������������ݹ����T����ÿ�������ú���Visitһ���ҽ�һ��
	if (T)	//T�ǿ�
	{
		(* Visit)(T->data);		//�ȷ��ʸ����
		PreOrderTraverse(T->lchild, Visit);	//���������������
		PreOrderTraverse(T->rchild, Visit);	//���������������� 
	} 
}

void InOrderTraverse(BiTree T, void(* Visit)(TElemType))
{
	//��ʼ������������T���ڣ�Visit�Ƕ�ÿ���������ĺ��� 
	//����������������T����ÿ�������ú���Visitһ���ҽ�һ��
	if(T)
	{
		InOrderTraverse(T->lchild, Visit);	//���������������
		(* Visit)(T->data);					//�ٷ��ʸ��ڵ�
		InOrderTraverse(T->rchild, Visit);	//����������������	
	} 
}






























