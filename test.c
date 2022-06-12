#include "chess.h"
#include "figures.h"

void display(){
  char** res = rotateR(join(rook, rook));
  interpreter(res);
}
