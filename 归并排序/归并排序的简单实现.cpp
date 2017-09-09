// #include <stdio.h>
//  void MSort(int A[], int TmpArray[], int Left, int Right)
//  {
//      int Center;

//      if(Left < Right)
//      {
//          Center = (Left+Right)/2;
//          MSort(A, TmpArray, Left, Center);
//          MSort(A, TmpArray, Center+1, Right);
//          Merge(A, TmpArray, Left, Center+1, Right);
//      }
//  }

//  void MergeSort(int A[], int N)
//  {
//      int *TmpArray;
//      TmpArray = malloc(N*sizeof(int));

//      if (TmpArray != NULL)
//      {
//          MSort(A, TmpArray, 0, N-1);
//          free(TmpArray);
//      }
//      else
//         printf("No space for tmp array!");
//  }

//  /*
//  Lpos = start of left half
//  Rpos = start of right half
//  */
//  void Merge(int A[], int TmpArray[], int Lpos, Int Rpos, int RightEnd)
//  {
//      int i, LeftEnd, NumElements, TmpPos;

//      LeftEnd = Rpos - 1;
//      TmpPos = Lpos;
//      NumElements = RightEnd - Lpos + 1;

//      //main loop
//      while (Lpos <= LeftEnd && Rpos <= RightEnd)
//         if (A[Lpos] <= A[Rpos])
//             TmpArray[TmpPos++] = A[Lpos++];
//         else
//             TmpArray[TmpPos++] = A[Rpos++];
    
//     while(Lpos <= LeftEnd) /*Copy rest of first half*/
//         TmpArray[TmpPos++] = A[Lpos++];
    
//     while(Rpos <= RightEnd) /*Copy rest of second half*/
//         TmpArray[TmpPos++] = A[Rpos++];

//     /*Copy TmpArray back*/
//     for (i=0; i<NumElements; i++, RightEnd--)
//         A[RightEnd] = TmpArray[RightEnd];

//  }


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
@method     将有个有序数组合并为新的有序数组

@process    将有序的arr[start...mid]和有序的arr[mid+1...end]归并为有序的brr[0...end-start+1]，
而后再将brr[0...end-start+1]复制到arr[start...end]，使arr[start...end]有序
*/
void Merge(int *arr, int *brr, int start, int mid, int end)
{
    int i = start;  int j = mid+1;  int k = 0;

    //比较两个有序序列中的元素，将较小的元素插入到brr中
    while(i<=mid && j<=end)
    {
        //分别从两个子数组的第一个元素开始同时向后推进
        if (arr[i] <= arr[j])
            brr[k++] = arr[i++];
        else
            brr[k++] = arr[j++];
    }

    //此处while结束之后，并没有完成数组的完全复制
    //因为arr或brr中最后剩余的一段，没有在while中进行比较，需要直接插入到brr中


    //将arr序列中剩余的元素复制到brr中
    //这两个语句只可能执行其中一个
    while (i <= mid)
        brr[k++] = arr[i++];
    while (j <= end)
        brr[k++] = arr[j++];
    
    //将brr中的元素复制到arr中，使arr[start...end]有序
    for (i=0; i<k; i++)
        arr[i+start] = brr[i];
}

/*
@method     此方法实质就是递归调用MSort，完成排序

@process    借助brr数组对arr[start...end]内的元素进行归并排序
归并排序后的顺序为从小到大
*/
void MSort(int *arr, int *brr, int start, int end)
{//递归调用数组比较的过程
    if (start < end)
    {
        int mid = (start+end)/2;
        
        //左边递归排序
        MSort(arr, brr, start, mid);
        //右边递归排序
        MSort(arr, brr, mid+1, end);
        //将已经排好序的左右两个序列再进行排序
        Merge(arr, brr, start, mid, end);
    }
}

/*
将该排序算法封装起来
主方法调用此方法完成全部的排序过程
*/
void Merge_Sort(int *arr, int len)
{
    int *brr = (int *)malloc(len*sizeof(int));
    MSort(arr, brr, 0, len-1);
    free(brr);
    brr = NULL;
}

int main(void)
{
    int num;
    printf("请输入排序的元素的个数：");
    scanf("%d", &num);

    int i;
    int *arr = (int *)malloc(num*sizeof(int));
    printf("请依次输入这%d个元素（必须为整数）：", num);
    for (i=0;i<num;i++)
        scanf("%d", arr+i);

    printf("归并排序后的顺序：");
    Merge_Sort(arr, num);
    for (i=0; i<num; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    arr = NULL;

    system("pause");

    return 0;
}