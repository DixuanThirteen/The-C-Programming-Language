#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int i;

void reverse(char s[]){
	int c , i , j;
	
	for(i = 0 , j = strlen(s) - 1 ; i < j ; i++ , j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int x , char n[]){
    static int sign = 0;        //静态变量sign，只会被初始化一次
    if( x < 0 && sign == 0){
        sign = x;               //如果x是负数，保存x的值
        x = -x;
    }
    if(x / 10){
        n[i++] = x % 10 + '0';
        itoa(x/10,n);           //递归
    }else{
        n[i++] = x % 10 + '0';
        if(sign < 0){           //符号添加符号
            n[i++] = '-';
        }
        n[i] = '\0';
    }
    reverse(n);//反转字符串n
}

int main(){
    int x;
    char n[MAXLINE];

    scanf("%d",&x);

    itoa(x,n);

    printf("%s",n);

    return 0;
}