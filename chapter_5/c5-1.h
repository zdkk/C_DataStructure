//c5-1.h	�����˳��洢�ṹ
#define MAX_ARRAY_DIM 8	//�����������ά����8
struct Array
{
	ElemType *base;	//����Ԫ�ػ�ַ����InitArray����
	int dim;		//����ά�� 
	int *bounds;	//����ά���ַ����InitArray����
	int *constants;  //����ӳ����������ַ����InitArray���� 
};
