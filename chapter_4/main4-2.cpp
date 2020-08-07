// main4-2.cpp 检验bo4-2.h的主程序
#include"../c1.h"
#include"c4-2.h" 
#include"bo4-2.h" 
typedef HSPtr String; 
#include"func4-2.h" 
int main(void)
{
  int i;
  char c;
  HString t1, s1, r1;
  HSPtr t = &t1, s = &s1, r = &r1;
  InitStr(t); 
  InitStr(s);
  InitStr(r);
  
  StrAssign(t, "God bye!"); 
  printf("串t为");
  StrPrint(t); 
  printf("串长为%d，串空否？%d（1：空 0：否）\n", StrLength(t), StrEmpty(t));
  
  StrAssign(s, "God luck!"); 
  printf("串s为");
  StrPrint(s); 
  
  i=StrCompare(s, t); 
  if(i<0)
    c = '<';
  else if(i==0)
    c = '=';
  else
    c = '>';
  printf("串s%c串t\n", c);
  
  Concat(r, t, s); 
  printf("串t连接串s产生的串r为");
  StrPrint(r); 
  
  StrAssign(s, "oo"); 
  printf("串s为");
  StrPrint(s); 
  StrAssign(t, "o"); 
  printf("串t为");
  StrPrint(t); 
  Replace(r, t, s); 
  printf("把串r中和串t相同的子串用串s代替后，串r为");
  StrPrint(r); 
  ClearStr(s); 
  printf("串s清空后，串长为%d，空否？%d（1：空 0：否）\n", StrLength(s), StrEmpty(s));
  SubStr(s, r, 6, 4); 
  printf("串s为从串r的第6个字符起的4个字符，长度为%d，串s为", s->length);
  StrPrint(s); 
  StrCopy(t, r); 
  printf("由串r复制得串t，串t为");
  StrPrint(t); 
  StrInsert(t, 6, s); 
  printf("在串t的第6个字符前插入串s后，串t为");
  StrPrint(t); 
  StrDelete(t, 1, 5); 
  printf("从串t的第1个字符起删除5个字符后，串t为");
  StrPrint(t); 
  printf("%d是从串t的第1个字符起，和串s相同的第1个子串的位置\n", Index(t, s, 1));
  printf("%d是从串t的第2个字符起，和串s相同的第1个子串的位置\n", Index(t, s, 2));
//  DestroyStr(t); 
  return 0;
}

