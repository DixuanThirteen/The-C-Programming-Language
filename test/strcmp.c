/*
    5.5 �ַ�ָ���뺯��
    strcmp����
    ����s�����ֵ�˳��С�ڡ����ڻ����t�Ľ���ֱ𷵻ظ�������0��������
*/
int strcmp(char *s, char *t){
    int i;

    for(i = 0 ; s[i] == t[i] ; i++)
        if(s[i] == '\0')
            return 0;

    return s[i] - t[i];
}

// int strcmp(char *s, char *t){

//     for( ; *s == *t ; s++ , t++){
//         if(*s == '\0')
//             return 0;
//     }
//     return *s - *t;
// }