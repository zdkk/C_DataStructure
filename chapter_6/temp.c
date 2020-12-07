//#include "../c1.h"
#define CHAR 1
#include "func6-1.h" 
#include "c6-2.h"
#include "bo6-3.h"

int main(void)
{
	CSTree T, p;
	char ch;
	printf("%d\n", T==NULL);
	InitTree(&T);
	CreateTree(&T);
	
	printf("%c\n", T->data);
	p = Point(T, 'a');
	printf("%c\n", p->data);
	ch = Parent(T, 'a');
	printf("%c\n", ch);
	putchar('\n');
	PostOrderTraverse(T, Visit);
	putchar('\n');
	LevelOrderTraverse(T, Visit);
	DestroyTree(&T);
	printf("%d\n", T==NULL);
	return 0;
}
 
