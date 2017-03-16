#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<math.h>
using namespace std;

int main() {
    char s[35],subed,sub;
    cin>>s>>subed>>sub;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==subed) cout<<sub;
        else cout<<s[i];
    }
    return 0;
}