//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    char w[101][101],a[101],b[101];
    int n=0;
    while(scanf("%s",w[n++])) if(getchar()!=' ') break;
    scanf("%s%s",a,b);
    for(int i=0;i<n;i++){
        if(memcmp(w[i],a,strlen(a))==0&&strlen(w[i])==strlen(a)) printf("%s ",b);
        else printf("%s ",w[i]);
    }
    printf("\n");
    return 0;
}
