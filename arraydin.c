#include <stdio.h>
#include "arraydin.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
    TI(*T) = (ElType *) malloc (sizeof(Bangunan) * (maxel+1));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

void Dealokasi(TabInt *T){
    free(TI(*T));
    MaxEl(*T) = 0;
    Neff(*T) = 0;
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
    return Neff(T);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T){
    return (MaxEl(T));
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
    return (IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T){
    return (Neff(T));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
    if((i <= MaxEl(T)) && (i >= IdxMin)){ 
        return true;
    }
    else{
        return false;
    }
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i){
    if((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T))){
        return true;
    }
    else{
        return false;
    }
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
    return (Neff(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
    return (Neff(T) == MaxEl(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
    IdxType i, N;
    do{
        scanf("%d", &N);
    } while((N < 0) || (N > MaxEl(*T)));
    Neff(*T) = N;
    for(i = IdxMin; i <= Neff(*T); i++){
        scanf("%d", &N);
        Elmt(*T, i) = N;
    }
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T){
    IdxType i;
    printf("[");
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        printf("%d", Elmt(T,i));
        if(i != GetLastIdx(T)){
            printf(",");
        }
    }
    printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
    IdxType i;
    TabInt arr;
    MakeEmpty(&arr,MaxEl(T1));
    if(plus){
        for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
            Elmt(arr,i) = Elmt(T1,i) + Elmt(T2 ,i);
        }
        Neff(arr) = Neff(T1);
    }
    else{
        for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
            Elmt(arr,i) = Elmt(T1,i) - Elmt(T2,i);
        }
        Neff(arr) = Neff(T1);
    }
    return arr;
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
    IdxType i;
    boolean answer;
    if(IsEmpty(T1) && IsEmpty(T2)){
        answer = true;
    }
    else if(Neff(T1) == Neff(T2)){
        i = GetFirstIdx(T1);
        while((Elmt(T1,i) == Elmt(T2,i)) && (i<GetLastIdx(T1))){
            i += 1;
        }
        if(Elmt(T1,i) == Elmt(T2,i)){
            answer = true;
        }
        else{
            answer = false;
        }
    }
    else{
        answer = false;
    }
    return answer;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
    if((IsEmpty(T))){
        return IdxUndef;
    }
    else{
        IdxType i = GetFirstIdx(T);
        while((Elmt(T,i) != X) && (i != GetLastIdx(T))){
            i += 1;
        }
        if(Elmt(T,i) == X){
            return i;
        }
        else{
            return IdxUndef ;
        }
    }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabInt T, ElType X){
    boolean Found = false;
    if(IsEmpty(T)){
        return Found;
    }
    else{
        IdxType i;
        i = GetFirstIdx(T);
        while(i <= GetLastIdx(T) && !Found){
            if(Elmt(T,i) == X){
                Found = true;
            }
            else{
                i += 1;
            }
        }
        return Found;
    }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
    IdxType i;
    *Min = Elmt(T, GetFirstIdx(T));
    *Max = Elmt(T, GetFirstIdx(T));
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(*Max < Elmt(T,i)){
            *Max = Elmt(T,i);
        }
        if(*Min > Elmt(T,i)){
            *Min = Elmt(T,i);
        }
    }
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
    IdxType i;
    MakeEmpty(Tout, MaxEl(Tin));
    for(i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++){
        Elmt(*Tout,i) = Elmt(Tin, i);
    }
    Neff(*Tout) = Neff(Tin);
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
ElType SumTab(TabInt T){
    if(IsEmpty(T)){
        return 0;
    }
    else{
        int sum = 0;
        int i;
        for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            sum += Elmt(T,i);
        }
        return sum;
    }
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX(TabInt T, ElType X){
    int i;
    int count = 0;
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Elmt(T,i) == X){
            count += 1;
        }
    }
    return count;
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap(TabInt T){
    int i;
    int count = 0;
    boolean answer = true;
    if(IsEmpty(T)){
        return !answer;
    }
    else{
        for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            if(Elmt(T,i) % 2 != 0){
                answer = false;
            }
        }
        return answer;
    }
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
    if(asc){
        IdxType i, j;
        ElType temp;
        if(!IsEmpty(*T)){
            for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
                temp = Elmt(*T,i);
                j = i - 1;
                while((j > 0) && (Elmt(*T,j) > temp)){
                    Elmt(*T,j+1) = Elmt(*T,j);
                    j -= 1;
                }
                Elmt(*T, j+1) = temp;
            }
        }
    }
    else{
        if(!IsEmpty(*T)){
            IdxType i, j, max;
            ElType temp;
            for(i = GetLastIdx(*T); i >= GetFirstIdx(*T); i--){
                max = GetFirstIdx(*T);
                for (j = GetFirstIdx(*T); j <= i; j++){
                    if(Elmt(*T,j) < Elmt(*T,max)){
                        max = j;
                    }
                }
                temp = Elmt(*T,i);
                Elmt(*T,i) = Elmt(*T,max);
                Elmt(*T,max) = temp;
            }
        }
    }
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
    Elmt(*T, GetLastIdx(*T)+1) = X;
    Neff(*T) += 1;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
    *X = Elmt(*T,GetLastIdx(*T));
    Neff(*T) -= 1;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
    int size = MaxEl(*T);
    TI(*T) = (ElType *) realloc (TI(*T), sizeof(int)*(size+num));
    MaxEl(*T) += num;
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num){
    int size = MaxEl(*T);
    TI(*T) = (ElType *) realloc (TI(*T), sizeof(int)*(size-num));
    MaxEl(*T) -= num;
    if(Neff(*T) > MaxEl(*T)){
		Neff(*T) = MaxEl(*T);
	}
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T){
    TI(*T) = (ElType *) realloc (TI(*T), (Neff(*T)+1)*sizeof(int));
    MaxEl(*T) = Neff(*T);
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
