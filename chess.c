#include <stdio.h>

char** reverse(char** fig){
  char** res = fig;
  int i = 0;
  while(*res){
    i++;
    res++;
  }
  printf("length: %d\n", i);
  return res;
}