#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int a_length=a.length(),b_length=b.length();
    int subtracted[a_length],subtract[b_length];
    for(int i=0;i<a_length;i++){
        subtracted[i]=a[i]-'0';
    }
    for(int i=0;i<b_length;i++){
        subtract[i]=b[i]-'0';
    }
    int j=b_length-1;
    int tmp=a_length-b_length;
    for(int i=a_length-1;i>=tmp;i--){
        if(subtracted[i]>=subtract[j]) subtracted[i]-=subtract[j];
        else if(subtracted[i]<subtract[j]){
            subtracted[i]+=10-subtract[j];
            subtracted[i-1]-=1;
        }
        --j;
    }
    while(subtracted[tmp-1]<0){
        subtracted[tmp-1]+=10;
        subtracted[tmp-2]-=1;
        --tmp;
    }
    for(int i=0;i<a_length;i++){
        cout<<subtracted[i];
    }
    return 0;
}