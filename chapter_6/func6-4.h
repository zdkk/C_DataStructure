//func6-4.h ��շ��������������
int main(void)
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w, n, i;
	
	printf("������Ȩֵ����(>1):");
	scanf("%d", &n);
	w = (int *)malloc(sizeof(int) * n);	//��̬���ɴ��n��Ȩֵ�Ŀռ�
	printf("����������%d��Ȩֵ(����):\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", w + i);
	HuffmanCoding(&HT, &HC, w, n);	//����w�����n��Ȩֵ����շ�������n���շ����������HC
	for (i = 1; i <= n; i++)
		puts(HC[i]);
		
	return 0; 
}
