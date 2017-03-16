#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

int repo[7],p;

double rePo(){
    //cout<<p<<endl;
    p++;
    switch(repo[p]){
        case -4:
            return rePo()+rePo();
            break;
        case -3:
            return rePo()-rePo();
            break;
        case -5:
            return -(rePo()-rePo());
            break;
        case -2:
            return rePo()*rePo();
            break;
        case -1:
            return rePo()/rePo();
            break;
        case -6:
            return 1.0/(rePo()/rePo());
            break;
        default:
            return repo[p];
    }
}

int main() {
    double num[4];
    while(cin>>num[0]>>num[1]>>num[2]>>num[3]){
        if(num[0]==0&&num[1]==0&&num[2]==0&&num[3]==0) break;
        int dup[24],dn=0,ans=0;
        for(int i=0;i<4;i++){
            repo[3]=num[i];
            for(int j=0;j<4;j++){
                if(j==i) continue;
                repo[4]=num[j];
                for(int k=0;k<4;k++){
                    if(k==i||k==j) continue;
                    repo[5]=num[k];
                    for(int l=0;l<4;l++){
                        if(l==k||l==j||l==i) continue;
                        repo[6]=num[l];
                        int tmp=repo[6]+repo[5]*100+repo[4]*10000+repo[3]*1000000,test=0;
                        for(int d=0;d<dn;d++)
                            if(tmp==dup[d]) test=1;
                        if(test==1) continue;
                        else{
                            dup[dn]=tmp;
                            dn++;
                        }
                        for(int a=-6;a<0;a++){
                            repo[0]=a;
                            for(int b=-6;b<0;b++){
                                repo[1]=b;
                                for(int c=-6;c<0;c++){
                                    repo[2]=c;
                                    p=-1;
                                    double result=rePo();
                                    if(result>23.95&&result<24.05){
                                        ans++;
                                        goto Done;
                                    }
                                    int ex=repo[2];
                                    repo[2]=repo[3];
                                    repo[3]=repo[4];
                                    repo[4]=ex;
                                    p=-1;
                                    result=rePo();
                                    if(result==24){
                                        ans++;
                                        goto Done;
                                    }
                                    ex=repo[4];
                                    repo[4]=repo[3];
                                    repo[3]=repo[2];
                                    repo[2]=ex;
                                }
                            }
                        }
                    }
                }
            }
        }
    Done:
        if(ans==0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}