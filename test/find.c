#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char *line , int max);

int main(int argc , char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c , except = 0 , number = 0 , found = 0;

    while(--argc > 0 && (*++argv)[0] == '+' ) //在windows系统 cmd中'-'似乎无法被读取，或已被占用，故改为'+'
        while( c = *++argv[0] )
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n" , c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1)
        printf("Usage: ./find.exe +x +n pattern\n");
    else
        while( get_line(line , MAXLINE) > 0){
            lineno++;
            if( ( strstr(line , *argv) != NULL ) != except){
                if(number)
                    printf("%ld",lineno);
                printf("%s" , line);
                found++;
            }
        }

    return found;
    
}

int get_line(char s[], int lim){    //lim = MAXLINE 最大字符数  s[] 字符数组 ， 用来储存字符文本
    int c , i;
    i = 0;

    while(--lim > 0 && (c = getchar()) != EOF && c != '\n') //判断字符是否超过最大值 ， 是否终止输入
        s[i++] = c;     //将字符存入数组
    if(c == '\n')
        s[i++] = c;     
    s[i] = '\0';        //在数组末尾加上终止符'\0'

    return i;           //返回字符数
}

//第一版
// int main(int argc , char *argv[])
// {
//     char line[MAXLINE];
//     int found;

//     if(argc != 2)
//         printf("Usage : find pattern\n");
//     else
//         while(get_line(line , MAXLINE) > 0)
//             if( strstr(line , argv[1]) != NULL ){
//                 printf("%s" , line);
//                 found++;
//             }
//     return found;
// }