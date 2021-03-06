#include "chess.h"
#include "figures.h"

void display(){
  char** blackSquare = reverse(whiteSquare);
  char** twoSquares = join(whiteSquare, blackSquare);
  freeMem(blackSquare);
  char** row = repeatH(twoSquares, 4);
  freeMem(twoSquares);
  interpreter(row);
  freeMem(row);
}
