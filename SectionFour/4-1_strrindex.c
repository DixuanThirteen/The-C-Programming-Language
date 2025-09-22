#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int strrindex(char s[] , char t[]);

int main(){
    char line[MAXLINE];
    char pattern[MAXLINE];
    int c , i;

    for(i = 0 ; (c = getchar()) != EOF && c != '\n' ; i++){
        pattern[i] = c;
    }

    pattern[i] = '\0';

    for(i = 0 ; (c = getchar()) != EOF && c != '\n' ; i++){
        line[i] = c;
    }

    line[i] = '\0';

    printf("%d\n", strrindex(line, pattern));
    
    return 0;
}

int strrindex(char s[] , char t[]){
    int i , j , k ;

    for(i = strlen(s) - 1 ; i >= 0 ; i--){

        for(j = strlen(t) - 1 , k = i ; j >= 0 && k >= 0 && s[k] == t[j] ; j-- , k--);
        if(j < 0)
            return k + 1;
    
    }

    return -1;

}