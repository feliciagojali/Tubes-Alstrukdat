#include "../point/point.h"
#include "../boolean/boolean.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    //KAMUS LOKAL
    POINT P;
    //ALGORITMA
    Absis(P) = X;
    Ordinat(P) = Y;
        return (P);
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    //KAMUS LOKAL
    //ALGORITMA
    return((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
    //KAMUS LOKAL
    //ALGORITMA
    printf("(%d, %d)",Absis(P),Ordinat(P));
}