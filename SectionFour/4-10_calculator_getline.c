#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 1000   /* max size of operand or operator 操作数和运算符的最大长度 */
#define NUMBER '0'  /* signal that a number was found 标志着找到了一个数字 */
#define MAXVAL 100  /* maximum depth of val stack 栈的最大深度 */
#define MAXLINE 1000 /* max size of input line 输入行的最大长度 */

int getop(char []); /* get next operator or numeric operand 获取栈顶元素 */
void push(double); /* push f onto value stack 往栈中压入元素 */
double pop(void); /* pop and return top value from stack 弹出栈顶元素 */
int get_line(char [], int); /* get line into s , return length 获取一行输入 */

int sp = 0;         /* next free stack position 栈指针 */
double val[MAXVAL]; /* value stack 栈 */

int main(){
    char s[MAXOP];
    double pop2;
    char num[MAXOP];
    char op[MAXOP];

    int i , j;
    int lim;

    while( (lim = getop(s)) != EOF){
        i = 0;
        j = 0;

        while(i < lim){
            while(s[i] == ' ' || s[i] == '\t')
                i++;
            if(isdigit(s[i])){
                while(isdigit(s[i])  || s[i] == '.'){
                    num[j++] = s[i++];
                }
                num[j] = '\0';
                push(atof(num));
                j = 0;
                continue;
            }else{
                op[j] = s[i++];
                switch (op[j])
                {
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
    }  
}


int getop(char s[]){
    int lim;
    lim = get_line(s , MAXLINE);
    return lim;
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

int get_line(char s[], int lim){
    int c , i;
    i = 0;

    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    if(c == EOF)
        exit(0);

    return i;
}