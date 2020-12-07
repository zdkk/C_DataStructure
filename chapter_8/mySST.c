//mySST.c 静态查找表的顺序存储结构 
//包括一种排序方式，顺序查找和折半查找
#include "../c1.h"
#define FLEN 21
#define ElemType int
char * s_gets(char * st, int n)
{
	char * ret;
	char *find;
	
	ret = fgets(st, n, stdin);
	if (ret)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret;
	
}
void Traverse(int *p, int n)
{
	int i;
	
	for (i = 1; i <= n; i++)
		printf("%d ", p[i]);
	printf("\n");
}
void sort(ElemType *p, int size)
{
	int i, j;
	int index;
	
	for (i = 1; i < size; i++)
	{
		index = i;	//假设初始的最小值序号为i
		for (j = i+1; j <= size; j++)
		{
			if (p[j] < p[index])
				index = j;	
		}
		if (i != index)
		{
			p[0] = p[i];
			p[i] = p[index];
			p[index] = p[0];
		}
	}
}
int findSeq(ElemType *p, int size, int value)
{
	int i;
	
	//这一步很妙,如果顺序表中没找到value那么在哨兵[0]处就会停止，避免了每一步检测表是否查询完毕！ 
	p[0] = value;
	
	for (i = size; p[i] != value; i--)
		continue;
	return i;
}

int findBin(ElemType *p, int size, int value)
{
	int low, high, mid;
	
	low = 1;
	high = size;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (value == p[mid])
			return mid;
		else if (value < p[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}
int main(void)
{
	FILE *f;
	char filename[FLEN];
	int *pd;
	int size;
	int i, j, k;
	
	puts("请输入数据文件名称:");
	s_gets(filename, FLEN);
	if ((f = fopen(filename, "r")) == NULL)
		exit(EXIT_FAILURE);
	fscanf(f, "%d", &size);
	pd = (int *)malloc(sizeof(int) * (size + 1));
	for (i = 1; i<=size; i++)
		fscanf(f, "%d", pd+i);
	Traverse(pd, size);
	
	sort(pd, size);
	Traverse(pd,size);
	
	puts("请输入要查找的值：");
	scanf("%d", &k);
	j = findSeq(pd, size, k);
	if (j)
		printf("%d是第%d个数。\n", pd[j], j);
	else
		printf("未找到该数。\n");
	
	j = findBin(pd, size, k);
	if (j)
		printf("%d是第%d个数。\n", pd[j], j);
	else
		printf("未找到该数。\n");
	
	fclose(f);
	return 0; 
	
} 
