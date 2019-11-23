/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KARK_H_
#define __MESIN_KARK_H_

#include "../boolean/boolean.h"

#define MARKK '#'
/* State Mesin */
extern char CCK;
extern boolean EOPK;

void STARTK();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADVK();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

#endif