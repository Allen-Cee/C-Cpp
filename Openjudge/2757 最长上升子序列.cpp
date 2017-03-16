#include<iostream>
using namespace std;

int list[1000];
int ex[1000];

int length(int a,int n){
    if(ex[a]!=-1) return ex[a];
    if(a==n-1){
        ex[a]=1;
        return 1;
    }
    int max=0;
    for(int i=a+1;i<n;i++){
        if(list[a]<list[i]){
            if(ex[i]!=-1){
                if(max<ex[i]) max=ex[i];
            }
            else{
                if(max<length(i,n)) max=length(i,n);
            }
        }
    }
    return ex[a]=max+1;
}

int main() {
    int n,len,max=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
        ex[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(ex[i]!=-1) len=ex[i];
        else len=length(i,n);
        if(max<len) max=len;
    }
    cout<<max<<endl;
    return 0;
}