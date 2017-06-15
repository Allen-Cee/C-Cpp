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

int M[6];
int SUM;

bool CH(int value,int n){
    if(n==0){
        if(value<=M[0]) return true;
        else return false;
    }
    else{
        int sum=0;
        for(int i=0;i<n;++i) sum+=M[i]*(i+1);
        if((!(value%(n+1)))&&(value<=(n+1)*M[n])) return true;
        else{
            for(int i=0;i<=M[n];++i){
                if(value-i*(n+1)>sum) continue;
                else if(value-i*(n+1)<0) break;
                if(CH(value-i*(n+1),n-1)) return true;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int cases=0;
    while(scanf("%d%d%d%d%d%d",&M[0],&M[1],&M[2],&M[3],&M[4],&M[5])){
        
        if(M[0]==0&&M[1]==0&&M[2]==0&&M[3]==0&&M[4]==0&&M[5]==0) break;
        ++cases;
        printf("Collection #%d:\n",cases);
        
        for(int i=0;i<6;++i){
            M[i]%=12;
            SUM+=(i+1)*M[i];
        }
        
        if(SUM%2) printf("Can't be divided.\n\n");
        else{
            SUM/=2;
            if(CH(SUM,5)) printf("Can be divided.\n\n");
            else printf("Can't be divided.\n\n");
        }
        
        SUM=0;
    }
    return 0;
}
