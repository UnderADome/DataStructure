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
