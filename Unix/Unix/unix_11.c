//
//  unix_11.c
//  Unix
//
//  Created by Administrator on 2020/2/21.
//  Copyright © 2020 Administrator. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void myQuickSort_1(int*,int,int);
void myInsertSort(int*,int);
void myQuickSort_2(int *arr,int l,int r,int cutoff);

//int main(){
//    srand(time(NULL));
//    int n;
//    int *arr;
//    clock_t start_t, end_t;
//    while (scanf("%d",&n)!=EOF) {
//        arr = malloc(sizeof(int)*n);
//        for(int i = 0;i<n;++i){
//            arr[i] =rand();
//        }
////        printf("before sorted!\n");
////        for(int i = 0;i<n;++i){
////            printf("%d ",arr[i]);
////        }
////        printf("\n");
//
////        myQuickSort_1(arr, 0, n-1);
//
//        int *arr_copy =malloc(sizeof(int)*n);
//        for(int i = 0;i<=100;++i){
//            for(int i = 0;i<n;++i){
//                 arr_copy[i] =arr[i];
//            }
//            start_t = clock();
//            myQuickSort_2(arr_copy, 0, n-1,i);
////            myInsertSort(arr_copy, n);
//            end_t = clock();
//            printf("cutoff of %d consumed time is %lf\n",i,(double)(end_t - start_t)/CLOCKS_PER_SEC);
//        }
////
////        printf("after sorted!\n");
////        for(int i = 0;i<n;++i){
////            printf("%d ",arr[i]);
////        }
////        printf("\n");
//    }
//}

void myQuickSort_1(int *arr,int l,int r)
{
    if(l>=r){
        return;
    }
    int i = l;
    int j =r+1;
    int pivot = arr[l];
    while (1) {
        do{
            i++;
        }while(i<=r&&arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>j){
            break;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    arr[l]=arr[j];
    arr[j] = pivot;
    myQuickSort_1(arr, l, j-1);
    myQuickSort_1(arr, j+1, r);
}

void myInsertSort(int *arr,int n)
{
    /* 6,4,5,0,9,11*/
    /*1st:4,6,5,0,9,11*/
    int i,j;
    for(i = 1;i<n;++i){
        int insertValue = arr[i];
        for(j=i;j>0&&insertValue<arr[j-1];--j){
            arr[j] =arr[j-1];
        }
        arr[j] = insertValue;
    }
}

void myQuickSort_2(int *arr,int l,int r,int cutoff)
{
    if(r-l <cutoff){
        return;
    }
    int i = l;
    int j =r+1;
    int pivot = arr[l];
    while (1) {
        do{
            i++;
        }while(i<=r&&arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>j){
            break;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    arr[l]=arr[j];
    arr[j] = pivot;
    myQuickSort_1(arr, l, j-1);
    myQuickSort_1(arr, j+1, r);
}
