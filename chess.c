#include <stdio.h>

char** reverse(char** fig){
  char** res = fig;
  int i = 0;
  while(*res){
    printf("%s\n", *res);
    i++;
    res++;
  }
  printf("length: %d\n", i);
  res = fig;
  return res;
}
