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

class Student{
public:
    char name[20],other[20];
    int num;
};

int CMP(const void *a,const void *b){
    return strcasecmp((*(Student *)a).name,(*(Student *)b).name);
}

int main(){
    freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    Student stu[100];
    int n=0;
    while(gets(stu[n].name)){
        char c=stu[n].name[0];
        if(!((c>='A'&&c<='Z')||(c>='a'&&c<='z'))) break;
        scanf("%d",&stu[n].num);
        gets(stu[n].other);
        n++;
    }
    qsort(stu,n,sizeof(stu[0]),CMP);
    for(int i=0;i<n;i++) printf("%s\n%08d%s\n",stu[i].name,stu[i].num,stu[i].other);
    return 0;
}
