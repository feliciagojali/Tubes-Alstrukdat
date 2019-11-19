#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkata.h"
#include "boolean.h"
#include "point.h"
#include "listlinier.h"
#include "bangunan.h"
#include "mesinkar.h"
#include "player.h"
#include "arraydin.h"

boolean isSuccess(int OwnArmy , int OwnEnemy) {
    if (OwnArmy < OwnEnemy) {
        return false;
    } else {
        return true;
    }
}

// addressB getAdrsBangunan(List L,int num){
//     int i = 1;
//     addressB P = First(L);
//     while(i<num){
//         P = Next(P);
//     }
//     return P;
// }

// Bangunan getBangunan (List L, int num){
//     addressB P = getAdrsBangunan(L,num);
//     return(Info(P));
// }

// void assignBangunan(List L, int num, Bangunan *B){
//     int i = 1;
//     addressB P = First(L);
//     while(i<num){
//         P = Next(P);
//     }
//     Absis(Titik(*B)) = Absis(Titik(Info(P)));
//     Ordinat(Titik(*B)) = Ordinat(Titik(Info(P)));
//     Jenis(*B) = Jenis(Info(P));
//     Pemilik(*B) = Pemilik(Info(P));
//     NPskn(*B) = NPskn(Info(P));
//     Lvl(*B) = Lvl(Info(P));
//     NTbhPskn(*B) = NTbhPskn(Info(P));
//     MxTmPskn(*B) = MxTmPskn(Info(P));
//     Defense(*B) = Defense(Info(P));
//     AwalPskn(*B) = AwalPskn(Info(P));

// }

void ATTACK(TabInt *TabBangunan, Player *P1, Player *P2, boolean *atkup, boolean *critical){
    int pasukan,numOwn,numEnemy,army;
    printf("Daftar bangunan: \n"); //buat procedure aja kali ya
    // ngeprint list bangunan yng ada menggunakan adt list
    PrintBangunan(*P1, *TabBangunan);
    printf("Bangunan yang digunakan untuk menyerang: "); scanf("%d",&numOwn);
    printf("Daftar bangunan yang dapat diserang: \n");
    PrintBangunan(*P2, *TabBangunan);
    printf("Bangunan yang diserang: "); scanf("%d",&numEnemy);
    printf("Jumlah pasukan: "); scanf("%d",&army);
    int i = 1;
    addressB X = First(listB(*P1));
    addressB Y = First(listB(*P2));
    while(i<numOwn){
        X = Next(X);
        i++;
    }
    i = 1;
    while(i<numEnemy){
        Y = Next(Y);
        i++;
    }
    
    if ((Jenis(Elmt(*TabBangunan, Info(Y))) == 'F') && (cariBangunan(Elmt(*TabBangunan,Info(Y)),P2,*TabBangunan))){
            printf("%c",Jenis(Elmt(*TabBangunan, Info(Y))));

         InputSkills(P2,3);   
    }
    NPskn(Elmt(*TabBangunan,Info(X))) -= army;

    if (!(*atkup)) { 
        if (Defense(Elmt(*TabBangunan,Info(Y)))) {
            army = 3*army/4;
        } 
    } 

    if (army < NPskn(Elmt(*TabBangunan,Info(Y)))) {
        printf("Bangunan gagal direbut\n");
        NPskn(Elmt(*TabBangunan,Info(Y))) -= army;
    } else {
        printf("Bangunan menjadi milikmu!\n");
        NPskn(Elmt(*TabBangunan,Info(Y))) = army - NPskn(Elmt(*TabBangunan,Info(Y)));
        int x = Info(Y);
        if (cariBangunan(Elmt(*TabBangunan,Info(Y)),P2,*TabBangunan)) {
            DelP(&listB(*P2),x);
        }
        InsVFirst(&listB(*P1),x);

    }
    // if ((Jenis(Elmt(*TabBangunan, Info(Y))) == 'T') && (Pemilik(Elmt(*TabBangunan,Info(Y))) != 0) && (countTower(*P1,*TabBangunan) == 3)) {
    //     InputSkills(P1,4);
    // }
    printf("daftar : \n");
    PrintBangunan(*P1,*TabBangunan);
    printf("daftar : \n");

    PrintBangunan(*P2,*TabBangunan);
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
        return false;
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

void changeLevel(Player *P, TabInt *T, addressB numInList){
    Lvl(Elmt(*T,Info(numInList))) += 1;
    NPskn(Elmt(*T,Info(numInList))) -= (MxTmPskn(Elmt(*T,Info(numInList)))/2);
}

void LEVEL_UP(Player *P, TabInt *T){
    int numBuilding;
    
    printf("Daftar bangunan: \n");

    PrintBangunan(*P, *T);
    // // print list bangunan yang dimiliki
    printf("Bangunan yang akan di level up: ");
    scanf("%d", &numBuilding); 
    addressB NumInList = First(listB(*P));
    int i = 1;
    while(i < numBuilding){
        NumInList = Next(NumInList);
        i ++;
    }
    // assignBangunan(listB(*P),numBuilding,&A);

    if(!isCanLevel(Elmt(*T, Info(NumInList)))){
        printf("Jumlah pasukan ");
        PrintJenisBangunan(Elmt(*T, Info(NumInList)));
        printf("kurang untuk level up");
        
    } else {
        Lvl(Elmt(*T,Info(NumInList))) += 1;
        NPskn(Elmt(*T,Info(NumInList))) -= (MxTmPskn(Elmt(*T,Info(NumInList)))/2);
        printf("Your building has been updated!\n");
        PrintBangunan(*P, *T);
        if(Lvl(Elmt(*T,Info(NumInList))) == 2){
			if(Jenis(Elmt(*T,Info(NumInList)))=='C'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),15,60,false);
			}
			else if(Jenis(Elmt(*T,Info(NumInList)))=='T'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),10,30,true);
			}
			else if(Jenis(Elmt(*T,Info(NumInList)))=='F'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),20,40,false);
			}
			else if(Jenis(Elmt(*T,Info(NumInList)))=='V'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),10,30,false);
			}
		}
		else if(Lvl(Elmt(*T,Info(NumInList))) == 3){
			if(Jenis(Elmt(*T,Info(NumInList))) =='C'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),20,80,false);
			}
			else if(Jenis(Elmt(*T,Info(NumInList)))=='T'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),20,40,true);
			}
			else if(Jenis(Elmt(*T,Info(NumInList)))=='F'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),30,60,true);
			}
			else if(Jenis(Elmt(*T,Info(NumInList)))=='V'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),15,40,false);
			}
		}
		else if(Lvl(Elmt(*T,Info(NumInList))) == 4){
			if(Jenis(Elmt(*T,Info(NumInList)))=='C'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),25,100,false);
			}
			else if(Jenis(Elmt(*T,Info(NumInList)))=='T'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),30,50,true);
			}
			else if(Jenis(Elmt(*T,Info(NumInList)))=='F'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),40,80,true);
			}
			else if(Jenis(Elmt(*T,Info(NumInList)))=='V'){
				UbahBangunan(&Elmt(*T,Info(NumInList)),20,50,false);
			}
		}
	}

}

// void SKILL(){
//  // queue
//     printf("SKILL");
// }

// void UNDO(){
//     //stack 
//     printf("UNDO");

// }

// void END_TURN(Player *P1, Player *P2,boolean *extra, boolean *atkup){
//     //ganti pemain berikutnya
//     if (!(*extra)) {
//         if(act(*P1) == 1){
//             act(*P1) = 0;
//             act(*P2) = 1;
//             printf("Sekarang giliran player 2 \n");
//         }
//         else{
//             act(*P1) = 1;
//             act(*P2) = 0;
//             printf("Sekarang giliran player 1 \n");
//         }
//     } else {
//         printf("Wah! Giliran kamu lagi! \n");
//         (*extra) = false;
//     }
//     (*atkup) = false;
// }
// void SAVE(){
//     printf("Lokasi save file: ");
//     //nama file
// }

void MOVE(Player P, TabInt *T){
    printf("Daftar Bangunan: \n");
    PrintBangunan(P, *T);

    int num,numrcv,army;

    printf("Pilih Bangunan : "); scanf("%d",&num);
    printf("Daftar Bangunan terdekat : \n"); // print bangunan terdekat
    PrintBangunan(P, *T);
    printf("Bangungan yang menerima : "); scanf("%d",&numrcv);
    printf("Jumlah Pasukan : "); scanf("%d",&army);
    
    addressB X = First(listB(P));
    addressB Y = First(listB(P));

    int i =1;

    while(i<num){
        X = Next(X);
        i++;
    }

    i = 1;
    while(i<numrcv){
        Y = Next(Y);
        i++;
    }

    if (NPskn(Elmt(*T, Info(X))) < army) {
        printf("Jumlah pasukan tidak cukup! \n");
    } else {
        if (army + NPskn(Elmt(*T, Info(Y))) <= MxTmPskn(Elmt(*T, Info(Y)))) {
            NPskn(Elmt(*T, Info(Y))) = MxTmPskn(Elmt(*T, Info(Y)));
            NPskn(Elmt(*T, Info(Y))) += army;
            NPskn(Elmt(*T, Info(X))) -= army;
            printf("%d pasukan dari "); PrintJenisBangunan(Elmt(*T, Info(X)));
            TulisPOINT(Titik(Elmt(*T, Info(X))));
            printf(" telah berpindah ke ");
            PrintJenisBangunan(Elmt(*T, Info(Y)));
            TulisPOINT(Titik(Elmt(*T, Info(Y))));
            printf("\n");
        } else{
            printf("Building hanya mampu menampung %d pasukan.\n", MxTmPskn(Elmt(*T, Info(Y))));
            printf("Perpindahan GAGAL!\n");
        }
    }
    // pilih bangunan target
    // masukan jumlah pasukan
    // tulis status: (jumlah_pasukan) pasukan dari (jenis building) (koordinat) telah berpindah ke (jenis building) (koordinat)
}

// void EXIT(){
//     exit(0);
// }

// boolean GAME_OVER(Player P1, Player P2){
//     return ((IsEmptyList(listB(P1))) || (IsEmptyList(listB(P2))));
// }

// void inputCommand(Player *P1, Player *P2){ // nanti ganti void INPUT_COMMAND()

//     boolean move = true;
//     boolean extra = false;
//     boolean atkup,critical = false;
//     char str[50];
//     StartSkills(P1);
//     StartSkills(P2);
//     int i =1;
//     act(*P1) = 1;
//     while(!GAME_OVER(*P1,*P2)){
//         while(act(*P1) == 1){
//             STARTKATA_KEYBOARD(str); 
//             if (isCommandSame(str, "ATTACK")) {
//                 ATTACK(P1,P2,&atkup,&critical);
//             }
//             else if(isCommandSame(str, "LEVEL_UP")){
//                 LEVEL_UP(P1);
//             }
//             else if(isCommandSame(str, "SKILL")){
//                 UseSkills(P1,&extra,&atkup);
//             }
//             else if(isCommandSame(str, "UNDO")){
//                 UNDO();
//             }
//             else if(isCommandSame(str, "END_TURN")){
//                 END_TURN(P1, P2, &extra, &atkup);
//             }
//             else if(isCommandSame(str, "SAVE")){
//                 SAVE();
//             }
//             else if(isCommandSame(str, "EXIT")){
//                 EXIT();
//             }
//             else if(isCommandSame(str, "MOVE")){
//                 if(move){
//                     MOVE(P1,P2);
//                     move = false;
//                 } else {
//                     printf("Kau sudah melakukan MOVE untuk giliran ini! \n");
//                     printf("Tunggu giliran berikutnya!\n");
//                 }
//             }
//             else{
//                 printf("Check your spelling please...\n");
//             }
//         }
//         while(act(*P2) == 1){            

//             STARTKATA_KEYBOARD(str); 
//             if (isCommandSame(str, "ATTACK")) {
//                 ATTACK(P2,P1,&atkup);
//             }
//             else if(isCommandSame(str, "LEVEL_UP")){
//                 LEVEL_UP(P2);
//             }
//             else if(isCommandSame(str, "SKILL")){
//                 UseSkills(P2,&extra,&atkup);
//             }
//             else if(isCommandSame(str, "UNDO")){
//                 UNDO();
//             }
//             else if(isCommandSame(str, "END_TURN")){
//                 END_TURN(P1, P2,&extra, &atkup);
//             }
//             else if(isCommandSame(str, "EXIT")){
//                 EXIT();
//             }
//             else if(isCommandSame(str, "SAVE")){
//                 SAVE();
//             }else if(isCommandSame(str, "MOVE")){
//                 if(move){
//                     MOVE(P1,P2);
//                     move = false;
//                 } else {
//                     printf("Kau sudah melakukan MOVE untuk giliran ini! \n");
//                     printf("Tunggu giliran berikutnya!\n");
//                 }
//             }
//             else{
//                 printf("Check your spelling please...\n");
//             }
//         }
//     }
// }


