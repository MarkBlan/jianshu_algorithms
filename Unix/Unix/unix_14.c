//
//  unix_14.c
//  Unix
//
//  Created by Administrator on 2020/2/23.
//  Copyright © 2020 Administrator. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void myBuildHeap(int *,int );
void mySiftUp(int *,int,int);
void mySiftDown(int *,int);
void myDeleteMin(int *,int);

int main(){
    srand((unsigned)time(NULL));
    int n;
    int *arr;
    while ((scanf("%d",&n)!=EOF)) {
        
        arr = malloc(sizeof(int)*(n+1));
        
        arr[0] = 0;
        
        for(int i = 1;i<=n;++i){
            
            arr[i] = rand()%100;
            
        }
        myBuildHeap(arr, n);
        
        for(int i = 1;i<=n;++i){
            printf("%d ",arr[i]);
        }
        printf("\n");
        free(arr);
    }
}

void myBuildHeap(int *arr,int n){
    
    int *arr_temp = malloc(sizeof(int)*(n+1));
    
    arr_temp[0] = 0;
    
    for(int i = 1;i<=n;++i){
        /*heap(location-1)*/
        /*build(loacation)*/
        mySiftUp(arr_temp,arr[i],i);
        
    }
    
    for(int i =1;i<=n;++i){
        
        arr[i] =arr_temp[i];
        
    }
    
    free(arr_temp);
}

void mySiftUp(int *arr,int k,int location){
    /*heap(location-1)*/
    int i = location;
    
    while (i/2>0 && k <arr[i/2]) {
        
        arr[i] = arr[i/2];
        
        i /=2;
    }
    
    arr[i]=k;
}

void mySiftDown(int *arr,int n){
    
}

void myDeleteMin(int *arr,int n){
    
}
