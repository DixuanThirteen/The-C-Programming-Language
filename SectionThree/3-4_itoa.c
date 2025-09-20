#include<stdio.h>
#include<string.h>

#define MAXLINE 1000

void itoa(int n , char s[]);
void reverse(char s[]);

int main(){
	int n;
	char s[MAXLINE];
	
	scanf("%d",&n);
	
	itoa(n,s);
	
	printf("%s",s);

	return 0;
}

void itoa(int n , char s[]){
	int i , sign;
	unsigned int un;
	
	if((sign = n) < 0){
		un = -((unsigned int)n);
	}else{
		un = n;
	}
		
	
	i = 0;
	
	do{
		s[i++] = un % 10 + '0';
	}while((un /= 10) > 0);
	
	if(sign < 0){
		s[i++] = '-';
	}
	s[i] = '\0';
	
	reverse(s);
}

void reverse(char s[]){
	int c , i , j;
	
	for(i = 0 , j = strlen(s) - 1 ; i < j ; i++ , j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
