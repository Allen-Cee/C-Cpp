//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<memory>
using namespace std;

int CMP(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int n,count=0;
    scanf("%d",&n);
    int num[n];
    bool nu[n];
    memset(nu,0,sizeof(nu));
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    qsort(num,n,sizeof(num[0]),CMP);
    for(int i=0;i<n-2;i++) for(int j=i+1;j<n-1;j++) for(int k=j+1;k<n;k++){
        if(nu[k]) continue;
        if(num[k]==num[i]+num[j]){
            nu[k]=1;
            count++;
            break;
        }
    }
    printf("%d\n",count);
    return 0;
}
