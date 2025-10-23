#include<stdio.h>
int main(){
	int a;
	
	if( (a = getchar() )!= EOF)
		return 0;
	else
		printf("%d",&a);
		
	return 0;	
}
