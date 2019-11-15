#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkata.h"
#include "boolean.h"
#include "point.h"
#include "listlinier.h"

boolean isSuccess(int OwnArmy , int OwnEnemy) {
    if (OwnArmy < OwnEnemy) {
        return false;
    } else {
        return true;
    }
}


void PrintBangunan (List L){
    address Y = First(L);
    if (!IsEmpty(L)) {
        int i = 1;
        while(Y != Nil) {
            printf("%d. ",i);
            if (Jenis(Info(Y)) == 'C' ) {
                printf('Castle ');
            } else if (Jenis(Info(Y)) == 'F') {
                printf('Fort ');
            } else if (Jenis(Info(Y)) == 'T') {
                printf('Tower ');
            } else {
                printf('Village ');
            }
            TulisPOINT(Titik(Info(Y)));
            printf(" %d",NPskn(Info(Y)));
            printf(' lvl. %d',Lvl(Info(Y)));
            i++;
            Y = Next(Y);

        } 

void ATTACK(){
    int numOwn,numEnemy,army;
    int X,Y;
    printf("Daftar bangunan: \n"); //buat procedure aja kali ya
    print();
    // ngeprint list bangunan yng ada menggunakan adt list
    scanf("Bangunan yang digunakan untuk menyerang: %d ",&numOwn);
    printf("Daftar bangunan yang dapat diserang: \n");
    // ngeprint list bangunan yang dapat diserang
    scanf("Bangunan yang diserang: %d",&numEnemy);
    scanf("Jumlah pasukan: %d",&army);
    if (isSuccess(X,Y)) {
        printf("Bangunan gagal direbut \n");
    } else {
        printf("Bangunan menjadi milikmu! \n");
    }
}


// bikin boolean cek ada yg bisa diserang atau ga
// buat fungsi mengurangi pasukan 


void LEVEL_UP(){
    printf("LEVEL UP");
    // int numBuilding;
    // printf("Daftar bangunan: \n");
    // // print list bangunan yang dimiliki
    // printf("Bangunan yang akan di level up: ");
    // scanf("%d", &numBuilding);
    // if(isCanLevel(building, army)){
    //     // level building naik
    //     printf("Level (jenis bangunan)-mu meningkat menjadi level (level yang baru)");
    // }
    // else{
    //     printf("Jumlah pasukan (jenis bangunan) kurang untuk level up");
    // }
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

void print(){
    // kamus
    List L;
    Bangunan A,B,C;
    POINT P = MakePOINT(2,5);
    POINT P2 = MakePOINT(1,4);
    POINT P3 = MakePOINT(8,8);

    MakeBangunan(&A,P,'C',1);
    MakeBangunan(&B,P2,'V',1);
    MakeBangunan(&C,P3,'T',1);

    InsertVFirst(&L,A);
    InsertVFirst(&L,B);
    InsertVFirst(&L,C);

    PrintBangunan(L);

}