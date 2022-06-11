#include <stdio.h>
#include <stdlib.h>

char negative(char ch){
  switch(ch){
    case '.': return '@';
    case '@': return '.';
    case '_': return '=';
    case '=': return '_';
    default: return ch;
  }
}

char** reverse(char** fig){
  char** res = (char**) malloc(sizeof(char*) * 58);
  char** resx = res;
  char** pfig = fig;
  char* lineR;
  char* lineF;
  int i = 0;
  while(*pfig){
    char arr[58];
    *res = arr;
    lineR = arr;
    lineF = *pfig;

    while(*lineF){
      *lineR = negative(*lineF);
      lineR++;
      lineF++;
      i++;
    }
    *lineR = 0;
    printf("%s", *res);
    printf("\n");
    res++;
    pfig++;
  }
  *res = 0;
  printf("length: %d\n", i);
  return resx;
}
