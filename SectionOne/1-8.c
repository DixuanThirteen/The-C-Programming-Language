#include <stdio.h>

int main(){
	int c;
	int cspace , ct , cn = 0;
	while( (c = getchar() ) != EOF){
		if(c == ' ')
			cspace++;
		else if(c == '\t')
			ct++;
		else if(c == '\n')
			cn++;
	} 
	printf("�ո�����%d\n�Ʊ������%d\n���з�����%d",cspace , ct , cn);
	return 0;
}
