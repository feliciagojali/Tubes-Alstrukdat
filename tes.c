#include <stdio.h>
#include <stdlib.h>
// #include "input_command.c"
#include "player.h"
#include "bangunan.h"
#include "listlinier.h"
#include "arraydin.h"
int main(){
   // INPUT_COMMAND();
   TabInt TabBangunan;
   listIdxBangunan IdxBangunan;
   MakeEmpty(&TabBangunan,50);
   CreateEmptyList(&IdxBangunan);
    // kamus
   Player P1 = initPlayer(1);
   Player P2 = initPlayer(2);
   Bangunan A,B,C,D,E,F;
   POINT Po1 = MakePOINT(2,5);
   POINT Po2 = MakePOINT(1,4);
   POINT Po3 = MakePOINT(8,8);
   POINT Po4 = MakePOINT(3,7);
   POINT Po5 = MakePOINT(0,3);
   POINT Po6 = MakePOINT(9,7);

   MakeBangunan(&A,Po1,'C',1);
   MakeBangunan(&B,Po2,'V',1);
   MakeBangunan(&C,Po3,'T',1);
   MakeBangunan(&D,Po4,'T',2);
   MakeBangunan(&E,Po5,'T',2);
   MakeBangunan(&F,Po6,'T',2);

   // AddAsLastEl(&TabBangunan,A);
   // InsVLast(&IdxBangunan, 1);
   // AddAsLastEl(&TabBangunan,B);
   // InsVLast(&IdxBangunan, 2);
   // AddAsLastEl(&TabBangunan,C);
   // InsVLast(&IdxBangunan, 3);
   // AddAsLastEl(&TabBangunan,D);
   // InsVLast(&IdxBangunan, 4);
   // AddAsLastEl(&TabBangunan,E);
   // InsVLast(&IdxBangunan, 5);
   // AddAsLastEl(&TabBangunan,F);
   // InsVLast(&IdxBangunan, 6);

   InsBangunan(&P1, A, &IdxBangunan, &TabBangunan);
   InsBangunan(&P1, B, &IdxBangunan, &TabBangunan);
   InsBangunan(&P1, C, &IdxBangunan, &TabBangunan);
   InsBangunan(&P2, D, &IdxBangunan, &TabBangunan);
   InsBangunan(&P2, E, &IdxBangunan, &TabBangunan);
   InsBangunan(&P2, F, &IdxBangunan, &TabBangunan);

   // for (int i = GetFirstIdx(TabBangunan); i<= GetLastIdx(TabBangunan); i++) {
   //    if (Pemilik(Elmt(TabBangunan,i)) == 1) {
   //       InsVLast(&listB(P1),i);
   //    } else if (Pemilik(Elmt(TabBangunan,i)) == 2) {
   //       InsVLast(&listB(P2),i);
   //    }
   // }

   printf("Bangunan milik Player 1:\n");
   PrintBangunan(P1,IdxBangunan,TabBangunan);
   printf("Bangunan milik Player 2:\n");
   PrintBangunan(P2, IdxBangunan,TabBangunan);

   // inputCommand(&P1, &P2);
   
   return 0;
}