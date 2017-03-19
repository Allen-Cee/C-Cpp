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
#include<memory.h>
using namespace std;

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    char oct[17];
    while(scanf("%s",oct)!=EOF){
        int num[45],tmp[45],lo=2,la=0;
        memset(num,0,sizeof(num));
        while(lo<strlen(oct)){
            if(oct[lo]=='0'){
                lo++;
                continue;
            }
            memset(tmp,0,sizeof(tmp));
            tmp[0]=oct[lo]-'0';
            int li=1;
            for(int l=0;l<(lo-1)*3;l++){
                for(int i=0;i<li;i++) tmp[i]*=5;
                for(int i=0;i<li;i++) if(tmp[i]>9){
                    tmp[i+1]+=tmp[i]/10;
                    tmp[i]%=10;
                }
                while(tmp[li]) li++;
            }
            for(int i=lo-2-((li-(lo-1)*3)+(lo-2)),j=li-1;j>=0;i++,j--) num[i]+=tmp[j];
            if(la<lo-2+li) la=lo-2+li;
            for(int i=la-1;i>0;i--) if(num[i]>9){
                num[i-1]+=num[i]/10;
                num[i]%=10;
            }
            lo++;
        }
        for(int i=la-1;i>0;i--) if(num[i]>9){
            num[i-1]+=num[i]/10;
            num[i]%=10;
        }
        while(num[la-1]==0) la--;
        printf("%s [8] = 0.",oct);
        for(int i=0;i<la;i++) printf("%d",num[i]);
        printf(" [10]\n");
    }
    return 0;
}
