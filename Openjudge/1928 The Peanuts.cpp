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
using namespace std;

int comp(const void *a,const void *b){
    return *((int *)b+2)-*((int *)a+2);
}

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t-->0){
        int m,n,k;
        scanf("%d%d%d",&m,&n,&k);
        int pn[m*n][3];
        for(int i=0;i<m;i++) for(int j=0;j<n;j++){
            pn[i*n+j][0]=j;
            pn[i*n+j][1]=i;
            scanf("%d",&pn[i*n+j][2]);
        }
        qsort(pn,m*n,sizeof(pn[0]),comp);
        int time=pn[0][1]+2,num=0;
        if(time+pn[0][1]+1<=k){
            num=pn[0][2];
            for(int i=1;i<m*n;i++){
                int tmp=time+abs(pn[i][0]-pn[i-1][0])+abs(pn[i][1]-pn[i-1][1])+1;
                if(tmp+pn[i][1]+1<=k){
                    time=tmp;
                    num+=pn[i][2];
                }
                else break;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
