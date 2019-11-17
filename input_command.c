#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkata.c"
#include "boolean.h"
#include "point.c"
#include "listlinier.h"
#include "bangunan.c"
#include "mesinkar.c"

boolean isSuccess(int OwnArmy , int OwnEnemy) {
    if (OwnArmy < OwnEnemy) {
        return false;
    } else {
        return true;
    }
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

void PrintBangunan (List L){
    address Y = First(L);
    if (!IsEmptyList(L)) {
        int i = 1;
        while(Next(Y) != Nil) {
            printf("%d. ",i);
            PrintJenisBangunan(Info(Y));
            TulisPOINT(Titik(Info(Y)));
            printf(" %d",NPskn(Info(Y)));
            printf(" lvl. %d \n",Lvl(Info(Y)));
            i++;
            Y = Next(Y);

        } 
    }
}
address getAdrsBangunan(List L,int num){
    int i = 1;
    address P = First(L);
    while(i<num){
        P = Next(P);
    }
    return P;
}
void assignBangunan(List L, int num, Bangunan *B){
    int i = 1;
    address P = First(L);
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
void ATTACK(){
    int pasukan,numOwn,numEnemy,army;
    List L1,L2;
    Bangunan X,Y;
    printf("Daftar bangunan: \n"); //buat procedure aja kali ya
    // ngeprint list bangunan yng ada menggunakan adt list
    scanf("Bangunan yang digunakan untuk menyerang: %d ",&numOwn);
    printf("Daftar bangunan yang dapat diserang: \n");
    // ngeprint list bangunan yang dapat diserang
    scanf("Bangunan yang diserang: %d",&numEnemy);
    scanf("Jumlah pasukan: %d",&army);
    assignBangunan(L1,numOwn,&X);
    assignBangunan(L2,numEnemy,&Y);
    if (Defense(Y)) {
        pasukan = (3*NPskn(X)/4);
    } else {
        pasukan = NPskn(X);
    }

    if (pasukan < NPskn(Y) ) {
        NPskn(Y) -= pasukan;
        printf("Bangunan gagal direbut \n");
    } else {
        DelBangunan(&L2,getAdrsBangunan(L2,numEnemy));
        InsVLast(&L1,Y);
        NPskn(Y) = pasukan - NPskn(Y);
        printf("Bangunan menjadi milikmu! \n");
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



int attackPasukan(Bangunan A,Bangunan B){
    



}



void LEVEL_UP(List L){
    printf("LEVEL UP");
    int numBuilding;
    printf("Daftar bangunan: \n");
    PrintBangunan(L);
    // // print list bangunan yang dimiliki
    printf("Bangunan yang akan di level up: ");
    scanf("%d", &numBuilding);
    address P = getAdrsBangunan(L,numBuilding);
    Bangunan A; 
    assignBangunan(L,numBuilding,&A);


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

void inputCommand(){ // nanti ganti void INPUT_COMMAND()
    char str[50];
    STARTKATA_KEYBOARD(str); 
    if (isCommandSame(str, "ATTACK")) {
        ATTACK();
    }
    else if(isCommandSame(str, "LEVEL_UP")){
        LEVEL_UP();
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
        INPUT_COMMAND();
    }
}

void InsListPlayer(List *L, Bangunan A) {
    List L1,L2;

    // memasukan bangunan dengan pemilik 1 ke list A dan pemilik 2 ke list B
    if (Pemilik(A) == 1) {
        InsVFirst(&L1,A);
    } else {
        InsVFirst(&L2,A);
    }


}