#include <stdio.h>

int main(){
  int Fahrenheit , Celsius;
  int step , lower , upper;

  lower = 0;
  upper = 300;
  step = 20;

  printf("���϶Ⱥ����϶ȶ��ձ�\n");
  printf("���϶�\t���϶�\n");

  
  for(Fahrenheit = upper ; Fahrenheit > lower ; Fahrenheit -= step){
    Celsius = 5 * (Fahrenheit - 32) / 9 ;//C = 5 �� (F - 32) / 9
    printf("%d\t%d\n", Fahrenheit , Celsius);
  }
  return 0;
}
