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
using namespace std;

int comp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n,same=0;
    scanf("%d",&n);
    int num[n];
    bool ndup=true;
    for(int t=0;t<n;t++){
        int d=6;
        num[t]=0;
        char pn[50];
        scanf("%s",pn);
        for(int i=0;pn[i]!='\0';i++){
            if(pn[i]>='0'&&pn[i]<='9') num[t]+=(pn[i]-'0')*pow(10,d--);
            else if(pn[i]>='A'&&pn[i]<='Y'){
                if(pn[i]>='A'&&pn[i]<='O') num[t]+=((pn[i]-'A')/3+2)*pow(10,d--);
                else if(pn[i]=='P'||pn[i]=='R'||pn[i]=='S') num[t]+=7*pow(10,d--);
                else if(pn[i]>='T'&&pn[i]<='Y') num[t]+=(pn[i]-'A'+5)/3*pow(10,d--);
            }
        }
    }
    qsort(num,n,sizeof(num[0]),comp);
    for(int i=0;i<n-1;i++){
        if(num[i+1]!=num[i]){
            if(same==0) continue;
            else{
                printf("%03d-%04d %d\n",num[i]/10000,num[i]%10000,same+1);
                same=0;
                ndup=false;
                continue;
            }
        }
        else same++;
    }
    if(same>0){
        printf("%03d-%04d %d\n",num[n-1]/10000,num[n-1]%10000,same+1);
        ndup=false;
    }
    if(ndup) printf("No duplicates.\n");
    return 0;
}
