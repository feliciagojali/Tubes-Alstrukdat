#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

#define Nil NULL

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L){
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang*/
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address AlokasiList (infotype X){
    address A = (address) malloc (sizeof(ElmtList));
    if(A != Nil){
        Info(A) = X;
        Next(A) = Nil;
        return A;
    }
    else{
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiList (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address Y = AlokasiList(X);
    if(Y != Nil){
        InsertFirst(L,Y);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address Y = AlokasiList(X);
    if(Y != Nil){
        InsertLast(L,Y);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address Y;
    DelFirst(L,&Y);
    *X = Info(Y);
    DealokasiList(&Y);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address prec;
    address P = First(*L);
    if(NbElmt(*L) == 1){
        *X = Info(P);
        Next(P) = Nil;
        CreateEmpty(L);
    }
    else{
        while(Next(P) != Nil){
            prec = P;
            P = Next(P);
        }
        *X = Info(P);
        Next(prec) = Nil;
        DealokasiList(&P);
    }    
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    address Y = First(*L);
    if(IsEmpty(*L)){
        InsertFirst(L, P);
    }
    else{
        while(Next(Y) != Nil){
            Y = Next(Y);
        }
        InsertAfter(L, P, Y);   
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    address Y = First(*L);
    address X = Next(Y);
    *P = Y;
    Next(Y) = Nil;
    First(*L) = X;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (List *L, address *P){
    address Last, PrecLast;

    Last = First(*L);
    PrecLast = Nil;
    while(Next(Last)!=Nil){
        PrecLast = Last;
        Last = Next(Last);
    }
    (*P) = Last;
    if(PrecLast == Nil){
        First(*L) = Nil;
    }
    else{
        Next(PrecLast) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

int NbElmt (List L){
    int count = 0;
    address Y = First(L);
    while(Y != Nil){
        Y = Next(Y);
        count++;
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */


/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
    address P;
    CreateEmpty(L3);
    if(!IsEmpty(*L1) && !IsEmpty(*L2)){
        First(*L3) = First(*L1);
        P = First(*L3);
        while(Next(P) != Nil){
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    else if(IsEmpty(*L1) && !IsEmpty(*L2)){
        First(*L3) = First(*L2);
    }
    else if(!IsEmpty(*L1) && IsEmpty(*L2)){
        First(*L3) = First(*L1);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */