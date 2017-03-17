//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<stdio.h>
#include<cstring>
#include<memory.h>

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    char tmp[41],one[41];
    short len=0;
    while(scanf("%s",tmp)!=EOF){
        if(len<strlen(tmp)){
            len=strlen(tmp);
            memcpy(one,tmp,sizeof(one));
        }
        memset(tmp,'\0',sizeof(tmp));
    }
    printf("%s\n",one);
    return 0;
}
