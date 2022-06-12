#include "chess.h"
#include "figures.h"

void display(){
  char** res = rotateL(knight);
  interpreter(res);
}
