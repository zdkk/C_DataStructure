//algo3-3
// �㷨3.2 �б༭����
typedef char SElemType;		//����ջԪ������Ϊchar
# include "../c1.h"
# include "c3-1.h"			//ջ��˳��洢�ṹ 
# include "bo3-1.h" 		//ջ��˳��洢�ṹ�Ļ�������

FILE *fp;

void copy(SElemType c)
{
	fputc(c, fp);	
} 
void LineEdit()
{
	//�����ַ�ջs�����ն˽���һ�в��������ù��̵ĺ�����
	SqStack s;
	char ch;
	
	InitStack(&s);
	printf("������һ���ı��ļ���^Z�������룺\n");
	ch = getchar();		//�����ַ���ch
	while (ch != EOF)	//��ȫ��δ������EOFΪ^Z����ȫ�Ľ�������
	{
		while(ch!='\n' && ch!=EOF)	//��ȫ��δ������δ����ĩ�����ǻ��з���
		{
			switch(ch)
			{
				case '#':
					Pop(&s, &ch);
					break;
				case '@':
					ClearStack(&s);
					break;
				default:
					Push(&s, ch);
			}
			ch = getchar();	//���ն˽�����һ���ַ���ch
		} //����ĩ����ȫ�Ľ������˳��˲�ѭ��
		StackTraverse(s, copy);	//��ջ�׵�ջ�����ν�վ���ַ��������ļ�������copy()������
	 	fputc('\n', fp);		//���ļ�����һ�����з�
		ClearStack(&s);			//��ջ���
		if(ch != EOF)			//ȫ��δ���� 
		ch = getchar();			//���ն˽�����һ���ַ���ch 
	 }
	 DestroyStack(&s);			//����ջs 
}

int main(void)
{
	fp =  fopen("edit.txt", "w+");	//�ڵ�ǰĿ¼�½���edit.txt�ļ�������д���ݣ�������ͬ���ļ���Ḳ�� 
	if(fp)	//�����ļ��ɹ�
	{
		LineEdit();
		fclose(fp);
	}
	else
		printf("�����ļ�ʧ��\n"); 
	return 0;
}

 
