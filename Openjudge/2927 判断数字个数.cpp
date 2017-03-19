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
#include<memory.h>
using namespace std;

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    char s[500];
    while(gets(s)){
        int n[10];
        memset(n,0,sizeof(n));
        for(int i=0;i<strlen(s);i++) if(s[i]>='0'&&s[i]<='9') n[s[i]-'0']++;
        for(int i=0;i<10;i++) if(n[i]>0) printf("%d:%d\n",i,n[i]);
    }
    return 0;
}
