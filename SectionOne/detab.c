#include <stdio.h>
#define MAX_LEN 1000
#define TAB_LEN 8
#define SPACE ' '

void detab(char orgin[] , char copy[]);

int main(){
	int a , len = 0;
	char str_detab[MAX_LEN];
	char str[MAX_LEN];
	
	while((a = getchar()) != EOF){
		str[len++] = a;
	}
	
	detab(str , str_detab);
	printf("%s",str_detab);
}

void detab(char orgin[] , char copy[]){
	int a;
	int line_len = 0;
	int len1 = 0;
	int len2 = 0;
	
	while((a = orgin[len1++]) != EOF){
		if(a == '\t'){
			int i , len ;
			for(i = 0 , len = TAB_LEN - line_len % TAB_LEN ; i < len ; i++ , line_len++){
				copy[len2++] = ' ';
			}
		}else{
			copy[len2++] = a;
			a == '\n' ? line_len = 0 : line_len++ ;
		}
	}
}
