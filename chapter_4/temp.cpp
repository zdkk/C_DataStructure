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
  
  printf("ÇëÊäÈë´®t£º");
  gets(c); 
  InitStr(t);
  printf("!!!!!!\n");
  StrAssign(t, c); 
  printf("´®tÎª");
  StrPrint(t); 
  printf("´®³¤Îª%d£¬´®¿Õ·ñ£¿%d£¨1£º¿Õ 0£º·ñ£©\n", StrLength(t), StrEmpty(t));
  
  k = StrDelete(t,2,3);
  printf("len = %d\n", StrLength(t));
  if(k)
  	StrPrint(t);
  
  return 0;
}
