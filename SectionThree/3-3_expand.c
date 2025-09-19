#include<stdio.h>

#define MAXLINE 1000

void expand(char s1[] , char s2[]);

int main(){
	char s1[MAXLINE] , s2[MAXLINE];
	
	scanf("%s",s1);
	
	expand(s1,s2);
	
	printf("%s",s2);
}

void expand(char s1[] , char s2[]){
	int i , j , c;
	int n , m , s;
	
	i = 0;
	j = 0;
	
	if(s1[i] == '-'){
		i++;
		s2[j++] = '-';
	}
		
		
	for( ; (c = s1[i]) != EOF ; i++){
		switch(c){
			case '-' :
				if(s1[i-1] >= 'a' && s1[i+1] <= 'z' && s1[i+1] > 'a' && s1[i-1] < s1[i+1]){
					n = s1[i-1];
					m = s1[i+1];
					for( s = n + 1 ; s < m ; s++ ){
						s2[j++] = s;
					}
				}else if(s1[i-1] >= '0' && s1[i+1] <= '9' && s1[i+1] > '0' && s1[i-1] < s1[i+1]){
					n = s1[i-1];
					m = s1[i+1];
					for( s = n ; s <= m ; s++ ){
						s2[j++] = s;
					}
				}else if(s1[i-1] >= 'A' && s1[i+1] <= 'Z' && s1[i+1] > 'A' && s1[i-1] < s1[i+1]){
					n = s1[i-1];
					m = s1[i+1];
					for( s = n ; s <= m ; s++ ){
						s2[j++] = s;
					}
				}else{
					s2[j++] = '-';
				}
				break;
			default :
				s2[j++] = s1[i];
				break;
		}
	}
}
