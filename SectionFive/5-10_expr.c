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

//double strtod(char* str , char **endptr),����double���ͣ���str�����ֲ���ת��Ϊdouble���ͷ��أ������ֺ���ַ���ֵ��endptr
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

/*��֪��strtodʱ�õķ������кܶ౨����û��
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
                case 'x':       //'*'�ᱻ����ͨ�����ʹ�����޷���ȡ��
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

    printf("���ս��:%f",pop());

    return 0;

}
*/