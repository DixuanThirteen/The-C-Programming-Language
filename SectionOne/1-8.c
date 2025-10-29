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
	printf("空格数：%d\n制表符数：%d\n换行符数：%d",cspace , ct , cn);
	return 0;
}
