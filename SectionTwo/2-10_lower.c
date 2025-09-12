#include<stdio.h>

char lower(char x);

int main(){
	char x;
	
	scanf("%c",&x);
	
	printf("%c",lower(x));
	
	return 0;
}

char lower(char x){
	char c;
	
	c = (x <= 90 && x >= 65) ?  x + ('a' - 'A') :  x;
	
	return c;
}
