#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void reverse(char s[]){
	static int i = 0;
    int j = strlen(s) - 1;
    int c;
	
    if(i < j - i){
        c = s[i];
        s[i] = s[j - i];
        s[j - i] = c;
        i++;
        reverse(s);
    }
        
}

void itoa(int x , char n[]){
    static int sign = 0;        //静态变量sign，只会被初始化一次
    static int i;
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