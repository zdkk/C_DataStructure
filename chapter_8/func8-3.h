//func8-3.h	包括数据元素类型的定义以及操作
typedef char KeyType;		//定义关键字域为字符型
typedef struct{	//数据元素类型
	KeyType key;	//关键字
	int weight;		//权值 
}ElemType;
void Visit(ElemType c)
{
	//Traverse()调用的与之配套的访问数据元素的函数
	printf("(%c, %d)", c.key, c.weight); 
}

void InputFromFile(FILE *f, ElemType *c)
{
	//与之配套的从文件输入数据元素的函数
	fscanf(f, "%*c %c %d", &c->key, &c->weight);	//%*c吃掉回车符 
}

void InputKey(KeyType *k)
{
	//与之配套的从键盘输入关键字的函数 
	scanf("%c", k);
}
