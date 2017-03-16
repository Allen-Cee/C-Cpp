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
    char s[200];
    scanf("%s",s);
    int mark=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(i==0||s[i-1]<'0'||s[i-1]>'9'){
                if(s[i+1]<'0'||s[i+1]>'9'){
                    printf("%d\n",s[i]-'0');//个位数
                    continue;
                }
                else if(s[i]!='0'){
                    mark=1;
                    printf("%d",s[i]-'0');//非零开头
                    continue;
                }
            }
            if(i>0&&s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'){
                if(s[i]!='0'){
                    mark=1;
                    printf("%d",s[i]-'0');//三位以上中间的非零数
                    continue;
                }
                else{
                    if(mark==1){
                        printf("%d",s[i]-'0');//三位以上中间的零数
                        continue;
                    }
                }
            }
            if(i>0&&s[i-1]>='0'&&s[i-1]<='9'&&(s[i+1]<'0'||s[i+1]>'9')){
                printf("%d\n",s[i]-'0');//两位以上末尾的数
                mark=0;
                continue;
            }
        }
    }
    return 0;
}