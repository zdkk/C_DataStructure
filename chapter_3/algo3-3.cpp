//algo3-3
// 算法3.2 行编辑程序
typedef char SElemType;		//定义栈元素类型为char
# include "../c1.h"
# include "c3-1.h"			//栈的顺序存储结构 
# include "bo3-1.h" 		//栈的顺序存储结构的基本操作

FILE *fp;

void copy(SElemType c)
{
	fputc(c, fp);	
} 
void LineEdit()
{
	//利用字符栈s，从终端接收一行并送至调用过程的函数区
	SqStack s;
	char ch;
	
	InitStack(&s);
	printf("请输入一个文本文件，^Z结束输入：\n");
	ch = getchar();		//接收字符到ch
	while (ch != EOF)	//当全文未结束（EOF为^Z键，全文结束符）
	{
		while(ch!='\n' && ch!=EOF)	//当全文未结束且未到行末（不是换行符）
		{
			switch(ch)
			{
				case '#':
					Pop(&s, &ch);
					break;
				case '@':
					ClearStack(&s);
					break;
				default:
					Push(&s, ch);
			}
			ch = getchar();	//从终端接收下一个字符到ch
		} //到行末或者全文结束，退出此层循环
		StackTraverse(s, copy);	//从栈底到栈顶依次将站内字符传送至文件（调用copy()函数）
	 	fputc('\n', fp);		//向文件输入一个换行符
		ClearStack(&s);			//将栈清空
		if(ch != EOF)			//全文未结束 
		ch = getchar();			//从终端接收下一个字符到ch 
	 }
	 DestroyStack(&s);			//销毁栈s 
}

int main(void)
{
	fp =  fopen("edit.txt", "w+");	//在当前目录下建立edit.txt文件，用于写数据，若已有同名文件则会覆盖 
	if(fp)	//创建文件成功
	{
		LineEdit();
		fclose(fp);
	}
	else
		printf("建立文件失败\n"); 
	return 0;
}

 
