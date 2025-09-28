#include<stdio.h>

int main(){
    int c;
    int i = 0;
    c = getchar();
    printf("%d\n",c);
    char ch = c;
    while (ch == EOF)
    {
        i++;
        printf("%c\n",ch);/* code */
        if (i>2)
        {
            exit(0);
        }
        
    }
    
    
    return 0;
}