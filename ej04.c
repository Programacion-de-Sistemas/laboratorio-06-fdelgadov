#include "chess.h"
#include "figures.h"

void display(){
  char** test = superImpose(reverse(bishop), whiteSquare);
  interpreter(test);
}
