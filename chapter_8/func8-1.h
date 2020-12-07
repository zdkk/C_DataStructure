//func8-1.h	定义数据元素类型以及对它的操作
typedef long KeyType;	//定义关键字域为long类型
#define key number		//定义关键字为准考证号
typedef struct	//数据元素类型 
{
	long number;	//准考证号，与关键字类型相同
	char name[9];	//姓名 4个汉字加一个串结束标志
	int Politics;	//政治
	int Chinese;	//语文
	int English;	//英语
	int Math;
	int Physics;
	int Chemistry;
	int Biology;
	int total;		//总分 
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
