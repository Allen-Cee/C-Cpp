#include<iostream>
using namespace std;

int prime(int a){
    int t=0;
    for(int i=2;i*i<=a;i++){
        if(a%i==0) t=1;
    }
    if(t==0) return 1;
    else return 0;
}

int factor(int a,int pre){
    int ans=0;
    for(int i=pre;i<=a;i++){
        if(i==a) ans++;
        if(a%i==0) ans+=factor(a/i,i);
    }
    return ans;
    
}

int main() {
    int n;
    cin>>n;
    while(n-->0){
        int a;
        cin>>a;
        cout<<factor(a,2)<<endl;
    }
    return 0;
}