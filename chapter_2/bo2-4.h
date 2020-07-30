//bo2-4.h
//����ͷ���ĵ������������������

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	//��ʼ������L����
	//�����������cur_e��L������Ԫ���Ҳ��ǵ�һ������pre_e������ǰ��������OK
		//�������ʧ�ܣ�pre_e�޶��壬����ERROR
	LNode *p, *q;
	p = L;		//pָ����Ԫ���
	
	while(p->next)		//p��ָ���ĺ�̲�Ϊ��
	{
		q = p->next;	//qָ��p�ĺ�� 
		if(q->data == cur_e)	//q��ָ�������Ԫ��ֵΪcur_e
		{
			*pre_e = p->data;	//��pָ���������Ԫ�ص�ֵ����*pre_e 
			return OK;	
		}
		p = q;		//p�ĺ�̽������Ԫ�ز�Ϊcur_e��p����	
	} 
	return ERROR;	//����ʧ�ܣ�����ERROR 
}

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	//��ʼ������L����
	//�����������cur_e��L������Ԫ���Ҳ������һ������next_e�������̣�����OK���������ʧ�ܣ�next_e�޶��壬����ERROR
	LNode *p, *q;
	p = L;			//pָ����Ԫ���
	
	while (p && p->next)		//pָ��Ľ���p�ĺ�̽�㶼��Ϊ��
	{
		q = p->next;			//qָ��p�ĺ�̽�� 
		if(p->data == cur_e)	//p��ָ�������Ԫ��ֵΪcur_e	
		{
			*next_e = q->data;	//��p�ĺ�̽������Ԫ�ظ�ֵ��*next_e
			return OK; 
		}
		p = q;					//p������Ԫ��ֵ������cur_e, pָ���̽�� 
	} 
	return ERROR;
} 
