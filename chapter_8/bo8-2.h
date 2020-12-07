//bo8-2.h 二叉排序树的基本操作(4个)，包括算法9.5(b)，算法9.6~算法9.8

Status SearchBST(BiTree *T, KeyType key, BiTree f, BiTree *p)
{
	//在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找成功，用p返回指向该数据元素结点的指针，并返回TRUE
	//否则指针p指向查找路径上访问的最后一个结点，并返回FALSE，指针f指向T的双亲，其初始调用值为NULL
	if (*T == NULL)	//*T为空指针
	{
		*p = f;		//未找到，*p指向双亲结点f
		return FALSE;	
	}
	else if EQ((*T)->data.key, key)//当前结点*T的关键字等于key
	{
		*p = *T;	//找到， *p指向当前结点*T 
		return TRUE;	
	}
	else if LT(key, (*T)->data.key)
		return SearchBST(&(*T)->lchild, key, *T, p);
	else
		return SearchBST(&(*T)->rchild, key, *T, p); 
}
Status InsertBST(BiTree *T, ElemType e)
{
	//若二叉排序树中T没有关键字等于e.key的元素，插入e并返回TRUE，否则返回FALSE 
	BiTree p, s;
	
	if (SearchBST(T, e.key, NULL, &p) == FALSE)	//查找不成功，则插入，此时p指向查找路径上访问的最后一个结点 
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		
		if (p == NULL)	//原二叉排序树为空树
			*T = s;
		else if LT(e.key, p->data.key)	//关键字小于双亲结点关键字，插入成左孩子
			p->lchild = s;
		else
			p->rchild = s; 
		return TRUE;
	}
	else
		return FALSE;
}
void Delete(BiTree *p)
{
	//从二叉排序树中删除p所指结点，并重接它的左或右子树	算法9.8
	BiTree s, q = *p;	//q指向待删除结点
	
	if ((*p)->rchild == NULL)	//待删除结点没有右子树，只需重接左子树（没有左子树也是这条分支）
	{
		*p = (*p)->lchild;
		free(q);	
	}
	else if ((*p)->lchild == NULL)	//待删除结点没有左子树，只需重接右子树
	{
		*p = (*p)->rchild;
		free(q);	
	}
	else			//待删除结点有左右子树，精髓就是将左子树中最大的关键字结点数据元素放在当前结点 
	{
		s = (*p)->lchild;	//s指向待删除结点的左孩子
		while (s->rchild)	//s有右孩子
		{
			q = s;
			s = s->rchild;	
		}		//s向右走到尽头（s指向待删除结点的前驱节点，q指向s的双亲结点（始终））
		(*p)->data = s->data; 
		if (q == (*p))	//待删除结点的左孩子没有右子树
			q->lchild = s->lchild;
		else			//待删除结点的左孩子有右子树 
			q->rchild = s->lchild;
		free(s);
	}
}
Status DeleteBST(BiTree *T, KeyType key)
{
	//若二叉排序树T中存在关键字等于key的数据元素时删除该数据元素所在结点并返回TRUE；否则返回FALSE 算法9.7 
	if ((*T) == NULL)	//树为空
		return FALSE;
	else
	{
		if EQ(key, (*T)->data.key)	//关键字等于当前结点的关键字
		{
			Delete(T);				//删除该结点，此时传入的是一个指向结点的指针的指针，该指向结点的指针为双亲结点的左/右指针（妙！） 
			return TRUE;	
		}
		else if LT(key, (*T)->data.key)//关键字小于当前结点关键字
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key); 
	}
}




















