//bo3-1.h
//顺序栈基本操作 9个
void InitStack(SqStack *S)
{
	//操作结果：构造一个空栈
	S->base = (SElemType *)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	if(!S->base)	//动态存储空间分配失败
		exit(OVERFLOW);
	S->top = S->base;	//栈顶指针指向栈底 
	S->stacksize = STACK_INIT_SIZE;	//当前已经分配的存储空间，以元素为单位 
} 

void DestroyStack(SqStack *S)
{
	//初始条件：S存在
	//操作结果：销毁栈S
	free(S->base);	//释放栈空间
	S->base = S->top = NULL;	//栈顶栈底指针均为空
	S->stacksize = 0;		//栈长度为0 
}

void ClearStack(SqStack *S)
{
	//初始条件：S存在
	//操作结果：将S置为空栈
	S->top = S->base;	//栈顶指针指向栈底  
}

Status StackEmpty(SqStack S)
{
	//初始条件：S存在
	//操作结果：若S为空栈，返回TRUE；否则返回FALSE
	if(S.top == S.base)
		return TRUE;
	else
		return FALSE;	
}

int StackLength(SqStack S)
{
	//初始条件：S存在
	//操作结果：返回S中元素个数
	return S.top - S.base; 
}

Status GetTop(SqStack S, SElemType *e)
{
	//初始条件:S存在
	//操作结果：若栈不为空，将栈顶元素赋给e，返回OK；否则返回ERROR
	if(StackEmpty(S))	//栈为空 
		return ERROR;
	*e = *(S.top - 1); //将栈顶元素赋给e
	return OK; 
}

void Push(SqStack *S, SElemType e)
{
	//初始条件：S存在
	//操作结果：插入e为S新的栈顶元素
	if(S->top-S->base == S->stacksize)	//栈满
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize+STACK_INCREMENT)*sizeof(SElemType));	//追加存储空间
		if(!S->base)	//失败
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;	//修改栈顶指针，指向新的栈顶 
		S->stacksize += STACK_INCREMENT;	//修改栈的长度 
	} 
	*(S->top) = e;						//新元素e入栈 
	S->top++; 							//栈顶指针后移 
}

Status Pop(SqStack *S, SElemType *e)
{
	//初始条件：S存在
	//操作结果：若S不为空，将栈顶元素赋给e，返回OK；否则返回ERROR
	if(StackEmpty(*S))
		return ERROR;
	S->top--;			//栈顶指针前移 
	*e = *S->top;		//将栈顶元素赋给e
	return OK; 
}

void StackTraverse(SqStack S, void(*visit)(SElemType))
{
	//从栈底到栈顶依次对每个数据元素调用visit()函数
	SElemType *p = S.base;
	while(S.top > p)	//p指向栈元素
	{
		(*visit)(*p);
		p++;
	}
	printf("\n"); 
}



















