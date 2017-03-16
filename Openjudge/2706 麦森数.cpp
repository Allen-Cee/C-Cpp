//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cmath>
#include<memory.h>

int * mul(int *n,int *m){
    static int z[500];
    memset(z,0,sizeof(z));
    for(int i=0;i<500;i++)for(int j=0;j<500;j++){
        if(i+j>=500) break;
        z[i+j]+=n[j]*m[i];
    }
    for(int i=0;i<499;i++){
        z[i+1]+=z[i]/10;
        z[i]%=10;
    }
    z[499]%=10;
    return z;
}

int  main(){
    int p,m[500],n[500];
    memset(n,0,sizeof(n));
    memset(m,0,sizeof(m));
    n[0]=1;
    m[0]=2;
    scanf("%d",&p);
    printf("%d\n",int(p*log10(2)+1));
    while(p>0){
        if(p&1) memcpy(n,mul(n,m),sizeof(n));
        p>>=1;
        memcpy(m,mul(m,m),sizeof(m));
    }
    n[0]--;
    for(int i=499;i>=0;i--){
        printf("%d",n[i]);
        if(i%50==0) printf("\n");
    }
    return 0;
}
