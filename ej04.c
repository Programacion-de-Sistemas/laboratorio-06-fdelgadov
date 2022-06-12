#include "chess.h"
#include "figures.h"

void display(){
  char** rk = join(rook, knight);
  char** lateralA = join(rk, bishop);
  freeMem(rk);
  char** qk = join(queen, king);
  char** bk = join(bishop, knight);
  char** lateralB = join(bk, rook);
  freeMem(bk);
  char** aux = join(lateralA, qk);
  freeMem(lateralA);
  freeMem(qk);
  char** backLine = join(aux, lateralB);
  freeMem(lateralB);

  char** blackSquare = reverse(whiteSquare);
  char** twoSquares = join(blackSquare, whiteSquare);
  freeMem(blackSquare);
  char** row = repeatH(twoSquares, 4);

  char** res = superImpose(backLine, row);
  freeMem(backLine);
  freeMem(row);

  interpreter(res);
}
