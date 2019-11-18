#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkata.c"
#include "boolean.h"
#include "point.c"
#include "listlinier.c"
#include "bangunan.c"
#include "mesinkar.c"
#include "player.c"

boolean isSuccess(int OwnArmy , int OwnEnemy) {
    if (OwnArmy < OwnEnemy) {
        return false;
    } else {
        return true;
    }
}

addressB getAdrsBangunan(List L,int num){
    int i = 1;
    addressB P = First(L);
    while(i<num){
        P = Next(P);
    }
    return P;
}
void assignBangunan(List L, int num, Bangunan *B){
    int i = 1;
    addressB P = First(L);
    while(i<num){
        P = Next(P);
    }
    Absis(Titik(*B)) = Absis(Titik(Info(P)));
    Ordinat(Titik(*B)) = Ordinat(Titik(Info(P)));
    Jenis(*B) = Jenis(Info(P));
    Pemilik(*B) = Pemilik(Info(P));
    NPskn(*B) = NPskn(Info(P));
    Lvl(*B) = Lvl(Info(P));
    NTbhPskn(*B) = NTbhPskn(Info(P));
    MxTmPskn(*B) = MxTmPskn(Info(P));
    Defense(*B) = Defense(Info(P));
    AwalPskn(*B) = AwalPskn(Info(P));

}
void ATTACK(Player *P1, Player *P2){
    int pasukan,numOwn,numEnemy,army;
    Bangunan X,Y;
    printf("Daftar bangunan: \n"); //buat procedure aja kali ya
    // ngeprint list bangunan yng ada menggunakan adt list
    PrintBangunan(*P1);
    scanf("Bangunan yang digunakan untuk menyerang: %d ",&numOwn);
    printf("Daftar bangunan yang dapat diserang: \n");
    // ngeprint list bangunan yang dapat diserang
    scanf("Bangunan yang diserang: %d",&numEnemy);
    scanf("Jumlah pasukan: %d",&army);
    assignBangunan(listB(*P1),numOwn,&X);
    assignBangunan(listB(*P2),numEnemy,&Y);
    if (Defense(Y)) {
        pasukan = (3*NPskn(X)/4);
    } else {
        pasukan = NPskn(X);
    }

    if (pasukan < NPskn(Y) ) {
        NPskn(Y) -= pasukan;
        printf("Bangunan gagal direbut \n");
    } else {
        DelBangunan(&listB(*P2),getAdrsBangunan(listB(*P2),numEnemy));
        InsVLast(&listB(*P1),Y);
        NPskn(Y) = pasukan - NPskn(Y);
        printf("Bangunan menjadi milikmu! \n");
    }
}

boolean isCommandSame(char *strg1, char *strg2)
{
    while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 )
    {
        strg1++;
        strg2++;
    }
 
    if(*strg1 == *strg2)
    {
        return true; // strings are identical
    }
 
    else
    {
        return *strg1 - *strg2;
    }
}
// bikin boolean cek ada yg bisa diserang atau ga
// buat fungsi mengurangi pasukan 
boolean isCanLevel (Bangunan A) {
    int x = MxTmPskn(A);
    if (NPskn(A) > x/2) {
        return true;
    } else {
        return false;
    }
}



void LEVEL_UP(Player *P){
    printf("LEVEL UP");
    int numBuilding;
    printf("Daftar bangunan: \n");
    PrintBangunan(*P);
    // // print list bangunan yang dimiliki
    printf("Bangunan yang akan di level up: ");
    scanf("%d", &numBuilding);
    Bangunan A; 
    assignBangunan(listB(*P),numBuilding,&A);


    if(isCanLevel(A)){
        Lvl(A) += 1;
    } else {
        printf("Jumlah pasukan ");
        PrintJenisBangunan(A);
        printf("kurang untuk level up");
    }
}

void SKILL(){
 // queue
    printf("SKILL");
}

void UNDO(){
    //stack 
    printf("UNDO");

}

void END_TURN(){
    //ganti pemain berikutnya
    printf("END_TURN");
}

void SAVE(){
    printf("Lokasi save file: ");
    //nama file
}

void MOVE(){
    printf("MOVE");
    // print list bangunan
    // pilih bangunan
    // daftar bangunan terdekat (graph)
    // pilih bangunan target
    // masukan jumlah pasukan
    // tulis status: (jumlah_pasukan) pasukan dari (jenis building) (koordinat) telah berpindah ke (jenis building) (koordinat)
}

void EXIT(){
    printf("EXIT");
}

void inputCommand(Player *P1, Player *P2){ // nanti ganti void INPUT_COMMAND()
    char str[50];
    int i =1;
    act(*P1) = 1;
    STARTKATA_KEYBOARD(str); 
    if (isCommandSame(str, "ATTACK")) {
        if(act(*P1) == 1){
            ATTACK(P1,P2);
        }
        else{
            ATTACK(P2,P1);
        }
    }
    else if(isCommandSame(str, "LEVEL_UP")){
        LEVEL_UP(P1);
    }
    else if(isCommandSame(str, "SKILL")){
        SKILL();
    }
    else if(isCommandSame(str, "UNDO")){
        UNDO();
    }
    else if(isCommandSame(str, "END_TURN")){
        END_TURN();
    }
    else if(isCommandSame(str, "SAVE")){
        SAVE();
    }
    else{
        printf("Check your spelling please...\n");
    }
}


