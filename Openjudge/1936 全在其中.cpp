//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<stdio.h>
#include<cstring>

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    char s[100001],t[100001];
    while(scanf("%s%s",s,t)!=EOF){
        int len1=(int)strlen(s),len2=(int)strlen(t),i=0,j=0;
        if(len1>len2){
            printf("No\n");
            continue;
        }
        for(;i<len1&&j<len2;j++){
            while(t[j]!=s[i]&&j<len2) j++;
            if(t[j]==s[i]&&j<len2) i++;
        }
        if(i==len1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
