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
    int t;
    scanf("%d",&t);
    while(t-->0){
        int n[5];
        for(int i=0;i<4;i++){
            scanf("%d",&n[i]);
            printf("%d ",n[i]);
        }
        if(n[1]-n[0]==n[2]-n[1]&&n[3]-n[2]==n[1]-n[0]) printf("%d\n",n[3]+n[1]-n[0]);
        else printf("%d\n",n[3]*n[1]/n[0]);
    }
    return 0;
}
