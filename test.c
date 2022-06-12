#include "chess.h"
#include "figures.h"

void display(){
  char** res = rotateR(knight);
  interpreter(res);
}
