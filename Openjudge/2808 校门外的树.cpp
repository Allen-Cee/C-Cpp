#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int tree[10010],l,n,left,right,num=0;
    cin>>l;
    for(int i=0;i<=l;i++){
        tree[i]=1;
    }
    cin>>n;
    while(n-->0){
        cin>>left>>right;
        for(int i=left;i<=right;i++) tree[i]=0;
    }
    for(int i=0;i<=l;i++)
        if(tree[i]==1) num++;
    cout<<num<<endl;
    return 0;
}
