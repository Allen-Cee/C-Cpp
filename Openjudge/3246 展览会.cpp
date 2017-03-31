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
    int n;
    scanf("%d",&n);
    int x[n],y[n],t[4000],max=0;
    memset(t,0,sizeof(t));
    for(int i=0;i<n;i++) scanf("%d",&x[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&y[i]);
        for(int j=x[i];j<y[i];j++) t[j]++;
    }
    for(int i=0;i<4000;i++) if(max<t[i]) max=t[i];
    printf("%d\n",max);
    return 0;
}
