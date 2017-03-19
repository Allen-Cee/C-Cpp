//
//  main.cpp
//  cpp_tmp
//
//  Created by Aoi on 3/7/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include<cstdio>
#include<cstdlib>

int comp1(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}

int comp2(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main() {
    //freopen("/Users/Aoi/Desktop/data.txt","r",stdin);
    int t,s,m,n;
    scanf("%d",&t);
    while(t-->0){
        int num=0,p=0;
        scanf("%d%d",&s,&m);
        int *a=new int[m];
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        scanf("%d",&n);
        int *b=new int[n];
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        qsort(a,m,sizeof(a[0]),comp1);
        qsort(b,n,sizeof(b[0]),comp2);
        for(int i=0;i<m;i++){
            bool u=1;
            for(int j=p;j<n;j++){
                if(a[i]+b[j]>s) break;
                else if(a[i]+b[j]==s){
                    if(u){
                        u=0;
                        p=j;
                    }
                    num++;
                }
            }
        }
        printf("%d\n",num);
        delete [] a;
        delete [] b;
    }
    return 0;
}
