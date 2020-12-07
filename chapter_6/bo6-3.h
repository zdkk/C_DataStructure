//bo6-3.h 树的二叉链表（孩子-兄弟）存储结构（c6-2.h定义）的基本操作(16个) 
#define ClearTree DestroyTree	//二者操作相同
void InitTree(CSTree *T)
{
	//操作结果：构造空树T 
	* T = NULL;	
}
void DestroyTree(CSTree * T)
{
	//初始条件：树T存在，操作结果：销毁树T
	if (*T) //非空树 
	{
		DestroyTree(&(*T)->firstchild);	//递归销毁T的长子为根节点的子树
		DestroyTree(&(*T)->nextsibling);//递归销毁T的下一个兄弟为根节点的子树
		free(*T);	//释放根节点
		*T = NULL; 
	} 
}

typedef CSTree QElemType;	//定义队列元素类型为 孩子-兄弟二叉链表的指针类型
#include "../chapter_3/c3-2.h"	//定义LinkQueue类型（链队列）
#include "../chapter_3/bo3-2.h"	//LinkQueue类型的基本操作
void CreateTree(CSTree * T)
{
	char c[20];	//临时存放孩子结点（设不超过20个）的值，即一个结点的子结点不超过20个 
	CSTree p, p1;
	LinkQueue q;
	int i, m;
	
	InitQueue(&q);	//初始化队列q
	printf("请输入根节点数据(字符型, #为空)");
	scanf("%c", &c[0]);	//输入根节点的值，之后的值被丢弃
	while (getchar() != '\n')
		continue;
	if (c[0] != Nil)	//非空树
	{
		*T = (CSTree)malloc(sizeof(CSNode));	//建立根节点
		if (!(*T))
		{
			fprintf(stderr, "创建根节点失败，退出程序\n");
			exit(OVERFLOW);
		}
		(*T)->data = c[0];						//根节点赋值
		(*T)->nextsibling = NULL;				//根节点没有下一个兄弟，赋值NULL
		EnQueue(&q, *T);						//入队根节点的指针	
		while (!QueueEmpty(q))				//队列不为空
		{
			DeQueue(&q, &p);						//出队一个结点的指针
			printf("请按长幼顺序输入结点%c的所有孩子: ", p->data);
			//不安全的gets函数 
			gets(c);	 						//将结点的所有孩子最为字符串输入 
			m = strlen(c);						//子结点个数为m
			if (m > 0)							//有孩子
			{
				p1 = p->firstchild = (CSTree)malloc(sizeof(CSNode));	//建立长子结点
				if (!p1)
				{
					fprintf(stderr, "长子结点创建失败,程序退出\n");
					exit(OVERFLOW);
				}
				p1->data = c[0];				//给长子结点赋值
				EnQueue(&q, p1);				//入队p1结点的指针
				for (i = 1; i < m; i++)			//对于除长子外的其他孩子
				{
					p1->nextsibling = (CSTree)malloc(sizeof(CSNode));	//建立下一个兄弟结点
					p1 = p1->nextsibling;		//p1指向下一个兄弟结点 
					if (!p1)
					{
						fprintf(stderr, "兄弟结点创建失败,程序退出\n");
						exit(OVERFLOW);
					}
					p1->data = c[i];			//给p1所指结点赋值 
					EnQueue(&q, p1);			//入队p1结点的指针	
				}
				p1->nextsibling = NULL;			//最后一个子结点没有下一个兄弟 
			}//endif(m>0)
			else
				p->firstchild = NULL;			//没有子结点 
		}//end while
	}//endif(c[0] = Nil)								//空树 
}
Status TreeEmpty(CSTree T)
{
	//初始条件：树T存在，即已经执行过InitTree或者CreateTree 
	//操作结果：若树T为空树，返回TRUE，否则返回FALSE
	if (T)
		return FALSE;
	else
		return TRUE; 
}
int TreeDepth(CSTree T)
{
	//初始条件：树T存在
	//操作结果：返回T的深度
	CSTree p;
	int depth, max = 0;
	
	if (!T)	//递归结束条件：子树是空树，深度为0 
		return 0; 
	for (p = T->firstchild; p; p = p->nextsibling)	//遍历T所指结点的所有子结点 
	{
		//求子树深度的最大值
		depth = TreeDepth(p);	//递归求子结点的深度depth
		if (depth > max)
			max = depth; 
	}
	return max + 1;				//树的深度 = 子树深度最大值 + 1； 
}
TElemType Value(CSTree p)
{
	//返回p所指结点的值
	return p->data; 
}
TElemType Root(CSTree T)
{
	//初始条件：树T存在
	//操作结果：返回T的根
	if (T)	//根节点非空
		return T->data;
	else
		return Nil; 
}
CSTree Point(CSTree T, TElemType s)
{
	//返回二叉链表（孩子-兄弟）树T中指向元素值为s的结点的指针
	LinkQueue q;
	QElemType a;
	
	if (T)	//非空树
	{
		InitQueue(&q);			//初始化队列
		EnQueue(&q, T);			//根节点指针入队
		while (!QueueEmpty(q))	//队列不为空
		{
			DeQueue(&q, &a);	//出队，队列元素赋值给a	
			if (a->data == s)	//找到元素值为s的结点 
				return a; 		//返回指向其的指针
			if (a->firstchild)	//有长子
				EnQueue(&q, a->firstchild);	//入队指向长子的指针 
			if (a->nextsibling)	//有下一个兄弟
				EnQueue(&q, a->nextsibling); //入队指向下一个兄弟的指针 
		}	
	} 
	return NULL;
}

Status Assign(CSTree T, TElemType cur_e, TElemType value)
{
	//初始条件：树T存在,cur_e是树中结点的值
	//操作结果：改cur_e为value 
	CSTree p;
	
	if (T)	//非空树
	{
		p = Point(T, cur_e);
		if (p)	//p不为空
		{
			p->data = value; 
			return OK;
		}
	}
	return ERROR;		//树空或未找到指定结点 
} 
TElemType Parent(CSTree T, TElemType cur_e)
{
	//初始条件：树T存在，cur_e是T中某个结点
	//操作结果：若cur_e是T的非根结点，则返回它的双亲，否则返回“空”
	CSTree p, t;
	LinkQueue q;
	
	InitQueue(&q);	//初始化队列
	if (T)			//树非空 
	{
		if (Value(T) == cur_e)	//根结点值为cur_e
			return Nil;
		EnQueue(&q, T);			//根结点指针入队
		while (!QueueEmpty(q))
		{
			DeQueue(&q, &p);	//出队元素（指针）赋给p
			if (p->firstchild)	//p所指结点有长子
			{
				if (Value(p->firstchild) == cur_e)	//长子数据为cur_e
					return Value(p);
				t = p;								//双亲指针赋给t
				p = p->firstchild;					//p指向长子
				EnQueue(&q, p);						//长子指针入队
				while (p->nextsibling)				//p有下一个兄弟
				{
					p = p->nextsibling;
					if (Value(p) == cur_e)			//下一个兄弟数据为cur_e 
						return Value(t);			//返回双亲的值
					EnQueue(&q, p);					//入队下一个兄弟 
				}		
			} 
		} 
	}
	return Nil;										//没找到或树空 
}
TElemType LeftChild(CSTree T, TElemType cur_e)
{
	//初始条件：树T存在
	//操作结果：如果cur_e是T的非叶结点，返回它的 最左孩子， 否则返回“空” 
	CSTree p;
	
	p = Point(T, cur_e);
	if (p && p->firstchild)
		return Value(p->firstchild);
	else
		return Nil;
}
TElemType RightSibling(CSTree T, TElemType cur_e)
{
	//初始条件：树T存在，cur_e是它的某个结点的值
	//操作结果：若cur_e结点有右兄弟，则返回它的右兄弟结点的值，否则返回“空”
	CSTree p;
	
	p = Point(T, cur_e);
	if (p && p->nextsibling)
		return Value(p->nextsibling);
	else
		return Nil;
}
Status InsertChild(CSTree *T, CSTree p, int i, CSTree c)
{
	//初始条件：树T存在，p指向T中某个结点，1<=i<=p所指结点的度+1, 非空树c与T不相交
	//操作结果：插入c为T中p结点的第i棵子树。因为p所指结点的地址不会改变，故p不需要传入地址
	int j;
	CSTree q;
	
	if (*T)		//T非空
	{
		if (i == 1)	//插入c为p的长子 
		{
			c->nextsibling = p->firstchild;		//p的原长子是c的右兄弟 
			p->firstchild = c;					//p的长子指针指向c 
		}	
		else		//c不是p的长子
		{
			q = p->firstchild;					//q指向p的长子结点
			j = 2;
			while (q && j < i)					//找到c的插入点并由q指向
			{
				q = q->nextsibling;
				j++;	
			}
			if (j == i)							//找到插入位置
			{
				c->nextsibling = q->nextsibling;//c的右兄弟指向p的原第i个孩子
				q->nextsibling = c;				//在p中插入c作为p的第i个孩子	
			} 
			else
				return ERROR;
		}
		return OK;
	}
	else
		return ERROR;
}
Status DeleteChild(CSTree *T, CSTree p, int i)
{
	//初始条件：树T存在，p指向T中某个结点，1 <= i <= p所指结点的度数
	//操作结果：删除T中p所指结点的第i棵子树
	CSTree b, q;
	int j;
	
	if (*T)	//T非空
	{
		if (i == 1)	//删除长子
		{
			b = p->firstchild;		//b指向p的长子结点
			p->firstchild = b->nextsibling;	//p的原次子成为长子
			b->nextsibling = NULL;
			DestroyTree(&b);		//销毁b指向的原长子结点子树 
		}	
		else	//删除非长子 
		{
			q = p->firstchild;		//q指向长子结点
			j = 2;
			while (q && j < i)		//找到第i棵子树
			{
				q = q->nextsibling;
				j++;
			}
			if (j == i)	//找到第i棵子树 
			{
				b = q->nextsibling;	//b指向待删除子树
				q->nextsibling = b->nextsibling;
				b->nextsibling = NULL;
				DestroyTree(&b); 
			}
			else
				return ERROR;
		}
		return OK;
	}
	return ERROR;
}

void PostOrderTraverse(CSTree T, void (* Visit)(TElemType))
{
	//后序遍历孩子-兄弟二叉链表结构的树T
	CSTree p;
	
	if (T)
	{
		if (T->firstchild)	//有长子
		{
			PostOrderTraverse(T->firstchild, Visit);	//后根遍历长子树
			p = T->firstchild->nextsibling;				//p指向长子的下一个兄弟
			while (p)									//还有下一个兄弟
			{
				PostOrderTraverse(p, Visit);			//后根遍历下一个兄弟子树
				p = p->nextsibling;	
			}
		}
		Visit(Value(T));								//最后访问根节点 
	}
}
void LevelOrderTraverse(CSTree T, void (* Visit)(TElemType))
{
	//层序遍历孩子-兄弟二叉链表结构的树T
	CSTree p;
	LinkQueue q;
	
	InitQueue(&q);	//初始化队列
	if (T)			//树非空
	{
		Visit(Value(T));
		EnQueue(&q, T);		//入队根结点指针
		while (!QueueEmpty(q))
		{
			DeQueue(&q, &p);	//出队一个结点的指针
			if (p->firstchild)	//p有长子
			{
				Visit(Value(p->firstchild));
				EnQueue(&q, p->firstchild);	//长子结点指针入队
				p = p->firstchild->nextsibling;
				while (p)					//有下一个兄弟
				{
					Visit(Value(p));		//访问该结点
					EnQueue(&q, p);			//入队兄弟结点
					p = p->nextsibling;		//p指向下一个兄弟结点	
				}
			}	
		}	
	}
	printf("\n");
}













































