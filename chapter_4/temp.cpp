#include"../c1.h"
#include"c4-2.h" 
#include"bo4-2.h" 
typedef HSPtr String; 
#include"func4-1.h" 
int main(void)
{
  int i;
  HString t1;
  HSPtr t = &t1; 
  char s, c[10];
  Status k;
  
  printf("�����봮t��");
  gets(c); 
  InitStr(t);
  printf("!!!!!!\n");
  StrAssign(t, c); 
  printf("��tΪ");
  StrPrint(t); 
  printf("����Ϊ%d�����շ�%d��1���� 0����\n", StrLength(t), StrEmpty(t));
  
  k = StrDelete(t,2,3);
  printf("len = %d\n", StrLength(t));
  if(k)
  	StrPrint(t);
  
  return 0;
}
