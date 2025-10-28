#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXVAL 100

double val[MAXVAL];
int sp = 0;

void push(double);
double pop(void);
//./expr.exe 2 3 4 + *
int main(int argc , char *argv[]){
    double n = 0;
    int i , c;
    for( i = 1 ; i <= argc ; i++ ){
        if( c = isdigit(argv[i]) ){
            push(c);
        }else{
            switch(c){
                case '+':
                    n = pop() + pop();
                    push(n);
                    break;
                case '-':
                    n = pop() - pop();
                    push(n);
                    break;
                case '*':
                    n = pop() * pop();
                    push(n);
                    break;
                case '/':
                    n = pop() / pop();
                    push(n);
                    break;
                default:
                    break;
            }
        }
    }

    n = pop();
    printf("最终结果:%f",n);
    
    return 0;

}

void push(double number){
    sp < val ? val[sp++] = number : printf("error: stack full, can't push %g\n", number);
}

double pop(void){
    if(sp > 0){
        return val[--sp];
    } else{
        return 0.0;
    } 
}
