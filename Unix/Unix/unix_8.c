//
//  unix_8.c
//  Unix
//
//  Created by Administrator on 2020/2/10.
//  Copyright © 2020 Administrator. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*O(n^3)*/
void maxseq_1(int *arr,int n,int* i,int* j,int* sum);
/*O(n^2)*/
void maxseq_2(int *arr,int n,int* i,int* j,int* sum);
/*O(nlogn)*/
int maxseq_3(int *arr,int l,int r);
/*O(n)*/
int maxseq_4(int *arr,int n);

int mymax_2(int a,int b);

int mymax_3(int a,int b,int c);

/*problem10:找出总和最接近0的子向量&&总和最接近k某一个s整数t的子向量*/
void findMaxSeqCloseZero(int *,int ,int *,int*,int*,int *);
void myquickSort(int *arr,int l,int r,int n);
int myPivot(int *arr,int l,int r,int n);

//int main()
//{
//    int arr[10] = {31,-41,59,26,-53,58,97,-93,-23,84};
//
////    int sum = 0;
////
//    int i =0;
//
//    int j = 0;
//    
////
////    maxseq_1(arr, 10, &i, &j, &sum);
////
////    printf(" 1:the max sum of the sequense of the array is from %d to %d:sum is %d \n",i,j,sum);
////
////    maxseq_2(arr, 10, &i, &j, &sum);
////
////    printf(" 2:the max sum of the sequense of the array is from %d to %d:sum is %d \n",i,j,sum);
////
////
////    int sum_3 =  maxseq_3(arr,0,9);
////    printf(" 3:the max sum of the sequense of the array is :sum is %d \n",sum_3);
////
////    int sum_4 = maxseq_4(arr, 10);
////    printf(" 4:the max sum of the sequense of the array is :sum is %d \n",sum_4);
//    
//    int sum[10];
//    
//    memset(sum,0,10);
//    
//    int sum_sort[10];
//    
//    memset(sum_sort,0,10);
//    /*定义sum[0] = 0*/
//    findMaxSeqCloseZero(arr,10,sum,sum_sort,&i,&j);
//    printf("[%d,%d] has min sum\n",i+1,j);
//}

void maxseq_1(int *arr,int n,int* i,int* j,int* sum)
{
    int maxValue = 0;
    for(int k =0;k<n;++k){
        for(int l = k;l<n;++l){
            *sum = 0;
            for(int m = k;m<=l;++m){
                *sum +=arr[m];
                if(*sum>maxValue){
                    
                    maxValue = *sum;
                    *i = k;
                    *j = m;
                }
            }
        }
    }
    *sum = maxValue;
}

void maxseq_2(int *arr,int n,int* i,int* j,int* sum)
{
    int maxSofar = 0;
    
    for(int k = 0;k<n;++k){
        *sum = 0;
        for(int l =k;l<n;++l){
            *sum += arr[l];
            if(*sum>maxSofar){
                maxSofar = *sum;
                *i = k;
                *j = l;
            }
        }
    }
    *sum = maxSofar;
}

int maxseq_3(int *arr,int l,int r)
{
    /*
     递归基：
     
     l==r && arr[l] <0,return 0
     
     l==r && arr[l] >=0,return arr[l]
     
    */
    
    /*
     
     int mid = l +(r-l)/2;
     
     int maxLeft = maxseq_3(arr, l, mid);
     
     int maxRight = maxseq_3(arr,mid+1,r);
     
     solve the maxMid:
     
     int maxMidL:
     for(j=mid;j>=l;--j)
     {
        sum_l +=arr[j];
        maxMidL = max(maxMidL,sum_l);
     }
     
     int maxMidR;
     for(j = mid+1;j<=r;++j)
     {
        sum_r +=arr[j];
        maxMidR = max(maxMidL,sum_r);
     }
     
     maxMid = maxMidL + maxMidR;
     
     return(max(maxLeft,maxRight,maxMid);
     
     */
//    if(l>r){
//        return 0;
//    }
    assert(l<=r);
    if(l == r){
        
        return mymax_2(arr[l], 0);
    }
    
    int mid = l+(r-l)/2;
    
    int maxLeft = maxseq_3(arr, l, mid);
    
    int maxRight = maxseq_3(arr,mid+1,r);
    
    int maxMidL = 0;
    
    int sum_l = 0;
    
    for(int j=mid;j>=l;--j)
    {
       sum_l +=arr[j];
        
       maxMidL = mymax_2(maxMidL,sum_l);
       
    }
    
    int maxMidR = 0;
    
    int sum_r = 0;
    
    for(int j = mid+1;j<=r;++j)
    {
       sum_r +=arr[j];
        
       maxMidR = mymax_2(maxMidR,sum_r);
        
    }
    
    int maxMid = maxMidL + maxMidR;
    
    return(mymax_3(maxLeft,maxRight,maxMid));

}

int mymax_2(int a,int b)
{
    return a>b?a:b;
}

int mymax_3(int a,int b,int c)
{
    int d = a>b?a:b;
    
    return d>c?d:c;
}

int maxseq_4(int *arr,int n)
{
    /*
     i from 0 to n-1
     maxending here is the max sum of  [0,i-1]，结束位置是i-1的最大值
     maxsofar 是指i-1之前（包括i-1）位置最大子序列和
     plus arr[i]:
     maxending = max(maxending+arr[i],0)
     
     maxsofar = max(maxsofar,maxending)
     
     */
    
    int maxending = 0;
    int maxsofar = 0;
    
    for(int i = 0;i<n;++i){
        maxending = mymax_2(maxending+arr[i], 0);
        maxsofar = mymax_2(maxending, maxsofar);
    }
    return maxsofar;
}

void findMaxSeqCloseZero(int *arr,int n,int *sum,int *sum_sort,int *h,int *m)
{
    /*O(n)*/
    for(int j = 0;j<n;++j){
        if(j == 0){
            /*sum[-1] = 0*/
            sum[0] = arr[0] +0;
        }
        else{
            sum[j] = arr[j] + sum[j-1];
        }
    }
    /*sum[i] means from 0 to i the sum of arr*/
    /*[k,l],sum[k-1] = sum[l] means [k,l] 区间累加 = 0*/

    for(int j = 0;j<n;++j){
        sum_sort[j] = sum[j];
    }
    clock_t start,end;
    start = clock();
    myquickSort(sum_sort, 0, n-1, n);
    end = clock();
    printf("total time = %f\n",(float)(end-start)/CLOCKS_PER_SEC);
    for(int i = 0;i<n;++i){
        printf("originl %d:%d\n",i,sum[i]);
    }
    for(int i = 0;i<n;++i){
        printf("%d:%d\n",i,sum_sort[i]);
    }
    int minSum = abs(sum_sort[0]);
    int k=0,l =0;
    for(int i = 1;i<n;++i){
        int delt = abs(sum_sort[i]-sum_sort[i-1]);
        if(delt < minSum){
            minSum = delt;
            k = i-1;
            l = i;
        }
    }
    printf("%d:%d has min sum:%d\n",k,l,minSum);
    for(int i =0;i<n;++i){
        if(sum_sort[k] == sum[i]){
            *h = i;
        }
        if(sum_sort[l] == sum[i]){
            *m = i;
            break;
        }
    }
}

void myquickSort(int *arr,int l,int r,int n)
{
    if(l>=r){
        return;
    }
    int mid = myPivot(arr, l, r, n);
    myquickSort(arr, l, mid-1, n);
    myquickSort(arr, mid+1, r, n);
}

int myPivot(int *arr,int l,int r,int n)
{
    int pivot = arr[l];
    
    int i = l;
    
    int j = r+1;

    while(1){
        do{
            i++;
        }while(i<=r && arr[i] < pivot);
        
        do{
            j--;
        }while(arr[j] > pivot);
        
        if(i>j){
            break;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] =temp;
    }
    arr[l] = arr[j];
    arr[j] = pivot;
    return j;
}
