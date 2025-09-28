#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define VAR '1'

int sp = 0;
double val[MAXVAL];

int buf[BUFSIZE];                    //此处原先为char型，改为int型
int bufp = 0;

double variable[26];

void push(double f){
	if(sp < MAXVAL){
		val[sp++] = f;
	}
	else{
		printf("Error! Stack Full, can't push %g\n", f);
	}
}

double pop(void){
	if(sp > 0){
		return val[--sp];
	}
	else{
		printf("Error! Stack Empty!\n");
		return 0.0;
	}
}

void printTop(void){
	if(sp > 0){
		printf("Top: %g\n", val[sp-1]);
	}
	else{
		printf("Error! Stack Empty!\n");
	}
}

void topCopy(void){
	if(sp > 0 || sp < MAXVAL){
		val[sp++] = val[sp-1];
	}
	else if(sp <= 0){
		printf("Error! Stack Empty!\n");
	}
	else{
		printf("Error! Stack Full!\n");
	}
}

void swapTop(void){
	double temp;
	if(sp >= 2){
		temp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = temp;
	}
	else{
		printf("Can't Swap Top Number!\n");
	}
}

void emptyStack(void){
	for(int i = sp - 1; i >= 0; i--){
		val[i] = 0;
	}
	sp = 0;
}

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE){
		printf("Ungetch! Too many characters!\n");
	}
	else{
		buf[bufp++] = c;
	}
}

int getop(char s[]){
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if(c == 's'){
		int next1 = getch();
		int next2 = getch();
		if(next1 == 'i' && next2 == 'n'){
			return c;
		}
	}

	if(c == 'e'){
		int next1 = getch();
		int next2 = getch();
		if(next1 == 'x' && next2 == 'p'){
			return c;
		}
	}

	if(c == 'p'){
		int next1 = getch();
		int next2 = getch();
		if(next1 == 'o' && next2 == 'w'){
			return c;
		}
	}

	if(c >= 'a' && c <= 'z'){
		int next = getch();
		if(next == ' '){
			ungetch(next);
			return VAR;
		}
	}
	
	if(c == '-'){
		int next = getch();
		if(!isdigit(next) && next != '.'){
			ungetch(next);
			return c;
		}
		s[1] = c = next;
		i = 1;
	}
	else{
		i = 0;
		if(!isdigit(c) && c != '.'){
			return c;
		}
	}

	if(isdigit(c)){
		while(isdigit(s[++i] = c = getch()))
			;
	}
	if(c == '.'){
		while(isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if(c != EOF){
		ungetch(c);
	}
	return NUMBER;
}

int main(){
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch(type){
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0){
				push(pop() / op2);
			}
			else{
				printf("Error! Zero Divisor!\n");
			}
			break;
		case '%':
			op2 = pop();
			push((int)pop() % (int)op2);
			break;
		case 's':
			op2 = pop();
			push(sin(op2));
			break;
		case 'e':
			op2 = pop();
			push(exp(op2));
			break;
		case 'p':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case VAR:
			variable[s[0] - 'a'] = pop();
			push(variable[s[0] - 'a']);
			printf("%c = %lf\n", s[0], variable[s[0] - 'a']);
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("Error! Unknown Command %s\n", s);
			break;
		}
	}

	system("pause");
	return 0;
}
