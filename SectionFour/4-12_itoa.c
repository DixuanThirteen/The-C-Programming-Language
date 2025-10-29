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
    static int sign = 0;        //��̬����sign��ֻ�ᱻ��ʼ��һ��
    if( x < 0 && sign == 0){
        sign = x;               //���x�Ǹ���������x��ֵ
        x = -x;
    }
    if(x / 10){
        n[i++] = x % 10 + '0';
        itoa(x/10,n);           //�ݹ�
    }else{
        n[i++] = x % 10 + '0';
        if(sign < 0){           //������ӷ���
            n[i++] = '-';
        }
        n[i] = '\0';
    }
    reverse(n);//��ת�ַ���n
}

int main(){
    int x;
    char n[MAXLINE];

    scanf("%d",&x);

    itoa(x,n);

    printf("%s",n);

    return 0;
}