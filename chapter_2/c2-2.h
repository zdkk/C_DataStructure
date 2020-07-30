//c2-2.h
//线性表的单链表存储结构
struct LNode
{
	ElemType data;
	struct LNode *next;	
};
typedef LNode * LinkList;
