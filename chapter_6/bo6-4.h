//bo6-4.h main6-2.c �� algo7-3.c����
void PreOrderTraverse(CSTree T, void (* Visit)(TElemType))
{
	if (T)
	{
		Visit(Value(T));
		PreOrderTraverse(T->firstchild, Visit);
		PreOrderTraverse(T->nextsibling, Visit);	
	}	
} 

