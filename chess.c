#include <stdio.h>
#include <stdlib.h>

char** reverse(char** fig){
  char** res = (char**) malloc(sizeof(char*) * 58);
  char** resx = res;
  char** pfig = fig;
  char* lineR;
  char* lineF;
  int i = 0;
  while(*pfig){
    *res = (char*) malloc(sizeof(char) * 58);
    lineR = *res;
    lineF = *pfig;

    while(*lineF){
      *lineR = *lineF;
      printf("%c", *lineR);
      lineR++;
      lineF++;
      i++;
    }
    *lineR = 0;
    printf("\n");
    res++;
    pfig++;
  }
  *res = 0;
  printf("length: %d\n", i);
  return resx;
}
