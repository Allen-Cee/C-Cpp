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
    char s[1000],sc[1000];
    int code[7]={4,9,6,2,8,7,3};
    gets(s);
    strcpy(sc,s);
    for(int i=0;s[i]!='\0';i++){
        sc[i]+=code[i%7];
        if(sc[i]>122) sc[i]=sc[i]%122+31;
    }
    printf("%s\n%s\n",sc,s);
    return 0;
}
