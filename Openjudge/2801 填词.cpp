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
    int n,m,p,w[26]={};
    char c;
    cin>>n>>m>>p;
    int mn=n*m;
    while(mn-->0){
        if((c=getchar())>='A'&&c<='Z') w[c-'A']++;
        else mn++;
    }
    getchar();
    while(p-->0) while((c=getchar())>='A'&&c<='Z') w[c-'A']--;
    for(int i=0;i<26;i++) while(w[i]-->0) cout<<(char)(i+'A');
    return 0;
}
