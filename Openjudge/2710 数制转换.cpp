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

int main(){
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    long sys1,sys2,n=0;
    char sn[20];
    scanf("%ld%s%ld",&sys1,sn,&sys2);
    //cout<<sys1<<" "<<sn<<" "<<sys2<<endl;
    for(int i=(int)strlen(sn)-1,j=0;i>=0;i--,j++){
        if(sn[i]>='a'&&sn[i]<='f') n+=(sn[i]-'a'+10)*pow(sys1,j);
        else if(sn[i]>='A'&&sn[i]<='F') n+=(sn[i]-'A'+10)*pow(sys1,j);
        else if(sn[i]>='0'&&sn[i]<='9') n+=(sn[i]-'0')*pow(sys1,j);
    }
    memset(sn,'\0',sizeof(sn));
    int i=0;
    if(n>0) while(n>0){
        long tmp=n%sys2;
        n-=tmp;
        n/=sys2;
        if(tmp>9) sn[i]=tmp-10+'A';
        else sn[i]=tmp+'0';
        i++;
    }
    else{
        sn[0]='0';
        i=1;
    }
    //printf("%ld\n",n);
    for(int j=i-1;j>=0;j--) printf("%c",sn[j]);
    printf("\n");
    return 0;
}
