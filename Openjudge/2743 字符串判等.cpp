#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    char s1[1000],s2[1000];
    gets(s1);
    gets(s2);
    int i,j;
    for(i=0;s1[i]!='\0';i++){
        if(s1[i]>='a'&&s1[i]<='z') s1[i]=(char)(s1[i]-32);
        else if(s1[i]==' '){
            for(int t=i;s1[t]!='\0';t++){
                s1[t]=s1[t+1];
            }
            i--;
        }
    }
    for(j=0;s2[j]!='\0';j++){
        if(s2[j]>='a'&&s2[j]<='z') s2[j]=(char)(s2[j]-32);
        else if(s2[j]==' '){
            for(int t=j;s2[t]!='\0';t++){
                s2[t]=s2[t+1];
            }
            j--;
        }
    }
    if(i!=j) cout<<"NO";
    else{
        int test=1;
        for(i=0;s1[i]!='\0';i++){
            if(s1[i]!=s2[i]){
                cout<<"NO";
                test=0;
                break;
            }
        }
        if(test==1) cout<<"YES";
    }
    return 0;
}