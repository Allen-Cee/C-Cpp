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

int comp(const void *a,const void *b){
    if(*((double *)b+2)-*((double *)a+2)>0) return 1;
    else if(*((double *)b+2)-*((double *)a+2)<0) return -1;
    return 0;
}

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    while(n-->0){
        int weight,num;
        scanf("%d%d",&weight,&num);
        double type[num][3],value=0,sum=0;
        for(int i=0;i<num;i++){
            scanf("%lf%lf",&type[i][0],&type[i][1]);
            type[i][2]=type[i][1]/type[i][0];
        }
        qsort(type,num,sizeof(type[0]),comp);
        for(int i=0;i<num;i++){
            if(sum+type[i][0]<=weight){
                sum+=type[i][0];
                value+=type[i][1];
            }
            else{
                value+=(weight-sum)/type[i][0]*type[i][1];
                sum=weight;
            }
        }
        printf("%.2lf\n",value);
    }
    return 0;
}
