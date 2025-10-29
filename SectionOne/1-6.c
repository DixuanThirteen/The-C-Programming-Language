#include<stdio.h>
int main(){
	if(getchar() != EOF)
		printf("1");
	else
		printf("2");
		
	return 0;	
}
/*
  如果输入 EOF 若返回 1，则证明（getchar() != EOF）的值为 1(true)
  若返回 2 ， 则证明（getchar() != EOF）的值为 0 (false)
*/
