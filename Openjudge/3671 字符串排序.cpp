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

int CMP(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    char s[5][11];
    for(int i=0;i<5;i++) scanf("%s",s[i]);
    qsort(s,5,sizeof(s[0]),CMP);
    for(int i=0;i<5;i++) printf("%s\n",s[i]);
    return 0;
}
