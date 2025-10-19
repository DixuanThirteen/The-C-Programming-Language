/*
    5.5 字符指针与函数
    strcmp函数
    根据s按照字典顺序小于、等于或大于t的结果分别返回负整数、0或正整数
*/
int strcmp(char *s, char *t){
    int i;

    for(i = 0 ; s[i] == t[i] ; i++)
        if(s[i] == '\0')
            return 0;

    return s[i] - t[i];
}

int strcmp(char *s, char *t){

    for( ; *s == *t ; s++ , t++){
        if(*s == '\0')
            return 0;
    }
    return *s - *t;
}