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

int height(char** fig){
  char** pfig = fig;
  int h = 0;

  while(*pfig){
    h++;
    pfig++;
  }

  return h;
}

int width(char** fig){
  int w = 0;
  char* line = *fig;

  while(*line){
    w++;
    line++;
  }

  return w;
}

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
      *lineR = negative(*lineF);
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

char** join(char** left, char** right){
  char** pleft = left;
  char** pright = right;

  int h = height(left);
  printf("h: %d\n", h);
  
  int w = width(right);
  printf("w: %d\n", w);
  
  w += width(right);
  printf("w: %d\n", w);

  char** res = (char**) malloc(sizeof(char*) * h);
  char** pres = res;

  return res;
}
