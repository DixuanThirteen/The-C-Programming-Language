#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int any(char s1[] , char s2[]);

int main(){
	char s1[MAXLINE] , s2[MAXLINE];
	
	scanf("%s",s1);
	scanf("%s",s2);
	
	int a = any(s1,s2);
	
	printf("%d",a);
	
	return 0;
} 

int any(char s1[] , char s2[]){
	int i , j , k ;
	char s[MAXLINE];
	
	for( k = 0 , j = 0 ; s2[k] != '\0' ; k++){
		for(i = 0 ; s1[i] != '\0' ; i++){
			if(s1[i] == s2[k]){
				return i+1;
			}
		}
		
	}
	return -1;

}
