#include<stdio.h>

int bitcount(unsigned x);

int main(){
	unsigned x;
	
	scanf("%u",&x);
	
	printf("%d",bitcount(x));
	
	return 0;
}

int bitcount(unsigned x){
	int i;
	for(i = 0 ; x != 0 ; i++){
		x&=(x-1);
	}
	return i;
}
