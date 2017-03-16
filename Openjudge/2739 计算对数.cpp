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
    char as[101],bs[101];
    scanf("%s%s",as,bs);
    int lena=(int)strlen(as),lenb=(int)strlen(bs);
    if(lena>lenb) printf("0\n");
    else{
        lenb+=lena;
        int a[lenb+1],b[lenb+1],m[lenb+1],r[lenb+1];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(a));
        memset(m,0,sizeof(a));
        memset(r,0,sizeof(a));
        for(int i=0;as[i]!='\0';i++) a[lenb-lena+i+1]=as[i]-'0';
        for(int i=0;bs[i]!='\0';i++) b[lena+i+1]=bs[i]-'0';
        int x=0;
        for(;;x++){
            bool com=false;
            for(int i=0;i<lenb+1;i++){
                m[i]=a[i];
                r[i]=a[i];
            }
            int t[lenb+1];
            if(x==0){
                memset(r,0,sizeof(r));
                r[lenb]=1;
            }
            else if(x>1){
                for(int l=2;l<=x;l++){
                    memset(t,0,sizeof(t));
                    for(int i=lenb;i>=0;i--){
                        for(int j=lenb;j>=0;j--){
                            t[i+j-lenb]+=m[i]*r[j];
                        }
                    }
                    for(int i=lenb;i>0;i--) if(t[i]>9){
                        t[i-1]+=t[i]/10;
                        t[i]%=10;
                    }
                    for(int i=0;i<lenb+1;i++) r[i]=t[i];
                }
            }
            int num=lenb+1;
            for(int i=0;i<lenb+1;i++){
                if(r[i]==0) num--;
                else break;
            }
            for(int i=0;i<lenb+1;i++){
                if(r[i]==b[i]) continue;
                else if(r[i]<b[i]) break;
                else if(r[i]>b[i]){
                    com=true;
                    break;
                }
            }
            if(com){
                x--;
                break;
            }
        }
        printf("%d\n",x);
    }
    return 0;
}