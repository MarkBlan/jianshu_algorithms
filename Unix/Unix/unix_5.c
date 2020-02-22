//
//  unix_5.c
//  Unix
//
//  Created by Administrator on 2020/2/21.
//  Copyright © 2020 Administrator. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int myBinarySearch_test(int*,int,int);
//int main(){
//    /*脚手架*/
//    /*编码实现*/
//    /*测试及调试*/
//    /*计时*/
//    int n,t;
//    int *arr;
//    while (scanf("%d %d",&n,&t)!= EOF) {
//        arr = malloc(sizeof(int) * n);
//        for(int i =0;i<n;++i){
//            arr[i] = 10*i;
//        }
//        printf(" %d\n",myBinarySearch_test(arr, n, t));
//    }
//}

int myBinarySearch_test(int *arr,int n,int t)
{
    int i = 0;
    int j = n-1;
    while (i<=j) {
        int m = i+(j-i)/2;
        if(arr[m] == t){
            return m;
        }
        else if(t > arr[m]){
            i = m+1;
        }
        else{
            j = m-1;
        }
    }
    return -1;
    
}
