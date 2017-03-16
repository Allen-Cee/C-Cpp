#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n>0){
        string s,e;
        char sx,ex;
        int sy,ey;
        cin>>s>>e;
        sx=s[0];
        ex=e[0];
        sy=s[1]-'0';
        ey=e[1]-'0';
        if(sx==ex&&sy==ey) cout<<0<<" "<<0<<" "<<0<<" "<<0<<endl;
        else{
            if(abs(sx-ex)>abs(sy-ey)) cout<<abs(sx-ex)<<" ";
            else cout<<abs(sy-ey)<<" ";
            if(abs(sx-ex)==abs(sy-ey)||sx==ex||sy==ey) cout<<1<<" ";
            else cout<<2<<" ";
            if(sx==ex||sy==ey) cout<<1<<" ";
            else cout<<2<<" ";
            if((abs(sx-ex)+abs(sy-ey))%2==1) cout<<"Inf"<<endl;
            else{
                if(abs(sx-ex)==abs(sy-ey)) cout<<1<<endl;
                else cout<<2<<endl;
            }
        }
        --n;
    }
    return 0;
}