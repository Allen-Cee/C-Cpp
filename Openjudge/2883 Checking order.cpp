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
    return *(int *)a-*(int *)b;
}

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n[5];
    while(scanf("%d",&n[0])!=EOF){
        bool b=1;
        for(int i=1;i<5;i++){
            scanf("%d",&n[i]);
            if(n[i]<n[i-1]) b=0;
        }
        if(b) printf("Yes\n");
        else{
            qsort(n,5,sizeof(n[0]),comp);
            printf("No ");
            for(int i=0;i<5;i++) printf("%d ",n[i]);
            printf("\n");
        }
    }
    return 0;
}
