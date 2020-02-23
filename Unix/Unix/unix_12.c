//
//  unix_12.c
//  Unix
//
//  Created by Administrator on 2020/2/22.
//  Copyright © 2020 Administrator. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myBigrand(void);

int myRandint(int,int);
/*problem:从[0,n)中随机选取m个数按序输出，每个数字的选中的概率一样*/


//int main(){
//    srand((unsigned)time(NULL));
//
//    int m,n;
//    
//    while (scanf("%d %d",&n,&m)!=EOF) {
//        if(m<=n){
//            /* 当*/
//            int remain = n;
//            int select = m;
//            for(int i =0;i<n;++i){
//                if(myBigrand()%remain<select){
//                    printf("%d\n",i);
//                    select--;
//                }
//                remain--;
//            }
//        }
//    }
//    
//}

int myBigrand()
{
    return abs(rand()*RAND_MAX + rand());
}

int myRandint(int l,int u){
    /*[l,u]*/
    /*etc.[1,2]*/
    return abs(myBigrand()%(u-l+1)) + l;
}
