//
//  unix_4.c
//  Unix
//
//  Created by Administrator on 2020/2/8.
//  Copyright © 2020 Administrator. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <time.h>
#define N 100
/*problem1:二分法的溢出错误*/
int myBinarySearch(int *arr,int n,int k);
/*problem1:二分法返回首个找到的元素的位置*/
int myBinarySearchFirst(int *arr,int n,int k);
/*problem9:i求x的n次方*/
int myexp(int x,int n);

//int main()
//{
//    int arr[N] = {};
//    for(int i = 0;i<N;++i){
//        arr[i] = i;
//    }
//    for(int k = 0;k<N+2;++k)
//    {
//        int location = myBinarySearch(arr, N, k);
//        
//        printf("location of %d is %d\n",k,location);
//    }
//}

int myBinarySearch(int *arr,int n,int k)
{
    int i = 0;
    int j = n-1;
    clock_t start_t, end_t;
    start_t = clock();
    while(i<=j){
        assert(i<=j && i<=n-1);
//        int mid = (i+j)/2;
        int mid = i+(j-i)/2;
        if(arr[mid] == k){
            assert(i<=j && i<=n-1);
            return mid;
        }
        else if(k > arr[mid]){
            assert(i<=j && i<=n-1);
            i = mid+1;
        }
        else{
            assert(i<=j && i<=n-1);
            j  = mid -1;
        }
    }
    end_t = clock();
    printf("consumed time is %lf\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
    return -1;
}

int myBinarySearchFirst(int *arr,int n,int k)
{
        int i = 0;
        int j = n-1;
        while(i<=j){
            assert(i<=j && i<=n-1);
            int mid = (i+j)/2;
//            int mid = i+(j-i)/2;
            if(arr[mid] == k){
                assert(i<=j && i<=n-1);
                int temp = mid;
                while(temp>=i&&arr[temp] == k)
                {
                    temp --;
                }
                assert(temp >=i);
                return temp;
            }
            else if(k > arr[mid]){
                assert(i<=j && i<=n-1);
                i = mid+1;
            }
            else{
                assert(i<=j && i<=n-1);
                j  = mid -1;
            }
        }
    return -1;
}

int myexp(int x,int n)
{
    /*function exp(x,n)
     precondition:n>=0
     post return result = x^n*/
    int x_arr[n];
    x_arr[0] = 1;
    for(int i =0;i<n;++i)
    {
        if(i+1<n)
        {
            x_arr[i+1] = x*x_arr[i];
        }
    }
    return x_arr[n-1];
}

