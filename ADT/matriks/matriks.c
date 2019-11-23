
#include "../matriks/matriks.h"
#include "../pcolor/pcolor.h"


void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    (*M).NBrsEff=NB;
    (*M).NKolEff=NK;
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEff(M);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEff(M);
}
/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    for(int i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn); i+=1){
        for(int j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn); j+=1){

            Elmt_Mat(*MHsl, i, j)=Elmt_Mat(MIn, i, j);
        }
    }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    for(int i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i+=1){
        for(int j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j+=1){
            if(Owner(M, i, j) == 0){
                printf("%c", Cell(M, i, j));
            } else if(Owner(M, i, j) == 1){
                print_red(Cell(M, i, j));
            } else {
                print_green(Cell(M, i, j));
            }
        }
        printf("\n");
    }
}