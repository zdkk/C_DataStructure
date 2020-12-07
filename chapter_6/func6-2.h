//func6-2.h algo6-1.c和algo6-2.c要调用的两个函数
#define Order	//定义Order
int min(HuffmanTree t, int i)
{
	//操作结果：返回赫夫曼树t的前i个结点中权值最小的树的根节点序号
	//函数select()调用
	int j, m;
	unsigned int k = UINT_MAX;	//k存取最小权值，初值取值为不小于可能的值（无符号整型的最大值）
	
	for (j = 1; j <= i; j++)	//对于前i个结点
	{
		if (t[j].weight < k && t[j].parent == 0)	//t[j]的权值小于k又是根节点
		{
			k = t[j].weight;						//t[j]的权值赋给t
			m = j;									//序号赋给m 
		}
	}
	t[m].parent = 1;	//给选中的根结点双亲赋非0值，避免二次查找该结点
	return m;			//返回根节点 
}
void select(HuffmanTree t, int i, int *s1, int *s2)
{
	//在赫夫曼树的前t个结点中选择两个权值最小的树的根节点序号，s1为其中序号较小的
#ifdef Order	//如果在主程序中定义了Order,则执行下面一段程序
	int j;
#endif
	*s1 = min(t, i);	//权值最小的根结点序号 
	*s2 = min(t, i);	//权值第二小的根结点序号
#ifdef Order
	if (*s1 > *s2)
	{
		//交换
		j = *s1;
		*s1 = *s2;
		*s2 = j; 
	}
#endif 
}
