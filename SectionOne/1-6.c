#include<stdio.h>
int main(){
	if(getchar() != EOF)
		printf("1");
	else
		printf("2");
		
	return 0;	
}
/*
  ������� EOF ������ 1����֤����getchar() != EOF����ֵΪ 1(true)
  ������ 2 �� ��֤����getchar() != EOF����ֵΪ 0 (false)
*/
