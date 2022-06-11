#include "figures.h"
#include "chess.h"

void display(){
  char** blackSquare = reverse(whiteSquare);
  char** twoSquares = join(blackSquare, whiteSquare);
  freeMem(blackSquare);
  char** row = repeatH(twoSquares, 4);
  freeMem(twoSquares);
  interpreter(row);
  freeMem(row);
}
