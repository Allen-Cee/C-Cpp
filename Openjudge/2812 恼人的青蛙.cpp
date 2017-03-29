//
//  main.cpp
//  Cpp_Project
//
//  Created by Aoi on 3/26/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<memory>
using namespace std;

bool field[5001][5001];
int cr[5001][5001],crn[5001];

int CMP(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    //freopen("/Users/Aoi/Documents/Code/C&Cpp/Cpp_Project/Cpp_Project/data.txt","r",stdin);
    int max_s=0,r,c,n;
    scanf("%d%d%d",&r,&c,&n);
    while(n-->0){
        int tmp_r,tmp_c;
        scanf("%d%d",&tmp_r,&tmp_c);
        tmp_r--;
        tmp_c--;
        field[tmp_r][tmp_c]=1;
        cr[tmp_c][crn[tmp_c]++]=tmp_r;
    }
    for(int i=0;i<c;i++) if(crn[i]) qsort(cr[i],crn[i],sizeof(cr[0][0]),CMP);
    for(int ic=0;ic<c;ic++){
        for(int j=0;j<crn[ic];j++){
            int ir=cr[ic][j];
            for(int tmp_j=j+1;tmp_j<crn[ic];tmp_j++){
                int nr=cr[ic][tmp_j],sr=nr-ir,nnr=ir+sr*2;
                if(nnr<0||nnr>=r||!field[nnr][ic]||!(ir-sr<0)) continue;
                int tmp_s=3;
                while(ir+sr*tmp_s>=0&&ir+sr*tmp_s<r&&field[ir+sr*tmp_s][ic]) tmp_s++;
                if(ir+sr*tmp_s>=0&&ir+sr*tmp_s<r) tmp_s=0;
                if(max_s<tmp_s) max_s=tmp_s;
            }
            for(int sc=1;sc<=c/2;sc++){
                int tmp_n=2;
                if(tmp_n<max_s) tmp_n=max_s;
                int nc=ic+sc,nmax_c=ic+sc*tmp_n,nnc=ic+sc*2;
                if(nmax_c>=c) break;
                bool find=0;
                for(int nj=0;nj<crn[nc];nj++){
                    int nr=cr[nc][nj],sr=nr-ir,nmax_r=ir+sr*tmp_n,nnr=ir+sr*2;
                    if(nmax_r<0||nmax_r>=r||!field[nnr][nnc]||!field[nmax_r][nmax_c]||(!(ic-sc<0)&&sr!=0&&!(ir-sr<0||ir-sr>=r))||(!(ic-sc<0)&&sr==0)) continue;
                    int tmp_s=3;
                    while(ic+sc*tmp_s<c&&ir+sr*tmp_s>=0&&ir+sr*tmp_s<r&&field[ir+sr*tmp_s][ic+sc*tmp_s]) tmp_s++;
                    if(ic+sc*tmp_s<c&&ir+sr*tmp_s>=0&&ir+sr*tmp_s<r) continue;
                    if(max_s<tmp_s){
                        max_s=tmp_s;
                        if(max_s==n) goto Done;
                    }
                    find=1;
                    break;
                }
                if(find) break;
            }
        }
    }
Done:
    printf("%d\n",max_s);
    return 0;
}
