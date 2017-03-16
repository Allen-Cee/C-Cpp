#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    char s1[100],s2[100];
    int num[100],num1[100],num2[100],len1,len2,intlen1=0,intlen2=0,decilen1=0,decilen2=0,dot=0,gap=0;
    cin>>s1>>s2;
    for(len1=0;s1[len1]!='\0';len1++){
        if(s1[len1]=='.') intlen1=len1;
    }
    if(intlen1!=0){
        decilen1=len1-intlen1-1;
    }
    for(len2=0;s2[len2]!='\0';len2++){
        if(s2[len2]=='.') intlen2=len2;
    }
    if(intlen2!=0){
        decilen2=len2-intlen2-1;
    }
    if(decilen1>=decilen2){
        dot=decilen1;
        gap=decilen1-decilen2;
        for(int i=0,j=len2-1;j>=0;i++){
            if(i<gap) num2[i]=0;
            if(s2[j]=='.'){
                i--;
                j--;
                continue;
            }
            if(i>=gap){
                num2[i]=s2[j]-'0';
                j--;
            }
        }
        len2+=gap;
        for(int i=0,j=len1-1;j>=0;j--){
            if(s1[j]=='.') continue;
            num1[i]=s1[j]-'0';
            i++;
        }
    }
    else{
        dot=decilen2;
        gap=decilen2-decilen1;
        for(int i=0,j=len1-1;j>=0;i++){
            if(i<gap) num1[i]=0;
            if(s1[j]=='.'){
                i--;
                j--;
                continue;
            }
            if(i>=gap){
                num1[i]=s1[j]-'0';
                j--;
            }
        }
        len1+=gap;
        for(int i=0,j=len2-1;j>=0;j--){
            if(s2[j]=='.') continue;
            num2[i]=s2[j]-'0';
            i++;
        }
    }
    if(decilen1) len1--;
    if(decilen2) len2--;
    for(int i=0;i<len1||i<len2;i++){
        num[i+1]=-1;
        if(i>=len1) num[i]=num2[i];
        if(i>=len2) num[i]=num1[i];
        if(i<len1&&i<len2) num[i]=num1[i]+num2[i];
    }
    int length=0;
    for(int i=0;num[i]!=-1;i++){
        if(num[i]>9){
            if(num[i+1]==-1) num[i+1]=num[i]/10;
            if(num[i+1]>-1) num[i+1]+=num[i]/10;
            num[i]%=10;
        }
        length++;
    }
    int t=0,mark=0;
    for(int i=0;i<length;i++){
        if(num[i]==0&&t==0) mark++;
        if(num[i]!=0) t=1;
    }
    for(int i=length-1;i>=mark;i--){
        cout<<num[i];
        if(i==dot&&i!=mark) cout<<".";
    }
    cout<<endl;
    //cout<<len1<<" "<<len2<<" "<<length<<" "<<dot<<" "<<mark<<endl;
    return 0;
}