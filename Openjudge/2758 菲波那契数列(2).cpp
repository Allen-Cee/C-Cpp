//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstdio>
using namespace std;

int  main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n,a;
    cin>>n;
    while(n-->0){
        int fc=1,fn=1;
        scanf("%d",&a);
        while(a-->1){
            int tmp=(fc+fn)%1000;
            fc=fn;
            fn=tmp;
        }
        printf("%d\n",fc);
    }
    return 0;
}
