# include<stdio.h>

int main(void)
{
	int num = 223, i;
	bool flag = false;
	
	for (i=2; i<223;i++)
	{
		if(num % i==0 )
		break;
	}
	printf("%d",i);
	return 0;
}
