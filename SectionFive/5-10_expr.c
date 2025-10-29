#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXVAL 100
#define MAXNUM 1000

double val[MAXVAL];
int sp = 0;

void push(double number){
    sp < MAXVAL ? val[sp++] = number : printf("error: stack full, can't push %g\n", number);
}

double pop(void){
    if(sp > 0){
        return val[--sp];
    } else{
        printf("error: stack empty");
        return 0.0;
    } 
}

//double strtod(char* str , char **endptr),返回double类型，将str的数字部分转化为double类型返回，把数字后的字符赋值给endptr
int main(int argc , char *argv[]){
    int i;
    double num , pop2;

    for(i = 1 ; i < argc ; i++){
        const char *str = argv[i];

        char *end = NULL;

        num = strtod(str , &end);

        if(str != end && *end == '\0'){
            push(num);
            continue;
        }

        if(strlen(str) == 1){
            switch (str[0])
            {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                pop2 = pop();
                push(pop() - pop2);
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '/':
                pop2 = pop();
                if(pop2 != 0)
                        push(pop() / pop2);
                    else{
                        printf("error: zero divisor\n");
                        return 0;
                    }
                break;
            default:
                printf("error: unknown command default\n");
                break;
            }
        }else{
            printf("error: unknown command\n");
            return 0;
        }
    }

    printf("%f",pop());
    return 0;

}

/*不知道strtod时用的方法，有很多报错检测没做
//./expr.exe 2 3 4 + x
int main(int argc , char *argv[]){
    int i , c;
    double pop2;
    char num[MAXNUM];
    while(--argc > 0 ){
        if( isdigit(c = (*++argv)[0] ) ){
            i = 0;
            while( isdigit(c = *argv[0]++) || c == '.'){
                num[i++] = c;
            }
            num[i] = '\0';
            push(atof(num));
            continue;
        }else{
            switch(c){
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    pop2 = pop();
                    push(pop() - pop2);
                    break;
                case 'x':       //'*'会被当成通配符，使程序无法获取。
                    push(pop() * pop());
                    break;
                case '/':
                    pop2 = pop();
                    if(pop2 != 0)
                        push(pop() / pop2);
                    else{
                        printf("error: zero divisor\n");
                        return 0;
                    }
                        
                    break;
                default:
                    printf("error: unknown command\n");
                    break;
            }
        }
        
    }

    printf("最终结果:%f",pop());

    return 0;

}
*/