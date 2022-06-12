#include "figures.h"
#include "chess.h"

void display(){
  char** blackSquare = reverse(whiteSquare);
  char** squaresA = join(whiteSquare, blackSquare);
  char** squaresB = join(blackSquare, whiteSquare);
  char** rowA = repeatH(squaresA, 4);
  char** rowB = repeatH(squaresB, 4);
  char** rows = up(rowB, rowA);
  char** block = repeatV(rows, 2);
  interpreter(block);
  freeMem(blackSquare);
  freeMem(squaresA);
  freeMem(squaresB);
  freeMem(rowA);
  freeMem(rowB);
  freeMem(rows);
  freeMem(block);
}
