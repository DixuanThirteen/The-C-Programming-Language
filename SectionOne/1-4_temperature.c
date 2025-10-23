#include <stdio.h>

int main(){
  int Fahrenheit , Celsius;
  int step , lower , upper;

  lower = 0;
  upper = 300;
  step = 20;

  printf("摄氏度和华氏度对照表\n");
  printf("摄氏度\t华氏度\n");

  Celsius = lower;
  while(Celsius < upper){
    Fahrenheit = 9 * Celsius / 5 + 32 ;//F = 9 × C / 5 + 32
    printf("%d\t%d\n", Celsius , Fahrenheit);
    Celsius += step;
  }
  return 0;
}
