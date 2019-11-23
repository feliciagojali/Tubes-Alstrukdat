/* File: mesinkata.c */
/* Realisasi mesinkata.h */


#include <stdio.h>
#include "../boolean/boolean.h"
#include "../mesinkar/mesinkark.h"
#include "../mesinkata/mesinkatak.h"

/* State Mesin Kata */
boolean EndKataK;
KataK CKataK;

void IgnoreBlankK()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while(CCK==BLANKK && CCK != MARKK){
        ADVK();
    }
}
void STARTKATAK()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    STARTK();
    IgnoreBlankK();
    if(CCK==MARKK){
        EndKataK = true;
    } else {
        EndKataK = false;
    }
}
void ADVKATAK()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlankK();
    if(CCK == MARKK){
        EndKataK = true;
    } else {
        IgnoreBlankK();
        SalinKataK();
    }
}

void InputK(KataK *X){
    ADVKATAK();
    (*X).Length = CKataK.Length;
    for(int i = 1; i <= CKataK.Length; i++){
        (*X).TabKata[i] = CKataK.TabKata[i];
    }
}

void PrintKataK(KataK x){
    for(int i = 1; i <= x.Length; i++){
        printf("%c", x.TabKata[i]);
    }
}
void SalinKataK()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 1;
    do {
        if(i <= NMaxK){
            CKataK.TabKata[i]=CCK;
            i += 1;
        }
        ADVK();
    } while (!(CCK==MARKK || CCK == BLANKK));
    CKataK.Length=i-1;
}