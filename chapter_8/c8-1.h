//c8-1.h 静态查找表的顺序存储结构
typedef struct	//Static Select Table
{
	ElemType * elem;	//数据元素的存储空间基址，建表时按实际长度分配，0号单元留空
	int length;			//表长度	
}SSTable;
