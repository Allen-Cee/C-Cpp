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

bool b;

inline void R(int n){
    if(n>9){
        b=1;
        n--;
    }
    else if(n<1) return;
    printf("%d",n);
    if(b) R(--n);
    else R(++n);
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    R(n);
    return 0;
}
