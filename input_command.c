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
#include "graph.h"

boolean isSuccess(int OwnArmy , int OwnEnemy) {
    if (OwnArmy < OwnEnemy) {
        return false;
    } else {
        return true;
    }
}

// addressB getAdrsBangunan(List L,int num){
//     int i = 1;F
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

void PrintBG(TabInt T){
    for(int i = 1; i <= GetLastIdx(T); i++){
        printf("%d. ",i);
        PrintJenisBangunan(Elmt(T, i));
        TulisPOINT(Titik(Elmt(T, i)));
        printf(" %d",NPskn(Elmt(T, i)));
        printf(" lvl. %d \n",Lvl(Elmt(T,i)));
    }
}

void ATTACK(TabInt *TabBangunan, Player *P1, Player *P2, boolean *atkup, boolean *critical, Graph G, Stack *undo){
    int pasukan,numOwn,numEnemy,army;
    TabInt myBangunan, enemyBangunan;
    int arr[50];

    // MakeEmpty(&myBangunan, MaxEl(*TabBangunan));
    MakeEmpty(&enemyBangunan, MaxEl(*TabBangunan));
    // int j = 1;
    // for(int i = GetFirstIdx(*TabBangunan); i <= GetLastIdx(*TabBangunan); i++){
    //     if(Pemilik(Elmt(*TabBangunan,i)) == ID(*P1)){
    //         AddAsLastEl(&myBangunan, Elmt(*TabBangunan, i));
    //         arr[j] = i;
    //         j++;
    //     }
    // }

    boolean claim = false;
    printf("Daftar bangunan: \n"); //buat procedure aja kali ya
    // ngeprint list bangunan yng ada menggunakan adt list
    PrintBangunan(*P1,*TabBangunan);
    // PrintBG(myBangunan);
    printf("Bangunan yang digunakan untuk menyerang: "); scanf("%d",&numOwn);
    while(numOwn > NbElmt(listB(*P1)) || numOwn < 1){
        printf("Invalid! Check again please. \n");
        printf("Bangunan yang digunakan untuk menyerang: "); scanf("%d",&numOwn);
    }
    addressB X = First(listB(*P1));
    int i = 1;
    while (X != Nil){
        if(i == numOwn){
            break;
        }
        X = Next(X);
        i++;
    }
    printf("num own ketemu\n");
    if (X != Nil) {
        printf("X!=Nil\n");
        int idDipilih = Info(X);
        if (hasAtk(Elmt(*TabBangunan,idDipilih)) == false) {
            printf("hasatk = false\n");
            adrNode t = SearchNode(G, idDipilih);
            printf("t : %d\n", t);
            int j = 1;
            if(t != NilGraph){
                adrSuccNode w = Adj(t);
                while(w != NilGraph){
                    int q = Id(Origin(w));
                    if(Pemilik(Elmt(*TabBangunan, q)) != ID(*P1)){
                        AddAsLastEl(&enemyBangunan, Elmt(*TabBangunan, q));
                        arr[j] = q;
                        j++;
                    }
                    w = NextG(w);
                }
                printf("j : %d\n", j);
                if(j == 1){
                    printf("Tidak ada bangunan yang berdekatan.\n");
                } else {
                    printf("Daftar bangunan yang dapat diserang: \n");
                    PrintBG(enemyBangunan);
                    printf("Bangunan yang diserang: "); scanf("%d",&numEnemy);

                    while (numEnemy > j-1 || numEnemy < 0) {
                        printf("Pilihlah bangunan yang benar : ");
                        scanf("%d",&numEnemy);
                    }
                    int idDiserang = arr[numEnemy];
                    printf("Jumlah pasukan: "); scanf("%d",&army);
                    while (army > NPskn(Elmt(*TabBangunan,idDipilih)) || army < 0) {
                        printf("Masukkan jumlah pasukan dengan benar!\n");
                        printf("Jumlah pasukan: "); scanf("%d",&army);
                    }
                  
                    if ((Jenis(Elmt(*TabBangunan, idDiserang)) == 'F') && (Pemilik(Elmt(*TabBangunan,idDipilih)) != 0)){
                        InputSkills(P2,3);   
                    }
                    NPskn(Elmt(*TabBangunan,idDipilih)) -= army;

                    if (!(*atkup) && !(*critical)) { 
                        if (Defense(Elmt(*TabBangunan,idDiserang))) {
                            army = 3*army/4;
                        } 
                    } 

                    if (*critical) {
                        army = 2*army;
                    }
                    int x = idDiserang;

                    if (army < NPskn(Elmt(*TabBangunan,idDiserang))) {
                        printf("Bangunan gagal direbut\n");
                        NPskn(Elmt(*TabBangunan,x)) -= army;
                    } else {
                        printf("Bangunan menjadi milikmu!\n");
                        NPskn(Elmt(*TabBangunan,x)) = army - NPskn(Elmt(*TabBangunan,x));
                        Pemilik(Elmt(*TabBangunan, x)) = ID(*P1);
                        DelP(&listB(*P2),x);
                        InsVLast(&listB(*P1),x);
                        claim = true;
                        //Dapet skill barrage
                        if (CountBangunan(*P1, *TabBangunan) == 10)
                        {
                            InputSkills(P2, 7);
                        }
                        //Lawan Dapet skill shield
                        if (CountBangunan(*P2, *TabBangunan) == 2)
                        {
                            InputSkills(P2, 2);
                        }
                    }
                
                    if ((Jenis(Elmt(*TabBangunan, x)) == 'T') && (Pemilik(Elmt(*TabBangunan,x)) != 0) && (countTower(*P1,*TabBangunan) == 3) && (claim)) {
                        InputSkills(P1,4);
                    }

                    printf("Daftar P1: \n");
                    PrintBangunan(*P1,*TabBangunan);
                    printf("Daftar P2: \n");

                    PrintBangunan(*P2,*TabBangunan);
                    (*critical) = true;
                    hasAtk(Elmt(*TabBangunan,idDipilih)) = true;
                    Push(undo, *TabBangunan);
                }
            } /* else {
            //     printf("There are no connected enemy's buildings with yours.\n");
            // }*/
        }else {
            printf("You've already attacked with this building! \n");
        }
    } else {
        printf("Pilihlah bangunan yang benar ! \n");
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

void changeLevel(Player *P, TabInt *T, int idDipilih){
    Lvl(Elmt(*T,idDipilih)) += 1;
    NPskn(Elmt(*T,idDipilih)) -= (MxTmPskn(Elmt(*T,idDipilih))/2);
}

void LEVEL_UP(Player *P, TabInt *T, Stack *undo){
    int numBuilding;
    printf("Daftar bangunan: \n");

    PrintBangunan(*P, *T);
    // // print list bangunan yang dimiliki
    printf("Bangunan yang akan di level up: ");
    scanf("%d", &numBuilding); 
    addressB X = First(listB(*P));
    int i = 1;
    if (CountBangunan(*P, *T) >= numBuilding && numBuilding > 0)
    {
        while (i < numBuilding){
        X = Next(X);
        i++;
        }
    
        int idDipilih = Info(X);

        // assignBangunan(listB(*P),numBuilding,&A);

        if(!isCanLevel(Elmt(*T, idDipilih))){
            printf("Jumlah pasukan ");
            PrintJenisBangunan(Elmt(*T, idDipilih));
            printf("kurang untuk level up\n");
        } else if (Lvl(Elmt(*T,idDipilih)) == 4) {
            printf("Level Bangunan sudah maksimum! \n");   
        } else {
            Lvl(Elmt(*T,idDipilih)) += 1;
            NPskn(Elmt(*T,idDipilih)) -= (MxTmPskn(Elmt(*T,idDipilih))/2);
            printf("Your building has been updated!\n");
            PrintBangunan(*P, *T);
            LevelUpBangunan(T,idDipilih);
        }
        Push(undo, *T);
    }
    else
    {
        printf("Bangunan pilihanmu tidak valid! \n");
    }
}

// void SKILL(){
//  // queue
//     printf("SKILL");
// }

void splitToPlayerList(Player *P1, Player *P2, TabInt T){
    for (int i = GetFirstIdx(T); i<= GetLastIdx(T); i++) {
      if (Pemilik(Elmt(T,i)) == 1 && ID(*P1) == 1) {
         InsVLast(&listB(*P1),i);
      } else if (Pemilik(Elmt(T,i)) == 2 && ID(*P2) == 2) {
         InsVLast(&listB(*P2),i);
      }
      else if (Pemilik(Elmt(T,i)) == 1 && ID(*P2) == 1) {
         InsVLast(&listB(*P2),i);
      }
      else if (Pemilik(Elmt(T,i)) == 2 && ID(*P1) == 2) {
         InsVLast(&listB(*P1),i);
      }

   }
}

void UpdateList(Player *P1, Player *P2, TabInt T){
    addressB temp;

    while(!IsEmptyList(listB(*P1))){
        DelLast(&listB(*P1), &temp);
    }
    while(!IsEmptyList(listB(*P2))){
        DelLast(&listB(*P2), &temp);
    }
    splitToPlayerList(P1, P2, T);
}

void UNDO(Player *P1, Player *P2, Stack *undo, TabInt *T){
    if(IsEmpty_Stackt(*undo)){
        printf("Cannot do that! This is your earliest status. \n");
    }
    else{
        infotypeS temp;
        Pop(undo, &temp); 
        CopyTab(InfoTop(*undo), T);
        UpdateList(P1, P2, *T);
        printf("Undo done. The buildings have been updated!\n");
        PrintBangunan(*P1, *T);
    }
}

void END_TURN(Player *P1, Player *P2, TabInt *T, boolean *extra, boolean *atkup){
    //ganti pemain berikutnya
    if (!(*extra)) {
        if(act(*P1) == 1 && act(*P2) == 0){
            act(*P1) = 0;
            act(*P2) = 1;
            printf("sampe sini\n");
        }
        else if(act(*P1) == 0 && act(*P2) == 1){
            act(*P1) = 1;
            act(*P2) = 0;
        }
    } else {
        printf("Wah! Giliran kamu lagi! \n");
        (*extra) = false;
    }
    (*atkup) = false;
    if (IsLevelFour(*P1, T))
    {
        InputSkills(P1, 6);
    }
    printf("%d %d\n", act(*P1), act(*P2));
}

// void SAVE(){
//     printf("Lokasi save file: ");
//     //nama file
// }

void MOVE(Player P, TabInt *T, Graph G, Stack *undo, boolean *move){
    TabInt terdekat;
    int num,numrcv,army;
    int numBuilding,arr2[50];
    int i=1;
    MakeEmpty(&terdekat, MaxEl(*T));

    printf("Daftar Bangunan: \n");
    PrintBangunan(P,*T);
    printf("Pilih Bangunan : "); scanf("%d",&num);
    addressB X = First(listB(P));
    while (i<num){
        X = Next(X);
        i++;
    }
    if (X!= Nil & num > 0) {
        int idDipilih = Info(X);
        int j = 1;
        adrNode t = SearchNode(G, idDipilih);
        if(t!=NilGraph){
            adrSuccNode w = Adj(t);
            while(w != NilGraph){
                int q = Id(Origin(w));
                if(Pemilik(Elmt(*T, q)) == ID(P)){
                    AddAsLastEl(&terdekat, Elmt(*T, q));
                    arr2[j] = q;
                    j++;
                }
                w = NextG(w);
            }
        }
        if (j==1){
            printf("Tidak ada bangunan yang berdekatan! \n");
        } else {
            printf("Daftar Bangunan terdekat : \n"); // print bangunan terdekat
            PrintBG(terdekat);
            printf("Bangunan yang menerima : "); scanf("%d",&numrcv);
            while (numrcv < 0 || numrcv > j -1) {
                printf("Pilihlah bangunan yang benar! \n");
                printf("Bangunan yang menerima : "); scanf("%d",&numrcv);
            }
            int idRcvDipilih = arr2[numrcv];
            printf("Jumlah Pasukan : "); scanf("%d",&army);
            while (army < 0)
            {
                printf("Masukkan jumlah pasukan yang benar ! \n");
                printf("Jumlah Pasukan : "); scanf("%d",&army);

            }
            if (NPskn(Elmt(*T, idDipilih)) < army) {
                printf("Jumlah pasukan tidak cukup! \n");
            } else {
                if(army + NPskn(Elmt(*T, idRcvDipilih)) > MxTmPskn(Elmt(*T, idRcvDipilih))){
                    printf("Building hanya mampu menampung %d pasukan.\n", MxTmPskn(Elmt(*T, idRcvDipilih)));
                    printf("Perpindahan GAGAL!\n");
                }
                else{
                    if (army + NPskn(Elmt(*T, idRcvDipilih)) == MxTmPskn(Elmt(*T, idRcvDipilih))) {
                        NPskn(Elmt(*T, idRcvDipilih)) = MxTmPskn(Elmt(*T, idRcvDipilih));
                    }
                    else if(army + NPskn(Elmt(*T, idRcvDipilih)) < MxTmPskn(Elmt(*T, idRcvDipilih))){
                        NPskn(Elmt(*T, idRcvDipilih)) += army;
                    }
                        NPskn(Elmt(*T, idDipilih)) -= army;
                        printf("%d pasukan dari ", army); PrintJenisBangunan(Elmt(*T, num));
                        TulisPOINT(Titik(Elmt(*T, idDipilih)));
                        printf(" telah berpindah ke ");
                        PrintJenisBangunan(Elmt(*T, idRcvDipilih));
                        TulisPOINT(Titik(Elmt(*T, idRcvDipilih)));
                        printf("\n");
                        Push(undo, *T);
                }
            }
        }
        *move = false;
    } else {
        printf("Pilihlah bangunan yang tepat! \n");
    }
    // pilih bangunan target
    // masukan jumlah pasukan
    // tulis status: (jumlah_pasukan) pasukan dari (jenis building) (koordinat) telah berpindah ke (jenis building) (koordinat)
}

void EXIT(){
    exit(0);
}

boolean GAME_OVER(TabInt T){
    int count1 = 0;
    int count2 = 0;

    for(int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Pemilik(Elmt(T, i)) == 1){
            count1++;
        }
        else if(Pemilik(Elmt(T, i)) == 2){
            count2++;
        }
    }
    return ((count1 == 0) || (count2 == 0));
}

void INPUT_COMMAND(Player *P1, Player *P2, TabInt *T, Graph G){
    char str[50], confirm;
    boolean atkup = false;
    boolean critical = false;
    boolean extra = false;
    boolean move = true;
    int isShieldP1 = 0;
    int isShieldP2 = 0;
    act(*P1) = 1;
    act(*P2) = 0;
    Stack undo;
    // TabInt T1;
    CreateEmpty_Stackt(&undo, MaxEl(*T));
    
    Push(&undo, *T);
    // if(IsEmpty_Stackt(undo)) {
    //     printf("berhasil");
    // }
    splitToPlayerList(P1,P2,*T);
    printf("DAFTAR BANGUNAN PLAYER 1 : \n");
    PrintBangunan(*P1,*T);
    printf("DAFTAR BANGUNAN PLAYER 2 : \n");
    PrintBangunan(*P2,*T);

    
    while(!GAME_OVER(*T)){
        if(act(*P1) == 1){
            printf("ENTER COMMAND: ");
            scanf(" %s", str);
            if (isCommandSame(str, "ATTACK")) {
                ATTACK(T, P1, P2, &atkup, &critical, G, &undo);
            }
            else if(isCommandSame(str, "LEVEL_UP")){
                LEVEL_UP(P1, T, &undo);
            }
            else if(isCommandSame(str, "SKILL")){
                if(IsEmpty_Queue(skill(*P1))){
                    printf("You don't have any skill left! \n");
                }
                else{
                    printHeadSkills(*P1);
                    printf("Do you want to use that skill? (Y/N) \n");
                    // do{
                    scanf(" %c", &confirm);
                    // } while(confirm == 'Y' || confirm == 'N');
                    if(confirm == 'Y'){
                        // printf("hallo\n");
                        if (InfoHead(skill(*P1)) == 3) {
                            UseSkills(P1, P2, &extra, &atkup,&critical,T, &isShieldP1, &undo);
                            InputSkills(P1,5);
                        } else {
                            UseSkills(P1, P2, &extra, &atkup,&critical,T, &isShieldP1, &undo);
                        }
                    }
                    else{
                        printf("You cancel the skill.\n");
                    }
                }
            }
            else if(isCommandSame(str, "UNDO")){
                UNDO(P1, P2, &undo, T);
            }
            else if(isCommandSame(str, "END_TURN")){
                END_TURN(P1, P2, T, &extra, &atkup);
                move = true;
                if(isShieldP2 > 0){
                    isShieldP2 -= 1;
                    if(isShieldP2 == 0){
                        ShieldDown(*P2, T);
                    }
                }
                DelAll(&undo);
                printf("Player 2's turn.\n");
            }
            // else if(isCommandSame(str, "SAVE")){
            //     SAVE();
            // }
            else if(isCommandSame(str, "EXIT")){
                EXIT();
            }
            else if(isCommandSame(str, "MOVE")){
                if(move){
                    MOVE(*P1, T, G, &undo,&move);
                } else {
                    printf("Kau sudah melakukan MOVE untuk giliran ini! \n");
                    printf("Tunggu giliran berikutnya!\n");
                }
            }
            else{
                printf("Check your spelling please...\n");
            }
        }
        else if(act(*P2) == 1){
            printf("ENTER COMMAND: ");
            scanf(" %s", str);
            if (isCommandSame(str, "ATTACK")) {
                ATTACK(T, P2, P1, &atkup, &critical, G, &undo);
            }
            else if(isCommandSame(str, "LEVEL_UP")){
                LEVEL_UP(P2, T, &undo);
            }
            else if(isCommandSame(str, "SKILL")){
                if(IsEmpty_Queue(skill(*P2))){
                    printf("You don't have any skill left! \n");
                }
                else{
                    printHeadSkills(*P2);
                    printf("Do you want to use that skill? (Y/N) \n");
                    // do{
                    scanf(" %c", &confirm);
                    // } while(confirm == 'Y' || confirm == 'N');
                    if(confirm == 'Y'){
                        // printf("hallo\n");
                        if (InfoHead(skill(*P2)) == 3) {
                            UseSkills(P2, P1, &extra, &atkup,&critical,T, &isShieldP1, &undo);
                            InputSkills(P1,5);
                        } else {
                            UseSkills(P2, P1, &extra, &atkup,&critical,T, &isShieldP1, &undo);
                        }
                    }
                    else{
                        printf("You cancel the skill.\n");
                    }
                }
            }
            else if(isCommandSame(str, "UNDO")){
                UNDO(P2, P1, &undo, T);
            }
            else if(isCommandSame(str, "END_TURN")){
                END_TURN(P1, P2, T, &extra, &atkup);
                move = true;
                if(isShieldP1 > 0){
                    isShieldP1 -= 1;
                    if(isShieldP1 == 0){
                        ShieldDown(*P1, T);
                    }
                }
                DelAll(&undo);
                printf("Player 1's turn.\n");
            }
            // else if(isCommandSame(str, "SAVE")){
            //     SAVE();
            // }
            else if(isCommandSame(str, "EXIT")){
                EXIT();
            }
            else if(isCommandSame(str, "MOVE")){
                if(move){
                    MOVE(*P2, T, G, &undo,&move);
                } else {
                    printf("Kau sudah melakukan MOVE untuk giliran ini! \n");
                    printf("Tunggu giliran berikutnya!\n");
                }
            }
            else{
                printf("Check your spelling please...\n");
            }
        }
    }
}