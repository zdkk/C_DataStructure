// main4-2.cpp ����bo4-2.h��������
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
  printf("��tΪ");
  StrPrint(t); 
  printf("����Ϊ%d�����շ�%d��1���� 0����\n", StrLength(t), StrEmpty(t));
  
  StrAssign(s, "God luck!"); 
  printf("��sΪ");
  StrPrint(s); 
  
  i=StrCompare(s, t); 
  if(i<0)
    c = '<';
  else if(i==0)
    c = '=';
  else
    c = '>';
  printf("��s%c��t\n", c);
  
  Concat(r, t, s); 
  printf("��t���Ӵ�s�����Ĵ�rΪ");
  StrPrint(r); 
  
  StrAssign(s, "oo"); 
  printf("��sΪ");
  StrPrint(s); 
  StrAssign(t, "o"); 
  printf("��tΪ");
  StrPrint(t); 
  Replace(r, t, s); 
  printf("�Ѵ�r�кʹ�t��ͬ���Ӵ��ô�s����󣬴�rΪ");
  StrPrint(r); 
  ClearStr(s); 
  printf("��s��պ󣬴���Ϊ%d���շ�%d��1���� 0����\n", StrLength(s), StrEmpty(s));
  SubStr(s, r, 6, 4); 
  printf("��sΪ�Ӵ�r�ĵ�6���ַ����4���ַ�������Ϊ%d����sΪ", s->length);
  StrPrint(s); 
  StrCopy(t, r); 
  printf("�ɴ�r���Ƶô�t����tΪ");
  StrPrint(t); 
  StrInsert(t, 6, s); 
  printf("�ڴ�t�ĵ�6���ַ�ǰ���봮s�󣬴�tΪ");
  StrPrint(t); 
  StrDelete(t, 1, 5); 
  printf("�Ӵ�t�ĵ�1���ַ���ɾ��5���ַ��󣬴�tΪ");
  StrPrint(t); 
  printf("%d�ǴӴ�t�ĵ�1���ַ��𣬺ʹ�s��ͬ�ĵ�1���Ӵ���λ��\n", Index(t, s, 1));
  printf("%d�ǴӴ�t�ĵ�2���ַ��𣬺ʹ�s��ͬ�ĵ�1���Ӵ���λ��\n", Index(t, s, 2));
//  DestroyStr(t); 
  return 0;
}

