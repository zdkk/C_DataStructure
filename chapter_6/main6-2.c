// main6-2.cpp ����bo6-3.h��bo6-4.h�ĳ���
#define CHAR 1 
#include"func6-1.h" 
#include"c6-2.h" 
#include"bo6-3.h" 
#include"bo6-4.h" 
void main()
{
  int i;
  CSTree T, p, q;
  TElemType e, e1;
  
  //��ʼ���� 
  InitTree(&T); 
  printf("������������շ�%d��1���� 0���񣩡�����Ϊ%c���������Ϊ%d��\n", 
  TreeEmpty(T), Root(T), TreeDepth(T));
  //������ 
  CreateTree(&T); 
  printf("������T�����շ�%d��1���� 0���񣩡�����Ϊ%c���������Ϊ%d��\n", 
  TreeEmpty(T), Root(T), TreeDepth(T));
  
  printf("���������T��\n");
  LevelOrderTraverse(T, Visit); 
  
  printf("��������޸ĵĽ���ֵ ��ֵ��");
  scanf("%c%*c%c%*c", &e, &e1);
  Assign(T, e, e1); 
  
  printf("��������޸ĺ����T��\n");
  LevelOrderTraverse(T, Visit); 
  
  printf("%c��˫����%c��������%c����һ���ֵ���%c��\n", e1, Parent(T, e1), 
  LeftChild(T, e1), RightSibling(T, e1));
  
  printf("������p��\n");
  CreateTree(&p);
   
  printf("���������p��\n");
  LevelOrderTraverse(p, Visit); 
  
  printf("����p�嵽��T�У�������T��p��˫�׽�� ������ţ�");
  scanf("%c%d%*c", &e, &i);
  q=Point(T, e); 
  InsertChild(&T, q, i, p); 
  printf("��������޸ĺ����T��\n");
  LevelOrderTraverse(T, Visit); 
  printf("�ȸ�������T��\n");
  PreOrderTraverse(T, Visit); 
  printf("\n���������T��\n");
  PostOrderTraverse(T, Visit); 
  printf("\nɾ����T�н��e�ĵ�i��������������e i��");
  scanf("%c%d", &e, &i);
  q=Point(T, e); 
  DeleteChild(&T, q, i); 
  printf("��������޸ĺ����T��\n");
  LevelOrderTraverse(T, Visit); 
  DestroyTree(&T); 
}
/*
---------------------------------------------
������������շ�1��1���� 0���񣩡�����Ϊ#���������Ϊ0��
��������ڵ�����(�ַ���, #Ϊ��)R
�밴����˳��������R�����к���: ABC
�밴����˳��������A�����к���: DE
�밴����˳��������B�����к���:
�밴����˳��������C�����к���: F
�밴����˳��������D�����к���:
�밴����˳��������E�����к���:
�밴����˳��������F�����к���: GHK
�밴����˳��������G�����к���:
�밴����˳��������H�����к���:
�밴����˳��������K�����к���:
������T�����շ�0��1���� 0���񣩡�����ΪR���������Ϊ4��
���������T��
R A B C D E F G H K
��������޸ĵĽ���ֵ ��ֵ��D d
��������޸ĺ����T��
R A B C d E F G H K
d��˫����A��������#����һ���ֵ���E��
������p��
��������ڵ�����(�ַ���, #Ϊ��)f
�밴����˳��������f�����к���: ghk
�밴����˳��������g�����к���:
�밴����˳��������h�����к���:
�밴����˳��������k�����к���:
���������p��
f g h k
����p�嵽��T�У�������T��p��˫�׽�� ������ţ�R 3
��������޸ĺ����T��
R A B f C d E g h k F G H K
�ȸ�������T��
R A d E B f g h k C F G H K
���������T��
d E A B g h k f G H K F C R
ɾ����T�н��e�ĵ�i��������������e i��C 1
��������޸ĺ����T��
R A B f C d E g h k
-----------------------------------
*/

