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

//Beatty Sequence Alpha/Beta==Phi 
double phi=((double)1+sqrt((double)5))/(double)2;

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        int c=abs(a-b);
        a=(a>b)?b:a;
        if(int(c*phi)==a) printf("0\n");
        else printf("1\n");
    }
    return 0;
}
