//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;

int mx[5][5],mi[5][5];
bool b;

int main(){
    //freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    int m[5][5];
    for(int i=0;i<5;i++){
        int tmp=0;
        for(int j=0;j<5;j++){
            scanf("%d",&m[i][j]);
            if(m[i][tmp]<m[i][j]) tmp=j;
        }
        mx[i][tmp]=1;
    }
    for(int j=0;j<5;j++){
        int tmp=0;
        for(int i=0;i<5;i++) if(m[tmp][j]>m[i][j]) tmp=i;
        if(mx[tmp][j]){
            b=1;
            printf("%d %d %d\n",tmp+1,j+1,m[tmp][j]);
            break;
        }
    }
    if(!b) printf("not found\n");
    return 0;
}
