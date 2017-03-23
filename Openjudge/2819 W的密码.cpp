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
    //freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    int k1,k2,k3;
    while(scanf("%d%d%d",&k1,&k2,&k3)){
        if(k1==0&&k2==0&&k3==0) break;
        char s[101];
        scanf("%s",s);
        int n1=0,n2=0,n3=0,num[strlen(s)];
        char a[strlen(s)+1];
        a[strlen(s)]='\0';
        for(int i=0;s[i]!='\0';i++) if(s[i]>='a'&&s[i]<='i') num[n1++]=i;
        for(int i=0;i<n1;i++) a[num[(i+k1)%n1]]=s[num[i]];
        for(int i=0;s[i]!='\0';i++) if(s[i]>='j'&&s[i]<='r') num[n2++]=i;
        for(int i=0;i<n2;i++) a[num[(i+k2)%n2]]=s[num[i]];
        for(int i=0;s[i]!='\0';i++) if((s[i]>='s'&&s[i]<='z')||s[i]=='_') num[n3++]=i;
        for(int i=0;i<n3;i++) a[num[(i+k3)%n3]]=s[num[i]];
        printf("%s\n",a);
    }
    return 0;
}
