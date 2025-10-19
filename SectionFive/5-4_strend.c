#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int strend(char *s , char *t);

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

    printf("%d" , strend(s , t));

    return 0;
}

int strend(char *s , char *t){
    int t_len = strlen(t); //读取t的长度
    int s_len = strlen(s); //读取s的长度
    int i;

    if(t_len <= s_len)       //判断s是否比t长
        i = s_len - t_len; 
    else
        return 0;

    while(i != 0){          //跳过s前面的字符，保留和t一样长度的字符
        s++;
        i--;
    }
    
    while(*t){              //用t判断是否读完了所有字符
        if(*s++ != *t++)
            return 0;
    }
    return 1;

}