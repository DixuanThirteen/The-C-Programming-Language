#include <stdio.h>
#include "calc.h"

#define MAXVAL 100  /* maximum depth of val stack 栈的最大深度 */

int sp = 0;         /* next free stack position 栈指针 */
double val[MAXVAL]; /* value stack 栈 */

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