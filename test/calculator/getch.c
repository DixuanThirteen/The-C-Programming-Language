#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100 /* size of buffer for ungetch 缓冲区的大小 */

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