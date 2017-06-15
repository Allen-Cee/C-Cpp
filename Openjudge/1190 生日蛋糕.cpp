//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//
//freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);

#include <iostream>
#include <algorithm>
#include <math.h>
#include <memory.h>
using namespace std;

int n=0,m=0;
int minS=1000000;

void setFloor(int curF,int maxR,int maxH,int curV,int accS){
    for(int curR=maxR;curR>=curF;--curR){
        for(int curH=maxH;curH>=curF;--curH){
            
            int leftV=curV-curR*curR*curH;
            int curS=accS+2*curR*curH;
            
            if(leftV<0) continue;
            if(curF>1) if(2*leftV/(curR-1)+curS>=minS) continue;
            
            if(curF==1){
                if(leftV==0&&minS>curS){
                    minS=curS;
                    break;
                }
                continue;
            }
            
            if(curF>1) setFloor(curF-1,curR-1,curH-1,leftV,curS);
        }
    }
}

int main(){
    
    scanf("%d%d",&n,&m);
    
    int mV=n;
    for(int i=1;i<m;i++) mV-=i*i;
    
    for(int curR=sqrt(mV);curR>=m;--curR){
        for(int curH=n/(curR*curR);curH>=m;--curH){
            
            int leftV=n-curR*curR*curH;
            int curS=2*curR*curH+curR*curR;
            
            if(leftV<0) continue;
            if(curR>1) if(2*leftV/(curR-1)+curS>=minS) continue;
            
            if(m==1){
                if(leftV==0&&minS>curS){
                    minS=curS;
                    break;
                }
                continue;
            }

            if(m>1) setFloor(m-1,curR-1,curH-1,leftV,curS);
        }
    }
    
    if(minS==1000000) printf("0\n");
    else printf("%d\n",minS);
    
    return 0;
}
