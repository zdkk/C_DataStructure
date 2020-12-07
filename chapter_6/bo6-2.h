//bo6-2.h	二叉链表（存储结构由c6-1.h定义）的基本操作18个，包括算法6.2-6.4
Status BiTreeEmpty(BiTree T)
{
	//初始条件：二叉树T存在
	//操作结果：若T为空二叉树，返回TRUE，否则返回FALSE
	return T ? FALSE : TRUE;  
}
int BiTreeDepth(BiTree T)
{
	//初始条件：二叉树T存在
	//操作结果：返回T的深度
	int i, j;
	if (!T)
		return 0;	//空树深度为0
	i = BiTreeDepth(T->lchild);	//i为左子树深度，如果左子树为空，则i为0
	j = BiTreeDepth(T->rchild);	//j为右子树深度，如果右子树为空，则j为0
	return i > j ? i+1 : j+1; 	//T的深度为其左右子树的深度中的大者加一 
}
TElemType Root(BiTree T)
{
	if (BiTreeEmpty(T))	//二叉树为空
		return Nil;		//返回“空” 
	else				//二叉树不为空 
		return T->data; //返回根节点的值 
}
TElemType Value(BiTree p)
{
	//初始条件：二叉树T存在，p指向T中某个结点
	//操作结果：返回p所指结点的值
	return p->data; 
}
void Assign(BiTree p,TElemType value)
{
	//初始条件：二叉树T存在，p指向T中某个结点
	//操作结果：给p所指结点赋值为value 
	p->data = value;
}

typedef BiTree QElemType;	//定义队列元素为二叉树的指针类型
#include "../chapter_3/c3-2.h"	//链队列
#include "../chapter_3/bo3-2.h"	//链队列的基本操作
BiTree Point(BiTree T, TElemType s)
{
	//初始条件：二叉树T存在
	//操作结果：返回T中指向元素值为s的结点的指针
	LinkQueue q;
	QElemType a;
	if(T)	//非空树
	{
		InitQueue(&q);	//初始化队列
		EnQueue(&q, T);	//根指针入队
		while (!QueueEmpty(q))	//队列不为空
		{
			DeQueue(&q, &a);	//出队，队列元素赋给a
			if (a->data == s)	//a所指结点值为s
			{
				DestroyQueue(&q);	//销毁队列
				return a;			//返回a	
			}
			if (a->lchild)			//有左孩子
				EnQueue(&q, a->lchild);	//左孩子入队
			if (a->rchild)			//有右孩子
				EnQueue(&q, a->rchild);	//右孩子入队 
		}
		DestroyQueue(&q);			//销毁队列 
	}
	return NULL;					//二叉树中没有元素值为s的结点 
}
TElemType LeftChild(BiTree T, TElemType e)
{
	//初始条件：二叉树T存在，e是T中某个结点元素值
	//操作结果：返回e的左孩子元素值，若e无左孩子，则返回空
	BiTree a;
	if(T)	//非空树
	{
		a = Point(T, e);	//a是指向结点e的指针
		if (a && a->lchild)	//T中存在结点e且e存在左孩子
			return a->lchild->data;	//返回e的左孩子的值	
	}
	return Nil;				//其余情况返回“空” 
}
TElemType RightChild(BiTree T, TElemType e)
{
	//初始条件：二叉树T存在，e是T中某个结点元素值
	//操作结果：返回e的右孩子元素值，若e无右孩子，则返回空
	BiTree a;
	if(T)	//非空树
	{
		a = Point(T, e);	//a是指向结点e的指针
		if (a && a->rchild)	//T中存在结点e且e存在右孩子
			return a->rchild->data;	//返回e的右孩子的值	
	}
	return Nil;				//其余情况返回“空” 
}
Status DeleteChild(BiTree p, int LR)
{
	//初始条件：二叉树T存在，p指向T中某个结点，LR为0或1
	//操作结果：根据LR为0或1删除T中p所指结点的左或右子树
	if (p)	//p非空
	{
		if(LR == 0)	//删除左子树
			ClearBiTree(&p->lchild);	//清空p所指结点的左子树
		else if(LR == 1)	//删除右子树
			ClearBiTree(&p->rchild);	//清空p所指结点的右子树
		return OK;
	}
	return ERROR;			//p为空返回ERROR 
}
void PostOrderTraverse(BiTree T, void(* Visit)(TElemType))
{
	//初始条件：T存在，Visit是对结点操作的应用函数
	//操作结果：后序遍历T，对T中每个结点调用函数Visit一次且仅一次
	if (T)	//T非空
	{
		PostOrderTraverse(T->lchild, Visit);	//先后序遍历左子树
		PostOrderTraverse(T->rchild, Visit);	//再后序遍历右子树
		(* Visit)(T->data);						//最后访问根结点	
	}
}
void LevelOrderTraverse(BiTree T, void(* Visit)(TElemType))
{
	//初始条件：二叉树T存在，Visit是对结点操作的应用函数
	//操作结果：层序递归遍历T（利用队列）对每个结点调用函数Visit一次且仅一次
	LinkQueue q;
	QElemType a;
	if (T)	//T非空
	{
		InitQueue(&q);		//初始化链队列
		EnQueue(&q, T);		//根指针入队列
		while (!QueueEmpty(q))	//队列非空
		{
			DeQueue(&q, &a);	//出队元素（指针），赋给a
			if (a->lchild)		//左孩子非空
				EnQueue(&q, a->lchild);	//左孩子入队
			if (a->rchild)		//右孩子非空
				EnQueue(&q, a->rchild);	//右孩子入队
			(* Visit)(a->data);	//访问a所指结点		 
		}
		printf("\n");
		DestroyQueue(&q);		//销毁队列q 
	} 
}
void CreateBiTree(BiTree *T)	//算法6.4 
{
	//按先序次序输入二叉树中的结点值（可为字符类型或整型，在主程序中定义）
	//构造二叉链表表示的二叉树T。变量Nil表示空（子）树
	TElemType ch;
	scanf(form,&ch);	//输入结点的值
	if (ch == Nil)		//结点值为空
		*T = NULL;		
	else				//结点值非空
	{
		*T = (BiTree)malloc(sizeof(BiTNode));	//生成根结点
		if (!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;//将值赋给T所指结点
		CreateBiTree(&(*T)->lchild);			//递归构造左子树 
		CreateBiTree(&(*T)->rchild); 			//递归构造右子树 
	}
}
TElemType Parent(BiTree T, TElemType e)
{
	//初始条件：二叉树T存在，e是T中某个结点
	//操作结果：若e是非根节点，则返回它的双亲，否则返回“空”
	LinkQueue q;
	QElemType a;
	if (T)	//非空树
	{
		InitQueue(&q);	//初始化队列
		EnQueue(&q, T);	//树根指针入队
		while (!QueueEmpty(q))	//队列不为空
		{
			DeQueue(&q, &a);	//出队，队列元素赋值给a
			if (a->lchild && a->lchild->data == e || a->rchild && a->rchild->data == e)	//找到e
				return a->data;	//返回双亲值
			else				//未找到e
			{
				if (a->lchild)	//a有左孩子
					EnQueue(&q, a->lchild);	//左孩子指针入队
				if (a->rchild)	//a有右孩子
					EnQueue(&q, a->rchild);	//右孩子指针入队	
			}	
		} 
	}
	return Nil;		//树为空或未找到e 
}

TElemType LeftSibling(BiTree T, TElemType e)		//此函数有点问题 
{
	//初始条件：二叉树T存在，e是T中某个结点
	//操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，返回“空”
	TElemType a;
	BiTree p;
	if (T)	//非空树
	{
		a = Parent(T,e);	//a为e的双亲
		if (a != Nil)		//找到e的双亲
		{
			p = Point(T, a);	//p为指向结点a的指针
			if (p->lchild && p->rchild && p->rchild->data == e)	//p存在左右孩子且右孩子是e
				return p->lchild->data;							//返回p的左孩子（e的左兄弟）	
		}
	}
	return Nil;					//其余情况返回“空” 
}
TElemType RightSibling(BiTree T, TElemType e)		//此函数有点问题 
{
	//初始条件：二叉树T存在，e是T中某个结点
	//操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，返回“空”
	TElemType a;
	BiTree p;
	if (T)	//非空树
	{
		a = Parent(T,e);	//a为e的双亲
		if (a != Nil)		//找到e的双亲
		{
			p = Point(T, a);	//p为指向结点a的指针
			if (p->lchild && p->rchild && p->lchild->data == e)	//p存在左右孩子且右孩子是e
				return p->rchild->data;							//返回p的左孩子（e的左兄弟）	
		}
	}
	return Nil;					//其余情况返回“空” 
}

Status InsertChild(BiTree p, int LR, BiTree c)
{
	//初始条件：二叉树T存在，p指向T中某个结点，LR为0或1，非空二叉树c与T不相交且右子树为空
	//操作结果：根据LR为0或1，插入c为T中p所指结点的左或右子树。p所指结点的原有左或右子树则成为c的右子树
	if (p)	//p非空
	{
		if (LR == 0)	//把二叉树c插为p所指结点的左子树
		{
			c->rchild = p->lchild;	//p所指结点的原左子树成为c的右子树
			p->lchild = c;			//二叉树c成为p的左子树	
		}
		else			//把二叉树c插为p所指结点的右子树 
		{
			c->rchild = p->rchild;	//p所指结点的原右子树成为c的右子树
			p->rchild = c;			//二叉树c成为p的右子树 
		}
		return OK;
	}
	return ERROR;					//p为空 
}

typedef BiTree SElemType;	//定义栈元素为二叉树的指针类型
#include "../chapter_3/c3-1.h"	//顺序栈
#include "../chapter_3/bo3-1.h"	//顺序栈的基本操作 

void InOrderTraverse1(BiTree T, void(* Visit)(TElemType))	//算法6.3 
{
	//采用二叉链表存储结构，Visit是对数据元素操作的应用函数 
	//中序遍历二叉树T的非递归算法（使用栈），对每个数据元素调用函数Visit
	SqStack S;
	InitStack(&S);	 //初始化栈S
	while (T || !StackEmpty(S))	//当二叉树T不为空或栈非空
	{
		if (T)	//二叉树非空
		{
			//根指针进栈，遍历左子树
			Push(&S, T);			//根指针入栈 
			T = T->lchild;		//T指向其左孩子 
		}
		else	//根指针出栈，访问根节点，遍历右子树 
		{
			Pop(&S, &T);			//出栈根指针
			(*Visit)(T->data);	//访问根节点
			T = T->rchild;		//T指向其右孩子 
		}
	}
	printf("\n");
	DestroyStack(&S);			//销毁栈S 
}
void InOrderTraverse2(BiTree T, void(* Visit)(TElemType))	//算法6.2 
{
	//采用二叉链表存储结构，Visit是对数据元素操作的应用函数 
	//中序遍历二叉树T的非递归算法（使用栈），对每个数据元素调用函数Visit
	SqStack S;
	BiTree p;
	InitStack(&S);
	Push(&S,T);	//根指针进栈，无论是否为空
	while (!StackEmpty(S))	//S非空
	{
		while (GetTop(S, &p) && p)	//栈顶元素不为空指针
			Push(&S, p->lchild);		//向左走到尽头，入栈左孩子指针
		Pop(&S, &p);					//空指针出栈
		if (!StackEmpty(S))			//访问结点，向右一步
		{
			Pop(&S, &p);				//弹出栈顶元素（非空指针）
			(*Visit)(p->data);		//访问刚刚弹出的结点（目前栈顶元素的左孩子）
			Push(&S, p->rchild);		//入栈右孩子指针	
		}	
	}
	printf("\n");
	DestroyStack(&S);				//销毁栈S 
}
int NodeCount(BiTree T)
{
	//操作结果：返回二叉树T中结点个数
	if (!T)	//T为空
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1; 
}
int NodeCount_0(BiTree T)
{
	//统计树中度为0的结点（即叶结点）个数
	if (T)	//T非空
	{
		if (T->lchild == NULL && T->rchild == NULL)
			return 1;
		else
			return NodeCount_0(T->lchild) + NodeCount_0(T->rchild);
	}
	else
		return 0; 
}
int NodeCount_1(BiTree T)
{
	//统计树中度为1的结点个数
	if (T)	//T非空
	{
		if ((T->lchild && T->rchild == NULL) || (T->lchild == NULL && T->rchild))
			return 1 + NodeCount_1(T->lchild) + NodeCount_1(T->rchild);
		else
			return NodeCount_1(T->lchild) + NodeCount_1(T->rchild);
	}
	else
		return 0; 
}
int NodeCount_2(BiTree T)
{
	//统计树中度为2的结点个数
	if (T)	//T非空
	{
		if (T->lchild && T->rchild)
			return 1 + NodeCount_2(T->lchild) + NodeCount_2(T->rchild);
		else
			return NodeCount_2(T->lchild) + NodeCount_2(T->rchild);
	}
	else
		return 0; 
}













