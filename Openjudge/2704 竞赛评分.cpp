//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<memory.h>
using namespace std;

int compd(const void *a,const void *b){
    return *((int *)b+1)-*((int *)a+1);
}

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n,score[3][2]={{1,0},{2,0},{3,0}};
    scanf("%d",&n);
    while(n-->0){
        char result[3][8];
        for(int i=0;i<3;i++){
            scanf("%s",result[i]);
            if(result[i][0]=='r') score[i][1]+=10;
            else if(result[i][0]=='w') score[i][1]-=10;
        }
    }
    qsort(score,3,sizeof(score[0]),compd);
    for(int i=0;i<3;i++){
        printf("(%d,%d)",score[i][0],score[i][1]);
        if(i<2&&score[i][1]>score[i+1][1]) printf("\n");
    }
    return 0;
}
