#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100   /* max size of operand or operator 操作数和运算符的最大长度 */


extern int getop(char []); /* get next operator or numeric operand 获取栈顶元素 */
extern void push(double); /* push f onto value stack 往栈中压入元素 */
extern double pop(void); /* pop and return top value from stack 弹出栈顶元素 */
extern int getch(void); /* get a (possibly pushed-back) character 获取输入字符 */
extern void ungetch(int); /* push a character back on input 将多余字符存入缓冲区 */

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
