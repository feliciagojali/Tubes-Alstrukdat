//Name File:    stackt.C
//Tanggal:      25 oktober 2019
//Deskripsi:    Implementasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama
//              TOP adalah alamat elemen puncak
//              Implementasi dalam bahasa C dengan alokasi statik
//Tubes Alstrukdat

/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#include <stdlib.h>
#include <stdio.h>
#include "../stackt/stackt.h"



/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty_Stackt (Stack *S, int maxel)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
  Top(*S) = Nil;
  Neff(InfoTop(*S)) = 0;
  MaxEl(InfoTop(*S)) = maxel;
  TI(InfoTop(*S)) = (ElType *) malloc (sizeof(TabInt) * (maxel+1));
  // printf("berhasil malloc\n");
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty_Stackt (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
  return (Top(S) == 1);
}
boolean IsFull_Stackt (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
  return (Top(S) == MaxElS);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypeS X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
  int i;
  Top(*S) +=1;
  MakeEmpty(&InfoTop(*S), MaxEl(X));
  for(i = GetFirstIdx(X);i<= GetLastIdx(X); i++){
    AddAsLastEl(&InfoTop(*S), Elmt(X, i));
  }
  
  Neff(InfoTop(*S)) = Neff(X);
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypeS* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
  *X = InfoTop(*S);
  Top(*S) -= 1;
}

void DelAll (Stack *S){
  infotypeS temp, tempPop;
  CopyTab(InfoTop(*S), &temp);
  while(!IsEmpty_Stackt(*S)){
    Pop(S, &tempPop);
  }
  Pop(S, &tempPop);
  Push(S, temp);
}