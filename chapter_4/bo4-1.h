//bo4-1.h
//串的定长顺序存储结构基本操作（12个）
#include <string.h>
#define DestroyStr ClearStr		//DestroyStr和ClearStr作用相同
#define InitStr ClearStr		//InitStr与ClearStr作用相同

Status StrAssign(SString T, char* chars)
{
	//生成一个值等于chars的串T
	int i;
	if(strlen(chars) > MAX_STR_LEN)	//chars的长度大于最大串长
		return ERROR;
	else
	{
		T[0] = strlen(chars);	//0号单元存储串的长度
		for(i=1; i<=T[0]; i++)
		{
			T[i] = chars[i-1];	
		}	
		return OK;
	}	
} 

void StrCopy(SString T, SString S)
{
	//由串S复制得串T
	int i;
	
	for (i=0; i<=S[0]; i++)
		T[i] = S[i]; 
}

Status StrEmpty(SString S)
{
	//若S为空串，返回TRUE，否则返回FALSE
	return S[0] ? FALSE : TRUE; 
}

int StrCompare(SString S, SString T)
{
	//初始条件：S和T存在
	//操作结果：若S>T返回值>0;若S<T返回值<0;若S==T返回值0
	int i;
	for (i=1; i<=S[0]&&i<=T[0]; i++)
		if(S[i] != T[i])
			return S[i] - T[i];
	return S[0] - T[0]; 
}

int StrLength(SString S)
{
	//返回S中元素个数
	return S[0]; 
}
void ClearStr(SString S)
{
	//初始条件：S存在
	//操作结果：清空S
	S[0] = 0;	//令串长为0 
}

Status Concat(SString T, SString S1, SString S2)
{
	//用T返回S1和S2连接而成的新串。若未截断返回TRUE；否则返回FALSE
	int i;
	
	if (S1[0] + S2[0] <= MAX_STR_LEN)	//未截断
	{
		for (i=1; i<=S1[0]; i++)
			T[i] = S1[i];
		for (i=1; i<=S2[0]; i++)
			T[i+S1[0]] = S2[i];
		T[0] = S1[0] + S2[0];
		return TRUE;
	} 
	else								//截断S2
	{
		for (i=1; i<=S1[0]; i++)
			T[i] = S1[i];
		for (i=1;i<=MAX_STR_LEN-S1[0]; i++)
			T[i+S1[0]] = S2[i];
		T[0] = MAX_STR_LEN;
		return FALSE;		
	} 
}
Status SubStr(SString Sub, SString S, int pos, int len)
{
	//用Sub返回串S的自pos个字符起长度为len的子串
	int i;
	if(pos<0 || pos>S[0] || len<0 || len>S[0]-pos+1)	//pos和len超出范围
		return ERROR;
	for(i=1; i<=len; i++)
		Sub[i] = S[i+pos-1];
	Sub[0] = len;
	return OK; 
}

int Index1(SString S, SString T, int pos)
{
	//返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数值为0
	//其中，T非空，1<=pos<=StrLen(S)
	int i, j;		//指示主串和子串当前比较字符
	
	if (1<=pos && pos<=S[0])	//pos合适
	{
		i = pos;				//从主串第pos个字符开始和子串T的第一个字符比较
		j = 1;
		
		while (i<=S[0] && j<=T[0])
			if (S[i] == T[j])
			{
				i++;
				j++;	
			}
			else
			{
				i = i - j + 2;		//两指针后退重新匹配
				j = 1; 
			}
		if (j> T[0])				//主串S中存在子串T
			return i - T[0];
		else						//主串中不存在子串T
			return 0; 
	} 
	else						//pos范围不合适 
		return 0;
}

Status StrInsert(SString S, int pos, SString T)
{
	//初始条件：串S和T存在，1<=pos<=StrLength(S)+1
	//操作结果：在串S的第pos个字符前插入串T，完全插入返回TRUE，否则返回FALSE
	int i;
	
	if (pos<1 || pos>S[0]+1)	//pos超出范围
		return ERROR;
	if (S[0]+T[0] <= MAX_STR_LEN)	//完全插入
	{
		for (i=S[0]; i>=pos; i--)
			S[i+T[0]] = S[i];		//串S后移串T的长度，为插入T准备空间
		for(i=pos; i<pos+T[0]; i++)
			S[i] = T[i-pos+1];	
		S[0] += T[0];				//更新串S的长度
		return TRUE; 
	}
	else							//部分插入 
	{
		for (i=MAX_STR_LEN; i>=pos+T[0]; i--)	//移动串S中位于pos之后且移后仍然在串内的元素 
			S[i] = S[i-T[0]];
		for (i=pos;i<pos+T[0]&&i<=MAX_STR_LEN; i++)//在串S中插入串T（也可能是部分插入） 
			S[i] = S[i-pos+1];
		S[0] = MAX_STR_LEN;
		return FALSE;
	}
}

Status StrDelete(SString S, int pos, int len)
{
	//初始条件：S存在，1<=pos<=StrLen(S)-len+1
	//操作结果：从串S中删除自pos个字符起长度为len的子串
	int i;
	
	if (pos<1 || pos>S[0]-len+1 || len<0)	//pos和len不合法
		return ERROR;
	for (i=pos+len; i<=S[0]; i++)			//对于删除子串后的所有字符 
		S[i-len] = S[i]; 					//向前移动删除子串的长度
	S[0] -= len;							//更新串长度
	return OK; 
}

void StrPrint(SString S)
{
	//输出字符串S
	int i;
	for (i=1; i<=S[0]; i++)
		printf("%c",S[i]);
	printf("\n"); 
}


















































