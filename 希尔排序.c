/**
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n = 10;
	int b[10] = {1,5,9,7,6,3,4,2,8,10};
	int i, j, t;

	int increment = n;
	
	do
	{
		increment = increment/3+1;
		for (i=increment; i<=n; i++)
		{
			if (b[i] < b[i-increment])
			{
				t = b[i];
				for (j=i-increment; j>=0&&t<b[j]; j-=increment)
					b[j+increment] = b[j];
				b[j+increment] = t;
			}
		}	
	}
	while(increment > 1);
	
	for (int i=0;i<n+1;i++)
		printf("%d ", b[i]);
	return 0;
}
**/
#include<stdio.h>
int main(void)
{
	int a[] = {81,94,11,96,12,35,17,95,28,58,41,75,15};
	int n = 13;
 	printf ("原始序列\n");
	for (int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n\n");
	int i, j, Increment;
	int Tmp;
	for (Increment=n/2; Increment>0; Increment/=2)
	{
		printf("\n增量为%d\n", Increment);
		
		for (i=Increment; i<n; i++)
		{
			printf("\ni=%d\n", i);
			
			Tmp = a[i];
			for (j=i; j>=Increment; j-=Increment)
			{
				
				if (Tmp<a[j-Increment])
					a[j] = a[j-Increment];
				else
					break;
				for (int i=0;i<n;i++)
					printf("%d ", a[i]);
				printf("\n");
			}
			a[j] = Tmp;
			
			for (int i=0;i<n;i++)
				printf("%d ", a[i]);
			printf("\n------------------------\n");
		}
		
		for (int i=0;i<n;i++)
			printf("%d ", a[i]);
		printf("\n*************************\n");
	}
	
	printf("\n最终结果:");
	for (int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
