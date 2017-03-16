#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main() {
    int n;
    cin>>n;
    char pre[n][200];
    int num[n];
    for(int i=0;i<n;i++){
        cin>>pre[i];
        int k=6;
        num[i]=0;
        for(int j=0;pre[i][j]!='\0';j++){
            if(pre[i][j]>='A'&&pre[i][j]<='Z'){
                if(pre[i][j]>='A'&&pre[i][j]<='Q') num[i]+=((pre[i][j]-'A')/3+2)*pow(10,k);
                else if(pre[i][j]=='P'||pre[i][j]=='R'||pre[i][j]=='S') num[i]+=7*pow(10,k);
                else if(pre[i][j]>='T'&&pre[i][j]<='Y') num[i]+=((pre[i][j]-'A'-1)/3+2)*pow(10,k);
                k--;
            }
            else if(pre[i][j]>='0'&&pre[i][j]<='9'){
                num[i]+=(pre[i][j]-'0')*pow(10,k);
                k--;
            }
        }
    }
    qsort(num,n,sizeof(int),comp);
    int count_num=1,t=0;
    for(int i=0;i<n;i++){
        if(num[i+1]==num[i]&&i<n-1) count_num++;
        else if(count_num!=1){
            printf("%03d-%04d %d\n",num[i]/10000,num[i]%10000,count_num);
            count_num=1;
            t=1;
        }
    }
    if(t==0) cout<<"No duplicates.";
    return 0;
}