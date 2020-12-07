//func8-2.h  包括数据元素类型的定义以及对它的操作
typedef int KeyType;	//定义关键域为整型
typedef struct
{
	KeyType key;	//仅有关键字域 
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
