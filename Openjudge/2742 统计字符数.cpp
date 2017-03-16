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
    string str;
    int max=0,num=0;
    char zone;
    for(int l=0;l<n;l++){
        cin>>str;
        max=0;
        for(int i=0;i<str.length();i++){
            num=0;
            for(int j=0;j<str.length();j++){
                if(str[i]==str[j]) ++num;
            }
            if(num>max||(num==max&&str[i]-'0'<zone-'0')){
                max=num;
                zone=str[i];
            }
        }
        cout<<zone<<" "<<max<<endl;
    }
    return 0;
}