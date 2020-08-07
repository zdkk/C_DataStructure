//bo3-1.h
//˳��ջ�������� 9��
void InitStack(SqStack *S)
{
	//�������������һ����ջ
	S->base = (SElemType *)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	if(!S->base)	//��̬�洢�ռ����ʧ��
		exit(OVERFLOW);
	S->top = S->base;	//ջ��ָ��ָ��ջ�� 
	S->stacksize = STACK_INIT_SIZE;	//��ǰ�Ѿ�����Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
} 

void DestroyStack(SqStack *S)
{
	//��ʼ������S����
	//�������������ջS
	free(S->base);	//�ͷ�ջ�ռ�
	S->base = S->top = NULL;	//ջ��ջ��ָ���Ϊ��
	S->stacksize = 0;		//ջ����Ϊ0 
}

void ClearStack(SqStack *S)
{
	//��ʼ������S����
	//�����������S��Ϊ��ջ
	S->top = S->base;	//ջ��ָ��ָ��ջ��  
}

Status StackEmpty(SqStack S)
{
	//��ʼ������S����
	//�����������SΪ��ջ������TRUE�����򷵻�FALSE
	if(S.top == S.base)
		return TRUE;
	else
		return FALSE;	
}

int StackLength(SqStack S)
{
	//��ʼ������S����
	//�������������S��Ԫ�ظ���
	return S.top - S.base; 
}

Status GetTop(SqStack S, SElemType *e)
{
	//��ʼ����:S����
	//�����������ջ��Ϊ�գ���ջ��Ԫ�ظ���e������OK�����򷵻�ERROR
	if(StackEmpty(S))	//ջΪ�� 
		return ERROR;
	*e = *(S.top - 1); //��ջ��Ԫ�ظ���e
	return OK; 
}

void Push(SqStack *S, SElemType e)
{
	//��ʼ������S����
	//�������������eΪS�µ�ջ��Ԫ��
	if(S->top-S->base == S->stacksize)	//ջ��
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize+STACK_INCREMENT)*sizeof(SElemType));	//׷�Ӵ洢�ռ�
		if(!S->base)	//ʧ��
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;	//�޸�ջ��ָ�룬ָ���µ�ջ�� 
		S->stacksize += STACK_INCREMENT;	//�޸�ջ�ĳ��� 
	} 
	*(S->top) = e;						//��Ԫ��e��ջ 
	S->top++; 							//ջ��ָ����� 
}

Status Pop(SqStack *S, SElemType *e)
{
	//��ʼ������S����
	//�����������S��Ϊ�գ���ջ��Ԫ�ظ���e������OK�����򷵻�ERROR
	if(StackEmpty(*S))
		return ERROR;
	S->top--;			//ջ��ָ��ǰ�� 
	*e = *S->top;		//��ջ��Ԫ�ظ���e
	return OK; 
}

void StackTraverse(SqStack S, void(*visit)(SElemType))
{
	//��ջ�׵�ջ�����ζ�ÿ������Ԫ�ص���visit()����
	SElemType *p = S.base;
	while(S.top > p)	//pָ��ջԪ��
	{
		(*visit)(*p);
		p++;
	}
	printf("\n"); 
}



















