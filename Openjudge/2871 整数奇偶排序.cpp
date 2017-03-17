//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

int comp(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}

int main() {
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int a[10];
    while(scanf("%d",&a[0])!=EOF){
        int o[10],e[10],on=0,en=0;
        for(int i=0;i<10;i++){
            if(i>0) scanf("%d",&a[i]);
            if(a[i]%2==1){
                o[on]=a[i];
                on++;
            }
            else{
                e[en]=a[i];
                en++;
            }
        }
        qsort(o,on,sizeof(o[0]),comp);
        qsort(e,en,sizeof(e[0]),comp);
        for(int i=0;i<on;i++) printf("%d ",o[i]);
        for(int i=en-1;i>=0;i--) printf("%d ",e[i]);
        printf("\n");
    }
    return 0;
}
