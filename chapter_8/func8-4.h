//func8-4.h	包括算法9.5(a)和bo6-1.h, algo8-4.cpp 和algo8-5.cpp调用
#include "../chapter_6/bo6-1.h"	//包括InitBiTree(),DestroyBiTree()和InOrderTraverse()函数
#define InitDSTable InitBiTree	//构造二叉排序树和平衡二叉树与初始化二叉树的操作相同
#define DestroyDSTable DestroyBiTree	//销毁二叉排序树与初始化二叉树的操作相同
#define TraverseDSTable InOrderTraverse	//按关键字顺序变量二叉排序树与中序遍历二叉树的操作相同

BiTree searchBST(BiTree T, KeyType key)	//算法9.5(a) 
{
	//在根指针T所指二叉排序树或平衡二叉树中递归地查找某关键字等于key的数据元素
	//若查找成功，返回指向该数据元素的指针，否则返回NULL
	
	if (!T || EQ(key, T->data.key))
		return T;
	else if LT(key, T->data.key)	//待查找关键字小于T所指结点关键字
		return searchBST(T->lchild, key);	//在左子树中继续递归查找
	else							//待查找关键字大于T所指结点关键字 
		return searchBST(T->rchild, key);	//在右子树中继续递归查找 
}

