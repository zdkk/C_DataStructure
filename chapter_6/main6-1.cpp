// main6-1.cpp ��������������������������
#define CHAR 1 
//#define CHAR 0 // ���ͣ�����ѡһ������3��
#include"func6-1.h" 
#include"c6-1.h" 
#include"bo6-1.h" 
#include"bo6-2.h" 
int main(void)
{
  int i;
  BiTree T, p, c;
  TElemType e1, e2;
  
  InitBiTree(&T); 
  printf("����ն����������շ�%d��1���� 0���񣩡��������=%d��\n", BiTreeEmpty(T), BiTreeDepth(T));
  e1=Root(T); 
  if(e1!=Nil)
    printf("�������ĸ�Ϊ"form"��\n", e1);
  else
    printf("���գ��޸���\n");
#if CHAR 
  printf("�밴����������������磺ab###��ʾaΪ����㣬bΪ�������Ķ���������\n");
#else 
  printf("�밴����������������磺1 2 0 0 0��ʾ1Ϊ����㣬2Ϊ�������Ķ���������\n");
#endif
  CreateBiTree(&T); 
  printf("���������������շ�%d��1���� 0���񣩡��������=%d��\n", BiTreeEmpty(T), BiTreeDepth(T));
  e1=Root(T); 
  if(e1!=Nil)
    printf("�������ĸ�Ϊ"form"��\n", e1);
  else
    printf("���գ��޸���\n");
  printf("����ݹ������������\n");
  InOrderTraverse(T, Visit); 
  printf("\n����ݹ������������\n");
  PostOrderTraverse(T, Visit); 
  
  printf("\nT�н�����Ϊ%d\n",NodeCount(T));
  printf("T�ж�Ϊ0�Ľ�����Ϊ%d\n",NodeCount_0(T));
  printf("T�ж�Ϊ1�Ľ�����Ϊ%d\n",NodeCount_1(T));
  printf("T�ж�Ϊ2�Ľ�����Ϊ%d\n",NodeCount_2(T));
  
  printf("\n������һ������ֵ��");
  scanf("%*c"form, &e1);
  p=Point(T, e1); 
  printf("����ֵΪ"form"��\n", Value(p));
  printf("���ı�˽���ֵ����������ֵ��");
  scanf("%*c"form"%*c", &e2); 
  Assign(p, e2); 
  printf("���������������\n");
  LevelOrderTraverse(T, Visit); 
  
  e1=Parent(T, e2); 
  if(e1!=Nil)
    printf(form"��˫����"form"��", e2, e1);
  else
    printf(form"û��˫�ף�", e2);
  e1=LeftChild(T, e2); 
  if(e1!=Nil)
    printf("������"form"��", e1);
  else
    printf("û�����ӣ�");
  e1=RightChild(T, e2); 
  if(e1!=Nil)
    printf("�Һ�����"form"��", e1);
  else
    printf("û���Һ��ӣ�");
  e1=LeftSibling(T, e2); 
  if(e1!=Nil)
    printf("���ֵ���"form"��", e1);
else
    printf("û�����ֵܣ�");
  e1=RightSibling(T, e2); 
  if(e1!=Nil)
    printf("���ֵ���"form"��\n", e1);
  else
    printf("û�����ֵܡ�\n");
  InitBiTree(&c); 
  printf("�빹��һ��������Ϊ�յĶ�����c��\n");
#if CHAR 
  printf("�밴����������������磺ab###��ʾaΪ����㣬bΪ�������Ķ���������\n");
#else 
  printf("�밴����������������磺1 2 0 0 0��ʾ1Ϊ����㣬2Ϊ�������Ķ���������\n");
#endif
  CreateBiTree(&c); 
  printf("����ݹ����������c��\n");
  InOrderTraverse(c, Visit); 
  printf("\n��c�嵽��T�У���������T����c��˫�׽�� cΪ��0�����ң�1��������");
  scanf("%*c"form"%d", &e1, &i);
  p=Point(T, e1); 
  InsertChild(p, i, c);
  
  printf("����ݹ������������\n");
  PreOrderTraverse(T, Visit); 
  printf("\nɾ���������������ɾ��������˫�׽�� ��0�����ң�1��������");
  scanf("%*c"form"%d", &e1, &i);
  p=Point(T, e1); 
  DeleteChild(p, i); 
  printf("����ݹ������������\n");
  PreOrderTraverse(T, Visit); 
  printf("\n����ǵݹ������������\n");
  InOrderTraverse1(T, Visit); 
  printf("����ǵݹ��������������һ�ַ�������\n");
  InOrderTraverse2(T, Visit); 
  DestroyBiTree(&T);
  return 0;
}
/*
--------------------------------------
�������ĸ�Ϊa��
����ݹ������������
g d b e a c f
����ݹ������������
g d e b f c a
T�н�����Ϊ7
T�ж�Ϊ0�Ľ�����Ϊ3
T�ж�Ϊ1�Ľ�����Ϊ2
T�ж�Ϊ2�Ľ�����Ϊ2
������һ������ֵ��b
����ֵΪb��
���ı�˽���ֵ����������ֵ��m
���������������
a m c d e f g
m��˫����a��������d���Һ�����e��û�����ֵܣ����ֵ���c��
�빹��һ��������Ϊ�յĶ�����c��
�밴����������������磺ab###��ʾaΪ����㣬bΪ�������Ķ���������
hijl###k###
����ݹ����������c��
l j i k h
��c�嵽��T�У���������T����c��˫�׽�� cΪ��0�����ң�1��������m1
����ݹ������������
a m d g h i j l k e c f
ɾ���������������ɾ��������˫�׽�� ��0�����ң�1��������h0
����ݹ������������
a m d g h e c f
����ǵݹ������������
g d m h e a c f
����ǵݹ��������������һ�ַ�������
g d m h e a c f
---------------------------------------
Nice!    
*/

