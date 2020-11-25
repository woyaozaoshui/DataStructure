#include<stdio.h>
#include<string>
#include<cstring>

void Getnext(int next[],char t[]){
	int j = 0,k = -1;
	next[0] = -1;
	int len = strlen(t);
	while(j<len){
		if(k == -1 || t[j] == t[k]){
			j++;
			k++;
			next[j] = k;
		}else{
			k = next[k];
		}
	}
}
int KMP(char s[],char t[],int next[]){
	int lens1 = strlen(s);
	int lens2 = strlen(t);
	int i = 0;
	int j = 0;
	while(i<lens1 && j<lens2){
		if( j == -1 || s[i] == t[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if(j>=lens2){
		return (i-j+1);
	}else{
		return (-1);
	}
}

int main(){
	int next[15] = {0};
	char s[100];
	char t[100];
	printf("请输入主串\n");
	gets(s);
	printf("请输入子串\n");
	gets(t);
	Getnext(next, t);
	printf("匹配的开始位置是：%d",KMP(s,t,next));
	return 0;
}


