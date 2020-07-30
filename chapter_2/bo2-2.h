//bo2-2.h
//带有头节点的单链表的基本操作（12个）包括算法2.8-2.10

void InitList(LinkList *L)
{
	//操作结果：创建一个带有头节点的空的单链表L 
	*L = (LinkList)malloc(sizeof(LNode));	//产生头节点，并使L指向该节点
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;	
} 

void DestroyList(LinkList *L)
{
	//初始条件：L已经存在
	//操作结果：销毁L
	LNode *p = *L, *q;
	while(p)	//L指向节点（非空） 
	{
		q = p;
		p = p->next;
		free(q);
	}
	*L = NULL;
}

void ClearList(LinkList *L)
{
	//初始条件：L存在
	//操作结果：将L置为空
	LNode *p = (*L)->next;		//p指向首元结点 
	(*L)->next = NULL;			//头节点指针域清空 
	DestroyList(&p);		//销毁p所指向的链表 
}

Status ListEmpty(LinkList L)
{
	//初始条件：L存在
	//操作结果：若L为空表，返回TRUE，否则返回FALSE
	if(L->next)		//非空 
		return FALSE;
	else
		return TRUE; 
}

int ListLength(LinkList L)
{
	int i = 0;		//初始化计数器为0
	LNode *p = L->next;	//p指向首元结点
	while (p)	//未到末尾 
	{
		i++;	//计数器加一 
		p = p->next;	//p指向下一个结点 
	} 
	return i;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
	//初始条件：L存在，1<=i<=ListLength(L)
	//操作结果：当第i个元素存在时，用e返回结果并返回OK，否则返回ERROR
	int j = 1;			//计数器初始值为1 
	LNode *p = L->next; //p指向首元结点
	
	while(p && j<i)		//顺指针向后查找，直到p指向第i个节点或p为NULL（第i个结点不存在） 
	{
		j++;
		p = p->next;
	} 
	if(!p || j>i)		//第i个节点不存在
		return ERROR;
	
	*e = p->data;
	return OK; 
}

int LocateElem(LinkList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
	//初始条件：L存在，compare()是数据元素判定函数（满足为1，否则为0）
	//操作结果：返回L中的一个与e满足关系compare()的数据元素的位序，若这样的元素不存在则返回0
	int i = 0;			//计数器初始置为0 
	LNode *p = L->next; //p指向首元结点
	while(p)			//未到末尾 
	{
		i++;	//计数器加一	
		if((*compare)(p->data, e))	//找到第一个满足条件的数据元素 
			return i;				//返回其位序 
		p = p->next; 				//p指向下一个结点 
	} 
	return 0;						//不存在满足条件的元素，返回0 
	 
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	//初始条件：L存在
	//操作结果：若cur_e是L的数据元素且不是第一个，则用pre_e返回它的前驱，返回OK
		//否则操作失败，pre_e无定义，返回ERROR
	LNode *p = L->next, *q;	//p指向首元结点
	
	while(p && p->next)		//p指向的结点有后继
	{
		q = p->next;
		if(q->data == cur_e)	//p的后继为cur_e
		{
			*pre_e = p->data;	//将p所指结点的数据元素赋值给*pre_e 
			return OK;			//返回OK 
		}
		p = q; 					//p的后继结点数据元素不等于cur_e,p后移 
	} 
	return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	//初始条件：L存在
	//操作结果： 若cur_e是L的数据元素且不是最后一个，则用next_e返回它的后继，返回OK
		//否则操作失败，next_e无定义，返回ERROR
	LNode *p = L->next;		//p指向首元结点
	
	while (p && p->next)	//p所指结点有后继
	{ 
		if (p->data == cur_e)	//p指向的结点值为cur_e
		{
			*next_e = p->next->data;
			return OK;
		 } 
		p = p->next;
	 } 
	return ERROR;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	//初始条件：L存在，1<=i<=ListLength(L)+1
	//操作结果：若i合法，在指定位置处插入元素e返回OK，否则返回ERROR
	int j = 0;	//计数器初始化0
	LNode *p = *L, *q;	//p指向头节点 
	
	while(p && j<(i-1))	//寻找第i-1个结点
	{
		j++;
		p = p->next;
	}
	if(!p && j>(i-1))	//i不合法
		return ERROR;
	
	q = (LNode *)malloc(sizeof(LNode));
	if(!q)	//分配存储空间失败
		return OVERFLOW;
	q->data = e;
	q->next = p->next;
	p->next = q; 
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	//初始条件：L存在，1<=i<=ListLength(L)
	//操作结果：若i合理，删除第i个元素并赋值给e，返回OK，否则返回ERROR
	int j = 0;	//计数器初始化0
	LNode *p = *L, *s;	//p指向头节点
	while(p->next && j<(i-1))	//寻找第i-1个节点，并令p指向其前驱
	{
		p = p->next;
		j++;
	}
	if(!p->next || j>i-1)	//i不合法
		return ERROR;
	
	s = p->next;		//s指向要删除的结点
	*e = s->data;		//将要删除的结点的元素值赋给*e
	
	p->next = s->next;	//p的后继指针指向要删除结点的下一个 
	free(s);			//释放要被删除的结点 
	return OK; 			//删除成功 
}

void ListTraverse(LinkList L, void(* visit)(ElemType))
{
	//初始条件：L存在
	//操作结果：依次对L的每个数据元素调用visit()函数
	LNode *p = L->next;		//p指向首元结点
	while(p)				//p指向的结点存在 
	{
		(* visit)(p->data);	//对p指向的结点的数据元素调用visit函数 
		p = p->next;		//p指向下一个结点 
	} 
	printf("\n");
}










