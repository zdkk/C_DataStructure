//func8-4.h	�����㷨9.5(a)��bo6-1.h, algo8-4.cpp ��algo8-5.cpp����
#include "../chapter_6/bo6-1.h"	//����InitBiTree(),DestroyBiTree()��InOrderTraverse()����
#define InitDSTable InitBiTree	//���������������ƽ����������ʼ���������Ĳ�����ͬ
#define DestroyDSTable DestroyBiTree	//���ٶ������������ʼ���������Ĳ�����ͬ
#define TraverseDSTable InOrderTraverse	//���ؼ���˳�������������������������������Ĳ�����ͬ

BiTree searchBST(BiTree T, KeyType key)	//�㷨9.5(a) 
{
	//�ڸ�ָ��T��ָ������������ƽ��������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ��
	//�����ҳɹ�������ָ�������Ԫ�ص�ָ�룬���򷵻�NULL
	
	if (!T || EQ(key, T->data.key))
		return T;
	else if LT(key, T->data.key)	//�����ҹؼ���С��T��ָ���ؼ���
		return searchBST(T->lchild, key);	//���������м����ݹ����
	else							//�����ҹؼ��ִ���T��ָ���ؼ��� 
		return searchBST(T->rchild, key);	//���������м����ݹ���� 
}

