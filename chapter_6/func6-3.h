//func6-3.h 算法6.12的前半部分
int m, i, s1, s2;
unsigned c;
HuffmanTree p;
char *cd;

if (n <= 1)	//叶子结点数不大于1
	return;
m = 2 * n - 1;	//n个叶结点的赫夫曼树共有2*n-1个结点
*HT = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));	//0号单元未使用
for (p = *HT + 1, i = 1; i <= n; i++, p++, w++)			//从1号单元到n号单元，给叶子结点赋值 
{
	//p初始指向一号单元
	p->weight = *w;		//赋权值
	p->parent = 0;		//双亲域为空，目前是根结点
	p->lchild = p->rchild = 0;	//左右孩子为空，目前也是叶结点，即只有根结点的树 
}
for (; i <= m; i++, p++)	//创建赫夫曼树
{
	//其余结点双亲域初值为0
	p->parent = 0; 
	//在HT[1~i-1]中选择parent为0且权值最小的两个结点，其序号分别为s1和s2
	select(*HT, i-1, &s1, &s2);
	(*HT)[s1].parent = (*HT)[s2].parent = i;
	p->lchild = s1;		//i号单元的左右孩子分别是s1和s2 
	p->rchild = s2;
	p->weight = (*HT)[s1].weight + (*HT)[s2].weight;	//i号单元的权值是s1和s2结点的权值之和	
} 
