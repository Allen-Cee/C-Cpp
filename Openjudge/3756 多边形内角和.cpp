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
    int sum=(n-2)*180;
    while(--n>0){
        int tmp;
        scanf("%d",&tmp);
        sum-=tmp;
    }
    printf("%d\n",sum);
    return 0;
}
