//algo8-1.c 检验bo8-1.h(无需顺序表部分)的程序
#include "../c1.h"
#include "func8-1.h"	//包含数据元素类型定义及操作 
#include "c8-1.h" 		//包含静态查找表的顺序存储结构
#include "c8-2.h"		//包含对两个数值型关键字比较的宏定义
#include "bo8-1.h"		//静态查找表的基本操作

char * s_gets(char * st, int n)
{
	char * ret;
	char *find;
	
	ret = fgets(st, n, stdin);
	if (ret)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret;
	
}
int main(void)
{
	SSTable st;
	int i;
	KeyType s;
	char filename[13];	//存储数据文件名（包括路径）
	
	printf("请输入数据文件名： ");
	s_gets(filename, 13);
	Create_SeqFromFile(&st, filename);	//由数据文件产生顺序静态查找表st
	for (i = 1; i <= st.length; i++)
		st.elem[i].total = st.elem[i].Politics + st.elem[i].Chinese + st.elem[i].English +st.elem[i].Math + st.elem[i].Physics
		+ st.elem[i].Chemistry + st.elem[i].Biology;
	printf("准考证号 姓名    政治 语文 外语 数学 物理 化学 生物 总分\n");
	Traverse(st, Visit);
	puts("请输入待查找人的准考证号：");
	InputFromKey(&s);
	i = Search_Seq(st, s);	//在静态查找表中查找含有关键字s的项的序号
	if (i)	//找到
		Visit(st.elem[i]);
	else
		printf("未找到\n");
	Destroy(&st); 
	
	return 0;
}
/*
请输入数据文件名： f8-1.txt
准考证号 姓名    政治 语文 外语 数学 物理 化学 生物 总分
179328   浣曟柟鏂?   85    89    98   100    93    80    47   592
179325   闄堝崕      85    86    88   100    92    90    45   586
179326   闄嗗崕      78    75    90    80    95    88    37   543
179327   寮犲钩      82    80     8    98    84    96    40   488
179324   璧垫檽鑹?   76    85    94    57    77    69    44   502
请输入待查找人的准考证号：
179326
179326   闄嗗崕      78    75    90    80    95    88    37   543
*/
