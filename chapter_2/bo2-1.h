//bo2-1.h
//顺序存储的线性表（顺序存储结构由c2-1.h定义）的基本操作（12）个包含算法2.3-2.6

void InitList(SqList *L)	//算法2.3
{
	//操作结果：构造一个空的顺序表L
	L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if(!L->elem)					//存储空间分配失败 
		exit(OVERFLOW);
	L->length = 0;					//空表长度为0 
	L->listsize = LIST_INIT_SIZE;	//初始存储容量	
} 

void DestroyList(SqList *L)
{
	//初始条件：顺序表L已经存在
	//操作结果：销毁线性表L
	free(L->elem);		//释放L->elem所指的存储空间 
	L->elem = NULL;		//L->elem不再指向任何存储单元 
	L->length = 0;
	L->listsize = 0; 
 } 
void ClearList(SqList *L)
{
	//初始条件：线性表L已经存在
	//操作结果：将L置为空表
	L->length = 0;
	return; 
}

Status ListEmpty(SqList L)
{
	//初始条件：线性表L已经存在
	//操作结果：若L为空表，返回TRUE，否则返回FALSE
	if(L.listsize == 0)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L)
{
	//初始条件：线性表L已经存在
	//操作结果：返回L中数据元素的个数
	return L.length; 
}

Status GetElem(SqList L, int i, ElemType *e)
{
	//初始条件：顺序表L已经存在，1<=i<=ListLength(L)
	//操作结果：用e返回L中第i个数据元素的值
	if(i<1 || i>L.length)
		return ERROR;
	*e = L.elem[i-1];
	return OK; 
}

int LocateElem(SqList L, ElemType e, Status(* compare)(ElemType, ElemType))
//定义了一个指针变量compare，该指针变量可以指向返回值类型为 Status 型，且有两个ElemType参数的函数. 
{
	//初始条件：顺序表L已经存在，compare()是数据元素判定函数（满足为1，否则为0）
	//操作结果：返回L中第一个与e满足关系compare()的数据元素的位序
	//若这样的数据元素不存在，则返回0
	int i = 1;	//i的初始值为第一个元素的位序
	ElemType *p = L.elem;	//p的初始值为第一个元素的存储位置
	
	while (i<=L.length && !((*compare)(*p,e)))	//(*compare)(*p,e)是通过函数指针调用compare函数，而compare是调用者传进来的函数指针 
	{
		i++;
		p++;
	}
	if(i <= L.length)	//找到满足关系的数据元素
		return i;
	else				//未找到满足关系的数据元素 
		return 0; 
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
	//初始条件：L已经存在
	//操作结果：若cur_e是L的数据元素且不是第一个，用pre_e返回它的前驱；否则操作失败，pre_e无定义
	int i = 2;					//从第二个元素开始 
	ElemType *p = L.elem + 1;	//p指向第二个元素
	
	while (i<=L.length && (*p)!=cur_e)
	{
		i++;	//计数器加1 
		p++;	//p指向下一元素 
	}
	if(i<=L.length)	//找到了cur_e元素，并由p指向它 
	{
		p--;			//p指向cur_e前一个元素 
		*pre_e = *p;	//用pre_e返回p指向的元素 
		return OK;
	}
	else
		return ERROR;
	 
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
	//初始条件：L已经存在
	//操作结果：若cur_e是L的数据元素且不是最后一个，用next_e返回它的后继；否则操作失败，next_e无定义
	int i = 1;
	ElemType *p = L.elem;
	
	while (i<=L.length-1 && (*p)!=cur_e)
	{
		p++;
		i++;
	}
	if (i == L.length)
		return ERROR;
	else
	{
		p++;
		*next_e = *p;
		return OK;
	}
}

Status ListInsert(SqList *L, int i, ElemType e)	//算法2.4 
{
	//初始条件：L已经存在，1<=i<=ListLength(*L)+1
	//操作结果：在L中第i个位置之前插入新的数据元素e,L的长度加1
	ElemType *newbase, *q, *p;
	
	if(i<1 || i>L->length+1)		//插入位置不合法 
		return ERROR;
	
	if(L->length == L->listsize)	//当前存储空间已满，增加分配，修改
	{
		newbase = (ElemType *)realloc(L->elem, (L->listsize+LIST_INCREMENT)*sizeof(ElemType));
		if(!newbase)	//存储分配失败
			exit(OVERFLOW);
		L->elem = newbase;	//修改L->elem的地址
		L->listsize += LIST_INCREMENT;	//增加存储容量	
	}	
	
	q = L->elem + i -1;		//q为插入位置
	for(p=L->elem+L->length-1; p>=q; p--)
	{
		*(p+1) = *p;
	}
	*q = e; 
	L->length++;	//表长加一 
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)	//算法2.5 
{
	//初始条件：L存在，1<=i<=ListLength(*L)
	//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减一 
	ElemType *p, *q;
	
	if(i<1 || i>L->length)		//i值不合法 
		return ERROR;
	
	p = L->elem + i - 1;		//p为要删除元素的指针
	*e = *p;					//用e返回将被删除元素的值 
	q = L->elem + L->length -1;	//q指向表尾元素 
	for(; p<q; p++)
	{
		*p = *(p+1);
	}
	
	L->length--;				//表长减一
	return OK; 
}

void ListTraverse(SqList L, void(* visit)(ElemType *))
{
	//初始条件：L已经存在
	//操作结果：依次对L中每个数据元素调用visit函数，visit函数可以修改元素的值！ 
	ElemType *p = L.elem;
	int i;
	
	for(i=0; i<L.length; i++)
	{
		(*visit)(p+i);
	}
	printf("\n");
}












