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

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    char s[101];
    while(scanf("%s",s)!=EOF){
        printf("%s\n",s);
        int len=(int)strlen(s);
        bool l[len],r[len];
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                l[i]=1;
            }
            else if(s[i]==')'){
                bool b=0;
                for(int j=i-1;j>=0;j--) if(l[j]){
                    l[j]=0;
                    b=1;
                    break;
                }
                if(!b) r[i]=1;
            }
        }
        for(int i=0;i<len;i++){
            if(l[i]) printf("$");
            else if(r[i]) printf("?");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
