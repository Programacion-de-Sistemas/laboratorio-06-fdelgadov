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

void freeMem(char** fig){
  char** pfig = fig;

  while(*pfig){
    free(*pfig);
    pfig++;
  }

  free(fig);
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
  int h = height(left);
  printf("h: %d\n", h);
  
  int w = width(left);
  printf("w: %d\n", w);
  
  w += width(right);
  printf("w: %d\n", w);

  char** res = (char**) malloc(sizeof(char*) * (h + 1));
  char** pres = res;
  char** pleft = left;
  char** pright = right;
  char* lineF;
  char* lineR;
  
  while(*pleft){
    *res = (char*) malloc(sizeof(char) * (w + 1));
    lineF = *pleft;
    lineR = *res;

    while(*lineF){
      *lineR = *lineF;
      lineR++;
      lineF++;
    }

    lineF = *pright;

    while(*lineF){
      *lineR = *lineF;
      lineR++;
      lineF++;
    }
    *lineR = 0;
    pleft++;
    pright++;
    res++;
  }
  *res = 0;

  return pres;
}

char** repeatH(char** fig, int k){
  int h = height(fig);
  printf("h: %d\n", h);
  char** res = (char**) malloc(sizeof(char*) * (h + 1));
  char** pres = res;
  int w = width(fig);
  printf("w: %d\n", w);
  char** pfig = fig;
  char* lineR;
  char* lineF;

  while(*pfig){
    *res = (char*) malloc(sizeof(char) * (w + 1));
    lineR = *res;
    lineF = *pfig;
    
    while(*lineF){
      *lineR = *lineF;
      lineR++;
      lineF++;
    }
    *lineR = 0;
    res++;
    pfig++;
  }
  *res = 0;

  for(int i = 1; i < k; i++){
    pres = join(pres, fig);
  }

  return pres;
}

char** up(char** upp, char** down){
  int h = height(upp) + height(down);
  int w = width(upp);
  
  char** res = (char**) malloc(sizeof(char*) * (h + 1));
  char** pres = res;
  char** pfig = upp;
  char* lineR;
  char* lineF;
  while(*pfig){
    *res = (char*) malloc(sizeof(char) * (w + 1));
    lineR = *res;
    lineF = *pfig;

    while(*lineF){
      *lineR = *lineF;
      lineR++;
      lineF++;
    }
    *lineR = 0;
    res++;
    pfig++;
  }

  pfig = down;
  while(*pfig){
    *res = (char*) malloc(sizeof(char) * (w + 1));
    lineR = *res;
    lineF = *pfig;

    while(*lineF){
      *lineR = *lineF;
      lineR++;
      lineF++;
    }
    *lineR = 0;
    res++;
    pfig++;
  }
  *res = 0;

  return pres;
}

char** repeatV(char** fig, int k){
  char** res = repeatH(fig, 1);
  
  for(int i = 1; i < k; i++){
    res = up(res, fig);
  }

  return res;
}
