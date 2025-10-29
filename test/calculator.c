#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 100   /* max size of operand or operator �����������������󳤶� */
#define NUMBER '0'  /* signal that a number was found ��־���ҵ���һ������ */
#define MAXVAL 100  /* maximum depth of val stack ջ�������� */
#define BUFSIZE 100 /* size of buffer for ungetch �������Ĵ�С */

int getop(char []); /* get next operator or numeric operand ��ȡջ��Ԫ�� */
void push(double); /* push f onto value stack ��ջ��ѹ��Ԫ�� */
double pop(void); /* pop and return top value from stack ����ջ��Ԫ�� */
int getch(void); /* get a (possibly pushed-back) character ��ȡ�����ַ� */
void ungetch(int); /* push a character back on input �������ַ����뻺���� */

int sp = 0;         /* next free stack position ջָ�� */
double val[MAXVAL]; /* value stack ջ */
char buf[BUFSIZE]; /* buffer for ungetch �洢�����ַ��Ļ����� */
int bufp = 0;      /* next free position in buf ������ָ�� */

int main(){
    int type;
    char s[MAXOP];
    double pop2;

    while((type = getop(s)) != EOF){
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                pop2 = pop();
                push(pop() - pop2);
                break;
            case '/':
                pop2 = pop();
                if(pop2 != 0.0)
                    push(pop() / pop2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}


int getop(char s[]){
    int c , i;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    i = 0;
    
    if (!isdigit(c) && c != '.'){
        return c; /* is a operator ��ζ����һ������� */
    }
    if(isdigit(c)){
        while( isdigit( s[++i] = c = getch() ) ) /* collect integer part �ռ��������֣����������ᳬǰ����һ���ַ�*/
            ;
    }
    if(c == '.'){
        while( isdigit( s[++i] = c = getch() ) )/* collect fraction part �ռ�С�����֣�Ҳ�ᳬǰ����һ���ַ�*/
            ;
    }

    s[i] = '\0';

    if(c != EOF)
        ungetch(c);

    return NUMBER;
}

void push(double number){
    if(sp < MAXVAL){ /* if stack is not full , push number onto stack , else print error message ���ջδ����������ѹ��ջ�У������ӡ������Ϣ */
        val[sp++] = number;
    }else{
        printf("error: stack full, can't push %g\n", number);
    }
}

double pop(void){
    if(sp > 0){ /*if stack is not empty , pop the top value from the stack , else print error message ���ջ��Ϊ�գ��򵯳�ջ��Ԫ�أ������ӡ������Ϣ */
        return val[--sp];
    }else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();  /* get a (possibly pushed-back) character �����������Ϊ�գ���ӻ�������ȡ��һ���ַ�������ӱ�׼�����ж�ȡһ���ַ� */
}

void ungetch(int c){
    if(bufp >= BUFSIZE) /* if buffer is full , print error message , else push character back �����������������ӡ������Ϣ��������뻺���� */
        printf("ungetch: too many characters\n"); 
    else
        buf[bufp++] = c;
}