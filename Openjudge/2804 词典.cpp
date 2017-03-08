#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;

char dict[100000][2][11];

void binarySearch(char sword[11],int left,int right){
    if(left<=right){
        int mid=(left+right)/2;
        //cout<<"Searching dict["<<mid<<"] "<<dict[mid][1]<<endl;
        if(strcmp(sword,dict[mid][1])<0) binarySearch(sword,left,mid-1);
        else if(strcmp(sword,dict[mid][1])>0) binarySearch(sword,mid+1,right);
        else cout<<dict[mid][0]<<endl;
    }
    else printf("eh\n");
    
}

void quickSort(int left,int right){
    if(left<right){
        //cout<<left<<" "<<right<<endl;
        char targ[11];
        strcpy(targ,dict[(left+right)/2][1]);
        int lleft=left,lright=right;
        int point=-1;
        while(left<right){
            while(strcmp(dict[left][1],targ)<=0&&left<right){
                if(strcmp(dict[left][1],targ)==0) point=left;
                left++;
            }
            while(strcmp(dict[right][1],targ)>0&&left<right) right--;
            char tmp[11];
            strcpy(tmp,dict[left][1]);
            strcpy(dict[left][1],dict[right][1]);
            strcpy(dict[right][1],tmp);
            strcpy(tmp,dict[left][0]);
            strcpy(dict[left][0],dict[right][0]);
            strcpy(dict[right][0],tmp);
        }
        //cout<<"left==right=="<<left<<endl;
        if(strcmp(dict[left][1],targ)<=0){
            char tmp[11];
            strcpy(tmp,dict[point][1]);
            strcpy(dict[point][1],dict[left][1]);
            strcpy(dict[left][1],tmp);
            strcpy(tmp,dict[point][0]);
            strcpy(dict[point][0],dict[left][0]);
            strcpy(dict[left][0],tmp);
            quickSort(lleft,left-1);
            quickSort(left+1,lright);
        }
        else if(strcmp(dict[left][1],targ)>0){
            quickSort(lleft,left-1);
            quickSort(left,lright);
        }
    }
}

int main() {
    char din;
    int num=0;
    while((din=getchar())!='\n'){
        dict[num][0][0]=din;
        int length=1;
        while((dict[num][0][length]=getchar())!=' ') length++;
        dict[num][0][length]='\0';
        scanf("%s",dict[num][1]);
        //printf("%s %s\n",dict[num][0],dict[num][1]);
        num++;
        getchar();
    }
    quickSort(0,num-1);
    //for(int i=0;i<num;i++) cout<<dict[i][0]<<" "<<dict[i][1]<<endl;
    //cout<<endl;
    char sword[11];
    while(scanf("%s",sword)!=EOF){
        //cout<<sword<<endl;
        binarySearch(sword,0,num-1);
        //for(int i=0;sword[i]!='\0';i++) sword[i]='\0';
        //getchar();
    }
    return 0;
}
