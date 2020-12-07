//bo5-1.h 顺序存储数组（由c5-1.h定义）的基本操作（5个）
Status InitArray(Array *A, int dim, ...)
{
	//若维数dim和各维长度合法，则构造相应的数组A并返回OK，否则返回ERROR
	
	int elemtotal = 1;	//数组元素总数，初值为1
	int i;
	va_list ap;			//变长参数表类型，在stdarg.h中
	
	if (dim < 1 || dim >MAX_ARRAY_DIM)	//数组维数越界
		return ERROR;	
	A->dim = dim;						//数组维数 
	A->bounds = (int *)malloc(sizeof(int) * dim);	//动态分配数组维界基址
	if (!A->bounds)
		exit(OVERFLOW);
	va_start(ap,dim);					//变长参数"..."从形参dim之后开始 
	for(i = 0; i < dim; i++)
	{
		A->bounds[i] = va_arg(ap,int);	//逐一将变长参数赋给A->bounds[i]
		if(A->bounds[i] < 0)
			return UNDERFLOW;			//在math.h中定义为4
		elemtotal *= A->bounds[i];		//数组元素总数 = 各维长度之乘积 
	}
	va_end(ap);							//结束提取变长参数
	A->base = (ElemType *)malloc(sizeof(ElemType) * elemtotal);	//动态分配数组存储空间
	if(!A->base)
		exit(OVERFLOW);
	A->constants = (int *)malloc(sizeof(int) * dim);			//动态分配数组偏移量基址
	if(!A->constants)
		exit(OVERFLOW);
	A->constants[dim - 1] = 1;			//最后一维的偏移量为1
	for (i = dim - 2; i >= 0; i--)
	{
		A->constants[i] = A->bounds[i + 1] * A->constants[i + 1];	//每一维的偏移量 
	}
	return OK; 
} 

void DestroyArray(Array *A)
{
	//销毁数组A 
	if(A->base)
		free(A->base);
	if(A->bounds)
		free(A->bounds);
	if(A->constants)
		free(A->constants);
	A->base = A->bounds = A->constants = NULL;
	A->dim = 0;
}

Status Locate(Array A, va_list ap, int *off)
{
	//若ap指示的各下标值合法，则求出该元素在A中的相对地址off 
	int i, ind;
	*off = 0;
	
	for (i = 0; i < A.dim; i++)	//逐一读取各维下标值 
	{
		ind = va_arg(ap, int);
		if(ind < 0 || ind >= A.bounds[i])	//各维下标不合法
			return OVERFLOW;
		*off += A.constants[i] * ind; 
	}
	return OK;
}

Status Value(ElemType *e, Array A, ...)
{
	//...依次为各维的下标值，若各下标合法，则e被赋值为A的相应的元素值
	va_list ap;		//变长参数表类型，在stdarg.h中
	int off;
	va_start(ap,A);
	if(Locate(A, ap, &off) == OVERFLOW)	//调用Locate求得变长参数所指单元的相对地址off 
		return ERROR;
	*e = *(A.base + off); 				//将变长参数所指单元值赋给e
	return OK; 
}

Status Assign(Array A, ElemType e, ...)	//变量A的值不变，故不需要传指针
{
	//...依次为各维下标值，若各下标合法，则将e的值赋给A的指定的元素
	va_list ap;
	int off;
	va_start(ap, e);
	if(Locate(A, ap, &off) == OVERFLOW)	//调用Locate求得变长参数所指单元的相对地址off 
		return ERROR;
	*(A.base + off) = e;				//将e的值赋给变长参数所指单元 
	return OK;
} 




















