#include<stdio.h>
#include<math.h>
#include<ctype.h>

#define MAXLINE 1000

int htoi (char s[MAXLINE]);

int main(void){
	
	char s[MAXLINE];
	
	scanf("%s",&s);
	
	printf("%d",htoi(s));
	return 0 ;
} 

int htoi (char s[MAXLINE]){
	int len , i , sum , a;
	
	sum = 0;
	a = 0;
	
	for(len = 0 ; s[len] != '\0' ; len++){
		;
	}
	
	i = 2;
	
	while(i<len){
		if(isdigit(s[i])){
			a = s[i] - '0';
		}else if(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'){
			a = tolower(s[i]) - 'a' + 10;
		}
		sum = sum * 16 + a;
		i++;
	}
	
	return sum;
	
	
}
