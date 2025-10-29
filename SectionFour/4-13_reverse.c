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
    static int sign = 0;        //��̬����sign��ֻ�ᱻ��ʼ��һ��
    static int i;
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