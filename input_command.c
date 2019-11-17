#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkata.c"
#include "boolean.h"
#include "point.c"
#include "listlinier.c"
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
    if (Jenis(Info(Y)) == 'C' ) {
        printf("Castle ");
    } else if (Jenis(Info(Y)) == 'F') {
        printf("Fort ");
    } else if (Jenis(Info(Y)) == 'T') {
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

    X = getBangunan(L1,numOwn);
    Y = getBangunan(L2,numEnemy);
    if (Defense(Y)) {
        pasukan = (3*NPskn(X)/4);
    } else {
        pasukan = NPskn(X);
    }

    if (pasukan < NPskn(Y) ) {
        NPskn(Y) -= pasukan;
        printf("Bangunan gagal direbut \n");
    } else {
        Del
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

boolean canHijack(Bangunan A, Bangunan B) {
    if Defense(B) {

    }
    
}

int attackPasukan(Bangunan A,Bangunan B){
    



}
Bangunan getBangunan(List L,int num){
    int i = 1;
    address P = First(L);
    while(i < num){
        P = Next(P);
    }
    return (Info(P));

}
void LEVEL_UP(List L){
    printf("LEVEL UP");
    int numBuilding;
    printf("Daftar bangunan: \n");
    PrintBangunan(L);
    // // print list bangunan yang dimiliki
    printf("Bangunan yang akan di level up: ");
    scanf("%d", &numBuilding);
    A = getBangunan(L,numBuilding);

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
    char cmd[10];
    boolean is = true;
    do { gets(cmd);
    
        if (strcmp(cmd, "ATTACK") == 0) {
            ATTACK();
            is = true;
        }
        else if(strcmp(cmd, "LEVEL_UP") == 0){
            LEVEL_UP();
            is = true;
        }
        else if(strcmp(cmd, "SKILL") == 0){
            SKILL();
            is = true;
        }
        else if(strcmp(cmd, "UNDO") == 0){
            UNDO();
            is = true;
        }
        else if(strcmp(cmd, "END_TURN") == 0){
            END_TURN();
            is = true;
        }
        else if(strcmp(cmd, "SAVE") == 0){
            SAVE();
            is = true;
        }

        else{
            printf("Check your spelling please\n");
            is = false;
        }
    }while (!is);

}

void InsListPlayer(List *L, Bangunan A) {

    // memasukan bangunan dengan pemilik 1 ke list A dan pemilik 2 ke list B
    if (Pemilik(A) == 1) {
        InsVFirst(L,A);
    } else {
        InsVFirst(L,B);
    }


}

int main(){
    // kamus
    List L;
    Bangunan A,B,C;
    POINT P = MakePOINT(2,5);
    POINT P2 = MakePOINT(1,4);
    POINT P3 = MakePOINT(8,8);

    MakeBangunan(&A,P,'C',1);
    MakeBangunan(&B,P2,'V',1);
    MakeBangunan(&C,P3,'T',1);

    InsVFirst(&L,A);
    InsVFirst(&L,B);
    InsVFirst(&L,C);

    PrintBangunan(L);
return 0;
}