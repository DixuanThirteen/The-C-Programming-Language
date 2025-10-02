#include <stdio.h>
#include <ctype.h>
#include "calc.h"

extern int getch(void); /* get a (possibly pushed-back) character 获取输入字符 */
extern void ungetch(int); /* push a character back on input 将多余字符存入缓冲区 */


int getop(char s[]){
    int c , i;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    i = 0;
    
    if (!isdigit(c) && c != '.'){
        return c; /* is a operator 意味着是一个运算符 */
    }
    if(isdigit(c)){
        while( isdigit( s[++i] = c = getch() ) ) /* collect integer part 收集整数部分，并且在最后会超前读入一个字符*/
            ;
    }
    if(c == '.'){
        while( isdigit( s[++i] = c = getch() ) )/* collect fraction part 收集小数部分，也会超前读入一个字符*/
            ;
    }

    s[i] = '\0';

    if(c != EOF)
        ungetch(c);

    return NUMBER;
}