#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(){
    int n, b;
    char s[MAXLINE];

    scanf("%d %d", &n, &b);

    itob(n, s, b);

    printf("%s\n", s);

    return 0;
}

void itob(int n, char s[], int b){

    if(b < 2 || b > 36){
        s[0] = '\0';
        return;
    }

    int i , sign , digit;
    unsigned int num;

    if((sign = n) < 0)
        num = -n;
    else
        num = n;

    i = 0;

    do{
        digit = num % b;
        num /= b;
        if(digit < 10)
            s[i++] = digit + '0';
        else
            s[i++] = digit - 10 + 'A';
    }while (num > 0);

    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
    
}

void reverse(char s[]){
    int c , i , j;

    for ( i = 0 , j = strlen(s) - 1; i < j ;  i++ , j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    
}