// func2-2.h 几个常用的函数
Status equal(ElemType c1, ElemType c2)
{ 
	//判断两个元素是否相等 
	if(c1==c2)
		return TRUE;
	else
		return FALSE;
}
int comp(ElemType a, ElemType b)
{ 
	// 比较两个元素的值，相等返回0，a>b返回1，a<b返回-1 
	if(a==b)
		return 0;
	else
		return (a-b)/abs(a-b);
}
void print(ElemType c)
{ 
	//以十进制整型格式打印元素c的值 
 	printf("%d ", c);
}
void print1(ElemType *c)
{ 
	// 以十进制整型格式打印元素*c的值
	printf("%d ", *c);
}
void print2(ElemType c)
{ 
	//以字符型格式打印元素c的值 
	printf("%c ", c);
}

