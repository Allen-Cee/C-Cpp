//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<memory>
using namespace std;

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int targ;
    char num[10];
    while(scanf("%d%s",&targ,num)){
        if(targ==0&&atoi(num)==0) break;
        int len=(int)strlen(num),method=pow(2,len-1)-1,count=0,result=0,max=0;
        //当前数字总位数len method共有len-1位 右移len-2为最高位
        for(int i=0;i<=method;i++){
            //i从右往左第j位为1代表num[j]后切割
            int sum=0,p=0;//p为当前开始切割数位-1
            for(int j=0;j<len;j++){//j最大为len 超过最大切割方法次数 因为最后一段一定要计入
                if(!((i>>j)&1)&&j<len-1) continue;
                char tmp[10];
                memset(tmp,'\0',sizeof(tmp));
                memcpy(tmp,num+p,j-p+1);
                p=j+1;
                sum+=atoi(tmp);
            }
            if(sum<=targ&&max<sum){
                max=sum;
                count=1;
                result=i;
            }
            else if(max==sum) count++;
        }
        if(count==0) printf("error\n");
        else if(count>1) printf("rejected\n");
        else{
            printf("%d ",max);
            int p=0;
            for(int j=0;j<len;j++){
                if(!((result>>j)&1)&&j<len-1) continue;
                char tmp[10];
                memset(tmp,'\0',sizeof(tmp));
                memcpy(tmp,num+p,j-p+1);
                p=j+1;
                printf("%s ",tmp);
            }
            printf("\n");
        }
    }
    return 0;
}
