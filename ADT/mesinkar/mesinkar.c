/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include <stdio.h>
#include "../mesinkar/mesinkar.h"

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START(int type) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */
    char MARK;
    /* Algoritma */
    switch(type){
        case 1:
            pita = stdin;
            MARK = '\n';
            break;
        case 2:
            pita = fopen("config.txt","r");
            MARK = '#';
            break;
    }
    ADV(MARK);
}
void ADV(char MARK){
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
       fclose(pita);
    }
}

void stopPita(){
    fclose(pita);
}