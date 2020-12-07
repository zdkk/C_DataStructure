//mySST.c ��̬���ұ��˳��洢�ṹ 
//����һ������ʽ��˳����Һ��۰����
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
		index = i;	//�����ʼ����Сֵ���Ϊi
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
	
	//��һ������,���˳�����û�ҵ�value��ô���ڱ�[0]���ͻ�ֹͣ��������ÿһ�������Ƿ��ѯ��ϣ� 
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
	
	puts("�����������ļ�����:");
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
	
	puts("������Ҫ���ҵ�ֵ��");
	scanf("%d", &k);
	j = findSeq(pd, size, k);
	if (j)
		printf("%d�ǵ�%d������\n", pd[j], j);
	else
		printf("δ�ҵ�������\n");
	
	j = findBin(pd, size, k);
	if (j)
		printf("%d�ǵ�%d������\n", pd[j], j);
	else
		printf("δ�ҵ�������\n");
	
	fclose(f);
	return 0; 
	
} 
