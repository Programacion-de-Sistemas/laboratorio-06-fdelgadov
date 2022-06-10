#include <stdio.h>

char** reverse(char** fig){
  char** res = fig;
  int i = 0;
  while(*res){
    char* line = *res;
    while(*line){
      printf("%c", *line);
      line++;
      i++;
    }
    printf("\n");
    res++;
  }
  printf("length: %d\n", i);
  res = fig;
  return res;
}
