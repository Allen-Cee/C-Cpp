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

int exchange(int (*matrix)[5],int n,int m){
    if(n>=0&&n<5&&m>=0&&m<5){
        int tmp[5];
        memcpy(tmp,*(matrix+n),sizeof(tmp));
        memcpy(*(matrix+n),*(matrix+m),sizeof(tmp));
        memcpy(*(matrix+m),tmp,sizeof(tmp));
        return 1;
    }
    return 0;
}

int main(){
    int matrix[5][5],n,m;
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) scanf("%d",&matrix[i][j]);
    scanf("%d%d",&n,&m);
    if(exchange(matrix,n,m)) for(int i=0;i<5;i++){
        for(int j=0;j<5;j++) printf("%4d",matrix[i][j]);
        printf("\n");
    }
    else printf("error\n");
    return 0;
}
