//bo4-2.h
//串采用堆分配存储结构（由4-2.h定义）的基本操作（12个）
#define DestroyStr ClearStr

void InitStr(HSPtr P)
{
	//初始化（产生空串）字符串P
	P->length = 0;
	P->ch = NULL;	
}

void ClearStr(HSPtr P)
{
	//操作结果：将S清空
	free(P->ch);		//释放P->ch所指空间
	InitStr(P);			//初始化串P 
}

void StrAssign(HSPtr P, char chars[])
{
	//生成一个其值等于常量字符串chars的串P
	int i,j;
	if(P->ch)		//P->ch指向某个数据单元
		free(P->ch);//释放P->ch原有存储空间
	i = strlen(chars);	//求chars的长度i 
	if(!i)				//chars的长度为0
		InitStr(P);		//生成空串
	else
	{
		P->ch = (char *)malloc(sizeof(char)*i);	//分配存储空间
		if(!P->ch)	//分配失败
			exit(OVERFLOW);
		for (j=0; j<i; j++)	//分配成功后，复制串chars到P 
			P->ch[j] = chars[j];
		P->length = i;		//更新串T的长度	
	} 
}

void StrCopy(HSPtr P, HSPtr Q)
{
	//初始条件：串P存在
	//操作结果：由串Q复制得到串P
	int i;
	
	if (P->ch)	//串P不为空
		ClearStr(P);	//释放串T原有存储空间
	P->ch = (char *)malloc(sizeof(char) * Q->length);	//分配存储空间 
	if(!P->ch)	//分配失败
			exit(OVERFLOW);
	for(i=0; i<Q->length; i++)
		P->ch[i] = Q->ch[i];	//逐一复制字符
	P->length = Q->length; 
}

Status StrEmpty(HSPtr P)
{
	//操作结果：若P为空返回TRUE；否则返回FALSE
	return P->length ? FALSE : TRUE; 
}

int StrCompare(HSPtr P, HSPtr Q)
{
	//若串P>串Q，返回值>0;若串P==串Q，返回值=0;若P<Q,返回值<0
	int i;
	
	for (i=0; i<P->length && i< Q->length; i++)	//在有效范围内 
	{
		if(P->ch[i]!= Q->ch[i])					//逐一比较字符 
			return P->ch[i]	- Q->ch[i];			//不想等返回两者ASCII之差 
	}
	return P->length - Q->length;				//在有效范围内，字符相等但长度不等，返回长度之差 
}

int StrLength(HSPtr P)
{
	//操作结果：返回P中字符个数，称为串的长度
	return P->length; 
}

void Concat(HSPtr R, HSPtr P, HSPtr Q)
{
	//用串R返回由P和Q连接而成的新串
	int i;
	if(R->ch)	//串R不为空
		ClearStr(R);
	R->length = P->length + Q->length;	//R的长度为P和Q长度之和
	R->ch = (char *)malloc(sizeof(char) * R->length);	//分配串R的存储空间
	if(!R->ch)											//存储空间分配失败
		exit(OVERFLOW);
	for (i=0; i<P->length; i++)							//将P的字符逐一复制给R 
		R->ch[i] = P->ch[i];		
	for (i=0; i<Q->length; i++)							//将Q的字符注意复制到R（接在P字符串后） 
		R->ch[i+P->length] = Q->ch[i]; 
}

Status SubStr(HSPtr Sub, HSPtr P, int pos, int len)
{
	//用Sub返回串S的第pos个字符起长度为len的字符串
	//其中，1<=pos<=StrLen(P)且0<=len<=StrLength(S)-pos+1
	int i;
	
	if (pos<1 || pos>P->length || len<0 || len>P->length-pos+1)
		return ERROR;		//pos或者len大小不符合要求
	if(Sub->ch)	//Sub非空
		ClearStr(Sub);	//将Sub清空
	if(len)		//len非空
	{
		Sub->ch = (char *)malloc(sizeof(char) * len);	//分配存储空间
		if(!Sub->ch)
			exit(OVERFLOW);								//分配失败
		Sub->length = len;
		for (i=0; i<len; i++)							//复制P的子串到Sub 
			Sub->ch[i] = P->ch[pos-1+i];	
	} 
	return OK;		 
}

Status StrInsert(HSPtr P, int pos, HSPtr T)
{
	//1<=pos<=P->length+1
	//在串P的第pos个字符前插入串T
	int i;
	
	if (pos<0 || pos>P->length+1)
		return ERROR;
	
	if (T->length)	//T非空
	{
		P->ch = (char *)realloc(P->ch,(P->length+T->length)*sizeof(char));
		if(!P->ch)	//分配失败
			exit(OVERFLOW);
		for (i=P->length-1; i>=pos-1; i--)	//为插入T腾出位置 
			P->ch[i+T->length] = P->ch[i];
		for (i=0; i<T->length; i++)
			P->ch[pos-1+i] = T->ch[i];	//插入T
		P->length += T->length; 
	}
	return OK;
}

Status StrDelete(HSPtr P, int pos, int len)
{
	//从串P中删除第pos个字符起长度为len的子串
	int i;
	
	if (P->length < pos+len-1 || pos<0 || len <0)	//pos和len值超出范围
		return ERROR;
	for (i=pos-1; i<P->length-len; i++)	//将待删除子串之后的字符逐一前移
		P->ch[i] =  P->ch[i+len];
	P->length -= len;			//更新串的长度
	P->ch = (char *)realloc(P->ch, P->length*sizeof(char));	//重新分配S的存储空间
	return OK; 
}

void StrPrint(HSPtr P)
{
	//输出字符串P
	for (int i=0; i<P->length; i++)
		printf("%c", P->ch[i]) ;
	printf("\n");
}
















