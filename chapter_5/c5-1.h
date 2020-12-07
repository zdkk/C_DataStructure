//c5-1.h	数组的顺序存储结构
#define MAX_ARRAY_DIM 8	//假设数组最大维数是8
struct Array
{
	ElemType *base;	//数组元素基址，由InitArray分配
	int dim;		//数组维数 
	int *bounds;	//数组维界基址，由InitArray分配
	int *constants;  //数组映像函数常量基址，由InitArray分配 
};
