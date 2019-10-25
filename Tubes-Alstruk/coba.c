#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "mesinkata.h"

boolean ATTACKCOMMAND(Kata Command) {
        Kata kataATTACK;
        int jumlah;
        boolean same = true;

        kataATTACK.TabKata[1] = 'A';
        kataATTACK.TabKata[2] = 'T';
        kataATTACK.TabKata[3] = 'T';
        kataATTACK.TabKata[4] = 'A';
        kataATTACK.TabKata[5] = 'C';
        kataATTACK.TabKata[6] = 'K';
        kataATTACK.Length = 6;
        
        jumlah = 1 ;
        if (Command.Length == kataATTACK.Length){
            while (same && jumlah <= kataATTACK.Length) {
                if (Command.TabKata[jumlah]!= kataATTACK.TabKata[jumlah]){
                    same = false;
                } else {
                    jumlah++;
                }
            }
            return same;
        } else {
            return false;
        }
       

    }
    

int main() {

    
    FILE *F;

    F = fopen("coba.txt","w+");
    char cmd[10];
    if(fgets(cmd,10,stdin)!= NULL) {
        fprintf(F,"%s.",cmd);

    };
    fclose(F);
    STARTKATA();
    if (ATTACKCOMMAND(CKata)) {
        printf("COMMAND BENAR");
    } else {
        printf("COMMAND SALAH");
    }







    return 0;
}