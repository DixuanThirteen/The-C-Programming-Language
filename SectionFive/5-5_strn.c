#include <stdio.h>
#define MAXLINE 100

void my_strncpy(char *s , char *t , int n);
void my_strncat(char *s , char *t , int n);
int strncmp(char *s , char *t , int n);

int main(){
    char s[MAXLINE] , t[MAXLINE];
    int i = 0;
    int n;

    while( (s[i++] = getchar()) != '\n' )
        ;
    s[--i] = '\0';
    
    i = 0;   
        
    while( (t[i++] = getchar()) != '\n' )
        ;
    t[--i] = '\0';

    scanf("%d",&n);
    char x[MAXLINE];

    printf("strncmp:%d\n" , strncmp(s , t , n));

    my_strncat(s , t , n);

    printf("strncat:%s\n", s);

    my_strncpy(x , t , n);

    printf("strncpy:%s\n", x);

    return 0;
}

void my_strncpy(char *s , char *t , int n){
    int i;
    for(i = 0 ; i < n && *t != '\0'; i++)
        *s++ = *t++;
    for( ; i < n ; i++)
        *s++ = '\0';
}

void my_strncat(char *s , char *t , int n){
    while(*s++ != '\0')
        ;
    s--;
    int i;
    for(i = 0 ; *t != '\0' && i < n ; i++)
        *s++ = *t++;
    if(i == n)
        *s = '\0';
    for( ; i < n ; i++)
        *s++ = '\0';
}

int strncmp(char *s , char *t , int n){

    while(n-- > 0){
        if(*s != *t)
            return *s - *t;
        if(*s == '\0')
            return 0;
        s++;
        t++;
    }
    return 0;

}