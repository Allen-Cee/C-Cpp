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
#include<cmath>
#include<memory.h>
using namespace std;

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    char s1[101],s2[101];
    while(gets(s1)){
        gets(s2);
        int l[26],u[26];
        memset(l,0,sizeof(l));
        memset(u,0,sizeof(u));
        for(int i=0;s1[i]!='\0';i++){
            if(s1[i]>='a'&&s1[i]<='z') l[s1[i]-'a']--;
            else if(s1[i]>='A'&&s1[i]<='Z') u[s1[i]-'A']--;
        }
        for(int i=0;s2[i]!='\0';i++){
            if(s2[i]>='a'&&s2[i]<='z') l[s2[i]-'a']++;
            else if(s2[i]>='A'&&s2[i]<='Z') u[s2[i]-'A']++;
        }
        bool b=0;
        for(int i=0;i<26;i++) if(l[i]<0||u[i]<0){
            b=1;
            break;
        }
        if(b) printf("0\n");
        else printf("1\n");
        memset(s1,'\0',sizeof(s1));
        memset(s2,'\0',sizeof(s2));
    }
    return 0;
}
