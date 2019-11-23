/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include <stdio.h>
#include "../mesinkar/mesinkark.h"

char CCK;
boolean EOPK;

static FILE * pitak;
static int retvalk;

void STARTK() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pitak = stdin;
    ADVK();
}

void ADVK() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    retvalk = fscanf(pitak,"%c",&CCK);
    EOPK = (CCK == MARKK);
    /*if (EOP) {
       fclose(pita);
    }*/
}