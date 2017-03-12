//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<memory.h>
using namespace std;

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int x,y;
    while(cin>>x>>y){
        if(x>=-1&&x<=1&&y>=-1&&y<=1) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
