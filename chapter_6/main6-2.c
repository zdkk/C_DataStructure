// main6-2.cpp 检验bo6-3.h和bo6-4.h的程序
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
  
  //初始化树 
  InitTree(&T); 
  printf("构造空树后，树空否？%d（1：是 0：否）。树根为%c，树的深度为%d。\n", 
  TreeEmpty(T), Root(T), TreeDepth(T));
  //构造树 
  CreateTree(&T); 
  printf("构造树T后，树空否？%d（1：是 0：否）。树根为%c，树的深度为%d。\n", 
  TreeEmpty(T), Root(T), TreeDepth(T));
  
  printf("层序遍历树T：\n");
  LevelOrderTraverse(T, Visit); 
  
  printf("请输入待修改的结点的值 新值：");
  scanf("%c%*c%c%*c", &e, &e1);
  Assign(T, e, e1); 
  
  printf("层序遍历修改后的树T：\n");
  LevelOrderTraverse(T, Visit); 
  
  printf("%c的双亲是%c，长子是%c，下一个兄弟是%c。\n", e1, Parent(T, e1), 
  LeftChild(T, e1), RightSibling(T, e1));
  
  printf("建立树p：\n");
  CreateTree(&p);
   
  printf("层序遍历树p：\n");
  LevelOrderTraverse(p, Visit); 
  
  printf("将树p插到树T中，请输入T中p的双亲结点 子树序号：");
  scanf("%c%d%*c", &e, &i);
  q=Point(T, e); 
  InsertChild(&T, q, i, p); 
  printf("层序遍历修改后的树T：\n");
  LevelOrderTraverse(T, Visit); 
  printf("先根遍历树T：\n");
  PreOrderTraverse(T, Visit); 
  printf("\n后根遍历树T：\n");
  PostOrderTraverse(T, Visit); 
  printf("\n删除树T中结点e的第i棵子树，请输入e i：");
  scanf("%c%d", &e, &i);
  q=Point(T, e); 
  DeleteChild(&T, q, i); 
  printf("层序遍历修改后的树T：\n");
  LevelOrderTraverse(T, Visit); 
  DestroyTree(&T); 
}
/*
---------------------------------------------
构造空树后，树空否？1（1：是 0：否）。树根为#，树的深度为0。
请输入根节点数据(字符型, #为空)R
请按长幼顺序输入结点R的所有孩子: ABC
请按长幼顺序输入结点A的所有孩子: DE
请按长幼顺序输入结点B的所有孩子:
请按长幼顺序输入结点C的所有孩子: F
请按长幼顺序输入结点D的所有孩子:
请按长幼顺序输入结点E的所有孩子:
请按长幼顺序输入结点F的所有孩子: GHK
请按长幼顺序输入结点G的所有孩子:
请按长幼顺序输入结点H的所有孩子:
请按长幼顺序输入结点K的所有孩子:
构造树T后，树空否？0（1：是 0：否）。树根为R，树的深度为4。
层序遍历树T：
R A B C D E F G H K
请输入待修改的结点的值 新值：D d
层序遍历修改后的树T：
R A B C d E F G H K
d的双亲是A，长子是#，下一个兄弟是E。
建立树p：
请输入根节点数据(字符型, #为空)f
请按长幼顺序输入结点f的所有孩子: ghk
请按长幼顺序输入结点g的所有孩子:
请按长幼顺序输入结点h的所有孩子:
请按长幼顺序输入结点k的所有孩子:
层序遍历树p：
f g h k
将树p插到树T中，请输入T中p的双亲结点 子树序号：R 3
层序遍历修改后的树T：
R A B f C d E g h k F G H K
先根遍历树T：
R A d E B f g h k C F G H K
后根遍历树T：
d E A B g h k f G H K F C R
删除树T中结点e的第i棵子树，请输入e i：C 1
层序遍历修改后的树T：
R A B f C d E g h k
-----------------------------------
*/

