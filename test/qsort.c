#include <stdio.h>

#define MAXLINE 100

void qsort(int v[] , int left , int right){
    int i , last;
    void swap(int v[] , int i , int j);

    if(left >= right) //数组包含元素数必须大于2
        return;
    
    swap(v , left , (left + right)/2); 
    last = left;
    for(i = left + 1 ; i <= right ; i++){
        if(v[i] < v[left])
            swap(v , ++last , i);
    }
    swap(v , left , last);

    qsort(v , left , last - 1);
    qsort(v , last + 1 , right);
}

void swap(int v[] , int i , int j){
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main(){
    int v[MAXLINE];
    int left , right;
    int n;

    scanf("%d\n",&n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d",&v[i]);
    }
        

    scanf("%d %d",&left , &right);

    qsort(v,left,right);

    for(int i = left ; i <= right ; i++){
        printf("%d ",v[i]);
    }
    

    return 0;
}