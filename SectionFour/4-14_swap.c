#include <stdio.h>

#define swap(t,x,y) \
    do              \
    {               \
        t temp;     \
        temp = x;   \
        x = y ;     \
        y = temp;   \
                    \
    } while (0);    


int main(){
    int a,b;
    a = 10;
    b = 20;

    swap(int , a , b);

    printf("%d %d",a,b);

    return 0;
}