//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n,max=0;
    scanf("%d",&n);
    short nm[n];
    char num[n][60];
    for(int i=0;i<n;i++){
        scanf("%s",num[i]);
        nm[i]=0;
        while(num[i][nm[i]]!='.') nm[i]++;
        if(max<nm[i]) max=nm[i];
    }
    for(int i=0;i<n;i++){
        int spc=max-nm[i];
        while(spc-->0) printf(" ");
        printf("%s\n",num[i]);
    }
    return 0;
}
