#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    int month_start[n];
    int day_start[n];
    long num[n];
    int month_end[n];
    int day_end[n];
    int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int days;
    for(int i=0;i<n;i++){
        cin>>month_start[i]>>day_start[i];
        cin>>num[i];
        cin>>month_end[i]>>day_end[i];
    }
    for(int i=0;i<n;i++){
        days=0;
        for(int m=month_start[i];m<=month_end[i];m++){
            if(month_start[i]==month_end[i]){
                days=day_end[i]-day_start[i];
                break;
            }
            else if(m==month_start[i]) days+=month[m]-day_start[i];
            else if(m>month_start[i]&&m<month_end[i]) days+=month[m];
            else if(m==month_end[i]) days+=day_end[i];
        }
        cout<<long(num[i]*pow(2,days))<<endl;
    }
    return 0;
}