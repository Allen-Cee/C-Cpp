//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;

int main(){
    freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int n1,n2;
    while(scanf("%d",&n1)!=EOF){
        getchar();
        char o=getchar();
        getchar();
        if(o!='!'){
            scanf("%d",&n2);
            if(o=='+') printf("%d\n",n1+n2);
            else if(o=='-') printf("%d\n",n1-n2);
            else if(o=='*') printf("%d\n",n1*n2);
            else if(o=='/'){
                if(n2==0) printf("error\n");
                else printf("%d\n",n1/n2);
            }
            else if(o=='%'){
                if(n2==0) printf("error\n");
                else printf("%d\n",n1%n2);
            }
        }
        else{
            if(n1==0) printf("1\n");
            else{
                int tmp=1;
                for(int i=2;i<=n1;i++) tmp*=i;
                printf("%d\n",tmp);
            }
        }
    }
    return 0;
}
