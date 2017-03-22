//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;

int comp(const void *a,const void *b){
    int m=*(int *)a;
    int n=*(int *)b;
    if((m+n)%2){
        if(m%2) return -1;
        else return 1;
    }
    return m-n;
}

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n[10];
    for(int i=0;i<10;i++) scanf("%d",&n[i]);
    qsort(n,10,sizeof(n[0]),comp);
    for(int i=0;i<10;i++) printf("%d ",n[i]);
    printf("\n");
    return 0;
}
