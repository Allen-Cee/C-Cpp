//
//  main.cpp
//  Cpp Project
//
//  Created by Aoi on 3/5/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<stdio.h>
using namespace std;

int& tmp(int x){
    static int r=0;
    r+=x;
    printf("%d\n",x);
    return r;
}

int main(){
    printf("%d %d %d\n",tmp(5),tmp(8),tmp(20));
    return 0;
}
