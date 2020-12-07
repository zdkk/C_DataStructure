//func6-4.h 求赫夫曼编码的主函数
int main(void)
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w, n, i;
	
	printf("请输入权值个数(>1):");
	scanf("%d", &n);
	w = (int *)malloc(sizeof(int) * n);	//动态生成存放n个权值的空间
	printf("请依次输入%d个权值(整型):\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", w + i);
	HuffmanCoding(&HT, &HC, w, n);	//根据w所存的n个权值构造赫夫曼树，n个赫夫曼编码存于HC
	for (i = 1; i <= n; i++)
		puts(HC[i]);
		
	return 0; 
}
