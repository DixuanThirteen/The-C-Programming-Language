/*
    5.5 字符指针与函数
    strcpy函数
    将指针t指向的字符串复制到指针s所指向的位置
*/
void strcpy(char *s, char *t){
    int i;

    i = 0;
    while( (s[i] = t[i]) != '\0')
        i++;
}

void strcpy(char *s,char *t){
    while(*s++ = *t++)
        ;
}