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
  int h = height(fig);
  char** res = (char**) malloc(sizeof(char*) * h);
  char** resx = res;
  char** pfig = fig;
  char* lineR;
  char* lineF;
  int w = width(fig);
  while(*pfig){
    *res = (char*) malloc(sizeof(char) * w);
    lineR = *res;
    lineF = *pfig;

    while(*lineF){
      *lineR = negative(*lineF);
      lineR++;
      lineF++;
    }
    *lineR = 0;
    res++;
    pfig++;
  }
  *res = 0;
  return resx;
}

char** join(char** left, char** right){
  int h = height(left);
  int w = width(left);
  w += width(right);

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
  char** res = (char**) malloc(sizeof(char*) * (h + 1));
  char** pres = res;
  int w = width(fig);
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
  
  char** tmp;
  for(int i = 1; i < k; i++){
    tmp = pres;
    pres = join(pres, fig);
    freeMem(tmp);
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
  char** tmp;

  for(int i = 1; i < k; i++){
    tmp = res;
    res = up(res, fig);
    freeMem(tmp);
  }

  return res;
}

char** superImpose(char** over, char** under){
  int h = height(over);
  int w = width(over);
  char** res = (char**) malloc(sizeof(char*) * (h + 1));
  char** pres = res;

  char* lineR = *res;
  char* lineO = *over;
  char* lineU = *under;

  while(*over){
    *res = (char*) malloc(sizeof(char) * (w + 1));
    lineR = *res;
    lineO = *over;
    lineU = *under;

    while(*lineO){
      if(*lineO == ' ')
        *lineR = *lineU;
      else
        *lineR = *lineO;
      
      lineR++;
      lineO++;
      lineU++;
    }
    *lineR = 0;

    res++;
    over++;
    under++;
  }
  *res = 0;
  
  return pres;
}

char** flipV(char** fig){
  int h = height(fig);
  int w = width(fig);
  char** res = (char**) malloc(sizeof(char*) * (h + 1));
  char** pres = res;
  char** pfig = fig;
  char* lineR;
  char* lineF;
  int i;

  while(*pfig){
    *res = (char*) malloc(sizeof(char) * (w + 1));
    lineR = *res;
    lineF = *pfig;
    
    i = w - 1;
    while(i >= 0){
      *lineR = lineF[i];
      lineR++;
      i--;
    }
    *lineR = 0;
    pfig++;
    res++;
  }
  *res = 0;

  return pres;
}

char** flipH(char** fig){
  int h = height(fig);
  int w = width(fig);
  char** res = (char**) malloc(sizeof(char*) * (h + 1));
  char** pres = res;
  char** pfig = fig;
  char* lineR;
  char* lineF;
  
  int j = h - 1;
  while(j >= 0){
    *res = (char*) malloc(sizeof(char) * (w + 1));
    lineR = *res;
    lineF = &pfig[j][0];

    while(*lineF){
      *lineR = *lineF;
      lineR++;
      lineF++;
    }
    *lineR = 0;
    
    j--;
    res++;
  }
  *res = 0;

  return pres;
}

char** rotateL(char** fig){
  int h = height(fig);
  int w = width(fig);
  char** res = (char**) malloc(sizeof(char*) * (w + 1));
  char** pres = res;
  char** pfig = fig;
  char* lineR;
  
  for(int j = w - 1; j >= 0; j--){
    *res = (char*) malloc(sizeof(char) * (h + 1));
    lineR = *res;

    for(int i = 0; i < h; i++){
      *lineR = pfig[i][j];
      lineR++;
    }

    *lineR = 0;
    res++;
  }

  *res = 0;

  return pres;
}

char** rotateR(char** fig){
  int h = height(fig);
  int w = width(fig);
  char** res = (char**) malloc(sizeof(char*) * (w + 1));
  char** pres = res;
  char** pfig = fig;
  char* lineR;
  
  for(int j = 0; j < w; j++){
    *res = (char*) malloc(sizeof(char) * (h + 1));
    lineR = *res;

    for(int i = h - 1; i >= 0; i--){
      *lineR = pfig[i][j];
      lineR++;
    }
    
    *lineR = 0;
    res++;
  }

  *res = 0;

  return pres;
}
