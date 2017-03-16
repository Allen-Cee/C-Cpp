#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
#include<unistd.h>
using namespace std;

int main() {
    char s1[102],s2[102];
    bool zero=false;
    scanf("%s%s",s2,s1);
    int lens1=(int)strlen(s1),lens2=(int)strlen(s2);
    int n1[lens1],n2[lens2],n1m[lens1+1];
    for(int i=0;i<lens1;i++){
        n1[i]=s1[i]-'0';
        n1m[i]=n1[i];
    }
    for(int i=0;i<lens2;i++) n2[i]=s2[i]-'0';
    if(lens1<=lens2) for(int i=lens1-1;i<lens2;i++){
        int comp=0;
        for(int m=0,n=i-lens1+1;m<lens1;m++,n++){
            if(n1[m]==n2[n]) continue;
            else if(n1[m]<n2[n]){
                comp=-1;
                break;
            }
            else if(n1[m]>n2[n]){
                comp=1;
                break;
            }
        }
        if(comp==1){
            if(lens1==lens2){
                printf("0");
                break;
            }
            if(zero) printf("0");
            n2[i-lens1+2]+=n2[i-lens1+1]*10;
            n2[i-lens1+1]=0;
        }
        else if(comp==0){
            printf("1");
            zero=true;
            for(int m=i-lens1+1;m<=i;m++) n2[m]=0;
        }
        else if(comp==-1){
            bool mcomp=true;//大于判断
            int m;//乘数
            for(m=2;mcomp;m++){//选择乘数 执行乘法和比较
                for(int n=lens1-1;n>=0;n--) n1m[n]=n1[n]*m;//赋值
                for(int n=lens1-1;n>0;n--) if(n1m[n]>9){//整理乘数n1m结果
                        n1m[n-1]+=n1m[n]/10;
                        n1m[n]%=10;
                }
                for(int n=0;n<lens1;n++){//比较
                    if(n1m[n]==n2[i-lens1+1+n]) continue;
                    else if(n1m[n]>n2[i-lens1+1+n]){
                        mcomp=false;
                        break;
                    }
                    else if(n1m[n]<n2[i-lens1+1+n]) break;
                }
            }
            m-=2;
            printf("%d",m);
            zero=true;
            for(int n=0;n<lens1;n++) n1m[n]=n1[n]*m;
            for(int n=lens1-1;n>0;n--) if(n1m[n]>9){
                n1m[n-1]+=n1m[n]/10;
                n1m[n]%=10;
            }
            for(int n=0;n<lens1;n++) n2[i-lens1+1+n]-=n1m[n];
            for(int n=lens1-1;n>0;n--) if(n2[i-lens1+1+n]<0){
                n2[i-lens1+1+n]+=10;
                n2[i-lens1+n]--;
            }
            n2[i-lens1+2]+=n2[i-lens1+1]*10;
            n2[i-lens1+1]=0;
        }
    }
    else printf("0");
    printf("\n");
    return 0;
}
