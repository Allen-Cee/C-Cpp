#include "iostream"
#include "stdio.h"
#include "memory.h"
#include "string.h"
using namespace std;

char s1[201],s2[201];

inline int min2(int a,int b){
	if(a<=b) return a;
	else return b;
}

inline int max2(int a,int b){
	if(a>=b) return a;
	else return b;
}

int check_string(int a,int b,int num[201][201]){
	if(s1[a]!='\0'&&s2[b]!='\0'){
		if(num[a][b]>=0) return num[a][b];
		else{
			if(s1[a]==s2[b]){
				num[a][b]=check_string(a+1,b+1,num)+1;
				return num[a][b];
			}
			else{
				num[a][b]=max2(check_string(a+1,b,num),check_string(a,b+1,num));
				return num[a][b];
			}
		}
	}
	else return 0;
}

int main(){
	memset(s1,'\0',201);
	memset(s2,'\0',201);
	while(scanf("%s%s",s1,s2)!=EOF){
		int num[201][201];
		memset(num,-1,sizeof(num));
		int ml=check_string(0,0,num);
		printf("%d\n",ml);
		memset(s1,'\0',201);
		memset(s2,'\0',201);
	}
	return 0;
}