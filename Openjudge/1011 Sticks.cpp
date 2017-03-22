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

int n,len,num,part[64];
bool visited[64],solved,lenfalse;

int CMP(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}

void DFS(int rl,int rn,int point){
    //cout<<"CHECKING... LEN "<<len<<" RL "<<rl<<" RN "<<rn<<" AT POINT "<<point<<" "<<part[point]<<endl;
    if(rl==len&&rn==1){
        printf("%d\n",len);
        solved=1;
        return;
    }
    while(point<n){
        while((part[point]>rl||visited[point])&&point<n) point++;
        if(point<n){
            rl-=part[point];
            visited[point]=1;
            if(rl==0) DFS(len,rn-1,0);
            else DFS(rl,rn,point+1);
            //if(rl==0) lenfalse=1;
            rl+=part[point];
            visited[point]=0;
            if(rl==len) return;
            if(lenfalse||solved){
                lenfalse=1;
                return;
            }
            do{point++;} while(part[point]==part[point-1]&&point<n);
        }
    }
}

int main(){
    //freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    while(scanf("%d",&n)){
        solved=0;
        memset(visited,0,sizeof(visited));
        memset(part,0,sizeof(part));
        if(n==0) break;
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&part[i]);
            sum+=part[i];
        }
        qsort(part,n,sizeof(part[0]),CMP);
        //for(int i=0;i<n;i++) printf("%d ",part[i]);
        for(int i=part[0];i<=sum;i++){
            if(sum%i==0){
                lenfalse=0;
                len=i;
                //cout<<"CHECKING LENGTH "<<i<<endl;
                num=sum/i;
                DFS(len,num,0);
                if(solved) break;
            }
        }
    }
    return 0;
}

//454
//454
//101
//89
//89
//20
//20
//99
//20
//16
//14
//6
//6
//8
//5
//1
//63 61 59 58 56 55 53 51 51 47 46 45 44 43 42 42 40 39 39 37 37 36 32 32 31 29 28 27 26 25 23 23 21 19 19 17 16 16 15 14 12 11 11 10 8 4
