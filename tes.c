#include <stdio.h>
#include <stdlib.h>
// #include "input_command.c"
#include "player.c"

int main(){
   // INPUT_COMMAND();
   
    // kamus
   Player P1 = initPlayer(1);
   Player P2 = initPlayer(2);
   Bangunan A,B,C;
   POINT P = MakePOINT(2,5);
   POINT P2 = MakePOINT(1,4);
   POINT P3 = MakePOINT(8,8);

   MakeBangunan(&A,P,'C',1);
   MakeBangunan(&B,P2,'V',1);
   MakeBangunan(&C,P3,'T',1);

   InsVFirst(&listB(P1),A);
   InsVFirst(&listB(P1),B);
   InsVFirst(&listB(P1),C);

   InsVFirst(&listB(P2),C);
   InsVFirst(&listB(P2),B);
   InsVFirst(&listB(P2),A);  


   PrintBangunan();
   return 0;
}