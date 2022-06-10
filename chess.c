#include <stdio.h>

char** reverse(char** fig){
  char** res = fig;
  int i = 0;
  while(*res){
    while(**res){
      printf("%d", **res);
      *res++;
      i++;
    }
    res++;
  }
  printf("length: %d\n", i);
  res = fig;
  return res;
}
