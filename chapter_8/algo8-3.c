//algo8-3.c	静态查找表（静态树表）的操作，包括算法9.3和9.4
#include "../c1.h"
#include "func8-3.h"	//包括数据元素类型的定义以及对它的操作 
#include "c8-1.h"		//静态查找表的顺序存储结构
#include "c8-2.h"		//对两个数值型关键字的比较的约定
#include "bo8-1.h"		//静态查找表（顺序表和有序表）的的基本操作（7个）
typedef ElemType TElemType;	//定义二叉树的元素类型为数据元素类型
#include "../chapter_6/c6-1.h"//二叉链表的存储结构
#include "../chapter_6/bo6-1.h"//二叉链表的基本操作
#define N 100			//静态查找表的最大表长，设置sw[]数组用到

Status SecondOptimal(BiTree * T, ElemType R[], int sw[], int low, int high)
{
	//由有序表R[low-high]及其累计权值表sw(其中sw[0]=0)递归构造次优查找树T	算法9.3
	//该算法是近似最优查找树，但是构造速度比最优二叉树快得多
	//※算法的核心是递归构造次优二叉树，每次的根结点都是**当前有序表中左右权值差最小的结点** 
	int j, i = low;		//有最小▲Pi值的序号，初值设为当low == high(有序表仅有一个元素)时的值
	double dw = sw[high] + sw[low - 1];	//严书式9-13中的固定项
	double min = fabs(dw - sw[low] - sw[low-1]);	//▲Pi的最小值，初值设为当low==high时的值（其实都一样）
	//double min = fabs(sw[high] - sw[low]);
	//无论high 是否等于low，都有 |sw[high] - sw[low]| = |sw[high] + sw[low-1] - sw[low] - sw[low-1]||dw - sw[low] - sw[low-1]|
	
	for (j = low + 1; j <= high; j++)		//当low≠high时，选择最小的▲Pi值
		if (fabs(dw - sw[j] - sw[j-1]) < min)	//找到小于min的值
		{
			i = j;	//更新有最小▲Pi值的序号
			min = fabs(dw - sw[j] - sw[j-1]);	//跟新▲Pi的最小值	
		}
	if (!(*T = (BiTree)malloc(sizeof(BiTNode))))//生成结点失败
		return ERROR;
	(*T)->data = R[i];								//将最小▲Pi值的数据元素赋给树结点的数据域
	if (i == low)								//有最小▲Pi值的序号是最小序号
		(*T)->lchild = NULL;						//设左子树为空
	else										//有最小▲Pi值的序号不是最小序号
		SecondOptimal(&(*T)->lchild, R, sw, low, i-1);//递归构造次优查找左子树
	if (i == high)
		(*T)->rchild = NULL;
	else
		SecondOptimal(&(*T)->rchild, R, sw, i+1, high);//递归构造次优查找右子树
	return OK; 
}

void FindSW(int sw[], SSTable ST)
{
	//按照有序表ST中的各数据元素的Weight域求累计权值数组sw, CreateSOSTree()调用
	int i;
	sw[0] = 0;	//置边界值
	printf("\nsw = 0");
	
	for (i = 1; i <= ST.length; i++)	//由小到大计算累计权值 [i] = [i-1]+[i]权值	
	{
		sw[i] = sw[i-1] + ST.elem[i].weight;
		printf("%5d", sw[i]);
	}
}

typedef BiTree SOSTree;		//次优查找树采用二叉链表的存储结构
void CreateSOSTree(SOSTree * T, SSTable ST)
{
	//由有序表ST构造一棵次优查找树T。ST的数据元素含有权域weight。 算法9.4
	int sw[N + 1];	//累计权值数组
	if (ST.length == 0)	//ST是空表
		*T = NULL;		//次优查找树T为空	
	else	//ST非空
	{
		FindSW(sw, ST);	//按照有序表ST中各数据元素的weight域求累计权值表sw
		SecondOptimal(T, ST.elem, sw, 1, ST.length);
		//由有序表ST[1-ST.length]及其权值表sw（其中sw[0] == 0）递归构造次优查找树T	
	}
}
Status Search_SOSTree(SOSTree *t, KeyType key)
{
	//在次优查找树T中查找主关键字等于key的元素。找到则返回OK，T指向该元素，否则返回FALSE
	SOSTree T = *t;
	while (T)	//T非空
	{
		if (T->data.key == key)
		{
			*t = T;
			return OK;
		}
		else if (T->data.key > key)
			T = T->lchild;
		else
			T = T->rchild;	
	}
	return FALSE;	//要查找的元素不存在 
}

int main(void)
{
	SSTable st;
	SOSTree t;
	SOSTree ret;
	Status i;
	KeyType s;
	
	Create_OrdFromFile(&st, "f8-3.txt");	//由数据文件产生非降序静态查找表st
	printf("		");
	Traverse(st, Visit);
	CreateSOSTree(&t, st);				//由有序表st构造次优查找树t
	printf("\n请输入待查找的字符：");
	InputKey(&s);						//键盘键入待查找字符
	ret = t;
	i = Search_SOSTree(&ret, s);		//在次优查找树上查找关键字等于s的元素
	if (i)	//找到
		printf("%c 的权值是%d\n", s, t->data.weight);
	else
		printf("表中不存在该字符\n");
	DestroyBiTree(&t);	//查找完毕，摧毁次优查找树t
	Destroy(&st);		//查找完毕，摧毁有序表st 

	return 0;
}
/*
--------------------
                (A, 1)(B, 1)(C, 2)(D, 5)(E, 3)(F, 4)(G, 4)(H, 3)(I, 5)
sw = 0    1    2    4    9   12   16   20   23   28
请输入待查找的字符：G
G 的权值是4
--------------------
*/























