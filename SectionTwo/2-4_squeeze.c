#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

char* squeeze(char s1[] , char s2[]);


int main(){
	char s1[MAXLINE] , s2[MAXLINE];
	
	scanf("%s",&s1);
	scanf("%s",&s2);
	
	printf("%s",squeeze(s1,s2));
	
	return 0;
}

char* squeeze(char s1[] , char s2[]){
	int i , j , k;
	
	for(k = 0 ; s2[k] != '\0' ; k++){
		
		for (i = 0 , j = 0 ; s1[i] != '\0' ; i++){
			
			if(s1[i] != s2[k]){
				s1[j++] = s1[i];
			}			
			
		}
		s1[j] = '\0';
	}
	
	return s1;
}
