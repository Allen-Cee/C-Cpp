//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 6/9/17.
//  Copyright © 2017 Aoi. All rights reserved.
//
//freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);

#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int NUM=0;
long long NO=0;
long long num[21][21][2];

bool used[21];

void PrintR(long long cur_no,int cur_len,int trans,int real_num){
    int cur_num=0;
    long long acc=0;
    for(int i=1;i<=NUM;++i){
        if(!used[i]) ++cur_num;
        else continue;
        //cout<<endl<<"R CURNO "<<cur_no<<" CURLEN "<<cur_len<<" I "<<i<<" ACC "<<acc<<" CURNUM "<<cur_num<<" REALNUM "<<real_num<<" TRANS "<<trans<<endl;
        if((trans==1&&cur_num<real_num&&cur_no<=acc+num[cur_len][cur_num][1])||(trans==-1&&cur_num>=real_num&&cur_no<=acc+num[cur_len][cur_num][0])){
            printf("%d ",i);
            used[i]=1;
            if(cur_len>1){
                PrintR(cur_no-acc,cur_len-1,trans*(-1),cur_num);
            }
            break;
        }
        if(cur_num<real_num&&trans==1) acc+=num[cur_len][cur_num][1];
        else if(cur_num>=real_num&&trans==-1) acc+=num[cur_len][cur_num][0];
    }
    return;
}

void Print(long long cur_no,int cur_len){
    int cur_num=0;
    long long acc=0;
    for(int i=1;i<=NUM;++i){
        if(!used[i]) ++cur_num;
        else continue;
        if(cur_no<=acc+num[cur_len][cur_num][0]+num[cur_len][cur_num][1]){
            printf("%d ",i);
            used[i]=1;
            if(cur_len>1){
                if(cur_no<=acc+num[cur_len][cur_num][0]) PrintR(cur_no-acc,cur_len-1,1,cur_num);
                else PrintR(cur_no-acc-num[cur_len][cur_num][0],cur_len-1,-1,cur_num);
            }
            break;
        }
        acc+=num[cur_len][cur_num][0]+num[cur_len][cur_num][1];
    }
    return;
}

int main(int argc, const char * argv[]) {
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int cases=0;
    scanf("%d",&cases);
    
    num[1][1][0]=num[1][1][1]=1;
    
    for(int cur_num=2;cur_num<=20;++cur_num){
        for(int i=1;i<=cur_num;++i){
            for(int j=1;j<i;++j) num[cur_num][i][0]+=num[cur_num-1][j][1];
            for(int j=i;j<cur_num;++j) num[cur_num][i][1]+=num[cur_num-1][j][0];
        }
    }
    
    while(cases-->0){
        scanf("%d%lld",&NUM,&NO);
        Print(NO,NUM);
        printf("\n");
        memset(used,0,sizeof(used));
    }
    return 0;
}



/*

 
 1 3 2 4
 1 4 2 3

 2 1 4 3
 2 3 1 4
 2 4 1 3
 
 3 1 4 2
 3 2 4 1
 3 4 1 2
 
 4 1 3 2
 4 2 3 1
 


*/
