#include<iostream>
using namespace std;

int main() {
    int n,m;
    while(1){
        cin>>n>>m;
        if(n==0&&m==0) break;
        int monkey[n];
        for(int i=0;i<n;i++){
            monkey[i]=i+1;
        }
        int count_num=0;
        int total_num=n;
        for(int i=0;i<n;i++){
            if(total_num==1&&monkey[i]!=0){
                cout<<monkey[i]<<endl;
                break;
            }
            if(monkey[i]!=0){
                ++count_num;
                if(count_num==m){
                    count_num=0;
                    monkey[i]=0;
                    --total_num;
                }
            }
            if(i==n-1) i=-1;
        }
    }
    return 0;
}