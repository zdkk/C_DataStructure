//bo2-6.h
//设立尾指针的单循环链表 12个基本操作 

void InitList(LinkList *L)
{
	//操作结果：构造一个空单循环链表
	(*L) = (LinkList)malloc(sizeof(LNode));	//产生头结点，L指向该结点 
	if(!(*L))	//存储分配失败 
		exit(OVERFLOW); 
	(*L)->next = (*L);	//头指针的指针域指向头结点 
}

void ClearList(LinkList *L)
{
	//初始条件：L存在
	//操作结果：将L清空
	LNode *p, *q;
	 (*L) = (*L)->next;	//(*L)指向头结点 
	p = (*L)->next;		//p指向首元结点
	while(p != (*L))			//p不指向头结点 
	{
		q = p;				//q指向p结点 
		p = p->next;		//p指向下一结点 
		free(q);			//释放q结点 
	} 
	(*L)->next = (*L);		//头结点的指针域指向头结点 
}

void DestroyList(LinkList *L)
{
	//初始条件：L存在
	//操作结果：销毁L
	ClearList(L);		//清空L 
	free(*L);			//释放头结点 
	(*L) = NULL;		//L置为NULL 
}

Status ListEmpty(LinkList L)
{
	//初始条件：L存在
	//操作结果：若L为空返回TRUE，否则返回FALSE
	
	if(L->next == L)
		return TRUE;
	else
		return FALSE; 
}

int ListLength(LinkList L)
{
	//初始条件：L存在
	//操作结果：返回L中数据元素的个数
	int i = 0;	//计数器初始化0
	LNode *p = L->next;	//p指向头结点
	
	while (p != L)		//未到末尾 
	{
		i++;
		p = p->next;
	}
	return i; 
}

Status GetElem(LinkList L, int i, ElemType *e)
{
	//初始条件：L存在
	//操作结果：若i合理，将第i个结点数据元素赋给*e,返回OK，否则返回ERROR
	
	int j = 1;	//j初始化为1
	LNode *p = L->next->next;	//p指向首元结点
	
	while (p!=L->next && j<i)	//顺指针向后查找，直到p指向第i个结点或p再次指向头结点（第i个结点不存在） 
	{
		p = p->next;
		j++;
	}
	if(p==L->next || j>i)	//i不合理
		return ERROR;
	
	*e = p->data;
	return OK;
}

int LocateElem(LinkList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
	//初始条件：L存在
	//操作结果：返回L中第一个与e满足compare关系的数据元素的位序，不存在则返回0
	
	int i = 1;			//计数器初始化0 
	LNode *p = L->next->next; //p指向头结点
	
	while(p != L->next)	//p不指向头结点
	{
		if((*compare)(p->data, e))	//p所指结点元素和e满足关系compare 
			return i;
		i++;
		p = p->next;	
	} 
	return 0;				//没找到满足条件的元素，返回0； 
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	//初始条件：L存在
	//操作结果：若L中存在结点数据元素等于cur_e且不是第一个结点，将其前驱结点数据元素赋给pre_e,返回OK，否则返回ERROR
	LNode *p, *q;
	p = L->next->next;	//p指向首元结点
	
	while (p!=L->next && p->next!=L->next)	//p和p的后继结点都不指向头结点
	{
		q = p->next;				//q指向p的后继结点 
		if(q->data == cur_e)		//q指向的结点数据元素等于cur_e
		{
			*pre_e = p->data;
			return OK;
		}	
		p = q;						//p指向下一结点 
	} 
	return ERROR;
 } 
 
 Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	//初始条件：L存在
	//操作结果： 若cur_e是L的数据元素且不是最后一个，则用next_e返回它的后继，返回OK
		//否则操作失败，next_e无定义，返回ERROR
	LNode *p = L->next->next;		//p指向首元结点
	
	while (p!=L->next && p->next!=L->next)	//p所指结点有后继
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
	//初始条件：L存在
	//操作结果：若i合理（1<=i<=ListLength(L)+1）向L中第i个结点前插入结点，其数据元素为e，返回OK，否则返回ERROR
	LNode *p = (*L)->next, *s;		//p指向头结点
	int j = 0;						//计数器初始化0 
	if(i<1 || i>ListLength(*L)+1)	//i值不合法
		return ERROR;
	
	while(j<i-1)					//寻找第i-1个结点 
	{
		j++;
		p = p->next;
	}
	
	s = (LNode*)malloc(sizeof(LNode));
	if(!s)	//分配存储失败
		exit(OVERFLOW);
	s->data = e;
	s->next = p->next;				//新结点指向原第i个结点
	p->next = s;					//原第i-1个结点指向新结点
	if(p == *L)						//如果插入位置是表尾
	{
		*L = s;						//L指向新的尾结点	
	} 
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	//初始条件：L存在，1<=i<=ListLength(L)
	//操作结果：若i合理，删除第i个元素并赋值给e，返回OK，否则返回ERROR
	int j = 0;			//计数器初始化0 
	LNode *p, *q;	
	p = (*L)->next;		//p指向头结点 
	
	while(p->next!=(*L)->next && j<i-1)	//寻找第i-1个节点，并令p指向其前驱
	{
		p = p->next;
		j++;
	}
	if(p->next ==(*L)->next || j>i)	//i不合理
		return ERROR;
	
	q = p->next;		//q指向待删除结点
	p->next = q->next;	//带删除结点前驱结点的后继指针指向待删除结点的后继结点
	*e = q->data;		//将待删除结点值赋给*e 
	if(q == *L)			//待删除结点是尾结点
		*L =  p;		//*L指向新的表尾结点
	free(q); 			//释放待删除结点
	return OK; 
}

void ListTraverse(LinkList L, void(*visit)(ElemType))
{
	//初始条件：L存在
	//操作结果：依次对L的每个数据元素调用visit()函数
	LNode *p = L->next->next;		//p指向首元结点
	while(p != L->next)				//p不指向头结点 
	{
		(* visit)(p->data);	//对p指向的结点的数据元素调用visit函数 
		p = p->next;		//p指向下一个结点 
	} 
	printf("\n");
}







