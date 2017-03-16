#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int comp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main() {
    int num[15],n,result=0;
    for(n=0;cin>>num[n];n++)
        if(num[n]==0) break;
    qsort(num,n,sizeof(int),comp);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(num[i]*2<num[j]) break;
            if(num[i]*2==num[j]){
                result++;
                break;
            }
        }
    cout<<result<<endl;
    return 0;
}