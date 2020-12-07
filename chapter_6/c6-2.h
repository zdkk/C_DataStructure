//c6-2.h 树的二叉链表（孩子-兄弟）存储结构 
typedef struct Node
{
	TElemType data;	//结点类型
	struct Node * firstchild, * nextsibling; 
}CSNode, *CSTree;

