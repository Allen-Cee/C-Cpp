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

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int n,max=-127;
    scanf("%d",&n);
    int m[n][n],sum[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&m[i][j]);
            if(max<m[i][j]) max=m[i][j];
            //预处理 避免后续确定上下界后再次遍历加总
            if(j==0) sum[i][j]=m[i][j];
            else sum[i][j]=m[i][j]+sum[i][j-1];
        }
    }
    for(int j1=0;j1<n-1;j1++){
        for(int j2=j1+1;j2<n;j2++){
            int maxn=0,cur=0;
            for(int i=0;i<n;i++){
                int tmp=sum[i][j2]-((j1==0)?0:sum[i][j1-1]);
                cur+=tmp;
                if(maxn<cur) maxn=cur;
                else if(cur<0) cur=0;
            }
            if(max<maxn) max=maxn;
        }
    }
    printf("%d\n",max);
    return 0;
}
