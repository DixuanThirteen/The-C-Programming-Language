#include <stdio.h>
#define MAXLINE 100
void my_strcat(char *s , char *t);/*ʹ��strcat����ʾ���ͳ�ͻ����Ȼ��Ӱ������*/

int main(){
    char s[MAXLINE] , t[MAXLINE];
    int i = 0;

    while( (s[i++] = getchar()) != '\n' )
        ;
    s[--i] = '\0';
    
    i = 0;   
        
    while( (t[i++] = getchar()) != '\n' )
        ;
    t[--i] = '\0';

    my_strcat(s , t);

    printf("%s",s);

    return 0;
}

void my_strcat(char *s , char *t){
    while(*s++ != '\0')
        ;

    s--;

    for( ; (*s = *t) ; s++ , t++)
        if(*t == '\0')
            break;
}