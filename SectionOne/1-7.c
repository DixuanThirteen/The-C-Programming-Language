#include<stdio.h>
int main(){
	char a;
	a = a;
	if( (a = getchar() )!= EOF)
		printf("1");
	else
		printf("%c",&a);
		
	return 0;	
}
