//bo2-7.h 
//带头结点的双向循环链表的基本操作（14个） 包括2.18，2.19

void InitList(DuLinkList *L)
{
	//操作结果：产生双向循环链表
	*L = (DuLNode *)malloc(sizeof(DuLNode));
	if(!(*L))
		exit(OVERFLOW);
	(*L)->next = (*L)->prior = (*L); 
} 

void ClearList(DuLinkList *L)
{
	//初始条件：L存在
	//操作结果：将L置为空表
	DuLNode *p = (*L)->next;	//p指向首元结点
	
	while (p != (*L))			//p未指向头结点
	{
		p = p->next;			//p指向下一结点 
		free(p->prior);			//释放p的前驱结点 
	} 
	p->next = p->prior = p;		//头结点的两个指针域均指向自身 
}

void DestroyList(DuLinkList *L)
{
	//初始条件：L存在
	//操作结果：销毁L
	ClearList(L);	//链表清空 
	free(*L);		//释放头结点
	(*L) = NULL;	//*L不指向任何存储单元 
}

Status ListEmpty(DuLinkList L)
{
	//初始条件：L存在
	//操作结果：若L为空返回TRUE，否则返回FALSE
	if(L->next == L && L->prior == L)
		return TRUE;
	else
		return FALSE; 
}

int ListLength(DuLinkList L)
{
	//初始条件：L存在
	//操作结果：返回L中元素个数，若L为空，返回0
	DuLNode *p = L->next;		//p指向首元结点
	int i = 0;			//计数器初始化0
	
	while(p != L)		//p不指向头结点
	{
		i++;
		p = p->next;
	}
	return i; 
}

Status GetElem(DuLinkList L, int i, ElemType *e)
{
	//初始条件：L存在
	//操作结果：当第i个元素存在时，用*e返回其值，返回OK；否则返回ERROR
	int j = 1;		//计时器初始化1
	DuLNode *p = L->next;	//p指向首元结点 
	
	while (p!=L && j<i)		//顺指针向后找，直到p指向第i个元素或p指向头结点 
	{
		p = p->next;
		j++;
	}
	if(p==L || j>i)		//i不合理
		return ERROR;
	
	*e = p->data;		//取第i个结点值赋给*e
	return OK; 
}

int LocateElem(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	//初始条件：L存在
	//操作结果：返回L中第一个与e满足compare关系的元素位序，若不存在这样的元素，返回0
	int i = 1;				//计数器初始化1 
	DuLNode *p = L->next; 	//p指向首元结点
	
	while (p!=L)			//p不指向头结点
	{
		if((*compare)(p->data, e))
			return i;
		i++;				//计数器加一 
		p = p->next;		//p指向下一结点 
	} 
	return 0; 
}

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType *pre_e)
{
	//初始条件：L存在
	//操作结果：若L中存在结点数据元素等于cur_e且不是首元结点，将其前驱结点数据元素赋给*pre_e,返回OK；否则pre_e无定义，返回ERROR
	DuLNode *p = L->next->next;	//p指向第二个结点 
	
	while (p != L)		//p不指向头结点
	{
		if(p->data == cur_e)	//p所指结点数据元素值等于cur_e 
		{
			*pre_e = p->prior->data;	//将p的前驱结点数据元素赋给pre_e指向的变量
			return OK; 
		}
		p = p->next;			//p指向下一结点 
	} 
	return ERROR;
}

Status NextElem(DuLinkList L, ElemType cur_e, ElemType *next_e)
{
	//初始条件：L存在
	//操作结果：若L中存在结点数据元素等于cur_e且不是尾结点，将其后继结点数据元素赋给*next_e,返回OK；否则next_e无定义，返回ERROR
	DuLNode *p = L->next;	//p指向首元结点
	
	while (p->next != L)	//p的后继结点不指向头结点
	{
		if(p->data == cur_e)	//p指向的结点数据元素值为cur_e
		{
			*next_e = p->next->data;
			return OK;
		}
		p = p->next; 
	}
	return ERROR; 
}

DuLinkList GetElemP(DuLinkList L, int i)	//新增
{
	//初始条件：L存在
	//操作结果：返回第i个元素的地址，i为0表示返回头结点地址，否则返回NULL
	DuLNode *p = L; 	//p指向头结点
	int j;
	
	if(i<0 || i>ListLength(L))
		return NULL;
	
	for (j=0; j<i; j++)
	{
		p = p->next;	//p指向下一结点	
	}	
	return p; 
 } 

Status ListInsert(DuLinkList *L, int i, ElemType e)
{
	//初始条件：L存在
	//操作结果：若i合理，在L中第i个结点前插入数据元素为e的新结点，返回OK；否则返回ERROR
	int j;
	DuLNode *p, *s;
	
	p = GetElemP(*L, i-1);		//获取第i-1个结点的指针
	if(!p)						//若p为NULL
		return ERROR;
		
	s = (DuLNode *)malloc(sizeof(DuLNode));
	if(!s)	//分配存储空间失败
		exit(OVERFLOW);
	s->data = e;
	
	s->prior = p;		//新结点p的前驱指针指向p结点 
	s->next = p->next;	//新结点后继指针指向p的后继结点
	p->next->prior = s;	//p的原后继结点的前驱指针指向新结点 
	p->next = s; 		//p的后继指针指向新结点
	return OK; 
}

Status ListDelete(DuLinkList *L, int i, ElemType *e)
{
	//初始条件：L存在
	//操作结果：若i合法（1<=i<=n)，删除第i各结点并将其数据元素赋给e指向的变量，返回OK；否则返回ERROR
	DuLNode *p = GetElemP(*L, i);		//获取第i个节点指针 
	
	if(p == NULL)						//第i个结点不存在 
		return ERROR;
	
	*e = p->data;
	p->prior->next = p->next;			//p的前驱结点的后继指针指向p的后继结点 
	p->next->prior = p->prior;			//p的后继结点的前驱指针指向p的前驱结点 
	free(p);							//释放p结点
	return OK; 
}

void ListTraverse(DuLinkList L, void(*visit)(ElemType))
{
	//初始条件：L存在
	//操作结果：从头结点出发，正序对每个结点数据元素调用函数visit()
	DuLNode *p = L->next;	//p指向首元结点
	while (p != L)			//p不指向头结点
	{
		(*visit)(p->data);	
		p = p->next;
	} 
	printf("\n");
}

void ListTraverseBack(DuLinkList L, void(*visit)(ElemType))
{
	//初始条件：L存在
	//操作结果：从头结点出发，倒序对每个结点数据元素调用函数visit()
	DuLNode *p = L->prior;	//p指向首元结点
	while (p != L)			//p不指向头结点
	{
		(*visit)(p->data);	
		p = p->prior;
	} 
	printf("\n");
}














