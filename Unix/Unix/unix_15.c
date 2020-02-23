//
//  unix_15.c
//  Unix
//
//  Created by Administrator on 2020/2/23.
//  Copyright © 2020 Administrator. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 5000000

int pstrncpm(const char *,const char *);
int comlen(const char *a,const char *b);


int main(){
    char c[MAXN];
    char *a[MAXN];
    
    char ch;
    int n =0;
    while ((ch = getchar())!=EOF) {
        c[n] = ch;
        a[n] = &c[n++];
    }
    c[n] = '\0';
    qsort(a, n, sizeof(char), pstrncpm);
    int maxlencur = 0;
    int maxi =0;
    for(int i =0;i<n;++i){
        int maxlen = comlen(a[i], a[i+1]);
        if(maxlencur<maxlen){
            maxlencur = maxlen;
            maxi = i;
        }
    }
    printf("%.*s\n",maxlencur,a[maxi]);
}


int pstrncpm(const char *a,const char *b)
{
    return strcmp(a,b);
}

int comlen(const char *a,const char *b)
{
    int i =0;
    while (*a != '\0' && (*a++ == *b++)) {
        ++i;
    }
    return i;
}
