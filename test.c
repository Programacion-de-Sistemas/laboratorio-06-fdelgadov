#include "chess.h"
#include "figures.h"

void display(){
  char** res = rotateL(join(rook, rook));
  interpreter(res);
}
