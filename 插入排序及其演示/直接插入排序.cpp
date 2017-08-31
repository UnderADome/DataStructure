#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0;i<n;i++)
		scanf("%d", &a[i]);
	
	for (int i=1;i<n;i++)
	{
		int temp = a[i];
		int j;
		for (j=i-1; j>=0&&a[j]<temp; j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = temp;
	}
	
	for (int i=0;i<n;i++)
		printf("%d ", a[i]);
	return 0;
}
