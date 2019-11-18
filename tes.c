#include <stdio.h>
#include <stdlib.h>
#include "input_command.c"
#include "player.h"
#include "bangunan.h"
#include "listlinier.h"

int main(){
   // INPUT_COMMAND();
   
    // kamus
   Player P1 = initPlayer(1);
   Player P2 = initPlayer(2);
   Bangunan A,B,C,D,E,F;
   POINT Po = MakePOINT(2,5);
   POINT Po2 = MakePOINT(1,4);
   POINT Po3 = MakePOINT(8,8);

   MakeBangunan(&A,Po,'C',1);
   MakeBangunan(&B,Po2,'V',1);
   MakeBangunan(&C,Po3,'T',1);
   MakeBangunan(&D,Po,'C',2);
   MakeBangunan(&E,Po2,'V',2);
   MakeBangunan(&F,Po3,'T',2);

   InsVFirst(&listB(P1),A);
   InsVFirst(&listB(P1),B);
   InsVFirst(&listB(P1),C);

   InsVFirst(&listB(P2),F);
   InsVFirst(&listB(P2),F);
   InsVFirst(&listB(P2),F);  

   printf("Bangunan milik Player 1:\n");
   PrintBangunan(P1);
   printf("Bangunan milik Player 2:\n");
   PrintBangunan(P2);

   inputCommand(&P1, &P2);
   
   return 0;
}