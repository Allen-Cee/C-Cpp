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
    freopen("/Users/Aoi/Desktop/Data.txt","r",stdin);
    char s[201];
    while(gets(s)){
        int h=0,maxlen=0;
        int len=(int)strlen(s);
        for(int i=0;i<len;i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                int lentmp=1,htmp=i;
                while((s[i+1]>='a'&&s[i+1]<='z')||(s[i+1]>='A'&&s[i+1]<='Z')){
                    i++;
                    lentmp++;
                }
                if(maxlen<=lentmp){
                    maxlen=lentmp;
                    h=htmp;
                }
            }
        }
        for(int i=h;(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z');i++) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
