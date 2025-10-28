#include <stdio.h>
#include <string.h>

#define MAXLEN 100
#define MAXLINES 100
#define STORESIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[] , int maxlines , char *store , int storesize);
void writelines(char *lineptr[] , int nlines);
void qsort(char *lineptr[] , int left , int right);
void swap(char *lineptr[] , int i , int j);
int get_line(char s[], int lim);

int main(){
    int nlines;
    char linestore[STORESIZE];      //����ռ�

    if( ( nlines = readlines(lineptr , MAXLINES , linestore , STORESIZE) ) >= 0){
        qsort(lineptr , 0 , nlines - 1);
        printf("�������\n");
        writelines(lineptr , nlines);
        return 0;
    }else{
        printf("error");
        return 1;
    }

    return 0;
}

int readlines(char *lineptr[] , int maxlines , char *store , int storesize){
    int nlines = 0;       //nlines:�ı�������
    char *p;
    char *end = store + storesize;      //β��ָ��
    p = store;                          //��pָ��linestore[0]
    while(nlines < maxlines && p < end){
        int lim = (int)(end - p);
        int len = get_line(p , lim);     //��������ı�����ָ��p��ͬʱ����linestore����Ϊpָ��linestore
        if(len <= 0)
            break;
        
        if( p[len - 1] == '\n' )        //��ĩβ���з�'\n'�����ս��'\0'
            p[len - 1] = '\0';

        lineptr[nlines++] = p;
        p += (int)strlen(p) + 1;        //��pָ��ָ����һ����λ
    }

    return nlines;
}

void writelines(char *lineptr[] , int nlines){
    int i;

    for( i = 0 ; i < nlines ; i++ )
        printf("%s\n",lineptr[i]);
}

void qsort(char *lineptr[] , int left , int right){
    int i , last; //last�ǻ�׼ֵ��ߵ����һ��Ԫ��
    if(left >= right)
        return;

    last = left;    //��leftΪ��׼ֵ��ߵ����һ��Ԫ�أ�leftҲ�ǻ�׼ֵ
    for(i = left + 1 ; i <= right ; i++)
        if( strcmp( lineptr[i] , lineptr[left] ) < 0 )
            swap( lineptr , i , ++last);
    swap(lineptr , last , left);

    qsort(lineptr , left , last - 1);
    qsort(lineptr , last + 1 , right);

}

void swap(char *lineptr[] , int i , int j){
    char *temp;

    temp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = temp;
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