#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char *line , int max);

int main(int argc , char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c , except = 0 , number = 0 , found = 0;

    while(--argc > 0 && (*++argv)[0] == '+' ) //��windowsϵͳ cmd��'-'�ƺ��޷�����ȡ�����ѱ�ռ�ã��ʸ�Ϊ'+'
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

int get_line(char s[], int lim){    //lim = MAXLINE ����ַ���  s[] �ַ����� �� ���������ַ��ı�
    int c , i;
    i = 0;

    while(--lim > 0 && (c = getchar()) != EOF && c != '\n') //�ж��ַ��Ƿ񳬹����ֵ �� �Ƿ���ֹ����
        s[i++] = c;     //���ַ���������
    if(c == '\n')
        s[i++] = c;     
    s[i] = '\0';        //������ĩβ������ֹ��'\0'

    return i;           //�����ַ���
}

//��һ��
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