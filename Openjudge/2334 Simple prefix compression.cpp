//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//
//freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    char s[2][256];
    int total_length=0;
    scanf("%s",s[0]);
    total_length+=strlen(s[0]);
    for(int i=1;i<n;i++){
        int minus=0;
        scanf("%s",s[1]);
        for(int j=0;j<255&&s[0][j]!='\0'&&s[1][j]!='\0';j++){
            if(s[0][j]==s[1][j]) ++minus;
            else break;
        }
        total_length+=strlen(s[1])-minus+1;
        strcpy(s[0],s[1]);
    }
    printf("%d\n",total_length);
    return 0;
}
