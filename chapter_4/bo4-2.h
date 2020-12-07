//bo4-2.h
//�����öѷ���洢�ṹ����4-2.h���壩�Ļ���������12����
#define DestroyStr ClearStr

void InitStr(HSPtr P)
{
	//��ʼ���������մ����ַ���P
	P->length = 0;
	P->ch = NULL;	
}

void ClearStr(HSPtr P)
{
	//�����������S���
	free(P->ch);		//�ͷ�P->ch��ָ�ռ�
	InitStr(P);			//��ʼ����P 
}

void StrAssign(HSPtr P, char chars[])
{
	//����һ����ֵ���ڳ����ַ���chars�Ĵ�P
	int i,j;
	if(P->ch)		//P->chָ��ĳ�����ݵ�Ԫ
		free(P->ch);//�ͷ�P->chԭ�д洢�ռ�
	i = strlen(chars);	//��chars�ĳ���i 
	if(!i)				//chars�ĳ���Ϊ0
		InitStr(P);		//���ɿմ�
	else
	{
		P->ch = (char *)malloc(sizeof(char)*i);	//����洢�ռ�
		if(!P->ch)	//����ʧ��
			exit(OVERFLOW);
		for (j=0; j<i; j++)	//����ɹ��󣬸��ƴ�chars��P 
			P->ch[j] = chars[j];
		P->length = i;		//���´�T�ĳ���	
	} 
}

void StrCopy(HSPtr P, HSPtr Q)
{
	//��ʼ��������P����
	//����������ɴ�Q���Ƶõ���P
	int i;
	
	if (P->ch)	//��P��Ϊ��
		ClearStr(P);	//�ͷŴ�Tԭ�д洢�ռ�
	P->ch = (char *)malloc(sizeof(char) * Q->length);	//����洢�ռ� 
	if(!P->ch)	//����ʧ��
			exit(OVERFLOW);
	for(i=0; i<Q->length; i++)
		P->ch[i] = Q->ch[i];	//��һ�����ַ�
	P->length = Q->length; 
}

Status StrEmpty(HSPtr P)
{
	//�����������PΪ�շ���TRUE�����򷵻�FALSE
	return P->length ? FALSE : TRUE; 
}

int StrCompare(HSPtr P, HSPtr Q)
{
	//����P>��Q������ֵ>0;����P==��Q������ֵ=0;��P<Q,����ֵ<0
	int i;
	
	for (i=0; i<P->length && i< Q->length; i++)	//����Ч��Χ�� 
	{
		if(P->ch[i]!= Q->ch[i])					//��һ�Ƚ��ַ� 
			return P->ch[i]	- Q->ch[i];			//����ȷ�������ASCII֮�� 
	}
	return P->length - Q->length;				//����Ч��Χ�ڣ��ַ���ȵ����Ȳ��ȣ����س���֮�� 
}

int StrLength(HSPtr P)
{
	//�������������P���ַ���������Ϊ���ĳ���
	return P->length; 
}

void Concat(HSPtr R, HSPtr P, HSPtr Q)
{
	//�ô�R������P��Q���Ӷ��ɵ��´�
	int i;
	if(R->ch)	//��R��Ϊ��
		ClearStr(R);
	R->length = P->length + Q->length;	//R�ĳ���ΪP��Q����֮��
	R->ch = (char *)malloc(sizeof(char) * R->length);	//���䴮R�Ĵ洢�ռ�
	if(!R->ch)											//�洢�ռ����ʧ��
		exit(OVERFLOW);
	for (i=0; i<P->length; i++)							//��P���ַ���һ���Ƹ�R 
		R->ch[i] = P->ch[i];		
	for (i=0; i<Q->length; i++)							//��Q���ַ�ע�⸴�Ƶ�R������P�ַ����� 
		R->ch[i+P->length] = Q->ch[i]; 
}

Status SubStr(HSPtr Sub, HSPtr P, int pos, int len)
{
	//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���ַ���
	//���У�1<=pos<=StrLen(P)��0<=len<=StrLength(S)-pos+1
	int i;
	
	if (pos<1 || pos>P->length || len<0 || len>P->length-pos+1)
		return ERROR;		//pos����len��С������Ҫ��
	if(Sub->ch)	//Sub�ǿ�
		ClearStr(Sub);	//��Sub���
	if(len)		//len�ǿ�
	{
		Sub->ch = (char *)malloc(sizeof(char) * len);	//����洢�ռ�
		if(!Sub->ch)
			exit(OVERFLOW);								//����ʧ��
		Sub->length = len;
		for (i=0; i<len; i++)							//����P���Ӵ���Sub 
			Sub->ch[i] = P->ch[pos-1+i];	
	} 
	return OK;		 
}

Status StrInsert(HSPtr P, int pos, HSPtr T)
{
	//1<=pos<=P->length+1
	//�ڴ�P�ĵ�pos���ַ�ǰ���봮T
	int i;
	
	if (pos<0 || pos>P->length+1)
		return ERROR;
	
	if (T->length)	//T�ǿ�
	{
		P->ch = (char *)realloc(P->ch,(P->length+T->length)*sizeof(char));
		if(!P->ch)	//����ʧ��
			exit(OVERFLOW);
		for (i=P->length-1; i>=pos-1; i--)	//Ϊ����T�ڳ�λ�� 
			P->ch[i+T->length] = P->ch[i];
		for (i=0; i<T->length; i++)
			P->ch[pos-1+i] = T->ch[i];	//����T
		P->length += T->length; 
	}
	return OK;
}

Status StrDelete(HSPtr P, int pos, int len)
{
	//�Ӵ�P��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
	int i;
	
	if (P->length < pos+len-1 || pos<0 || len <0)	//pos��lenֵ������Χ
		return ERROR;
	for (i=pos-1; i<P->length-len; i++)	//����ɾ���Ӵ�֮����ַ���һǰ��
		P->ch[i] =  P->ch[i+len];
	P->length -= len;			//���´��ĳ���
	P->ch = (char *)realloc(P->ch, P->length*sizeof(char));	//���·���S�Ĵ洢�ռ�
	return OK; 
}

void StrPrint(HSPtr P)
{
	//����ַ���P
	for (int i=0; i<P->length; i++)
		printf("%c", P->ch[i]) ;
	printf("\n");
}
















