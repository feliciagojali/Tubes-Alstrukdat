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
   Bangunan A,B,C;
   POINT Po = MakePOINT(2,5);
   POINT Po2 = MakePOINT(1,4);
   POINT Po3 = MakePOINT(8,8);

   MakeBangunan(&A,Po,'C',1);
   MakeBangunan(&B,Po2,'V',1);
   MakeBangunan(&C,Po3,'T',1);

   InsVFirst(&listB(P1),A);
   InsVFirst(&listB(P1),B);
   InsVFirst(&listB(P1),C);

   InsVFirst(&listB(P2),C);
   InsVFirst(&listB(P2),B);
   InsVFirst(&listB(P2),A);  

   inputCommand(&P1,&P2);
   return 0;
}