#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <typeinfo>
#include <unistd.h>
using namespace std;

int n,getMan;

int getMax(int num[],int p){
    if(p<n-1){
        int tmp=getMax(num,p+1);
        if(tmp>0){
            if(getMan<num[p]+tmp) getMan=num[p]+tmp;
            return num[p]+tmp;
        }
        else{
            if(getMan<num[p]) getMan=num[p];
            return num[p];
        }
    }
    else return num[p];
}

int main(){
    int man=0;
    scanf("%d",&n);
    int m[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&m[i][j]);
    for(int j1=0;j1<n;j1++){
        for(int j2=j1;j2<n;j2++){
            int num[n];
            for(int i=0;i<n;i++){
                int sum=0;
                for(int j=j1;j<=j2;j++) sum+=m[i][j];
                num[i]=sum;
            }
            getMan=num[0];
            getMax(num,0);
            if(man<getMan) man=getMan;
        }
    }
    printf("%d\n",man);
    return 0;
}