//bo4-1.h
//���Ķ���˳��洢�ṹ����������12����
#include <string.h>
#define DestroyStr ClearStr		//DestroyStr��ClearStr������ͬ
#define InitStr ClearStr		//InitStr��ClearStr������ͬ

Status StrAssign(SString T, char* chars)
{
	//����һ��ֵ����chars�Ĵ�T
	int i;
	if(strlen(chars) > MAX_STR_LEN)	//chars�ĳ��ȴ�����󴮳�
		return ERROR;
	else
	{
		T[0] = strlen(chars);	//0�ŵ�Ԫ�洢���ĳ���
		for(i=1; i<=T[0]; i++)
		{
			T[i] = chars[i-1];	
		}	
		return OK;
	}	
} 

void StrCopy(SString T, SString S)
{
	//�ɴ�S���Ƶô�T
	int i;
	
	for (i=0; i<=S[0]; i++)
		T[i] = S[i]; 
}

Status StrEmpty(SString S)
{
	//��SΪ�մ�������TRUE�����򷵻�FALSE
	return S[0] ? FALSE : TRUE; 
}

int StrCompare(SString S, SString T)
{
	//��ʼ������S��T����
	//�����������S>T����ֵ>0;��S<T����ֵ<0;��S==T����ֵ0
	int i;
	for (i=1; i<=S[0]&&i<=T[0]; i++)
		if(S[i] != T[i])
			return S[i] - T[i];
	return S[0] - T[0]; 
}

int StrLength(SString S)
{
	//����S��Ԫ�ظ���
	return S[0]; 
}
void ClearStr(SString S)
{
	//��ʼ������S����
	//������������S
	S[0] = 0;	//���Ϊ0 
}

Status Concat(SString T, SString S1, SString S2)
{
	//��T����S1��S2���Ӷ��ɵ��´�����δ�ضϷ���TRUE�����򷵻�FALSE
	int i;
	
	if (S1[0] + S2[0] <= MAX_STR_LEN)	//δ�ض�
	{
		for (i=1; i<=S1[0]; i++)
			T[i] = S1[i];
		for (i=1; i<=S2[0]; i++)
			T[i+S1[0]] = S2[i];
		T[0] = S1[0] + S2[0];
		return TRUE;
	} 
	else								//�ض�S2
	{
		for (i=1; i<=S1[0]; i++)
			T[i] = S1[i];
		for (i=1;i<=MAX_STR_LEN-S1[0]; i++)
			T[i+S1[0]] = S2[i];
		T[0] = MAX_STR_LEN;
		return FALSE;		
	} 
}
Status SubStr(SString Sub, SString S, int pos, int len)
{
	//��Sub���ش�S����pos���ַ��𳤶�Ϊlen���Ӵ�
	int i;
	if(pos<0 || pos>S[0] || len<0 || len>S[0]-pos+1)	//pos��len������Χ
		return ERROR;
	for(i=1; i<=len; i++)
		Sub[i] = S[i+pos-1];
	Sub[0] = len;
	return OK; 
}

int Index1(SString S, SString T, int pos)
{
	//�����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ�����ֵΪ0
	//���У�T�ǿգ�1<=pos<=StrLen(S)
	int i, j;		//ָʾ�������Ӵ���ǰ�Ƚ��ַ�
	
	if (1<=pos && pos<=S[0])	//pos����
	{
		i = pos;				//��������pos���ַ���ʼ���Ӵ�T�ĵ�һ���ַ��Ƚ�
		j = 1;
		
		while (i<=S[0] && j<=T[0])
			if (S[i] == T[j])
			{
				i++;
				j++;	
			}
			else
			{
				i = i - j + 2;		//��ָ���������ƥ��
				j = 1; 
			}
		if (j> T[0])				//����S�д����Ӵ�T
			return i - T[0];
		else						//�����в������Ӵ�T
			return 0; 
	} 
	else						//pos��Χ������ 
		return 0;
}

Status StrInsert(SString S, int pos, SString T)
{
	//��ʼ��������S��T���ڣ�1<=pos<=StrLength(S)+1
	//����������ڴ�S�ĵ�pos���ַ�ǰ���봮T����ȫ���뷵��TRUE�����򷵻�FALSE
	int i;
	
	if (pos<1 || pos>S[0]+1)	//pos������Χ
		return ERROR;
	if (S[0]+T[0] <= MAX_STR_LEN)	//��ȫ����
	{
		for (i=S[0]; i>=pos; i--)
			S[i+T[0]] = S[i];		//��S���ƴ�T�ĳ��ȣ�Ϊ����T׼���ռ�
		for(i=pos; i<pos+T[0]; i++)
			S[i] = T[i-pos+1];	
		S[0] += T[0];				//���´�S�ĳ���
		return TRUE; 
	}
	else							//���ֲ��� 
	{
		for (i=MAX_STR_LEN; i>=pos+T[0]; i--)	//�ƶ���S��λ��pos֮�����ƺ���Ȼ�ڴ��ڵ�Ԫ�� 
			S[i] = S[i-T[0]];
		for (i=pos;i<pos+T[0]&&i<=MAX_STR_LEN; i++)//�ڴ�S�в��봮T��Ҳ�����ǲ��ֲ��룩 
			S[i] = S[i-pos+1];
		S[0] = MAX_STR_LEN;
		return FALSE;
	}
}

Status StrDelete(SString S, int pos, int len)
{
	//��ʼ������S���ڣ�1<=pos<=StrLen(S)-len+1
	//����������Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
	int i;
	
	if (pos<1 || pos>S[0]-len+1 || len<0)	//pos��len���Ϸ�
		return ERROR;
	for (i=pos+len; i<=S[0]; i++)			//����ɾ���Ӵ���������ַ� 
		S[i-len] = S[i]; 					//��ǰ�ƶ�ɾ���Ӵ��ĳ���
	S[0] -= len;							//���´�����
	return OK; 
}

void StrPrint(SString S)
{
	//����ַ���S
	int i;
	for (i=1; i<=S[0]; i++)
		printf("%c",S[i]);
	printf("\n"); 
}


















































