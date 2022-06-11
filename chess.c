#include <stdio.h>
#include <stdlib.h>

char** reverse(char** fig){
  char** res = (char**) malloc(sizeof(char*) * 58);
  char** pfig = fig;
  char* lineR;
  char* lineF;
  int i = 0;
  while(*res){
    *res = (char*) malloc(sizeof(char) * 58);
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
  return res;
}
