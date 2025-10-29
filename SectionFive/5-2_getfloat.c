#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100 /* size of buffer for ungetch �������Ĵ�С */

int getch(void);
void ungetch(int);
char buf[BUFSIZE]; /* buffer for ungetch �洢�����ַ��Ļ����� */
int bufp = 0;      /* next free position in buf ������ָ�� */

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();  /* get a (possibly pushed-back) character �����������Ϊ�գ���ӻ�������ȡ��һ���ַ�������ӱ�׼�����ж�ȡһ���ַ� */
}

void ungetch(int c){
    if(bufp >= BUFSIZE) /* if buffer is full , print error message , else push character back �����������������ӡ������Ϣ��������뻺���� */
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