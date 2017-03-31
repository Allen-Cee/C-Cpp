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
    char c[61];
    while(scanf("%s",c)!=EOF){
        int len=(int)strlen(c),n[len],sum=0;
        for(int i=len-1,j=0;i>=0;i--,j++){
            n[j]=c[i]-'0';
            sum+=n[j];
        }
        if(sum%9!=0){
            printf("%s is not cyclic\n",c);
            continue;
        }
        for(int i=0;i<len;i++) n[i]*=len+1;
        for(int i=0;i<len-1;i++) if(n[i]>9){
            n[i+1]+=n[i]/10;
            n[i]%=10;
            if(n[i]!=9){
                printf("%s is not cyclic\n",c);
                goto Done;
            }
        }
        if(n[len-1]!=9) printf("%s is not cyclic\n",c);
        else printf("%s is cyclic\n",c);
    Done:
        memset(c,'\0',sizeof(c));
    }
    return 0;
}
