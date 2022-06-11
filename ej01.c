#include "chess.h"
#include "figures.h"

void display(){
  char** blackSquare = reverse(whiteSquare);
  char** twoSquares = join(whiteSquare, blackSquare);
  freeMem(blackSquare);
  interpreter(twoSquares);
  freeMem(twoSquares);
}
