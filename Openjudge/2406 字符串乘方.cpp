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
    char s[1000001];
    while(scanf("%s",s)){
        int len=(int)strlen(s),i;
        if(s[0]=='.'&&len==1) break;
        for(i=1;i<len;i++){
            if(len%i) continue;
            bool b=1;
            char *sub=new char[i];
            memcpy(sub,s,i);
            for(int j=0;j<len;j+=i) if(memcmp(sub,&s[j],i)){
                b=0;
                break;
            }
            if(b) break;
        }
        printf("%d\n",len/i);
    }
    return 0;
}
