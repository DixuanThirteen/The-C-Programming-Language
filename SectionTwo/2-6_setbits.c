#include<stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(){
	unsigned x , y;
	int p , n;

	scanf("%u",&x);
	scanf("%d",&p);
	scanf("%d",&n);
	scanf("%u",&y);
	
	printf("%u",setbits(x,p,n,y));
	
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
	unsigned i;
	
	i = x >> (p+1-n) & ~(~0 << n);
	
	y = y >> n;
	
	y = y << n;
	
	return i | y;
}
