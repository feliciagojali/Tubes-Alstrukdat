#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "matriks/matriks.h"
#include "mesinkata/mesinkata.h"
#include "mesinkata/mesinkatak.h"
#include "boolean/boolean.h"
#include "point/point.h"
#include "listlinier/listlinier.h"
#include "bangunan/bangunan.h"
#include "mesinkar/mesinkar.h"
#include "mesinkar/mesinkark.h"
#include "player/player.h"
#include "arraydin/arraydin.h"
#include "graph/graph.h"

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

int vmin(int a, int b){
    if(a < b){
        return a;
    } else {
        return b;
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
    printf("Your buildings: \n"); //buat procedure aja kali ya
    // ngeprint list bangunan yng ada menggunakan adt list
    PrintBangunan(*P1,*TabBangunan);
    // PrintBG(myBangunan);
    printf("Choose a building to attack: "); scanf("%d",&numOwn);
    while(numOwn > NbElmt(listB(*P1)) || numOwn < 1){
        printf("Invalid! Check again please. \n");
        printf("Choose a building to attack: "); scanf("%d",&numOwn);
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

    // printf("num own ketemu\n");
    if (X != Nil) {
        // printf("X!=Nil\n");
        int idDipilih = Info(X);
        if (hasAtk(Elmt(*TabBangunan,idDipilih)) == false) {
            // printf("hasatk = false\n");
            adrNode t = SearchNode(G, idDipilih);
            // printf("t : %d\n", t);
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
                // printf("j : %d\n", j);
                if(j == 1){
                    printf("No buildings connected to yours.\n");
                } else {
                    printf("Buildings that can be attacked: \n");
                    PrintBG(enemyBangunan);
                    printf("Choose a building to be attacked: "); scanf("%d",&numEnemy);

                    while (numEnemy > j-1 || numEnemy < 0) {
                        printf("Choose the right building please.\n");
                        printf("Buildings that can be attacked: \n");
                        scanf("%d",&numEnemy);
                    }
                    int idDiserang = arr[numEnemy];
                    printf("Amount of army: "); scanf("%d",&army);
                    while (army > NPskn(Elmt(*TabBangunan,idDipilih)) || army < 0) {
                        printf("Input the correct amount of army, please! Can't you see your own army?!\n");
                        printf("Amount of army: "); scanf("%d",&army);
                    }

                    /*
                        COBA NGUBAH
                    */
                    if(*critical){
                        int armyAtk = army*2;
                         if(armyAtk < NPskn(Elmt(*TabBangunan,idDiserang))){
                            printf("Not enough amount of army! Failed to claim the building.\n");
                            NPskn(Elmt(*TabBangunan, idDiserang)) -= armyAtk;
                            NPskn(Elmt(*TabBangunan, idDipilih)) -= army;
                        } else {
                            int x = idDiserang;
                            printf("The building is claimed! It's yours now.\n");
                            NPskn(Elmt(*TabBangunan, idDiserang)) = vmin(MxTmPskn(Elmt(*TabBangunan, idDiserang)), armyAtk - NPskn(Elmt(*TabBangunan,idDiserang)));
                            NPskn(Elmt(*TabBangunan, idDipilih)) -= army;
                            int pemilikasli = Pemilik(Elmt(*TabBangunan, x));
                            Pemilik(Elmt(*TabBangunan, x)) = ID(*P1);
                            Lvl(Elmt(*TabBangunan, x)) = 1;
                            if(Jenis(Elmt(*TabBangunan,x))=='C'){
                                // NTbhPskn(*B)=10;
                                // MxTmPskn(*B)=40;
                                // Defense(*B)=false;
                                // AwalPskn(*B)=40;
                                // NPskn(*B)=40;
                                UbahBangunan(&Elmt(*TabBangunan, x), 10, 40, false);
                            }
                            else if(Jenis(Elmt(*TabBangunan,x))=='T'){
                                // NTbhPskn(*B)=5;
                                // MxTmPskn(*B)=20;
                                // Defense(*B)=true;
                                // AwalPskn(*B)=30;
                                // NPskn(*B)=20;
                                UbahBangunan(&Elmt(*TabBangunan, x), 5, 20, true);
                            }
                            else if(Jenis(Elmt(*TabBangunan,x))=='F'){
                                // NTbhPskn(*B)=10;
                                // MxTmPskn(*B)=20;
                                // Defense(*B)=false;
                                // AwalPskn(*B)=80;
                                // NPskn(*B)=20;
                                UbahBangunan(&Elmt(*TabBangunan, x), 10, 20, false);
                            }
                            else if(Jenis(Elmt(*TabBangunan,x))=='V'){
                                // NTbhPskn(*B)=5;
                                // MxTmPskn(*B)=20;
                                // Defense(*B)=false;
                                // AwalPskn(*B)=20;
                                // NPskn(*B)=20;
                                UbahBangunan(&Elmt(*TabBangunan, x), 5, 20, false);
                            }
                            DelP(&listB(*P2),x);
                            InsVLast(&listB(*P1),x);
                            claim = true;
                            //Dapet skill barrage
                            if (CountBangunan(*P1, *TabBangunan) == 10)
                            {
                                InputSkills(P2, 7);
                            }
                            //Lawan Dapet skill shield
                            if ((CountBangunan(*P2, *TabBangunan) == 2) && (pemilikasli != 0))
                            {
                                InputSkills(P2, 2);
                            }
                            //Lawan dapet skill Extraturn
                            if ((Jenis(Elmt(*TabBangunan, idDiserang)) == 'F') && (pemilikasli != 0))
                            {
                                InputSkills(P2,3);   
                            }
                            //Dapet skill attack up
                            if ((Jenis(Elmt(*TabBangunan, idDiserang)) == 'T') && (pemilikasli != 0) && (countTower(*P1,*TabBangunan) == 3))
                            {
                                InputSkills(P1,4);
                            }
                        }
                    } else if(*atkup || !Defense(Elmt(*TabBangunan, idDiserang))){
                        int x = idDiserang;
                        NPskn(Elmt(*TabBangunan, idDipilih)) -= army;
                        if(army < NPskn(Elmt(*TabBangunan,idDiserang))) {
                            printf("Failed to claim the building.\n");
                            NPskn(Elmt(*TabBangunan,x)) -= army;
                        } else {
                            printf("The building is claimed! It's yours now.\n");
                            NPskn(Elmt(*TabBangunan,x)) = vmin(MxTmPskn(Elmt(*TabBangunan, idDiserang)), army - NPskn(Elmt(*TabBangunan,x)));
                            int pemilikasli = Pemilik(Elmt(*TabBangunan, x));
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
                            if ((CountBangunan(*P2, *TabBangunan) == 2) && (pemilikasli != 0))
                            {
                                InputSkills(P2, 2);
                            }
                            //Lawan dapet skill Extraturn
                            if ((Jenis(Elmt(*TabBangunan, idDiserang)) == 'F') && (pemilikasli != 0))
                            {
                                InputSkills(P2,3);   
                            }
                            //Dapet skill attack up
                            if ((Jenis(Elmt(*TabBangunan, idDiserang)) == 'T') && (pemilikasli != 0) && (countTower(*P1,*TabBangunan) == 3))
                            {
                                InputSkills(P1,4);
                            }
                        }
                    } else {
                        int ans = -1;
                        for(int i = 1; i <= army; i++){
                            if((i * 3) / 4 >= NPskn(Elmt(*TabBangunan, idDiserang))){
                                ans = i;
                                break;
                            }
                        }
                        if(ans == -1){
                            printf("Failed to claim the building.\n");
                            NPskn(Elmt(*TabBangunan, idDipilih)) -= army;
                            NPskn(Elmt(*TabBangunan, idDiserang)) -= (3 * army) / 4;
                        } else {
                            int x = idDiserang;
                            printf("The building is claimed! It's yours now.\n");
                            NPskn(Elmt(*TabBangunan, idDipilih)) -= army;
                            NPskn(Elmt(*TabBangunan, idDiserang)) = vmin(MxTmPskn(Elmt(*TabBangunan, idDiserang)), army - ans + (3 * ans) / 4 - NPskn(Elmt(*TabBangunan, idDiserang)));
                            int pemilikasli = Pemilik(Elmt(*TabBangunan, x));
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
                            if ((CountBangunan(*P2, *TabBangunan) == 2) && (pemilikasli != 0))
                            {
                                InputSkills(P2, 2);
                            }
                            //Lawan dapet skill Extraturn
                            if ((Jenis(Elmt(*TabBangunan, idDiserang)) == 'F') && (pemilikasli != 0))
                            {
                                InputSkills(P2,3);   
                            }
                            //Dapet skill attack up
                            if ((Jenis(Elmt(*TabBangunan, idDiserang)) == 'T') && (pemilikasli != 0) && (countTower(*P1,*TabBangunan) == 3))
                            {
                                InputSkills(P1,4);
                            }
                        }
                    }

                   /*
                        END COBA NGUBAH
                   */
                    /*NPskn(Elmt(*TabBangunan,idDipilih)) -= army;

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
                        int pemilikasli = Pemilik(Elmt(*TabBangunan, x));
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
                        if ((CountBangunan(*P2, *TabBangunan) == 2) && (pemilikasli != 0))
                        {
                            InputSkills(P2, 2);
                        }
                        //Lawan dapet skill Extraturn
                        if ((Jenis(Elmt(*TabBangunan, idDiserang)) == 'F') && (pemilikasli != 0))
                        {
                            InputSkills(P2,3);   
                        }
                        //Dapet skill attack up
                        if ((Jenis(Elmt(*TabBangunan, idDiserang)) == 'T') && (pemilikasli != 0) && (countTower(*P1,*TabBangunan) == 3))
                        {
                            InputSkills(P1,4);
                        }
                    }*/
            

                    // printf("Daftar P1: \n");
                    // PrintBangunan(*P1,*TabBangunan);
                    // printf("Daftar P2: \n");
                    // PrintBangunan(*P2,*TabBangunan);
                    (*critical) = false;
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
        printf("Choose the building on the list, please! \n");
    }
}

boolean isCommandSame(KataK X, char *strg2)
{
    for(int i = 1; i <= X.Length; i++){
        if(X.TabKata[i] != strg2[i - 1]){
            return false;
        }
    }
    return true;
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
    printf("Your buildings: \n");

    PrintBangunan(*P, *T);
    // // print list bangunan yang dimiliki
    printf("The building to be levelled up: ");
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
            printf("Amount of army ");
            PrintJenisBangunan(Elmt(*T, idDipilih));
            printf("is not enough for the building to be levelled up!\n");
        } else if (Lvl(Elmt(*T,idDipilih)) == 4) {
            printf("The building's level is maximum! \n");   
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
        printf("Choose the building on the list, please! \n");
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

void UNDO(Player *P1, Player *P2, Stack *undo, TabInt *T, Stack *undo2, TabInt *mov){
    if(IsEmpty_Stackt(*undo)){
        printf("Cannot do that! This is your earliest status. \n");
    }
    else{
        infotypeS temp;
        Pop(undo, &temp); 
        CopyTab(InfoTop(*undo), T);
        infotypeS temp2;
        Pop(undo2, &temp2); 
        CopyTab(InfoTop(*undo2), mov);
        UpdateList(P1, P2, *T);
        printf("Undo done. The buildings have been updated!\n");
        PrintBangunan(*P1, *T);
    }
}

void hasAtkOff(Player P, TabInt *T){
    addressB B;
    
    B = First(listB(P));
    while(B!=Nil){
        hasAtk(Elmt(*T, Info(B))) = false;
        B = Next(B);
    }
}

void END_TURN(Player *P1, Player *P2, TabInt *T, boolean *extra, boolean *atkup){
    //ganti pemain berikutnya
    if (!(*extra)) {
        if(act(*P1) == 1 && act(*P2) == 0){
            act(*P1) = 0;
            act(*P2) = 1;
            if (IsLevelFour(*P1, *T))
            {
                InputSkills(P1, 6);
            }
            printf("Player 2's turn.\n");
        }
        else if(act(*P1) == 0 && act(*P2) == 1){
            act(*P1) = 1;
            act(*P2) = 0;
            if (IsLevelFour(*P2, *T))
            {
                InputSkills(P2, 6);
            }
            printf("Player 1's turn.\n");
        }
    } else {
        printf("Wow! It's your turn again! Lucky you. \n");
        (*extra) = false;
    }
    (*atkup) = false;
    // printf("%d %d\n", act(*P1), act(*P2));
}

// void SAVE(){
//     printf("Lokasi save file: ");
//     //nama file
// }

boolean MOVE(Player P, TabInt *T, Graph G, Stack *undo, boolean *move){
    TabInt terdekat;
    int num,numrcv,army;
    int numBuilding,arr2[50];
    int i=1;
    MakeEmpty(&terdekat, MaxEl(*T));

    printf("Your buildings: \n");
    PrintBangunan(P,*T);
    printf("Choose buildings to send the army : "); scanf("%d",&num);
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
            printf("No buildings are connected to yours! \n");
            return false;
        } else {
            printf("Connected buildings : \n"); // print bangunan terdekat
            PrintBG(terdekat);
            printf("Choose a building to receive the army : "); scanf("%d",&numrcv);
            while (numrcv < 0 || numrcv > j -1) {
                printf("Choose a building on the list, please! Can't you see it?! \n");
                printf("Choose a building to receive the army : "); scanf("%d",&numrcv);
            }
            int idRcvDipilih = arr2[numrcv];
            printf("Amount of army : "); scanf("%d",&army);
            while (NPskn(Elmt(*T, idDipilih)) < army)
            {
                printf("Input the right amount of army please! \n");
                printf("Amount of army : "); scanf("%d",&army);

            }
            // if (NPskn(Elmt(*T, idDipilih)) < army) {
            //     printf("The amount of army is not enough! \n");
            // } else {
                if(army + NPskn(Elmt(*T, idRcvDipilih)) > MxTmPskn(Elmt(*T, idRcvDipilih))){
                    printf("The building could only accomodate %d soldiers.\n", MxTmPskn(Elmt(*T, idRcvDipilih)));
                    printf("MOVE FAILED!\n");
                    return false;
                }
                else{
                    if (army + NPskn(Elmt(*T, idRcvDipilih)) == MxTmPskn(Elmt(*T, idRcvDipilih))) {
                        NPskn(Elmt(*T, idRcvDipilih)) = MxTmPskn(Elmt(*T, idRcvDipilih));
                    }
                    else if(army + NPskn(Elmt(*T, idRcvDipilih)) < MxTmPskn(Elmt(*T, idRcvDipilih))){
                        NPskn(Elmt(*T, idRcvDipilih)) += army;
                    }
                        NPskn(Elmt(*T, idDipilih)) -= army;
                        printf("%d soldiers from ", army); PrintJenisBangunan(Elmt(*T, num));
                        TulisPOINT(Titik(Elmt(*T, idDipilih)));
                        printf(" has been moved to ");
                        PrintJenisBangunan(Elmt(*T, idRcvDipilih));
                        TulisPOINT(Titik(Elmt(*T, idRcvDipilih)));
                        printf("\n");
                        Push(undo, *T);
                        *move = false;
                    return true;
                }
            // }
        }
    } else {
        printf("Choose the building on the list, please! You're not blind, right? \n");
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
void saveMap(MATRIKS *peta, TabInt TabBangunan){
    for(int i = 1; i <= GetLastIdxBrs(*peta); i++){
        for(int j = 1; j <= GetLastIdxKol(*peta); j++){
            if(i == 1 || j == 1 || i == GetLastIdxBrs(*peta) || j == GetLastIdxKol(*peta)){
                Cell(*peta, i, j) = '*';
                Owner(*peta, i, j) = 0;
            } else {
                int xpos = i - 1;
                int ypos = j - 1;
                boolean ada = false;
                for(int k = 1; k <= GetLastIdx(TabBangunan); k++){
                    POINT t = Titik(Elmt(TabBangunan, k));
                    if(EQ(t, MakePOINT(xpos, ypos))){
                        ada = true;
                        Cell(*peta, i, j) = Jenis(Elmt(TabBangunan, k));
                        Owner(*peta, i, j) = Pemilik(Elmt(TabBangunan, k));
                    }
                }
                if(!ada){
                    Cell(*peta, i, j) = ' ';
                    Owner(*peta, i, j) = 0;
                }
            }
        }
    }
}

void viewMap(MATRIKS peta){
    TulisMATRIKS(peta);
}

void AddPasukan(Player P, TabInt *T){
    addressB B;

    B = First(listB(P));
    while(B!=Nil){
        if( NPskn(Elmt(*T, Info(B)))+NTbhPskn(Elmt(*T, Info(B))) >= MxTmPskn(Elmt(*T, Info(B))) ){
            NPskn(Elmt(*T, Info(B))) = MxTmPskn(Elmt(*T, Info(B)));
        }
        else{
            NPskn(Elmt(*T, Info(B))) += NTbhPskn(Elmt(*T, Info(B)));
        }
        B = Next(B);
    }
}

void LIST_COMMAND()
//Prosedur untuk tampilkan command
{
    printf("\n");
    printf("Command available   :\n");
    printf("1. ATTACK   "); printf("5. MOVE\n");
    printf("2. LEVEL_UP "); printf("6. END_TURN\n");
    printf("3. SKILL    "); printf("7. SAVE\n");
    printf("4. UNDO     "); printf("8. EXIT\n");
    printf("\n");
}

void INPUT_COMMAND(Player *P1, Player *P2, TabInt *T, Graph G, MATRIKS peta){
    char confirm;
    boolean atkup = false;
    boolean critical = false;
    boolean extra = false;
    boolean move = true;
    int isShieldP1 = 0;
    int isShieldP2 = 0;
    act(*P1) = 1;
    act(*P2) = 0;
    Stack undo;
    Stack undo2;
    CreateEmpty_Stackt(&undo2, MaxEl(*T));
    /* buat move */
    TabInt mov;
    MakeEmpty(&mov, 50);
    Bangunan mov1;
    MakeBangunan(&mov1, MakePOINT(1, 1), 'T', 0);
    AddAsLastEl(&mov, mov1);
    Push(&undo2, mov);

    // TabInt T1;
    CreateEmpty_Stackt(&undo, MaxEl(*T));
    
    Push(&undo, *T);
    // if(IsEmpty_Stackt(undo)) {
    //     printf("berhasil");
    // }
    splitToPlayerList(P1,P2,*T);

    AddPasukan(*P1, T);
    // printf("DAFTAR BANGUNAN PLAYER 1 : \n");
    // PrintBangunan(*P1,*T);
    // printf("DAFTAR BANGUNAN PLAYER 2 : \n");
    // PrintBangunan(*P2,*T);
    while(!GAME_OVER(*T)){
        system("cls");
        viewMap(peta);
        printf("\n");
        printf("Details:\n");
        printf("Player : ");
        if(act(*P1) == 1){
            printf("1\n");
            printf("Buildings:\n");
            PrintBangunan(*P1, *T);
            if (IsEmpty_Queue(skill(*P1)))
            {
                printf("You don't have any skills left\n");
            }
            else
            {
            printHeadSkills(*P1);
            }
        }
        else{
            printf("2\n");
            printf("Buildings:\n");
            PrintBangunan(*P2, *T);
            if (IsEmpty_Queue(skill(*P2)))
            {
                printf("You don't have any skills left\n");
            }
            else
            {
                printHeadSkills(*P2);
            }
        }

        if(act(*P1) == 1){
            LIST_COMMAND();
            printf("ENTER COMMAND: ");
            STARTKATAK();
            KataK str;
            InputK(&str);
            if (isCommandSame(str, "ATTACK")) {
                ATTACK(T, P1, P2, &atkup, &critical, G, &undo);
                saveMap(&peta, *T);
                Push(&undo2, mov);
            }
            else if(isCommandSame(str, "LEVEL_UP")){
                LEVEL_UP(P1, T, &undo);
                saveMap(&peta, *T);
                Push(&undo2, mov);
            }
            else if(isCommandSame(str, "SKILL")){
                if(IsEmpty_Queue(skill(*P1))){
                    printf("You don't have any skill left! \n");
                }
                else{
                    // printHeadSkills(*P1);
                    // printf("Do you want to use that skill? (Y/N) \n");
                    // // do{
                    // scanf(" %c", &confirm);
                    // // } while(confirm == 'Y' || confirm == 'N');
                    // if(confirm == 'Y'){
                        // printf("hallo\n");
                        if (InfoHead(skill(*P1)) == 3) {
                            UseSkills(P1, P2, &extra, &atkup,&critical,T, &isShieldP1, &undo);
                            InputSkills(P2,5);
                        } else {
                            UseSkills(P1, P2, &extra, &atkup,&critical,T, &isShieldP1, &undo);
                        }
                        Push(&undo, *T);
                        saveMap(&peta, *T);
                        DelAll(&undo);
                        Push(&undo2, mov);
                        DelAll(&undo2);
                    }
                    // else{
                    //     printf("You cancel the skill.\n");
                    // }
                }
            else if(isCommandSame(str, "UNDO")){
                UNDO(P1, P2, &undo, T, &undo2, &mov);
                saveMap(&peta, *T);
            }
            else if(isCommandSame(str, "END_TURN")){
                END_TURN(P1, P2, T, &extra, &atkup);
                if(isShieldP2 > 0){
                    isShieldP2 -= 1;
                    if(isShieldP2 == 0){
                        ShieldDown(*P2, T);
                    }
                }
                hasAtkOff(*P1, T);
                AddPasukan(*P2, T);
                Push(&undo, *T);
                saveMap(&peta, *T);
                DelAll(&undo);
                Push(&undo2, mov);
                DelAll(&undo2);
            }
            // else if(isCommandSame(str, "SAVE")){
            //     SAVE();
            // }
            else if(isCommandSame(str, "EXIT")){
                EXIT();
            }
            else if(isCommandSame(str, "MOVE")){
                int t = Absis(Titik(Elmt(mov, 1)));
                if(t == 1){
                    boolean k = MOVE(*P1, T, G, &undo, &move);
                    saveMap(&peta, *T);
                    if(k){
                        Absis(Titik(Elmt(mov, 1))) = 0;
                    }
                    Push(&undo2, mov);
                } else {
                    printf("You have used MOVE for this turn! \n");
                    printf("Wait for the next turn please!\n");
                }
            }
            else{
                printf("Check your spelling please...\n");
            }
        }
        else if(act(*P2) == 1){
            LIST_COMMAND();
            printf("ENTER COMMAND: ");
            KataK str;
            InputK(&str);
            if (isCommandSame(str, "ATTACK")) {
                ATTACK(T, P2, P1, &atkup, &critical, G, &undo);
                saveMap(&peta, *T);
                Push(&undo2, mov);
            }
            else if(isCommandSame(str, "LEVEL_UP")){
                LEVEL_UP(P2, T, &undo);
                saveMap(&peta, *T);
                Push(&undo2, mov);
            }
            else if(isCommandSame(str, "SKILL")){
                if(IsEmpty_Queue(skill(*P2))){
                    printf("You don't have any skill left! \n");
                }
                else{
                        if (InfoHead(skill(*P2)) == 3) {
                            UseSkills(P2, P1, &extra, &atkup,&critical,T, &isShieldP1, &undo);
                            InputSkills(P1,5);
                        } else {
                            UseSkills(P2, P1, &extra, &atkup,&critical,T, &isShieldP1, &undo);
                        }
                        Push(&undo, *T);
                        saveMap(&peta, *T);
                        DelAll(&undo);
                        Push(&undo2, mov);
                        DelAll(&undo2);
                    }
            }
            else if(isCommandSame(str, "UNDO")){
                UNDO(P2, P1, &undo, T, &undo2, &mov);
                saveMap(&peta, *T);
            }
            else if(isCommandSame(str, "END_TURN")){
                END_TURN(P1, P2, T, &extra, &atkup);
                if(isShieldP1 > 0){
                    isShieldP1 -= 1;
                    if(isShieldP1 == 0){
                        ShieldDown(*P1, T);
                    }
                }
                hasAtkOff(*P2, T);
                AddPasukan(*P1, T);
                Push(&undo, *T);
                saveMap(&peta, *T);
                DelAll(&undo);
                Push(&undo2, mov);
                DelAll(&undo2);
            }
            // else if(isCommandSame(str, "SAVE")){
            //     SAVE();
            // }
            else if(isCommandSame(str, "EXIT")){
                EXIT();
            }
            else if(isCommandSame(str, "MOVE")){
                int t = Ordinat(Titik(Elmt(mov, 1)));
                if(t == 1){
                    boolean k = MOVE(*P2, T, G, &undo,&move);
                    if(k){
                        Ordinat(Titik(Elmt(mov, 1))) = 0;
                    }
                    Push(&undo2, mov);
                    saveMap(&peta, *T);
                } else {
                    printf("You have used MOVE for this turn! \n");
                    printf("Wait for the next turn please!\n");
                }
            }
            else{
                printf("Check your spelling please...\n");
            }
        }
        printf("Press any key to continue...\n\n");
        _getch();
    }
}