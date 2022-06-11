#include <stdio.h>

char** reverse(char** fig){
  char** res;
  char** pfig = fig;
  char* lineR;
  char* lineF;
  int i = 0;
  while(*res){
    lineR = *res;
    lineF = *pfig;
    while(*lineR){
      *lineR = *lineF;
      printf("%c", *lineR);
      lineR++;
      lineF++;
      i++;
    }
    printf("\n");
    res++;
    pfig++;
  }
  printf("length: %d\n", i);
  res = fig;
  return res;
}
