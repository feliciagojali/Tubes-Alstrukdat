#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L){
    return (First(L) == NULL);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
    First(*L) = NULL;
}
/* I.S. sembarang*/
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressB AlokasiList (infotypeB X){
    addressB A = (addressB) malloc (sizeof(ElmtList));
    if(A != NULL){
        Info(A) = X;
        Next(A) = NULL;
        return A;
    }
    else{
        return NULL;
    }
}
/* Mengirimkan addressBhasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressBtidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiList (addressB*P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressBP */


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeB X){
    addressB Y = AlokasiList(X);
    if(Y != NULL){
        InsertFirst(L,Y);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotypeB X){
    addressB Y = AlokasiList(X);
    if(Y != NULL){
        InsertLast(L,Y);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeB *X){
    addressB Y;
    DelFirst(L,&Y);
    *X = Info(Y);
    DealokasiList(&Y);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotypeB *X){
    addressB prec;
    addressB P = First(*L);
    if(NbElmt(*L) == 1){
        *X = Info(P);
        Next(P) = NULL;
        CreateEmptyList(L);
    }
    else{
        while(Next(P) != NULL){
            prec = P;
            P = Next(P);
        }
        *X = Info(P);
        Next(prec) = NULL;
        DealokasiList(&P);
    }    
}
void DelBangunan(List *L, addressB X){
    addressB P = First(*L);

    while (Next(P) != NULL && Next(P) != X){
        P = Next(P);
    }
    addressB A = Next(Next(P));
    Next(P) = A;
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressB P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressB P sebagai elemen pertama */
void InsertAfter (List *L, addressB P, addressB Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, addressB P){
    addressB Y = First(*L);
    if(IsEmptyList(*L)){
        InsertFirst(L, P);
    }
    else{
        while(Next(Y) != NULL){
            Y = Next(Y);
        }
        InsertAfter(L, P, Y);   
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressB *P){
    addressB Y = First(*L);
    addressB X = Next(Y);
    *P = Y;
    Next(Y) = NULL;
    First(*L) = X;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (List *L, addressB *P){
    addressB Last, PrecLast;

    Last = First(*L);
    PrecLast = NULL;
    while(Next(Last)!=NULL){
        PrecLast = Last;
        Last = Next(Last);
    }
    (*P) = Last;
    if(PrecLast == NULL){
        First(*L) = NULL;
    }
    else{
        Next(PrecLast) = NULL;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, addressB *Pdel, addressB Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = NULL;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

int NbElmt (List L){
    int count = 0;
    addressB Y = First(L);
    while(Y != NULL){
        Y = Next(Y);
        count++;
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */


/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
    addressB P;
    CreateEmptyList(L3);
    if(!IsEmptyList(*L1) && !IsEmptyList(*L2)){
        First(*L3) = First(*L1);
        P = First(*L3);
        while(Next(P) != NULL){
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    else if(IsEmptyList(*L1) && !IsEmptyList(*L2)){
        First(*L3) = First(*L2);
    }
    else if(!IsEmptyList(*L1) && IsEmptyList(*L2)){
        First(*L3) = First(*L1);
    }
    CreateEmptyList(L1);
    CreateEmptyList(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */