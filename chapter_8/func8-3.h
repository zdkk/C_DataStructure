//func8-3.h	��������Ԫ�����͵Ķ����Լ�����
typedef char KeyType;		//����ؼ�����Ϊ�ַ���
typedef struct{	//����Ԫ������
	KeyType key;	//�ؼ���
	int weight;		//Ȩֵ 
}ElemType;
void Visit(ElemType c)
{
	//Traverse()���õ���֮���׵ķ�������Ԫ�صĺ���
	printf("(%c, %d)", c.key, c.weight); 
}

void InputFromFile(FILE *f, ElemType *c)
{
	//��֮���׵Ĵ��ļ���������Ԫ�صĺ���
	fscanf(f, "%*c %c %d", &c->key, &c->weight);	//%*c�Ե��س��� 
}

void InputKey(KeyType *k)
{
	//��֮���׵ĴӼ�������ؼ��ֵĺ��� 
	scanf("%c", k);
}
