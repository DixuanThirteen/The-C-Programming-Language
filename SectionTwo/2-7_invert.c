#include<stdio.h>

unsigned invert(unsigned x , int p , int n);

int main(){
	unsigned x;
	int p , n;
	
	scanf("%u",&x);
	scanf("%d\n%d",&p,&n);
	
	printf("%u",invert(x , p , n));
	
	return 0;
}

unsigned invert(unsigned x , int p , int n){
	unsigned y,z;
	
	y = (x >> (p+1-n) & ~(~0 << n)) << (p+1-n);  //将x中从第p位开始的n个位 ，储存在y的相同位置 

	z = (~y >> (p+1-n) & ~(~0 << n)) << (p+1-n);//将y中储存x的部份取反 
	
	return ~(~x | y) + z;//~(~x | y)是将x中从第p位开始的n个位的值设为0 
}
