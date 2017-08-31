#include<stdio.h>
int main(void)
{
	int b[13] = {45,32,48,65,12,43,62,59,68,32,15,45,55};
	printf("原始数列:");
	for (int i=0;i<13;i++)		
		printf("%d ", b[i]);
	printf("\n");
	int i, j, mid, low, high, temp;
	for (i=0;i<13;i++)
	{
		temp = b[i+1];
		low = 0;
		high = i;
		while(low<=high)
		{
			mid = (low+high)/2;
			if (b[mid]>temp)
				high = mid-1;
			else
				low = mid +1;
		}
		for (j=i; j>=low; j--)
		{
			b[j+1] = b[j];
		}
		b[low] = temp;
		printf("第%d次排序：", i+1);
		for (int i=0;i<13;i++)
			printf("%d ", b[i]);
		printf("\n");
	}
	
	for (int i=0;i<13;i++)
		printf("%d ", b[i]);

	getchar();
	return 0;
} 
