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

int CMPD(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}

int CMPA(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int tmp;
    while(scanf("%d",&tmp)!=EOF){
        int no=0,ne=0,o[10],e[10],n=9;
        if(tmp%2) o[no++]=tmp;
        else e[ne++]=tmp;
        while(n-->0){
            scanf("%d",&tmp);
            if(tmp%2) o[no++]=tmp;
            else e[ne++]=tmp;
        }
        qsort(o,no,sizeof(o[0]),CMPD);
        qsort(e,ne,sizeof(e[0]),CMPA);
        for(int i=0;i<no;i++) printf("%d ",o[i]);
        for(int i=0;i<ne;i++) printf("%d ",e[i]);
        printf("\n");
    }
    return 0;
}
