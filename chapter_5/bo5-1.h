//bo5-1.h ˳��洢���飨��c5-1.h���壩�Ļ���������5����
Status InitArray(Array *A, int dim, ...)
{
	//��ά��dim�͸�ά���ȺϷ���������Ӧ������A������OK�����򷵻�ERROR
	
	int elemtotal = 1;	//����Ԫ����������ֵΪ1
	int i;
	va_list ap;			//�䳤���������ͣ���stdarg.h��
	
	if (dim < 1 || dim >MAX_ARRAY_DIM)	//����ά��Խ��
		return ERROR;	
	A->dim = dim;						//����ά�� 
	A->bounds = (int *)malloc(sizeof(int) * dim);	//��̬��������ά���ַ
	if (!A->bounds)
		exit(OVERFLOW);
	va_start(ap,dim);					//�䳤����"..."���β�dim֮��ʼ 
	for(i = 0; i < dim; i++)
	{
		A->bounds[i] = va_arg(ap,int);	//��һ���䳤��������A->bounds[i]
		if(A->bounds[i] < 0)
			return UNDERFLOW;			//��math.h�ж���Ϊ4
		elemtotal *= A->bounds[i];		//����Ԫ������ = ��ά����֮�˻� 
	}
	va_end(ap);							//������ȡ�䳤����
	A->base = (ElemType *)malloc(sizeof(ElemType) * elemtotal);	//��̬��������洢�ռ�
	if(!A->base)
		exit(OVERFLOW);
	A->constants = (int *)malloc(sizeof(int) * dim);			//��̬��������ƫ������ַ
	if(!A->constants)
		exit(OVERFLOW);
	A->constants[dim - 1] = 1;			//���һά��ƫ����Ϊ1
	for (i = dim - 2; i >= 0; i--)
	{
		A->constants[i] = A->bounds[i + 1] * A->constants[i + 1];	//ÿһά��ƫ���� 
	}
	return OK; 
} 

void DestroyArray(Array *A)
{
	//��������A 
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
	//��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�е���Ե�ַoff 
	int i, ind;
	*off = 0;
	
	for (i = 0; i < A.dim; i++)	//��һ��ȡ��ά�±�ֵ 
	{
		ind = va_arg(ap, int);
		if(ind < 0 || ind >= A.bounds[i])	//��ά�±겻�Ϸ�
			return OVERFLOW;
		*off += A.constants[i] * ind; 
	}
	return OK;
}

Status Value(ElemType *e, Array A, ...)
{
	//...����Ϊ��ά���±�ֵ�������±�Ϸ�����e����ֵΪA����Ӧ��Ԫ��ֵ
	va_list ap;		//�䳤���������ͣ���stdarg.h��
	int off;
	va_start(ap,A);
	if(Locate(A, ap, &off) == OVERFLOW)	//����Locate��ñ䳤������ָ��Ԫ����Ե�ַoff 
		return ERROR;
	*e = *(A.base + off); 				//���䳤������ָ��Ԫֵ����e
	return OK; 
}

Status Assign(Array A, ElemType e, ...)	//����A��ֵ���䣬�ʲ���Ҫ��ָ��
{
	//...����Ϊ��ά�±�ֵ�������±�Ϸ�����e��ֵ����A��ָ����Ԫ��
	va_list ap;
	int off;
	va_start(ap, e);
	if(Locate(A, ap, &off) == OVERFLOW)	//����Locate��ñ䳤������ָ��Ԫ����Ե�ַoff 
		return ERROR;
	*(A.base + off) = e;				//��e��ֵ�����䳤������ָ��Ԫ 
	return OK;
} 




















