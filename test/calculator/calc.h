#define NUMBER '0'  /* signal that a number was found 标志着找到了一个数字 */
void push(double); /* push f onto value stack 往栈中压入元素 */
double pop(void); /* pop and return top value from stack 弹出栈顶元素 */
int getop(char []); /* get next operator or numeric operand 获取栈顶元素 */
int getch(void); /* get a (possibly pushed-back) character 获取输入字符 */
void ungetch(int); /* push a character back on input 将多余字符存入缓冲区 */
