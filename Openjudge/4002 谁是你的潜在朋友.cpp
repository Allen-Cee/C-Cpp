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
    int n,m;
    scanf("%d%d",&n,&m);
    int s[n],b[m+1];
    memset(b,-1,sizeof(b));
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
        b[s[i]]++;
    }
    for(int i=0;i<n;i++){
        if(b[s[i]]) printf("%d\n",b[s[i]]);
        else printf("BeiJu\n");
    }
    return 0;
}
