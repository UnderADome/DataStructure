#include <stdio.h>
#include <stdlib.h>

void Quick_Sort(int *, int, int);
int findPoss(int *, int , int);

int main(void)
{
    int num;
    printf("请输入排序的元素的个数：");
    scanf("%d", &num);

    int i;
    int *arr = (int *)malloc(num*sizeof(int));
    printf("请依次输入这%d个元素（必须为整数）", num);
    for (i=0; i<num; i++)
        scanf("%d", arr+i);
    
    printf("快速排序后的顺序：");
    Quick_Sort(arr, 0, num-1);
    for (i=0; i<num; i++)
        printf("%d", arr[i]);
    printf("\n");

    free(arr);
    arr = NULL;
    system("pause");

    return 0;
}