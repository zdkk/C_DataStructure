//func8-5.h ��������Ԫ�����͵Ķ����Լ������Ĳ���
typedef int KeyType;	//����ؼ�������Ϊ����
typedef struct{		//����Ԫ������ 
	KeyType key;	//�ؼ���
	int others;		//�������� 
}ElemType; 

void Visit(ElemType c)	//Traverse()���õ���֮ƥ��ķ�������Ԫ�صĺ���
{
	printf("(%d, %d)", c.key, c.others);	
}

void InputFromFile(FILE *f, ElemType *c)	//��֮ƥ��Ĵ��ļ���������Ԫ�صĺ���
{
	fscanf(f, "%d %d", &c->key, &c->others);	
}

void InputFromKey(KeyType *k)	//��֮ƥ��ĴӼ�������ؼ��ֵĺ���
{
	scanf("%d", k);	
}
