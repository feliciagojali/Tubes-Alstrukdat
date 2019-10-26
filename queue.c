//Name File:    queue.c
//Tanggal:      26 oktober 2019
//Deskripsi:    Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik
//              Model Implementasi Versi III dengan circular buffer
//Tubes Alstrukdat

#include "boolean.h"
#include <stdlib.h>
#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmpty_Queue (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q)==0) && (Tail(Q)==0));
}

boolean IsFull_Queue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return(NBElmt_Queue(Q)==MaxEl(Q));
}
int NBElmt_Queue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    int hasil;
    if (IsEmpty_Queue(Q))
    {
        hasil = 0;
    }
    else if (Head(Q) > Tail(Q))
    {
        hasil = (MaxEl(Q) -(Head(Q) - Tail(Q)) +1);
    }
    else 
    {
        hasil =  (Tail(Q) - Head(Q) +1);
    }
    return hasil;
}
/* *** Kreator *** */
void CreateEmpty_Queue (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    //Alokasi
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));

    if ((*Q).T == NULL)
    {
        MaxEl(*Q) = 0;
        
    }
    else 
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }

}
/* *** Destruktor *** */
void DeAlokasi_Queue(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmpty_Queue(*Q))
    {
        Head(*Q) +=1;
        Tail(*Q) +=1;
        InfoTail(*Q) = X;
    }
    else if (Tail(*Q)== MaxEl(*Q))
    {
        Tail(*Q)=1;
        InfoTail(*Q)=X;
    }
    else
    {
        Tail(*Q)+=1;
        InfoTail(*Q)=X;
    }
}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    *X=InfoHead(*Q);
    if (Head(*Q)==Tail(*Q))
    {
        Head(*Q) =Nil;
        Tail(*Q) =Nil;
    }
    else if (Tail(*Q)== MaxEl(*Q))
    {
        Head(*Q)=1;
    }
    else
    {
        Head(*Q)+=1;
    }
}