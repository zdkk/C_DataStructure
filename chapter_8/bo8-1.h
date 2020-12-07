//bo8-1.h	静态查找表（顺序表和有序表）的基本操作（7个),包括9.1和9.2
void Create_SeqFromFile(SSTable * ST, char * filename)
{
	//操作结果：由数据文件构造静态顺序查找表ST
	int i;
	FILE *f;	//文件指针类型
	
	f = fopen(filename, "r");	//以只读方式打开文件filename
	if (!f)
		exit(EXIT_FAILURE);
	fscanf(f, "%d", &ST->length);	//先读入文件中数据元素个数
	ST->elem = (ElemType *)malloc(sizeof(ElemType) * (ST->length + 1));
	//动态生成ST->length + 1 个数据元素空间(0号单元不用)
	if (!ST->elem)	//空
		exit(OVERFLOW);
	for (i = 1; i <= ST->length; i++)
		InputFromFile(f, ST->elem + i);
		//由文件依次输入静态顺序查找表ST的数据元素，在func8-1.h中
	fclose(f);	//关闭文件 
 }
 void Ascend(SSTable *ST)
 {
 	//重建静态查找表按关键字非降序排序
	int i, j, k;
	
	for (i = 1; i < ST->length; i++)
	{
		k = i;	//k存储当前数据元素空间最小关键字的序号，此处是初始化，认为i就是目前最小的关键字的序号
		ST->elem[0] = ST->elem[i];	//待比较值存到[0]单元
		
		for (j = i + 1; j <= ST->length; j++)	//从元素[i]之后比起 
			if LT(ST->elem[j].key, ST->elem[0].key)//当前元素的关键字小于带比较关键字 
			{
				k = j;							//当前元素序号成为最小值序号 
				ST->elem[0] = ST->elem[j];		//存储当前元素（最小值）到最小值存储单元 
			}
		if (k != i)	//有比[i]更小的值则交换
		{
			ST->elem[k] = ST->elem[i];
			ST->elem[i] = ST->elem[0];	
		}
	} 
 }
 
void Create_OrdFromFile(SSTable * ST, char * filename)
{
	//操作结果：由含n个数据元素的数组r构造按关键字非降序查找表ST
	Create_SeqFromFile(ST, filename);	//建立无序查找表ST 
	Ascend(ST);							//将无序查找表ST重建为按关键字非降序查找表 
}

Status Destroy(SSTable * ST)
{
	//初始条件：静态查找表ST存在
	//操作结果：销毁表ST
	free(ST->elem);
	ST->elem = NULL;
	ST->length = 0;
	return OK;
}

int Search_Seq(SSTable ST, KeyType key)
{
	//在顺序表ST中顺序查找其主关键字等于key的数据元素
	//若找到，返回元素在表中的位置，否则返回0	//算法9.1
	int i;
	
	ST.elem[0].key = key;	//哨兵，存储关键字
	for (i = ST.length; !EQ(ST.elem[i].key, ST.elem[0].key); --i)	//从后往前找 
		continue;
	return i; 	//找不到时i为0 
}

int Search_Bin(SSTable ST, KeyType key)
{
	//在顺序表ST中折半查找其主关键字等于key的数据元素
	//若找到，则返回该元素在表中的位置，否则返回0	算法9.2
	int mid, low = 1, high = ST.length;	//置区间初值
	
	while (low <= high)					//查找范围大于0 
	{
		mid = (low + high) / 2;			//中值序号
		if EQ(key, ST.elem[mid].key)		//中值是待查找元素
			return mid;
		else if LT(key, ST.elem[mid].key)	//关键字小于中值
			high = mid - 1;				//继续在前半区查找
		else
			low = mid + 1;				//继续在后半区查找 
	}
	return 0;							//顺序表中不存在待查找元素 
}

void Traverse(SSTable ST, void (* Visit)(ElemType))
{
	//初始条件：静态查找表ST存在，Visit()是对记录操作的应用函数
	//操作结构：按顺序对ST中的每个记录调用函数Visit一次且仅一次
	int i;
	ElemType * p = ++ST.elem;	//p指向第一个记录
	
	for (i = 1; i <= ST.length; i++, p++)	//依次对所有记录
		Visit(*p); 							//调用函数Visit 
}

