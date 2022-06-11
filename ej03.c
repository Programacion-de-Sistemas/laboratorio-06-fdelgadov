#include "figures.h"
#include "chess.h"

void display(){
  char** blackSquare = reverse(whiteSquare);
  char** squaresA = join(whiteSquare, blackSquare);
  char** squaresB = join(blackSquare, whiteSquare);
  char** rowA = repeatH(squaresA, 4);
  char** rowB = repeatH(squaresB, 4);
  char** rows = up(rowA, rowB);
  interpreter(rows);
}
