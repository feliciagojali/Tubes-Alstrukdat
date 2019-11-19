#include <stdio.h>
#include <stdlib.h>
#include "player.h"

int Max_Queue = 20;

Player initPlayer(int id){
    Player P;
    ID(P) = id;
    act(P) = 0;

    CreateEmptyList(&listB(P));
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

void PrintBangunan(Player P, listIdxBangunan L, TabInt T){
    addressB Y = First(L);
    int i = 1;
    while(Y != Nil) {
        if(Pemilik(Elmt(T,Info(Y))) == ID(P)){
            printf("%d. ",i);
            PrintJenisBangunan(Elmt(T,Info(Y)));
            TulisPOINT(Titik(Elmt(T,i)));
            printf(" %d",NPskn(Elmt(T,i)));
            printf(" lvl. %d \n",Lvl(Elmt(T,i)));
            i++;
        }
        Y = Next(Y);
    } 
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
    InsVLast(L, NbElmtT(*T));
}

int countTower(Player P){

    int jumlah = 0;
    addressB X = First(listB(P));
    while (X != NULL) {
        if (Jenis(Info(X)) == 'T') {
            jumlah +=1;
        }
    }
    return jumlah;
}
/* ---- BAGIAN SKILL ---- */
void printHeadSkills(Player *P) 
// prosedur mengeluarkan skill yang ada di Head dari queue
{
    printf("Skill Available : ");
    int x = Head(skill(*P));
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

void UseSkills(Player *P, boolean *extra, boolean *atkup)
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
        if (IsEmpty_Queue(skill(*P))) {
            printf("Kamu tidak memiliki skill apapun ! \n");
        } else {
            Del(&skill(*P), &X);
            if (X == 1)
            {
                InstantUpgrade();
            }
            else if (X == 2)
            {
                Shield();
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
                CriticalHit();
            }
            else if (X == 6)
            {
                InstantReinforcement();
            }
            else if (X == 7)
            {
                Barrage();
            }
        }
    }

void InputSkills(Player *P,int X)
//Prosedur yang digunakan untuk nambahin skill ke Queue
//Queue berisikan integer
//digunain di main program saat ada keadaan
//dimana membuat seorang pemain mendapatkan skills tertentu
//int yang terdefinisi adalah 2-7
    {
        if (X >=2 && X <= 6)
        {
            Add(&skill(*P),X);
            printf("Selamat Anda mendapatkan Skill ");
            if (X == 2)
            {
                printf("Shield\n");
            }
            else if (X == 3)
            {
                printf("ExtraTurn\n");
            }
            else if (X == 4)
            {
                printf("AttackUp\n");
            }
            else if (X == 5)
            {
                printf("CriticalHit\n");
            }
            else if (X == 6)
            {
                printf("InstantReinforcement\n");
            }
            else if (X == 7)
            {
                printf("Barrage\n");
            }
        }
    }

void InstantUpgrade(Player *P)
//Pada stackt dan Queue int 1
//Bangunan akan naik 1 level
//Skill hanya ada di daftar skill awal
//PARAMETER TERGNTUNG INPUT BANGUNAN
{
    addressB X = First(listB(*P));
    while (X != NULL){
        Lvl(Info(X)) += 1;
        X = Next(X);
    }
}

    
void Shield() //-->Bonus
//Pada stackt dan Queue int 2
//Seluruh bangunan akan memiliki pertahanan selama 2 turn
//jika digunakan 2 kali berturut turut, durasi tidak bertambah
//Namun nilai maksimum
{

}
void ExtraTurn()
//Pada stackt dan Queue int 3
//Ketika diaktifkan, setelah gilirannya berakhir
//pemain selanjutnya tetap pemain yang sama
//Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan
{

}
void AttackUp() //-->Bonus
//Pada stackt dan Queue int 4
//Pertahanan bangunan musuh tidak mempengaruhi penyerangan
//Skill didapatkan jika baru saja serang Tower lawan
//dan jumlah towernya menjadi 3
{

}
void CriticalHit() //-->Bonus
//Pada stackt dan Queue int 5 
//Penyerangan setelah pengaktifan skillini
//Jumlah pasukan pada bangunan yang melakukan serangan
//hanya berkurang 1/2 dari jumlah seharusnya
{

}

void InstantReinforcement()
//Pada stackt dan Queue int 6
//Seluruh bangunan pasukan +5
//Skill didapat jika bangunan yang dimiliki pemain
//seluruhnya telah level 4
//didapatkan diakhir gilirannya
//PARAMETERNYA TYPE BANGUNAN dan kepemilikannya

{
    /*Castle.Pasukan += 5 ;
    Tower.Pasukan += 5;
    Fort.Pasukan += 5;
    Village.Pasukan +=5;
    */
}
void Barrage()
//Pada stackt dan Queue int 7
//Jumlah pasukan musuh berkurang 10 di seluruh bangunannya
//Skill didapat jika lawan baru saja bertambah bangunannya
//menjadi 10 bangunan
{
    /* If (Castle.Pasukan >= 10 && Tower.Pasukan >= 10 && Fort.Pasukan >= 10 && Village.Pasukan >=10 )
    {
        Castle.Pasukan -= 10 ;
        Tower.Pasukan -= 10;
        Fort.Pasukan -= 10;
        Village.Pasukan -=10;
    }
    */
}