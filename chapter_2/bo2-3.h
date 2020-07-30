//bo2-3.h
//不设头结点的单链表部分基本操作（9个）
#define DestroyList ClearList	//没有头结点的单链表清空和销毁是同样的操作
void InitList(LinkList *L)
{
	//操作结果：构造一个空的线性表L
	*L = NULL;	
} 

void ClearList(LinkList *L)
{
	//初始条件：L已经存在
	//操作结果：将L置空 
	LNode *p = *L, *q;
	while(p)		//*L不为空 
	{
		q = p;		//q指向首元结点 
		p = p->next;	//p指向下一结点 （新的首元结点） 
		free(q);		//释放q结点（首元结点） 
	}
	*L = NULL;
}

Status ListEmpty(LinkList L)
{
	//初始条件：L存在
	//操作结果：若L为空表，返回TRUE，否则返回FALSE 
	if(L)
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{
	//初始条件：L已经存在
	//操作结果：返回L中数据元素个数
	int i = 0;	//计数器初值为0
	LNode *p = L;	//p指向首元结点
	while(p)	//p指向的结点（不为空）
	{
		i++;
		p = p->next;
	}
	return i; 
}

Status GetElem(LinkList L, int i, ElemType *e)
{
	//初始条件：L存在，L为不设头结点的单链表的头指针 
	//操作结果：当第i个元素存在时，其值赋给*e，返回OK，否则返回FALSE
	int j = 1;		//计数器初值为0 
	LNode *p = L; 	//p指向首元结点
	if(i<1)	//i值不合法
		return ERROR;
	while(p && j<i)		//未到第i个元素，也未到表尾
	{
		j++;
		p = p->next;	
	} 
	if(j==i && p)		//存在第i个元素
	{
		*e = p->data;
		return OK;
	}
	return ERROR;		//不存在第i个元素返回ERROR 
}

int LocateElem(LinkList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
	//初始条件：L存在，L为指向首元结点的单链表头指针，compare()是数据元素判定函数，满足为1，否则为0
	//操作结果：返回L中第一个满足关系compare()的数据元素的位序，不存在则返回0
	int j = 1;
	LNode *p = L;
	while(p)	//p不为空
	{
		if((*compare)(p->data, e))	//判断当前p所指向结点的数据元素是否满足条件 
			return j;				//满足返回当前结点位序 
		j++;						//计数器加一 
		p = p->next;				//p指向下一结点 
	}
	return 0;		//满足条件的元素不存在返回0 
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	//初始条件：L存在，L是指向单链表首元结点的头指针。在第i 个位置之前插入元素e
	//操作结果：若i合法（1<=i<=n+1）,在i的位置插入元素e，返回OK，否则返回ERROR
	int j = 1;		//计数器初始化1 
	LNode *p = *L, *s;	//p指向首元结点 
	if(i<1)			//i不合法
		return ERROR;
	 
	s = (LNode *)malloc(sizeof(LNode));
	if(!s)	//分配存储空间失败
		exit(OVERFLOW); 
	s->data = e;	//s数据域赋值e
	
	if(i==1)	//插在表头
	{
		s->next = *L;	//新结点指向原首元结点 
		*L = s;			//新结点成为首元结点 
	} 
	else
	{
		//插在L其他位置
		while(p && j<i-1)	//寻找第i-1个结点
		{
			j++;
			p = p->next;	
		}
		if(!p)	//i大于表长加一
			return ERROR;
		
		s->next = p->next;	//新结点指向原第i个结点
		p->next = s;		//原第i-1个结点指向新结点 
	}
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	//初始条件：在不设头结点的单链表L中。
	//操作结果：若i值合法（1<=i<=ListLength(L)），删除第i个结点用*e返回其值，返回OK，否则返回ERROR
	int j = 1;
	LNode *p = *L, *q;
	
	if(!(*L))		//L为空表,不存在可以删除的元素 
		return ERROR;
	if(i==1)	//删除首元结点
	{
		*L = p->next;		//*L指向第二个结点 
		*e = p->data;		//将待删除的结点数据元素值赋给*e 
		free(p);			//删除待释放结点 
	}
	else
	{
		//删除其他结点
		while(p->next && j<i-1)	 //寻找第i个结点并令p指向其前驱
		{
			p = p->next;
			j++;	
		}
		if(!(p->next) || j>i-1)			//i不合法 
			return ERROR; 
		q = p->next;			//q指向待删除结点 
		*e = q->data;			//将待删除结点数据元素赋值给*e 
		p->next = q->next;		//待删除结点的前驱指向待删除结点的后继 
		free(q);				//释放待删除结点 
	} 	
	return OK;
}

void ListTraverse(LinkList L, void(* visit)(ElemType))
{
	//初始条件：L存在
	//操作结果：用visit()函数对每个结点数据元素进行操作
	LNode *p = L;		//p指向首元结点 
	
	while (p)			//p所指结点存在 
	{
		(*visit)(p->data);	//对p所指向结点数据元素调用函数visit() 
		p = p->next;		//p指向下一结点 
	}
	printf("\n");
}












