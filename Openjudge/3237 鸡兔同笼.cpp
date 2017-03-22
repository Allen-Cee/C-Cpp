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

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    while(n--){
        int l;
        scanf("%d",&l);
        if(l%2==1) printf("0 0\n");
        else if(l%4==0) printf("%d %d\n",l/4,l/2);
        else printf("%d %d\n",(l+2)/4,l/2);
        
    }
    return 0;
}
