#include "chess.h"
#include "figures.h"

void display(){
  char** blackKnight = reverse(knight);
  freeMem(blackKnight);
  interpreter(blackKnight);
}
