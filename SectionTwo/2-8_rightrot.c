#include<stdio.h>

unsigned rightrot(unsigned x, int n);

int main(){
	unsigned x;
	int n;
	
	scanf("%u",&x);
	scanf("%d",&n);
	
	printf("%u",rightrot(x,n));
	
	return 0;
} 

unsigned rightrot(unsigned x, int n){
	int bits = sizeof(unsigned)*8;
	
	//以下可直接写作 return (x >> n) | (x << (bits - n)); 
	unsigned y = x;
	
	x = x >> n;
	y = y << (bits-n);
	
	return x|y;
}
