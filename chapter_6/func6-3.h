//func6-3.h �㷨6.12��ǰ�벿��
int m, i, s1, s2;
unsigned c;
HuffmanTree p;
char *cd;

if (n <= 1)	//Ҷ�ӽ����������1
	return;
m = 2 * n - 1;	//n��Ҷ���ĺշ���������2*n-1�����
*HT = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));	//0�ŵ�Ԫδʹ��
for (p = *HT + 1, i = 1; i <= n; i++, p++, w++)			//��1�ŵ�Ԫ��n�ŵ�Ԫ����Ҷ�ӽ�㸳ֵ 
{
	//p��ʼָ��һ�ŵ�Ԫ
	p->weight = *w;		//��Ȩֵ
	p->parent = 0;		//˫����Ϊ�գ�Ŀǰ�Ǹ����
	p->lchild = p->rchild = 0;	//���Һ���Ϊ�գ�ĿǰҲ��Ҷ��㣬��ֻ�и������� 
}
for (; i <= m; i++, p++)	//�����շ�����
{
	//������˫�����ֵΪ0
	p->parent = 0; 
	//��HT[1~i-1]��ѡ��parentΪ0��Ȩֵ��С��������㣬����ŷֱ�Ϊs1��s2
	select(*HT, i-1, &s1, &s2);
	(*HT)[s1].parent = (*HT)[s2].parent = i;
	p->lchild = s1;		//i�ŵ�Ԫ�����Һ��ӷֱ���s1��s2 
	p->rchild = s2;
	p->weight = (*HT)[s1].weight + (*HT)[s2].weight;	//i�ŵ�Ԫ��Ȩֵ��s1��s2����Ȩֵ֮��	
} 
