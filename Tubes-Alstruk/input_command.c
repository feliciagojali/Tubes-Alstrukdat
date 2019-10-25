#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "mesinkata.h"

boolean cek(Kata kata, Kata Command){
    int jumlah;
    boolean same = true;

    jumlah = 1 ;
    if (Command.Length == kata.Length){
        while (same && jumlah <= kata.Length) {
            if (Command.TabKata[jumlah]!= kata.TabKata[jumlah]){
                same = false;
            } else {
                jumlah++;
            }
        }
    }
    else {
        same = false;
    }
    // printf("%d\n", same);
    return same;
}

boolean ATTACKCOMMAND(Kata Command) {
        Kata kataATTACK;

        kataATTACK.TabKata[1] = 'A';
        kataATTACK.TabKata[2] = 'T';
        kataATTACK.TabKata[3] = 'T';
        kataATTACK.TabKata[4] = 'A';
        kataATTACK.TabKata[5] = 'C';
        kataATTACK.TabKata[6] = 'K';
        kataATTACK.Length = 6;
        // printf("%d\n", cek(kataATTACK, Command));
        return (cek(kataATTACK, Command));
    }

boolean LEVEL_UPCOMMAND(Kata Command){
    Kata kataLEVEL_UP;
    
    kataLEVEL_UP.TabKata[1] = 'L';
    kataLEVEL_UP.TabKata[2] = 'E';
    kataLEVEL_UP.TabKata[3] = 'V';
    kataLEVEL_UP.TabKata[4] = 'E';
    kataLEVEL_UP.TabKata[5] = 'L';
    kataLEVEL_UP.TabKata[6] = '_';
    kataLEVEL_UP.TabKata[7] = 'U';
    kataLEVEL_UP.TabKata[8] = 'P';
    kataLEVEL_UP.Length = 8;

    return cek(kataLEVEL_UP, Command);
}
    
boolean SKILLCOMMAND(Kata Command){
    Kata kataSKILL;
    
    kataSKILL.TabKata[1] = 'S';
    kataSKILL.TabKata[2] = 'K';
    kataSKILL.TabKata[3] = 'I';
    kataSKILL.TabKata[4] = 'L';
    kataSKILL.TabKata[5] = 'L';
    kataSKILL.Length = 5;

    return cek(kataSKILL, Command);
}

boolean UNDOCOMMAND(Kata Command){
    Kata kataUNDO;
    
    kataUNDO.TabKata[1] = 'U';
    kataUNDO.TabKata[2] = 'N';
    kataUNDO.TabKata[3] = 'D';
    kataUNDO.TabKata[4] = 'O';
    kataUNDO.Length = 4;

    return cek(kataUNDO, Command);
}

boolean END_TURNCOMMAND(Kata Command){
    Kata kataEND_TURN;
    
    kataEND_TURN.TabKata[1] = 'E';
    kataEND_TURN.TabKata[2] = 'N';
    kataEND_TURN.TabKata[3] = 'D';
    kataEND_TURN.TabKata[4] = '_';
    kataEND_TURN.TabKata[5] = 'T';
    kataEND_TURN.TabKata[6] = 'U';
    kataEND_TURN.TabKata[7] = 'R';
    kataEND_TURN.TabKata[8] = 'N';
    kataEND_TURN.Length = 8;

    return cek(kataEND_TURN, Command);
}

boolean SAVECOMMAND(Kata Command){
    Kata kataSAVE;
    
    kataSAVE.TabKata[1] = 'S';
    kataSAVE.TabKata[2] = 'A';
    kataSAVE.TabKata[3] = 'V';
    kataSAVE.TabKata[4] = 'E';
    kataSAVE.Length = 4;

    return cek(kataSAVE, Command);
}

boolean MOVECOMMAND(Kata Command){
    Kata kataMOVE;

    kataMOVE.TabKata[1] = 'M';
    kataMOVE.TabKata[2] = 'O';
    kataMOVE.TabKata[3] = 'V';
    kataMOVE.TabKata[4] = 'E';
    kataMOVE.Length = 4;

    return cek(kataMOVE, Command);
}

boolean EXITCOMMAND(Kata Command){
    Kata kataEXIT;

    kataEXIT.TabKata[1] = 'E';
    kataEXIT.TabKata[2] = 'X';
    kataEXIT.TabKata[3] = 'I';
    kataEXIT.TabKata[4] = 'T';
    kataEXIT.Length = 4;

    return cek(kataEXIT, Command);
}

void ATTACK(){
    int numOwn,numEnemy,army;
    int X,Y;
    printf("Daftar bangunan: \n"); //buat procedure aja kali ya
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

boolean isSuccess(int OwnArmy , int OwnEnemy) {
    if (OwnArmy < OwnEnemy) {
        return false;
    } else {
        return true;
    }
}
// bikin boolean cek ada yg bisa diserang atau ga
// buat fungsi mengurangi pasukan 


void LEVEL_UP(){
    int numBuilding;
    printf("Daftar bangunan: \n");
    // print list bangunan yang dimiliki
    printf("Bangunan yang akan di level up: ");
    scanf("%d", &numBuilding);
    if(isCanLevel(building, army)){
        // level building naik
        printf("Level (jenis bangunan)-mu meningkat menjadi level (level yang baru)");
    }
    else{
        printf("Jumlah pasukan (jenis bangunan) kurang untuk level up");
    }
}

void SKILL(){
 // queue
}

void UNDO(){
    //stack

}

void END_TURN(){
    //ganti pemain berikutnya
}

void SAVE(){
    printf("Lokasi save file: ");
    //nama file
}

void MOVE(){
    // print list bangunan
    // pilih bangunan
    // daftar bangunan terdekat (graph)
    // pilih bangunan target
    // masukan jumlah pasukan
    // tulis status: (jumlah_pasukan) pasukan dari (jenis building) (koordinat) telah berpindah ke (jenis building) (koordinat)
}

void EXIT(){
    
}

int main(){
    FILE *fp = fopen("command.txt", "w+");
    char cmd[10];
    gets(cmd);
    fprintf(fp,"%s.", cmd);
    fclose(fp);
    STARTKATA();
    if (ATTACKCOMMAND(CKata)) {
        printf("U choose ATTACK");
        // 
    }
    else if(LEVEL_UPCOMMAND(CKata)){
        printf("U choose LEVEL_UP");
    }
    else if(SKILLCOMMAND(CKata)){
        printf("U choose SKILL");
    }
    else if(UNDOCOMMAND(CKata)){
        printf("U choose UNDO");
    }
    else if(END_TURNCOMMAND(CKata)){
        printf("U choose END_TURN");
    }
    else if(SAVECOMMAND(CKata)){
        printf("U choose SAVE");
    }
    else{
        printf("Check your spelling please");
    }

    return 0;
}