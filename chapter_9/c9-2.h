//c9-2.h	顺序表类型的存储结构
#define MAX_SIZE 20	//示例长度
struct SqList	//顺序表类型
{
	RedType r[MAX_SIZE + 1];	//r[0]用作闲置或哨兵单元
	int length;					//顺序表长度 
};
