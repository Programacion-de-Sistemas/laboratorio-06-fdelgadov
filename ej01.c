#include "chess.h"
#include "figures.h"

void display(){
  interpreter(join(whiteSquare, reverse(whiteSquare)));
}
