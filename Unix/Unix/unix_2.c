//
//  unix_2.c
//  
//
//  Created by Administrator on 2020/1/31.
//

#include <stdio.h>
#include <assert.h>
//
//
/*problem2:*/
int myBinarySearch();
/*problem3:i n:a[i]=a[2*i]=a[3*i]的次数*/
/*problem4:杂技算法，求逆算法*/
/*problem5:abc->cba*/
void reverse(char *arr,int n,int i,int j);
/*problem7:4000*4000矩阵转置变换*/
void matrixT(int **arrin,int n,int m);
void matrixT_qsort(int *arr,int n);
void matrixT_qsort_recur(int *arr,int i,int j);
int matrix_qsort_pivot(int *arr,int i,int j);
/*problem8:*/
//int main()
//{
//    /*abcdef-->defbca  bc is the pivot*/
////    char test[6] = {'a','b','c','d','e','f'};
////    reverse(test, 6, 0, 0);
////    reverse(test, 6, 1, 2);
////    reverse(test, 6, 3, 5);
////    reverse(test, 6, 0, 5);
////    for(int i = 0;i<6;++i)
////    {
////        printf("%c ",test[i]);
////    }
////    printf("\n");
//}

void reverse(char *arr,int n,int i,int j)
{
    int l = i;
    int r = j;
    while(l<r)
    {
        char temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}

void matrixT(int **arrin,int n,int m)
{
    
}

void matrixT_qsort(int *arr,int n)
{
    matrixT_qsort_recur(arr,0,n-1);
}
void matrixT_qsort_recur(int *arr,int i,int j)
{
    /*递归基*/
    if(i >= j){
        return;
    }
    int pivot =matrix_qsort_pivot(arr,i,j);
    matrixT_qsort_recur(arr,i,pivot);
    matrixT_qsort_recur(arr,pivot+1,j);
}

int matrix_qsort_pivot(int *arr,int i,int j)
{
    /*随机化的效果可能更好*/
    int pivot_value = arr[i];
    int l = i+1;
    int r = j;
    while(l<=r){
        while(l<=j&&arr[l++]<=pivot_value){
            assert(l<=r);
        }
        while (r>=i+1 && arr[r--] >pivot_value) {
            assert(l<=r);
        }
        if(l<=r){
            break;
        }
        assert(l<=r);
        assert(l<=j&&r>=i+1);
        int temp = arr[l];
        arr[l]=arr[r];
        arr[r] = temp;
    }
    arr[i] = arr[l];
    arr[l] = pivot_value;
    return l;
}
