//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<stdio.h>

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    while(n-->0){
        int m,b=0,c=0;
        scanf("%d",&m);
        int *p=new int[m];
        for(int i=0;i<m;i++) scanf("%d",&p[i]);
        for(int t=1;t<=60;){
            if(b<m&&c==p[b]){
                b++;
                t+=3;
                continue;
            }
            c++;
            t++;
        }
        printf("%d\n",c);
        delete [] p;
    }
    return 0;
}
