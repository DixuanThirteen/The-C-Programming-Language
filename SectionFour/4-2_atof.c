#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAXLINE 1000

double atof(char s[]);
int get_line(char s[], int lim);

int main(){
    double atof(char s[]);
    char line[MAXLINE];
    int get_line(char s[] , int lim);

    while(get_line(line , MAXLINE) > 0)
        printf("%f\n", atof(line));
    return 0;
}

double atof(char s[]){
    double val , power;
    int i , sign , exp_sign , exp_val;

    val = 0.0;
    power = 1.0;
    i = 0;
    exp_val = 0;
    
    sign = (s[0] == '-') ? -1 : 1;
    if(s[0] == '+' || s[0] == '-')
        i++;


    for( ; s[i] != '\n' && s[i] != EOF; ){
        val = (s[i++] - '0') + val * 10.0;
        if (s[i] == '.'){
            i++;

            while(s[i] != '\n' && s[i] != EOF){
                val = (s[i++] - '0') + val * 10.0;
                power *= 10;

                if(s[i] == 'e' || s[i] == 'E'){
                    i++;

                    exp_sign = (s[i] == '-') ? -1 : 1;
                    if(s[i] == '+' || s[i] == '-')
                        i++;
                    
                    while(s[i] != EOF && s[i] != '\n'){
                        exp_val = (s[i++] - '0') + exp_val * 10;
                    }
                }
            }
        }
    }
    
    
    return  sign * val / power * (exp_sign == -1 ? pow(10,-1 * exp_val) : pow(10,exp_val)); 
}

int get_line(char s[], int lim){
    int c , i;
    i = 0;
    while(i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

// int main(){
//     char s[MAXLINE];
//     int c , i;
//     double atof(char s[]);

//     i = 0;

//     while((c = getchar()) != EOF && c != '\n')
//         s[i++] = c;
//     if(c == '\n')
//         s[i++] = c;
//     s[i] = '\0';
    
//     double num = atof(s);
    
//     printf("%f\n", num);
    
//     return 0;
// }