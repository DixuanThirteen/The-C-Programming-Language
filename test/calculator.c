#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 100   /* max size of operand or operator 操作数和运算符的最大长度 */
#define NUMBER '0'  /* signal that a number was found 标志着找到了一个数字 */
#define MAXVAL 100  /* maximum depth of val stack 栈的最大深度 */
#define BUFSIZE 100 /* size of buffer for ungetch 缓冲区的大小 */

int getop(char []); /* get next operator or numeric operand 获取栈顶元素 */
void push(double); /* push f onto value stack 往栈中压入元素 */
double pop(void); /* pop and return top value from stack 弹出栈顶元素 */
int getch(void); /* get a (possibly pushed-back) character 获取输入字符 */
void ungetch(int); /* push a character back on input 将多余字符存入缓冲区 */

int sp = 0;         /* next free stack position 栈指针 */
double val[MAXVAL]; /* value stack 栈 */
char buf[BUFSIZE]; /* buffer for ungetch 存储多余字符的缓冲区 */
int bufp = 0;      /* next free position in buf 缓冲区指针 */

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

void push(double number){
    if(sp < MAXVAL){ /* if stack is not full , push number onto stack , else print error message 如果栈未满，则将数字压入栈中，否则打印错误信息 */
        val[sp++] = number;
    }else{
        printf("error: stack full, can't push %g\n", number);
    }
}

double pop(void){
    if(sp > 0){ /*if stack is not empty , pop the top value from the stack , else print error message 如果栈不为空，则弹出栈顶元素，否则打印错误信息 */
        return val[--sp];
    }else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();  /* get a (possibly pushed-back) character 如果缓冲区不为空，则从缓冲区中取出一个字符，否则从标准输入中读取一个字符 */
}

void ungetch(int c){
    if(bufp >= BUFSIZE) /* if buffer is full , print error message , else push character back 如果缓冲区已满，打印错误信息，否则存入缓冲区 */
        printf("ungetch: too many characters\n"); 
    else
        buf[bufp++] = c;
}