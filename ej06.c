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

  char** blackBackLine = reverse(backLine);

  char** pawnLine = repeatH(pawn, 8);
  char** blackPawnLine = reverse(pawnLine);

  char** blackSquare = reverse(whiteSquare);
  char** twoSquares = join(blackSquare, whiteSquare);
  freeMem(blackSquare);
  char** row = repeatH(twoSquares, 4);
  char** reverseRow = reverse(row);
  char** block = up(row, reverseRow);
  freeMem(row);
  freeMem(reverseRow);

  char** whites = up(backLine, pawnLine);
  freeMem(backLine);
  freeMem(pawnLine);

  char** blacks = up(blackPawnLine, blackBackLine);
  freeMem(blackPawnLine);
  freeMem(blackBackLine);

  char** blockWhites = superImpose(whites, block);
  freeMem(whites);
  char** blockBlacks = superImpose(blacks, block);
  freeMem(blacks);
  char** emptyBlock = repeatV(block, 2);
  freeMem(block);

  aux = up(blockWhites, emptyBlock);
  freeMem(blockWhites);
  freeMem(emptyBlock);
  char** res = up(aux, blockBlacks);
  freeMem(aux);
  freeMem(blockBlacks);

  interpreter(res);
}
