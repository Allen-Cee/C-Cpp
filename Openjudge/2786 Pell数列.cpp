#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
    int n,k;
    scanf("%d",&n);
    while(n-->0){
        scanf("%d",&k);
        int *pa=new int [k];
        pa[0]=1;
        pa[1]=2;
        int i=2,l=k+1;
        for(;i<k;i++){
            pa[i]=2*pa[i-1]+pa[i-2];
            pa[i]%=32767;
            if(pa[i]==2&&pa[i-1]==1){
                l=i-1;
                break;
            }
        }
        printf("%d\n",pa[k%l-1]);
        delete [] pa;
    }
}
