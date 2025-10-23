#include <stdio.h>

int main(){
  int Fahrenheit , Celsius;
  int step , lower , upper;

  lower = 0;
  upper = 300;
  step = 20;

  printf("华氏度和摄氏度对照表\n");

  Fahrenheit = lower;
  while(Fahrenheit < upper){
    Celsius = 5 * (Fahrenheit - 32) / 9 ;//C = 5 × (F - 32) / 9
    printf("%d\t%d\n", Fahrenheit , Celsius);
    Fahrenheit += step;
  }
  return 0;
}
