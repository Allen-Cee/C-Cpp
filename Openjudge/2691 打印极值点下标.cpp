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
        int *p=new int [k];
        scanf("%d%d",&p[0],&p[1]);
        if(p[0]!=p[1]) printf("0 ");
        for(int i=2;i<k;i++){
            scanf("%d",&p[i]);
            if((p[i]>p[i-1]&&p[i-1]<p[i-2])||(p[i]<p[i-1]&&p[i-1]>p[i-2])) printf("%d ",i-1);
        }
        if(p[k-1]!=p[k-2]) printf("%d\n",k-1);
        else printf("\n");
        delete [] p;
    }
    return 0;
}
