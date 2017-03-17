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
    char f[10][5]={
        {'a','b','n','b','a'},
        {'n','r','n','r','n'},
        {'a','r','a','l','a'},
        {'a','r','a','r','a'},
        {'n','b','a','r','n'},
        {'a','l','a','r','a'},
        {'a','l','a','b','a'},
        {'a','r','n','r','n'},
        {'a','b','a','b','a'},
        {'a','b','a','r','a'}
    };
    int n;
    char num[10];
    while(scanf("%d",&n)){
        scanf("%s",num);
        if(n==0&&num[0]=='0') break;
        for(int k=0;k<5;k++){
            if(k==1||k==3){
                for(int l=0;l<n;l++){
                    for(int i=0;i<strlen(num);i++){
                        if(f[num[i]-'0'][k]=='b') for(int j=0;j<n+2;j++){
                            if(j==0||j==n+1) printf("|");
                            else printf(" ");
                        }
                        else if(f[num[i]-'0'][k]=='l') for(int j=0;j<n+2;j++){
                            if(j==0) printf("|");
                            else printf(" ");
                        }
                        else for(int j=0;j<n+2;j++){
                            if(j==n+1) printf("|");
                            else printf(" ");
                        }
                        printf(" ");
                    }
                    printf("\n");
                }
            }
            else{
                for(int i=0;i<strlen(num);i++){
                    printf(" ");
                    if(f[num[i]-'0'][k]=='a') for(int j=0;j<n;j++) printf("-");
                    else for(int j=0;j<n;j++) printf(" ");
                    printf("  ");
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
