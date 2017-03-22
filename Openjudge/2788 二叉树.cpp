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
    int n,m;
    while(scanf("%d%d",&m,&n)){
        if(n==0&&m==0) break;
        int i=1;
        while(pow(2,i)*m<=n) i++;
        int min=(int)pow(2,i-1)*m,max=min+min/m-1;
        printf("%d\n",min/m+((n>max)?max:n)-min);
    }
    return 0;
}
