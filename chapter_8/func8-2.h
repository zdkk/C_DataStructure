//func8-2.h  ��������Ԫ�����͵Ķ����Լ������Ĳ���
typedef int KeyType;	//����ؼ���Ϊ����
typedef struct
{
	KeyType key;	//���йؼ����� 
}ElemType;
void Visit(ElemType c)
{
	printf("%d ", c.key);
}
void InputFromFile(FILE *f, ElemType *c)
{
	fscanf(f, "%d", &c->key);
}
void InputFromKey(KeyType *c)
{
	scanf("%d", c);
}
