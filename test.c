#include "chess.h"
#include "figures.h"

void display(){
  char** flip = flipH(knight);
  interpreter(flip);
}
