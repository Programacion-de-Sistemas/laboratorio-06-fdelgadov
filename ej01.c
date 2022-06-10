#include "chess.h"
#include "figures.h"

void display(){
  interpreter(repeatH(join(whiteSquare, reverse(whiteSquare)), 4));
}
