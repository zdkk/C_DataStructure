//myHuffman.c	照着书敲完后自己再敲一遍
#include "../c1.h"
typedef struct{
	unsigned weight;
	unsigned parent, lchild, rchild;
}HTNode, * HuffmanTree;
typedef char ** HuffmanCode;

int min(HuffmanTree t, int i)
{
	int j, m;
	unsigned int k = UINT_MAX;
	
	for (j = 1; j <= i; j++)
	{
		if (t[j].weight < k && t[j].parent == 0)
		{
			k = t[j].weight;
			m = j;
		}
	}
	t[m].parent = 1;
	return m; 
}
void select(HuffmanTree t, int i, int *s1, int *s2)
{
	int m;
	
	*s1 = min(t, i);
	*s2 = min(t, i);
	
	if (*s1 > *s2)
	{
		m = *s1;
		*s1 = *s2;
		*s2 = m;
	}
}

void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int * w, int n)
{
	int i, j, c;
	int s1, s2;
	char * cd;
	int start;
	int m;
	HuffmanTree p;
	
	if (n <= 1)
		return;
	
	m = 2 * n - 1;
	(*HT) = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));
	for (i = 1, p = *HT + 1; i <= n; i++, p++, w++)
	{
		p->parent = 0;
		p->weight = *w;
		p->lchild = p->rchild = 0;
	}
	for (; i <= m; i++, p++)
	{
		p->parent = 0;
		select(*HT, i - 1, &s1, &s2);
		p->weight = (*HT)[s1].weight + (*HT)[s2].weight;
		p->lchild = s1;
		p->rchild = s2;
		(*HT)[s1].parent = i;
		(*HT)[s2].parent = i;
	}
	(*HC) = (HuffmanCode)malloc(sizeof(char *) * (n + 1));
	cd = (char *)malloc(sizeof(char) * n);
	cd[n - 1] = '\0';
	
	for (i = 1; i <= n; i++)
	{
		start = n - 1;
		for (j = i, c = (*HT)[i].parent; c != 0; j = c, c = (*HT)[c].parent)
		{
			if ((*HT)[c].lchild == j)
			{
				cd[--start] = '0';
			}
			else
				cd[--start] = '1';
		}
		(*HC)[i] = (char *)malloc(sizeof(char) * (n - start));
		strcpy((*HC)[i], &cd[start]);
	}
	free(cd);
}


int main(void)
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *m;
	int i, n;
	
	printf("请输入权值个数(>1):");
	scanf("%d", &n);
	m = (int *)malloc(sizeof(int) * n);
	printf("请输入%d个权值(整型)\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", m+i);
	HuffmanCoding(&HT, &HC, m, n);
	for (i = 1; i <= n; i++)
		printf("%s\n", HC[i]);
		
	return 0;
}
