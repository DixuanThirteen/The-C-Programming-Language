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
    char linestore[STORESIZE];      //储存空间

    if( ( nlines = readlines(lineptr , MAXLINES , linestore , STORESIZE) ) >= 0){
        qsort(lineptr , 0 , nlines - 1);
        printf("正序输出\n");
        writelines(lineptr , nlines);
        return 0;
    }else{
        printf("error");
        return 1;
    }

    return 0;
}

int readlines(char *lineptr[] , int maxlines , char *store , int storesize){
    int nlines = 0;       //nlines:文本行数量
    char *p;
    char *end = store + storesize;      //尾后指针
    p = store;                          //让p指向linestore[0]
    while(nlines < maxlines && p < end){
        int lim = (int)(end - p);
        int len = get_line(p , lim);     //把输入的文本存入指针p，同时存入linestore，因为p指向linestore
        if(len <= 0)
            break;
        
        if( p[len - 1] == '\n' )        //把末尾换行符'\n'换成终结符'\0'
            p[len - 1] = '\0';

        lineptr[nlines++] = p;
        p += (int)strlen(p) + 1;        //把p指针指向下一个空位
    }

    return nlines;
}

void writelines(char *lineptr[] , int nlines){
    int i;

    for( i = 0 ; i < nlines ; i++ )
        printf("%s\n",lineptr[i]);
}

void qsort(char *lineptr[] , int left , int right){
    int i , last; //last是基准值左边的最后一个元素
    if(left >= right)
        return;

    last = left;    //设left为基准值左边的最后一个元素，left也是基准值
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