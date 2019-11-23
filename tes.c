#include <stdio.h>
#include <stdlib.h>
#include "input_command.c"
#include "player.h"
#include "bangunan.h"
#include "listlinier.h"
#include "arraydin.h"
int main(){
   // INPUT_COMMAND();
   TabInt TabBangunan;
   Stack S;
   listIdxBangunan IdxBangunan;
   boolean atk,ctrl = false;
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
   MakeBangunan(&B,Po2,'T',1);
   MakeBangunan(&C,Po3,'T',1);
   MakeBangunan(&D,Po4,'T',2);
   MakeBangunan(&E,Po5,'F',2);
   MakeBangunan(&F,Po6,'T',2);
  

   AddAsLastEl(&TabBangunan,A);
   AddAsLastEl(&TabBangunan,B);
   AddAsLastEl(&TabBangunan,C);
   AddAsLastEl(&TabBangunan,D);
   AddAsLastEl(&TabBangunan,E);
   AddAsLastEl(&TabBangunan,F);

   Graph G;
   CreateGraph(1, &G);
   InsertEdge(&G, 1, 2);
   InsertEdge(&G, 1, 4);
   InsertEdge(&G, 2, 1);
   InsertEdge(&G, 4, 1);
   InsertEdge(&G, 1, 5);
   InsertEdge(&G, 5, 1);
   InsertEdge(&G, 3, 4);

   // }
   // printf("Bangunan milik Player 1:\n");
   // PrintBangunan(P1,TabBangunan);
   // printf("Bangunan milik Player 2:\n");
   // PrintBangunan(P2,TabBangunan);
   // DelIndeksB(A,&P1,TabBangunan);
   // printf("Bangunan milik Player 1:\n");
   // PrintBangunan(P1,TabBangunan);
   // InsIndeksB(A,&P2,TabBangunan);
   // printf("Bangunan milik Player 2:\n");
   // PrintBangunan(P2,TabBangunan);
   // ATTACK(&TabBangunan, &P1, &P2, &atk, &ctrl, &S);
   // MOVE(P2, &TabBangunan);
   // PrintBangunan(P2, TabBangunan);

   INPUT_COMMAND(&P1, &P2, &TabBangunan, G);
   return 0;
}