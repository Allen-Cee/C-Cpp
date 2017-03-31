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
    int t;
    scanf("%d",&t);
    while(t-->0){
        int num=0;
        char hex[9];
        scanf("%s",hex);
        for(int i=(int)strlen(hex)-1,j=0;i>=0;i--,j++){
            if(hex[i]>='A'&&hex[i]<='F') num+=(hex[i]-'A'+10)*pow(16,j);
            else if(hex[i]>='0'&&hex[i]<='9') num+=(hex[i]-'0')*pow(16,j);
        }
        printf("%d\n",num);
    }
    return 0;
}
