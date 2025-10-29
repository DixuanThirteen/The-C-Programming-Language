#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int strend(char *s , char *t);

int main(){
    char s[MAXLINE] , t[MAXLINE];
    int i = 0;

    while( (s[i++] = getchar()) != '\n' )
        ;
    s[--i] = '\0';
    
    i = 0;   
        
    while( (t[i++] = getchar()) != '\n' )
        ;
    t[--i] = '\0';

    printf("%d" , strend(s , t));

    return 0;
}

int strend(char *s , char *t){
    int t_len = strlen(t); //��ȡt�ĳ���
    int s_len = strlen(s); //��ȡs�ĳ���
    int i;

    if(t_len <= s_len)       //�ж�s�Ƿ��t��
        i = s_len - t_len; 
    else
        return 0;

    while(i != 0){          //����sǰ����ַ���������tһ�����ȵ��ַ�
        s++;
        i--;
    }
    
    while(*t){              //��t�ж��Ƿ�����������ַ�
        if(*s++ != *t++)
            return 0;
    }
    return 1;

}