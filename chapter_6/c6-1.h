//c6-1.h 二叉树的二叉链表存储结构
typedef struct BiTNode
{
	TElemType data;		//结点的数据元素
	struct BiTNode *lchild, *rchild;	//左右孩子指针	
}BiTNode, *BiTree;
