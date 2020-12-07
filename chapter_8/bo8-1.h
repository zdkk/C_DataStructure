//bo8-1.h	��̬���ұ�˳����������Ļ���������7��),����9.1��9.2
void Create_SeqFromFile(SSTable * ST, char * filename)
{
	//����������������ļ����쾲̬˳����ұ�ST
	int i;
	FILE *f;	//�ļ�ָ������
	
	f = fopen(filename, "r");	//��ֻ����ʽ���ļ�filename
	if (!f)
		exit(EXIT_FAILURE);
	fscanf(f, "%d", &ST->length);	//�ȶ����ļ�������Ԫ�ظ���
	ST->elem = (ElemType *)malloc(sizeof(ElemType) * (ST->length + 1));
	//��̬����ST->length + 1 ������Ԫ�ؿռ�(0�ŵ�Ԫ����)
	if (!ST->elem)	//��
		exit(OVERFLOW);
	for (i = 1; i <= ST->length; i++)
		InputFromFile(f, ST->elem + i);
		//���ļ��������뾲̬˳����ұ�ST������Ԫ�أ���func8-1.h��
	fclose(f);	//�ر��ļ� 
 }
 void Ascend(SSTable *ST)
 {
 	//�ؽ���̬���ұ��ؼ��ַǽ�������
	int i, j, k;
	
	for (i = 1; i < ST->length; i++)
	{
		k = i;	//k�洢��ǰ����Ԫ�ؿռ���С�ؼ��ֵ���ţ��˴��ǳ�ʼ������Ϊi����Ŀǰ��С�Ĺؼ��ֵ����
		ST->elem[0] = ST->elem[i];	//���Ƚ�ֵ�浽[0]��Ԫ
		
		for (j = i + 1; j <= ST->length; j++)	//��Ԫ��[i]֮����� 
			if LT(ST->elem[j].key, ST->elem[0].key)//��ǰԪ�صĹؼ���С�ڴ��ȽϹؼ��� 
			{
				k = j;							//��ǰԪ����ų�Ϊ��Сֵ��� 
				ST->elem[0] = ST->elem[j];		//�洢��ǰԪ�أ���Сֵ������Сֵ�洢��Ԫ 
			}
		if (k != i)	//�б�[i]��С��ֵ�򽻻�
		{
			ST->elem[k] = ST->elem[i];
			ST->elem[i] = ST->elem[0];	
		}
	} 
 }
 
void Create_OrdFromFile(SSTable * ST, char * filename)
{
	//����������ɺ�n������Ԫ�ص�����r���찴�ؼ��ַǽ�����ұ�ST
	Create_SeqFromFile(ST, filename);	//����������ұ�ST 
	Ascend(ST);							//��������ұ�ST�ؽ�Ϊ���ؼ��ַǽ�����ұ� 
}

Status Destroy(SSTable * ST)
{
	//��ʼ��������̬���ұ�ST����
	//������������ٱ�ST
	free(ST->elem);
	ST->elem = NULL;
	ST->length = 0;
	return OK;
}

int Search_Seq(SSTable ST, KeyType key)
{
	//��˳���ST��˳����������ؼ��ֵ���key������Ԫ��
	//���ҵ�������Ԫ���ڱ��е�λ�ã����򷵻�0	//�㷨9.1
	int i;
	
	ST.elem[0].key = key;	//�ڱ����洢�ؼ���
	for (i = ST.length; !EQ(ST.elem[i].key, ST.elem[0].key); --i)	//�Ӻ���ǰ�� 
		continue;
	return i; 	//�Ҳ���ʱiΪ0 
}

int Search_Bin(SSTable ST, KeyType key)
{
	//��˳���ST���۰���������ؼ��ֵ���key������Ԫ��
	//���ҵ����򷵻ظ�Ԫ���ڱ��е�λ�ã����򷵻�0	�㷨9.2
	int mid, low = 1, high = ST.length;	//�������ֵ
	
	while (low <= high)					//���ҷ�Χ����0 
	{
		mid = (low + high) / 2;			//��ֵ���
		if EQ(key, ST.elem[mid].key)		//��ֵ�Ǵ�����Ԫ��
			return mid;
		else if LT(key, ST.elem[mid].key)	//�ؼ���С����ֵ
			high = mid - 1;				//������ǰ��������
		else
			low = mid + 1;				//�����ں�������� 
	}
	return 0;							//˳����в����ڴ�����Ԫ�� 
}

void Traverse(SSTable ST, void (* Visit)(ElemType))
{
	//��ʼ��������̬���ұ�ST���ڣ�Visit()�ǶԼ�¼������Ӧ�ú���
	//�����ṹ����˳���ST�е�ÿ����¼���ú���Visitһ���ҽ�һ��
	int i;
	ElemType * p = ++ST.elem;	//pָ���һ����¼
	
	for (i = 1; i <= ST.length; i++, p++)	//���ζ����м�¼
		Visit(*p); 							//���ú���Visit 
}

