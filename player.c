#include <stdio.h>
#include <stdlib.h>
#include "player.h"

Player initPlayer(int id){
    Player P;
    ID(&P) = id;
    CreateEmptyList(&listB(P));
    return P;  
}

void PrintJenisBangunan(Bangunan A) {
    if (Jenis(A) == 'C' ) {
        printf("Castle ");
    } else if (Jenis(A) == 'F') {
        printf("Fort ");
    } else if (Jenis(A) == 'T') {
        printf("Tower ");
    } else {
        printf("Village ");
    }
}

void PrintBangunan(Player P){
    address Y = First(listB(P));
    if (!IsEmptyList(listB(P))) {
        int i = 1;
        while(Next(Y) != Nil) {
            printf("%d. ",i);
            PrintJenisBangunan(Info(Y));
            TulisPOINT(Titik(Info(Y)));
            printf(" %d",NPskn(Info(Y)));
            printf(" lvl. %d \n",Lvl(Info(Y)));
            i++;
            Y = Next(Y);
        } 
    }
}