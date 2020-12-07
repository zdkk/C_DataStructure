//algo6-2.c	求赫夫曼编码	实现算法6-12的程序
#include "../c1.h"
#include "c6-3.h"		//赫夫曼树和赫夫曼编码的存储结构 
#include "func6-2.h" 	//内含min()和select()函数

void HuffmanCoding(HuffmanTree * HT, HuffmanCode * HC, int * w, int n)
{
	//w存放n个字符的权值(均>0),构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
	unsigned cdlen;
#include "func6-3.h"	//算法6-12的前半部分，以下为算法6.13无栈非递归遍历赫夫曼树，求赫夫曼编码 
	
	*HC = (HuffmanCode)malloc(sizeof(char *) * (n + 1));	//分配n个字符编码的头指针向量([0]不用) 
	cd = (char *)malloc(n * sizeof(char));	//分配求编码的工作空间
	c = m;	//m = 2 * n - 1;从最后一个结点，也就是根结点开始
	cdlen = 0;	//码长初始值为0
	for (i = 1; i <= m; i++)
		(*HT)[i].weight = 0;	//求编码不需要权值域，用作结点状态标志位，0表示左右孩子都不曾被访问
	while (c)	//刚开始c等于根结点序号，循环结束的时候c为0，代表访问到叶结点的孩子域
	{
		if ((*HT)[c].weight == 0)	//当前结点左右孩子都未被访问
		{	//向左 
			(*HT)[c].weight = 1;	//1为左孩子被访问，右孩子未被访问的标记
			if ((*HT)[c].lchild != 0)	//有左孩子，即该结点不是叶子节点
			{
				c = (*HT)[c].lchild;	//置c为其左孩子序号（向叶子方向前进一步）
				cd[cdlen++] = '0';		//左支编码为0	
			}
			else if((*HT)[c].rchild == 0)//序号c为叶子节点，记录该叶结点的字符的编码 
			{
				(*HC)[c] = (char *)malloc(sizeof(char) * (cdlen + 1));
				cd[cdlen] = '\0';		//添加串结束符 
				strcpy((*HC)[c], cd);	//复制编码串 
			}
		}//endif((*HT)[c].weight == 0)
		else if((*HT)[c].weight == 1)	//左孩子被访问过，右孩子没有
		{	//向右 
			(*HT)[c].weight = 2;	//左右孩子均被访问过的标记
			if ((*HT)[c].rchild != 0)	//有右孩子（不是叶结点）
			{
				c = (*HT)[c].rchild;	//置c为其右孩子序号，向叶结点方向前进一步
				cd[cdlen++] = '1';		//右分支编码为1	
			}
		}
		else	//左右孩子均被访问过（(*HT)[c].weight == 2），向根结点方向回退一步
		{
			c = (*HT)[c].parent;
			cdlen--;	
		}
	}
	free(cd);
}
#include "func6-4.h"
