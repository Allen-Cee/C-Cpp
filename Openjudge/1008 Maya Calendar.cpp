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

char hm[19][7]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"},td[20][9]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int main() {
    int n;
    cin>>n;
    printf("%d\n",n);
    while(n-->0){
        float df;
        int y;
        char m[7];
        scanf("%f%s%d",&df,m,&y);
        int d=df;
        int i;
        for(i=0;i<19;i++) if(strcmp(hm[i],m)==0) break;
        int num=y*365+i*20+d;
        printf("%d %s %d\n",num%13+1,td[num%20],num/260);
    }
    return 0;
}
