//func8-1.h	��������Ԫ�������Լ������Ĳ���
typedef long KeyType;	//����ؼ�����Ϊlong����
#define key number		//����ؼ���Ϊ׼��֤��
typedef struct	//����Ԫ������ 
{
	long number;	//׼��֤�ţ���ؼ���������ͬ
	char name[9];	//���� 4�����ּ�һ����������־
	int Politics;	//����
	int Chinese;	//����
	int English;	//Ӣ��
	int Math;
	int Physics;
	int Chemistry;
	int Biology;
	int total;		//�ܷ� 
}ElemType;
void Visit(ElemType c)
{
	printf("%-8ld %-8s %5d %5d %5d %5d %5d %5d %5d %5d\n",
		c.number, c.name, c.Politics, c.Chinese, c.English, c.Math, c.Physics, c.Chemistry, c.Biology, c.total);
}

void InputFromFile(FILE *f, ElemType *c)
{
	fscanf(f, "%ld %s %d %d %d %d %d %d %d", &c->number, &c->name, &c->Politics,
		&c->Chinese, &c->English, &c->Math, &c->Physics, &c->Chemistry, &c->Biology);
}
void InputFromKey(KeyType *k)
{
	scanf("%ld", k);
}
