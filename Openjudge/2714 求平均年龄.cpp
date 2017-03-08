#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
    int n;
    float addup_age=0;
    float ave_age;
    scanf("%d",&n);
    int stu_age[n];
    for(int i=0;i<n;i++){
        scanf("%d",&stu_age[i]);
        addup_age+=stu_age[i];
    }
    ave_age=addup_age/n;
    printf("%.2f",ave_age);
}