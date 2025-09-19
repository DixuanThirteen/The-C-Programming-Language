#include <stdio.h>
#define MAXLINE 1000

void escape(char s[] , char t[]);
void reescape(char s[] , char t[]);

int main(){
	char in_str[MAXLINE];
	char cpy_str[MAXLINE];
	int c , len;
	
	len = 0;
	
	while((c = getchar()) != EOF){
		in_str[len++] = c;
	}
	
	escape(in_str , cpy_str);
	
	printf("%s\n",cpy_str);
	
	reescape(cpy_str , in_str);
	
	printf("%s",in_str);
	
	return 0;
	
}

void escape(char s[] , char t[]){
	int a , len , i;
	len = 0;
	
	for(i = 0 ; (a = s[len]) != EOF ; len++){
		switch(a){
			case '\n':
				t[i++] = '\\';
				t[i++] = 'n';
				break;
			case '\t':
				t[i++] = '\\';
				t[i++] = 't';
				break;
			default:
				t[i++] = s[len];
				break;
		}
	}
}

void reescape(char s[] , char t[]){
	int a , len , i;
	len = 0;
	
	for(i = 0 ; (a = s[len]) != EOF ; len++){
		switch(a){
			case '\\':
				len++;
				a = s[len];
				switch(a){
					case 'n':
						t[i++] = '\n';
						break;
					case 't':
						t[i++] = '\t';
						break;
				}
				break;
			default:
				t[i++] = s[len];
				break;
		}
	}
}
