#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100 /* size of buffer for ungetch 缓冲区的大小 */

int getch(void);
void ungetch(int);
char buf[BUFSIZE]; /* buffer for ungetch 存储多余字符的缓冲区 */
int bufp = 0;      /* next free position in buf 缓冲区指针 */

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();  /* get a (possibly pushed-back) character 如果缓冲区不为空，则从缓冲区中取出一个字符，否则从标准输入中读取一个字符 */
}

void ungetch(int c){
    if(bufp >= BUFSIZE) /* if buffer is full , print error message , else push character back 如果缓冲区已满，打印错误信息，否则存入缓冲区 */
        printf("ungetch: too many characters\n"); 
    else
        buf[bufp++] = c;
}

int getfloat(double *pn){
    int c , sign;
    double decimal , power ;
    decimal = 0;
    power = 1;

    while ( isspace( c = getch() ) )
        ;

    if(!isdigit(c) && c != EOF && c != '-' && c != '+'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '-' || c == '+'){
        int signchar = c;
        c = getch();
        if(!isdigit(c)){
            if(c != EOF){
                ungetch(c);
            }
            ungetch(signchar);
            return 0;
        }
    }
    for(*pn = 0 ; isdigit(c) ; c = getch() )
        *pn = *pn * 10.0 + (c - '0');
    if(c == '.'){
        c = getch();
        while(isdigit(c)){
            decimal = decimal * 10.0 + (c - '0') ;
            power *= 10;
            c = getch();
        }
    }

    *pn = (*pn + decimal / power) * sign;


    if(c != EOF){
        ungetch(c);
    }

    return c;
    
}

int main(){
    double x;
    switch(getfloat(&x)){
        case 0 :
            printf("ERROR");
            break;
        default :
            printf("%f",x);
            break;
    }

    return 0;
}