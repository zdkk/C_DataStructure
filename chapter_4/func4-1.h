//func4-1.h
//与存储结构无关的两个基本操作
int Index(String S, String T, int pos)
{
	//模式匹配算法BF
	/*
		T为非空主串，若主串S中第pos个字符之后存在与T相等的子串
		返回第一个这样的子串在S中的位置，否则返回0
	*/
	int n, m, i;
	String sub;

	InitStr(sub);	//新增
	if (pos>0) 
	{
		n = StrLength(S);	//主串S的长度
		m = StrLength(T);	//模式串T的长度
		i = pos;

		while (i <= n-m+1)	//i从串S的pos到倒数第m个 
		{
			SubStr(sub, S, i, m);	//子串sub是从主串S的第i个字符起，长度为m的字串
			if (StrCompare(sub, T) != 0)//子串sub不等于模式串T 
				i++;					//继续向后比较 
			else
				return i; 				//返回模式串T的第一个字符在主串S中的位置 
		}
	}
	return 0; 
}

Status Replace(String S, String T, String V)
{
	//初始条件：串S，T和V存在，串T是非空串
	//操作结果：用串V替换主串S中出现的所有与串T相等的不重叠的子串 
		//S中的子串T--->V 
	int i = 1;	//从串S的第一个字符起查找串T
	Status k;
	
	if (StrEmpty(T))	//T是空串 
		return ERROR; 
	while (i)
	{
		i = Index(S, T, i);		//结果i为从上一个i之后找到的子串T的位置
		if (i)					//串S中存在串T
		{
			StrDelete(S, i, StrLength(T));	//删除串T
			k = StrInsert(S, i, V);	//在原串T的位置插入串V	
			if(!k)				//不能完全插入
				return ERROR;
			i += StrLength(V);	//在插入的串V后面继续查找串T 
		} 
	}
	return OK; 
}
