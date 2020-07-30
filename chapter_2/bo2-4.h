//bo2-4.h
//不带头结点的单链表的另外两个操作

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	//初始条件：L存在
	//操作结果：若cur_e是L的数据元素且不是第一个，用pre_e返回其前驱，返回OK
		//否则操作失败，pre_e无定义，返回ERROR
	LNode *p, *q;
	p = L;		//p指向首元结点
	
	while(p->next)		//p所指结点的后继不为空
	{
		q = p->next;	//q指向p的后继 
		if(q->data == cur_e)	//q所指结点数据元素值为cur_e
		{
			*pre_e = p->data;	//将p指向结点的数据元素的值赋给*pre_e 
			return OK;	
		}
		p = q;		//p的后继结点数据元素不为cur_e，p后移	
	} 
	return ERROR;	//操作失败，返回ERROR 
}

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	//初始条件：L存在
	//操作结果：若cur_e是L的数据元素且不是最后一个，用next_e返回其后继，返回OK。否则操作失败，next_e无定义，返回ERROR
	LNode *p, *q;
	p = L;			//p指向首元结点
	
	while (p && p->next)		//p指向的结点和p的后继结点都不为空
	{
		q = p->next;			//q指向p的后继结点 
		if(p->data == cur_e)	//p所指结点数据元素值为cur_e	
		{
			*next_e = q->data;	//将p的后继结点数据元素赋值给*next_e
			return OK; 
		}
		p = q;					//p的数据元素值不等于cur_e, p指向后继结点 
	} 
	return ERROR;
} 
