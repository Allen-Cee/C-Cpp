//
//  main.cpp
//  cpp_test
//
//  Created by Aoi on 3/10/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;

int main(){
    char str[11],substr[4];
    while(scanf("%s%s",str,substr)!=EOF){
        int max=0;
        for(int i=0;str[i]!='\0';i++) if(str[i]>str[max]) max=i;
        for(int i=0;i<=max;i++) printf("%c",str[i]);
        printf("%s",substr);
        if(max<strlen(str)-1) for(int i=max+1;str[i]!='\0';i++) printf("%c",str[i]);
        printf("\n");
        memset(str,'\0',11);
        memset(substr,'\0',4);
    }
    return 0;
}
