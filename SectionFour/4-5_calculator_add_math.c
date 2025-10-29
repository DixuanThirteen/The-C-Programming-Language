#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP 100   /* max size of operand or operator �����������������󳤶� */
#define MAXVAL 100  /* maximum depth of val stack ջ�������� */
#define BUFSIZE 100 /* size of buffer for ungetch �������Ĵ�С */
#define NUMBER '0'  /* signal that a number was found ��־���ҵ���һ������ */
#define FUNC 'F'    /* signal that a function was found ��־���ҵ���һ������ */
#define ERREO 'E'   /* error */

int getop(char []); /* get next operator or numeric operand ��ȡջ��Ԫ�� */
void push(double); /* push f onto value stack ��ջ��ѹ��Ԫ�� */
double pop(void); /* pop and return top value from stack ����ջ��Ԫ�� */
int getch(void); /* get a (possibly pushed-back) character ��ȡ�����ַ� */
void ungetch(int); /* push a character back on input �������ַ����뻺���� */
void func(char []); /* perform math function ִ����ѧ���� */

int sp = 0;         /* next free stack position ջָ�� */
double val[MAXVAL]; /* value stack ջ */
char buf[BUFSIZE]; /* buffer for ungetch �洢�����ַ��Ļ����� */
int bufp = 0;      /* next free position in buf ������ָ�� */
int cmd = 0; // command flag �����־

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
            case FUNC: /* new case for math function or command ������ѧ������������֧ */
                func(s);
                break;
            case ERREO:
                printf("error: unknown command1 %s\n", s);
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
            case '%':
                pop2 = pop();
                if(pop2 != 0.0)
                    push((int)pop() % (int)pop2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                if(cmd == 0) /* if command flag is not set ��������־δ���� */
                    printf("\t%.8g\n", pop());
                else
                    cmd = 0; // reset command flag ���������־
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}

// getop: get next character or numeric operand
int getop(char s[]){
    int c , i;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    i = 0;

    if(isalpha(c)){
        while ( isalpha(c = getch()))
            s[++i] = c;
        s[++i] = '\0';
        if(c != EOF)
            ungetch(c);
        if(i > 1){ /* is a math function or command ��һ����ѧ������������ */
            return FUNC;
        }else{
            return ERREO;
        }
    }

    if (!isdigit(c) && c != '.'){
        if( c == '-' || c == '+'){ /* check positive or negative signed ����Ƿ����������� */
            int next = getch();
            if(!isdigit(next) && next != '.'){
                ungetch(next);
                return c; /* is a operator ��ζ����һ������� */
            }else{
                c = next;
                s[++i] = c; /* collect the sign �ռ����� */
            }
        }else{
            return c; /* is a operator ��ζ����һ������� */
        }
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



    
void func(char s[]){
    double pop2;

    if(strcmp(s, "sin") == 0){
        cmd = 1; // set command flag ���������־
        push(sin(pop()));
    }else if(strcmp(s,"exp") == 0){
        cmd = 1;
        push(exp(pop()));
    }else if(strcmp(s,"pow") == 0){
        cmd = 1;
        pop2 = pop();
        push(pow(pop(), pop2));
    }else if(strcmp(s,"top") == 0){
        cmd = 1;
        if(sp > 0){
            printf("top element is\t%.8g\n", val[sp-1]);
        }else{
            printf("error: stack empty\n");
        }
    }else if(strcmp(s,"dup") == 0){
        cmd = 1;
        if(sp > 0){
				    pop2 = pop();
				    push(pop2);
				    push(pop2); 
                    int temp = sp;
                    while(sp != 0)
                        printf("\t%.8g\n", val[--sp]);
                    sp = temp; // restore stack pointer �ָ�ջָ��
                }else{
                    printf("error: stack empty\n");
                }
    }else if(strcmp(s,"swap") == 0){
        cmd = 1;
        if(sp > 1){
            double pop1 = pop();
            pop2 = pop();
            push(pop1);
            push(pop2);
            int temp = sp;
            while(sp != 0){
                printf("\t%.8g\n", val[--sp]);
                sp = temp; // restore stack pointer �ָ�ջָ��
            }
        }else{
                printf("error: stack has less than two elements\n");
        }
            
    }else if(strcmp(s,"clear") == 0){
        cmd = 1;
        sp = 0;
        printf("stack cleared\n");
    }else{
        cmd = 1;
        printf("error: unknown command %s\n", s);
    }
}


// push and pop functions for value stack
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

//getch and ungetch with a buffer
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();  /* get a (possibly pushed-back) character �����������Ϊ�գ���ӻ�������ȡ��һ���ַ�������ӱ�׼�����ж�ȡһ���ַ� */
}

void ungetch(int c){
    if(bufp >= BUFSIZE) /* if buffer is full , print error message , else push character back �����������������ӡ������Ϣ��������뻺���� */
        printf("ungetch: too many characters\n"); 
    else
        buf[bufp++] = c;
}