#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
#include<unistd.h>
using namespace std;

int MAX,n,M[25],MN[25];

int numM(int ci){
    if(MN[ci]==0){
        int mc=0;
        for(int i=ci+1;i<n;i++){
            if(M[i]>M[ci]) continue;
            else{
                int mn;
                if(MN[i]>0) mn=MN[i];
                else mn=numM(i);
                if(mc<mn) mc=mn;
            }
        }
        MN[ci]=mc+1;
        return MN[ci];
    }
    else return MN[ci];
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&M[i]);
    for(int i=0;i<n;i++) if(MAX<numM(i)) MAX=MN[i];
    printf("%d\n",MAX);
    return 0;
}
