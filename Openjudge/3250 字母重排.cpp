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
    return *(char *)a-*(char *)b;
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    char s[1024],l[1024],n=0;
    scanf("%s",s);
    for(int i=(int)strlen(s)-1;i>=0;i--) if(s[i]>='a'&&s[i]<='z') l[n++]=s[i];
    qsort(l,n,sizeof(l[0]),CMP);
    printf("%s\n",l);
    return 0;
}
