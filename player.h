#ifndef player_H
#define player_H


#include "listlinier.h"
#include "bangunan.h"
#include "queue.h"
#include "stackt.h"
#include "arraydin.h"

typedef List listIdxBangunan;
typedef struct {
    int active;
    int ID;
    List listBangunan;
    Queue skill;
} Player;

#define ID(P) (P).ID
#define listB(P) (P).listBangunan
#define act(P) (P).active // 1 jika turn dia dan 0 jika bukan turn dia
#define skill(P) (P).skill // skill yang dimiliki oleh player

Player initPlayer(int id);

void PrintJenisBangunan(Bangunan A);

void PrintBangunan(Player P, TabInt T);

void InsBangunan(Player P, Bangunan B, listIdxBangunan *L, TabInt *T);

boolean cariBangunan(Bangunan A,Player P,TabInt T);

int countTower (Player P, TabInt T);

void printHeadSkills(Player P);

void StartSkills(Player *P);
//Prosedur yang digunakan saat pertama kali game diaktifkan
//Membuat Queue berisi skill untuk pemain
//PARAMETERNYA NANTI TYPE BANGUNAN

void UseSkills(Player *P1, Player *P2, boolean *extra, boolean *atkup, boolean *critical, TabInt *T,int *isShield, Stack *S);
//Prosedur yang digunakan untuk menggunakan skills yang dimiliki pemain
//Ketika command skill di input
//Skill yang dapat digunakan adalah skill di head queue
//input berupa integer karena setiap skill dilambangkan dengan
//integer 1-7

void InputSkills(Player *P,int X);
//Prosedur yang digunakan untuk nambahin skill ke Queue
//Queue berisikan integer
//digunain di main program saat ada keadaan
//dimana membuat seorang pemain mendapatkan skills tertentu

void InstantUpgrade(Player P, TabInt *T);
//Pada stackt dan Queue int 1
//Bangunan akan naik 1 level
//Skill hanya ada di daftar skill awal

void Shield(Player P, TabInt *T, int *isShield); //-->Bonus
//Pada stackt dan Queue int 2
//Seluruh bangunan akan memiliki pertahanan selama 2 turn
//jika digunakan 2 kali berturut turut, durasi tidak bertambah
//Namun nilai maksimum

void ShieldDown(Player P, TabInt *T);
// me-non-aktifkan efek Shield

void InstantReinforcement(Player P, TabInt *T);
//Pada stackt dan Queue int 6
//Seluruh bangunan pasukan +5
//Skill didapat jika bangunan yang dimiliki pemain
//seluruhnya telah level 4
//didapatkan diakhir gilirannya

void Barrage(Player P1, Player P2,TabInt *T);
//Pada stackt dan Queue int 7
//Jumlah pasukan musuh berkurang 10 di seluruh bangunannya
//Skill didapat jika lawan baru saja bertambah bangunannya
//menjadi 10 bangunan

int CountBangunan(Player P, TabInt T);
//fungsi hitung banyaknya bangunan yang dimiliki oleh suatu player

boolean IsLevelFour(Player P, TabInt *T);
//boolean cek apakah seluruh bangunan pemain levelnya 4

void LevelUpBangunan (TabInt *T, int idDipilih);

#endif