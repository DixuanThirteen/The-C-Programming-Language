/*
    5.5 �ַ�ָ���뺯��
    strcpy����
    ��ָ��tָ����ַ������Ƶ�ָ��s��ָ���λ��
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