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

class Student{
public:
    double s;
    int t;
};

int CMP(const void *a,const void *b){
    Student sa=*(Student *)a,sb=*(Student *)b;
    if(sa.t==sb.t) return sb.s-sa.s;
    return sa.t-sb.t;
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int n;
    while(scanf("%d",&n)){
        if(n==0) break;
        Student stu[n];
        int num=0;
        for(int i=0;i<n;i++){
            int t;
            double s;
            scanf("%lf%d",&s,&t);
            if(t>=0){
                stu[num].t=t;
                stu[num++].s=s/3.6;
            }
        }
        qsort(stu,num,sizeof(stu[0]),CMP);
        int ct=stu[0].t+1;
        double cm=0;
        for(;cm<4500;ct++) for(int i=0;i<num;i++) if(cm<=stu[i].s*(ct-stu[i].t)) cm=stu[i].s*(ct-stu[i].t);
        printf("%d\n",ct-1);
    }
    return 0;
}
