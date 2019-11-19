#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "boolean.h"

int Max_Queue = 10;

Player initPlayer(int id){
    Player P;
    ID(P) = id;
    act(P) = 0;
    CreateEmpty_Queue(&skill(P),Max_Queue);
    CreateEmptyList(&listB(P));
    StartSkills(&P);
    return P;  
}

void PrintJenisBangunan(Bangunan A) {
    if (Jenis(A) == 'C' ) {
        printf("Castle ");
    } else if (Jenis(A) == 'F') {
        printf("Fort ");
    } else if (Jenis(A) == 'T') {
        printf("Tower ");
    } else {
        printf("Village ");
    }
}

void PrintBangunan(Player P, TabInt T){
    addressB Y = First(listB(P));
    if (!IsEmptyList(listB(P))) {
        int i = 1;
        while(Y != Nil) {
            printf("%d. ",i);
            PrintJenisBangunan(Elmt(T,Info(Y)));
            TulisPOINT(Titik(Elmt(T,Info(Y))));
            printf(" %d",NPskn(Elmt(T,Info(Y))));
            printf(" lvl. %d \n",Lvl(Elmt(T,Info(Y))));
            i++;
            Y = Next(Y);
        } 
    }
}
boolean cariBangunan(Bangunan A,Player *P,TabInt T)
{
    addressB X = First(listB(*P));
    boolean ada = false;
    while (X!=NULL){
        if (EQ(Titik(Elmt(T,Info(X))),Titik(A))) {
            ada = true;
        }
        X = Next(X);
    }
    return ada;
}


void InsBangunan(Player *P, Bangunan B, listIdxBangunan *L, TabInt *T)
{
    if(ID(*P) == 1){
        Pemilik(B) = 1;
    }
    else{
        Pemilik(B) = 2;
    }
    AddAsLastEl(T, B);
    InsVLast(L, NbElmtTab(*T));
}

int countTower(Player P, TabInt T){

    int jumlah = 0;
    addressB X = First(listB(P));
    while (X != NULL) {
        if (Jenis(Elmt(T, Info(X))) == 'T') {
            jumlah +=1;
        }
        X = Next(X);
    }
    return jumlah;
}
/* ---- BAGIAN SKILL ---- */
void printHeadSkills(Player P) 
// prosedur mengeluarkan skill yang ada di Head dari queue
{
    printf("Skill Available : ");
    int x = InfoHead(skill(P));
    if (x == 1){
        printf("Instant Upgrade \n");
    } else if (x == 2) {
        printf("Shield \n");
    } else if (x == 3) {
        printf("Extra Turn \n");
    } else if (x == 4) {
        printf("Attack Up \n");
    } else if (x == 5) {
        printf("Critical Hit \n");
    } else if (x == 6) {
        printf("Instant Reinforcement \n");
    } else if (x == 7) {
        printf("Barrage \n");
    }
}
void StartSkills(Player *P)
//Prosedur yang digunakan saat pertama kali game diaktifkan
//Membuat Queue berisi skill untuk pemain
//F.S Queue terdefinisi, skill dimiliki instant upgrade
    {
        CreateEmpty_Queue(&skill(*P), Max_Queue);
        Add(&skill(*P),1);
    }

void UseSkills(Player *P, boolean *extra, boolean *atkup, boolean *critical, TabInt *T,int *isShield)
//Prosedur yang digunakan untuk menggunakan skills yang dimiliki pemain
// Q dan S telah terdefinisi sebelumnya
//Ketika command skill di input
//Skill yang dapat digunakan adalah skill di head queue
//input berupa integer karena setiap skill dilambangkan dengan
//integer 1-7
    {
        //Kamus Lokal
        int X;

        //Algoritma
        if (IsEmpty_Queue(skill(*P))) 
        {
            printf("Kamu tidak memiliki skill apapun ! \n");
        } 
        else 
        {
            Del(&skill(*P), &X);
            //Kosongin stactk
            if (X == 1)
            {
                InstantUpgrade(P,T);
            }
            else if (X == 2)
            {
                Shield(*P,T, isShield);
            }
            else if (X == 3)
            {
                (*extra) = true;
            }
            else if (X == 4)
            {
                (*atkup) = true;
            }
            else if (X == 5)
            {
                (*critical) = true;
            }
            else if (X == 6)
            {
                InstantReinforcement(P,T);
            }
            else if (X == 7)
            {
                Barrage(P,T);
            }
        }
    printf("daftar : \n");
    PrintBangunan(*P,*T);
    }

void InputSkills(Player *P,int X)
//Prosedur yang digunakan untuk nambahin skill ke Queue
//Queue berisikan integer
//digunain di main program saat ada keadaan
//dimana membuat seorang pemain mendapatkan skills tertentu
//int yang terdefinisi adalah 2-7
    {
        if (IsFull_Queue(skill(*P)))
        {
            printf("Skill gagal kamu dapatkan! Kamu masih memiliki 10 Skill!");
        }
        else if (X >=2 && X <= 6)
        {
            Add(&skill(*P),X);
            printf("Selamat P%d, Anda mendapatkan Skill ", ID(*P));
            if (X == 2)
            {
                printf("Shield\n");
            }
            else if (X == 3)
            {
                printf("Extra Turn\n");
            }
            else if (X == 4)
            {
                printf("Attack Up\n");
            }
            else if (X == 5)
            {
                printf("Critical Hit\n");
            }
            else if (X == 6)
            {
                printf("Instant Reinforcement\n");
            }
            else if (X == 7)
            {
                printf("Barrage\n");
            }
        }
    }

void InstantUpgrade(Player *P, TabInt *T)
//Pada stackt dan Queue int 1
//Bangunan akan naik 1 level
//Skill hanya ada di daftar skill awal
//PARAMETER TERGNTUNG INPUT BANGUNAN
{
    addressB X = First(listB(*P));
    while (X != NULL)
    {
        if (Lvl(Elmt(*T,Info(X))) != 4)
        {
            Lvl(Elmt(*T,Info(X))) += 1;
        }
        X = Next(X);
    }
}

    
void Shield(Player P, TabInt *T, int *isShield) //-->Bonus
//Pada stackt dan Queue int 2
//Seluruh bangunan akan memiliki pertahanan selama 2 turn
//jika digunakan 2 kali berturut turut, durasi tidak bertambah
//Namun nilai maksimum
{
    addressB B = First(listB(P));

    while(B != Nil){
        Defense(Elmt(*T,Info(B))) = true;
        B = Next(B);
    }
    (*isShield) = 2;
    printf("Your buildings' defenses have been updated!\n");
}

void ShieldDown(Player P, TabInt *T)
// untuk mengembalikan bangunan seperti semula setelah efek shield habis
{
    addressB B = First(listB(P));

    while(B != Nil){
        if(Jenis(Elmt(*T, Info(B))) == 'C' || Jenis(Elmt(*T, Info(B))) == 'V' || (Jenis(Elmt(*T, Info(B))) == 'F' && Lvl(Elmt(*T, Info(B))) <= 2)){
            Defense(Elmt(*T, Info(B))) = false;
        }
        B = Next(B);
    }
    printf("The effect of 'shield' ran out! Your buildings' defenses are back to normal.\n");
}



void InstantReinforcement(Player *P, TabInt *T)
//Pada stackt dan Queue int 6
//Seluruh bangunan pasukan +5
//Skill didapat jika bangunan yang dimiliki pemain
//seluruhnya telah level 4
//didapatkan diakhir gilirannya

{
    addressB X;
    
    X = First(listB(*P));
    while (X != NULL)
    {
        NPskn(Elmt(*T,Info(X))) += 5;
        X = Next(X);
    }
}
void Barrage(Player *P, TabInt *T)
//Pada stackt dan Queue int 7
//Jumlah pasukan musuh berkurang 10 di seluruh bangunannya
//Skill didapat jika lawan baru saja bertambah bangunannya
//menjadi 10 bangunan
{
    addressB X;
    
    X = First(listB(*P));
    while (X != NULL)
    {
        NPskn(Elmt(*T,Info(X))) -= 10;
        X = Next(X);
    }
}

int CountBangunan(Player *P, TabInt *T)
//fungsi hitung banyaknya bangunan yang dimiliki oleh suatu player
{
    addressB X;
    int Count;
    
    Count =0;
    X = First(listB(*P));
    while (X != NULL)
    {
        Count +=1;
        X = Next(X);
    }
    return Count;
}

boolean IsLevelFour(Player *P, TabInt *T)
//boolean cek apakah seluruh bangunan pemain levelnya 4
{
    addressB X;
    boolean LevelFour;
    
    LevelFour = true;
    X = First(listB(*P));
    while ((X != NULL) && (LevelFour))
    {
        if (Lvl(Elmt(*T,Info(X))) != 4)
        {
            LevelFour = false;
        }
        X = Next(X);
    }
    return LevelFour;
}
