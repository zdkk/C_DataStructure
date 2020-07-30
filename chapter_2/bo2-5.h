//bo2-5
//静态链表（数据结构由c2-3.h定义）的基本操作13个，包括2.13-2.16

#define DestroyList ClearList	//DestroyList和ClearList操作相同
int Malloc(SLinkList space)	//算法2.15
{
	//若备用链表非空，则返回分配的结点下标（备用链表的 第一个结点）；否则返回0
	int i = space[0].cur;	//备用链表的第一个结点位置
	if(i)					//备用链表非空 
	{
		space[0].cur = space[i].cur;	//备用链表的头结点指向原备用链表的第二个结点 
	}	
	return i;
} 

void Free(SLinkList space, int k)	//算法2.16
{
	//将下标为k的空闲结点回收到备用链表中（成为备用链表的第一个结点）
	space[k].cur = space[0].cur;	//回收结点的游标指向备用链表的第一个结点 
	space[0].cur = k;				//备用链表的头结点指向新回收的结点 
} 

void InitList(SLinkList L)			//算法2.14 
{
	//操作结果：构造一个空链表L，表头为L的最后一个单元L[MAX_SIZE - 1],其余单元链成一个备用链表，表头为L的第一个单元L[0]，0表示空指针
	L[MAX_SIZE - 1].cur = 0;	//将L的最后一个单元作为空链表的头结点 
	int i;
	
	for(i=0; i<MAX_SIZE-2; i++)	//将其余单元链成以L[0]为头结点的备用链表 
		L[i].cur = i+1;
	L[i].cur = 0;
}

void ClearList(SLinkList L)
{
	//初始条件：L已经存在
	//操作结果：将L置为空表
	//实现方式：将备用链表尾结点的后继指向已用链表首元结点，将已用链表头结点指针域清空 
	int j, i = L[0].cur;	//i指向备用链表首元结点
	while(i)	//未到备用链表尾节点
	{
		j = i;			//j指向当前节点 
		i = L[i].cur;	//i指向下一结点 
	} 
	L[j].cur = L[MAX_SIZE-1].cur;	//链表的首元结点接到备用链表尾部
	L[MAX_SIZE-1].cur = 0;			//链表清空 
}

Status ListEmpty(SLinkList L)
{
	//若L是空表返回TRUE，否则返回FALSE
	if(L[MAX_SIZE-1].cur)			//链表非空，返回FALSE 
		return FALSE;
	else							//否则返回TRUE 
		return TRUE; 
}

int ListLength(SLinkList L)
{
	//返回L中数据元素个数
	int i = 0;
	int j = L[MAX_SIZE - 1].cur;	//j指向链表首元结点 
	while(j)		//未到链表末尾 
	{
		i++;		//计数器加一 
		j = L[j].cur;//j指向下一个结点 
	}
	return i; 
}

Status GetElem(SLinkList L, int i, ElemType *e)
{
	//用e返回L中第i个元素的值，返回OK，否则返回ERROR
	int j = 1, k = L[MAX_SIZE-1].cur;	//k指向首元结点
	
	while (k && j<i)	//顺时针向后查找，直到k指向第i个结点或k为空（第i个结点不存在）
	{
		k = L[k].cur;	//k指向下一结点
		j++;			//计数器加一 
	}
	if(!k || j>i)		//i不合法
		return ERROR;
	*e = L[k].data;		//将第i个元素的值赋给*e 
	return OK; 
}

int LocateElem(SLinkList L, ElemType e)	//算法2.13
{
	//在静态链表L中查找第一个值为e的元素。若找到，返回其在L中的位序，否则返回0
	int i = L[MAX_SIZE-1].cur;	//i指向首元结点
	
	while(i)	//i指向非空结点
	{
		if(L[i].data == e)	//如果i指向的结点数据元素的值为e，返回其位序 
			return i;
		i = L[i].cur;		//否则i指向下一结点 
	}	
	return 0;				//没找到，返回0 
}

Status PriorElem(SLinkList L, ElemType cur_e, ElemType *pre_e)
{
	//初始条件：L存在
	//操作结果：若cur_e是L的数据元素且不是第一个，用pre_e返回它的前驱，返回OK；否则操作失败，pre_e无定义，返回ERROR 
	int i = L[MAX_SIZE-1].cur, j;		//i指向首元结点 
	while(i && L[i].cur)				//i指向的结点以及i的后继结点不为空 
	{
		j = L[i].cur;					//j指向i的后继结点
		if(L[j].data == cur_e)			//j指向结点的数据元素等于cur_e
		{
			*pre_e = L[i].data;			//将i指向的结点的数据元素赋值给*pre_e 
			return OK;
		}
		i = j;							//i指向下一结点 
	}
	return ERROR; 
}

Status NextElem(SLinkList L, ElemType cur_e, ElemType *next_e)
{
	//初始条件：L存在
	//操作结果：若cur_e是L的数据元素且不是最后一个，用next_e返回它的后继，返回OK；否则操作失败，next_e无定义，返回ERROR 
	int i = L[MAX_SIZE - 1].cur;		//i指向首元结点
	while(i && L[i].cur)				//i指向的结点以及i的后继结点不为空
	{
		if(L[i].data == cur_e)			//i指向结点的数据元素等于cur_e 
		{
			*next_e = L[L[i].cur].data;	//将i的后继结点数据元素赋给*next_e
			return OK;	 
		}
		i = L[i].cur;					//i指向后继结点 
	}
	return ERROR; 
}

Status ListInsert(SLinkList L, int i, ElemType e)
{
	//初始条件：L存在
	//操作结果：向L中第i(1<=i<=ListLength(L)+1)个结点插入元素e，成功返回OK，否则返回ERROR 
	int j = 0;	//计数器初始化0
	int k = MAX_SIZE - 1;	//k指向头结点
	int r = Malloc(L);		//分配空间
	if(!r)	//没有空间可用，分配失败 
		return ERROR;
	L[r].data = e;			//为新分配结点的数据元素赋值e 
	
	while (k && j<i-1)		//顺时针向后查找，直到k指向第i-1个结点或k为空（第i-1个结点不存在）
	{
		k = L[k].cur;
		j++;
	}
	if (!k || j>i-1)		//i不合理
		return ERROR;
	
	L[r].cur  =L[k].cur;	//r的后继指针指向k的后继结点
	L[k].cur = r;			//k的后继结点指向r 
	return OK; 
}

Status ListDelete(SLinkList L, int i, ElemType *e)
{
	//初始条件：L存在
	//操作结果：若i合理(1<=i<=ListLength(L)),用e返回第i个结点数据元素，返回OK，否则返回ERROR
	int j = 0;	//计数器初始化0
	int k = MAX_SIZE - 1;	//k指向头结点
	int r;
	
	while(L[k].cur && j<i-1)	//寻找第i-1个节点，并令k指向其前驱
	{
		k =L[k].cur;			//k指向下一结点 
		j++;					//计数器加一 
	} 
	if(!L[k].cur || j>i-1)		//i不合理
		return ERROR;
	
	r = L[k].cur;				//r指向待删除结点
	*e = L[r].data;				//用e返回待删除结点数据元素
	L[k].cur = L[r].cur;		//待删除结点前驱指向待删除结点后继
	Free(L, r);					//回收待删除结点 
	return OK; 
}

void ListTraverse(SLinkList L, void(*visit)(ElemType))
{
	//初始条件：L存在
	//操作结果：依次对L每个结点的数据元素调用visit函数
	int i = L[MAX_SIZE-1].cur;	//i指向首元结点
	while(i)					//i指向非空结点
	{
		(*visit)(L[i].data);	//对当前结点数据元素调用visit函数 
		i = L[i].cur;			//i指向下一结点 
	} 
	printf("\n");
 } 





	 












