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
	
	y = (x >> (p+1-n) & ~(~0 << n)) << (p+1-n);  //��x�дӵ�pλ��ʼ��n��λ ��������y����ͬλ�� 

	z = (~y >> (p+1-n) & ~(~0 << n)) << (p+1-n);//��y�д���x�Ĳ���ȡ�� 
	
	return ~(~x | y) + z;//~(~x | y)�ǽ�x�дӵ�pλ��ʼ��n��λ��ֵ��Ϊ0 
}
