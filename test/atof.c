#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

double atof(char s[]);
// int get_line(char s[], int lim);

int main(){
    char s[MAXLINE];
    int c , i;
    double atof(char s[]);

    i = 0;

    while((c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    
    double num = atof(s);
    
    printf("%f\n", num);
    
    return 0;
}

double atof(char s[]){
    double val , power;
    int i , j , sign;

    val = 0.0;
    power = 1.0;
    i = 0;
    
    sign = (s[0] == '-') ? -1 : 1;
    if(s[0] == '+' || s[0] == '-')
        i++;


    for( ; s[i] != '\n' && s[i] != EOF && s[i] != '.'; ){
        val = (s[i++] - '0') + val * 10.0;
    }
    if (s[i] == '.')
    {
        i++;

        while(s[i] != '\n' && s[i] != EOF){
            val = (s[i++] - '0') + val * 10.0;
            power *= 10;
        }
    }
    
    return  sign * val / power; 
}
// int main(){
//     double sum , atof(char s[]);
//     char line[MAXLINE];
//     int getline(char s[] , int lim);

//     sum = 0;
//     while(getline(line , MAXLINE) > 0)
//         printf("\t%g\n", sum += atof(line));
//     return 0;
// }

// int get_line(char s[], int lim){
//     int c , i;
//     i = 0;
//     while(i < lim - 1 && (c = getchar()) != EOF && c != '\n')
//         s[i++] = c;
//     if(c == '\n'){
//         s[i++] = c;
//     }
//     s[i] = '\0';
//     return i;
// }

