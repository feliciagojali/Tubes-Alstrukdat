#include <stdio.h>
#include <stdlib.h>
#include "../player/player.h"
#include "../boolean/boolean.h"

int Max_Queue = 10;

Player initPlayer(int id){
    Player P;
    ID(P) = id;
    act(P) = 0;
    CreateEmpty_Queue(&skill(P),Max_Queue);
    CreateEmptyList(&listB(P));
    StartSkills(&P);
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

void PrintBangunan(Player P, TabInt T){
    addressB Y = First(listB(P));
    int j = 1;
    while(Y != Nil) {
            printf("%d. ",j);
            PrintJenisBangunan(Elmt(T,Info(Y)));
            TulisPOINT(Titik(Elmt(T,Info(Y))));
            printf(" %d",NPskn(Elmt(T,Info(Y))));
            printf(" lvl. %d \n",Lvl(Elmt(T,Info(Y))));
            
            Y = Next(Y);
            j++;
        }

}

boolean cariBangunan(Bangunan A,Player P,TabInt T)
{
    int numBuilding;
    TabInt myBangunan;
    int arr[50],j;
    MakeEmpty(&myBangunan, MaxEl(T));
    j = 1;
    for(int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){

        if(Pemilik(Elmt(T,i)) == ID(P)){
            AddAsLastEl(&myBangunan, Elmt(T, i));
            arr[j] = i;
            j++;
        }
    }
    int k = GetFirstIdx(myBangunan);
    while(k <= GetLastIdx(myBangunan) && !EQ(Titik(Elmt(T, k)), Titik(A))){
        k++;
    }
    return (EQ(Titik(Elmt(T, k)), Titik(A)));
}


void InsBangunan(Player P, Bangunan B, listIdxBangunan *L, TabInt *T)
{
    if(ID(P) == 1){
        Pemilik(B) = 1;
    }
    else{
        Pemilik(B) = 2;
    }
    AddAsLastEl(T, B);
    InsVLast(L, NbElmtTab(*T));
}

int countTower(Player P, TabInt T){

    int jumlah = 0;
    addressB X = First(listB(P));
    while (X != NULL) {
        if (Jenis(Elmt(T, Info(X))) == 'T') {
            jumlah +=1;
        }
        X = Next(X);
    }
    return jumlah;
}
/* ---- BAGIAN SKILL ---- */
void printHeadSkills(Player P) 
// prosedur mengeluarkan skill yang ada di Head dari queue
{
    printf("Skill Available : ");
    int x = InfoHead(skill(P));
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

void UseSkills(Player *P1, Player *P2, boolean *extra, boolean *atkup, boolean *critical, TabInt *T,int *isShield, Stack *S)
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
        if (IsEmpty_Queue(skill(*P1))) 
        {
            printf("Kamu tidak memiliki skill apapun ! \n");
        } 
        else 
        {
            Del(&skill(*P1), &X);
            DelAll(S); // kosongin stack
            if (X == 1)
            {
                InstantUpgrade(*P1,T);
            }
            else if (X == 2)
            {
                Shield(*P1,T, isShield);
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
                (*critical) = true;
            }
            else if (X == 6)
            {
                InstantReinforcement(*P1,T);
            }
            else if (X == 7)
            {
                Barrage(*P1, *P2, T);
            }
        }
    printf("Your buildings have been updated!\n");
    PrintBangunan(*P1,*T);
    }

void InputSkills(Player *P,int X)
//Prosedur yang digunakan untuk nambahin skill ke Queue
//Queue berisikan integer
//digunain di main program saat ada keadaan
//dimana membuat seorang pemain mendapatkan skills tertentu
//int yang terdefinisi adalah 2-7
    {
        if (IsFull_Queue(skill(*P)))
        {
            printf("Failed to obtain the skill! You still have 10 skills!");
        }
        else if (X >=2 && X <= 6)
        {
            Add(&skill(*P),X);
            printf("Congrats! Player %d, You got a skill! It is ", ID(*P));
            if (X == 2)
            {
                printf("Shield\n");
            }
            else if (X == 3)
            {
                printf("Extra Turn\n");
            }
            else if (X == 4)
            {
                printf("Attack Up\n");
            }
            else if (X == 5)
            {
                printf("Critical Hit\n");
            }
            else if (X == 6)
            {
                printf("Instant Reinforcement\n");
            }
            else if (X == 7)
            {
                printf("Barrage\n");
            }
        }
    }

void InstantUpgrade(Player P, TabInt *T)
//Pada stackt dan Queue int 1
//Bangunan akan naik 1 level
//Skill hanya ada di daftar skill awal
//PARAMETER TERGNTUNG INPUT BANGUNAN
{
    addressB X = First(listB(P));

    while (X!=Nil){
        if(Lvl(Elmt(*T,Info(X)))!= 4) {
            Lvl(Elmt(*T,Info(X))) += 1;
            LevelUpBangunan(T,Info(X));
        } 
        X = Next(X);
    }



}

    
void Shield(Player P, TabInt *T, int *isShield) //-->Bonus
//Pada stackt dan Queue int 2
//Seluruh bangunan akan memiliki pertahanan selama 2 turn
//jika digunakan 2 kali berturut turut, durasi tidak bertambah
//Namun nilai maksimum
{
    for(int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        if(Pemilik(Elmt(*T,i)) == ID(P)){
            Defense(Elmt(*T,i)) = true;
        }
    }
    (*isShield) = 2;
    printf("Your buildings' defenses are all on!\n");
}

void ShieldDown(Player P, TabInt *T)
// untuk mengembalikan bangunan seperti semula setelah efek shield habis
{
    for(int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        if(Pemilik(Elmt(*T,i)) == ID(P)){
            if(Jenis(Elmt(*T, i)) == 'C' || Jenis(Elmt(*T, i)) == 'V' || (Jenis(Elmt(*T, i)) == 'F' && Lvl(Elmt(*T, i)) <= 2)){
                Defense(Elmt(*T,i)) = true;
            }
        }
    }
    printf("The effect of 'shield' ran out! Your buildings' defenses are back to normal.\n");
}



void InstantReinforcement(Player P, TabInt *T)
//Pada stackt dan Queue int 6
//Seluruh bangunan pasukan +5
//Skill didapat jika bangunan yang dimiliki pemain
//seluruhnya telah level 4
//didapatkan diakhir gilirannya

{
    for(int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        if(Pemilik(Elmt(*T,i)) == ID(P)){
            NPskn(Elmt(*T,i)) += 5;
        }
    }
}

void Barrage(Player P1, Player P2, TabInt *T)
//Pada stackt dan Queue int 7
//Jumlah pasukan musuh berkurang 10 di seluruh bangunannya
//Skill didapat jika lawan baru saja bertambah bangunannya
//menjadi 10 bangunan
{
    if(ID(P1) == 1){
        ID(P2) = 2;
    }
    else if(ID(P1) == 2){
        ID(P2) = 1;

    }
    for(int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        if(Pemilik(Elmt(*T,i)) == ID(P2)){
            NPskn(Elmt(*T,i)) -= 10;
            if(NPskn(Elmt(*T,i)) < 0){
                NPskn(Elmt(*T,i)) = 0;
            }
        }
    }
}

int CountBangunan(Player P, TabInt T)
//fungsi hitung banyaknya bangunan yang dimiliki oleh suatu player
{
    int Count = 0;
    
    for(int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Pemilik(Elmt(T,i)) == ID(P)){
            Count++;
        }
    }

    return Count;
}

boolean IsLevelFour(Player P, TabInt *T)
//boolean cek apakah seluruh bangunan pemain levelnya 4
{
    int i = GetFirstIdx(*T);
    while(i <= GetLastIdx(*T)){
        if(Pemilik(Elmt(*T,i)) == ID(P)){
            if(Lvl(Elmt(*T,i)) != 4){
                return false;
            }
        i++;
        }
    }
    return true;
}

void LevelUpBangunan (TabInt *T, int idDipilih){
    if(Lvl(Elmt(*T,idDipilih)) == 2){
			if(Jenis(Elmt(*T,idDipilih))=='C'){
				UbahBangunan(&Elmt(*T,idDipilih),15,60,false);
			}
			else if(Jenis(Elmt(*T,idDipilih))=='T'){
				UbahBangunan(&Elmt(*T,idDipilih),10,30,true);
			}
			else if(Jenis(Elmt(*T,idDipilih))=='F'){
				UbahBangunan(&Elmt(*T,idDipilih),20,40,false);
			}
			else if(Jenis(Elmt(*T,idDipilih))=='V'){
				UbahBangunan(&Elmt(*T,idDipilih),10,30,false);
			}
		}
		else if(Lvl(Elmt(*T,idDipilih)) == 3){
			if(Jenis(Elmt(*T,idDipilih)) =='C'){
				UbahBangunan(&Elmt(*T,idDipilih),20,80,false);
			}
			else if(Jenis(Elmt(*T,idDipilih))=='T'){
				UbahBangunan(&Elmt(*T,idDipilih),20,40,true);
			}
			else if(Jenis(Elmt(*T,idDipilih))=='F'){
				UbahBangunan(&Elmt(*T,idDipilih),30,60,true);
			}
			else if(Jenis(Elmt(*T,idDipilih))=='V'){
				UbahBangunan(&Elmt(*T,idDipilih),15,40,false);
			}
		}
		else if(Lvl(Elmt(*T,idDipilih)) == 4){
			if(Jenis(Elmt(*T,idDipilih))=='C'){
				UbahBangunan(&Elmt(*T,idDipilih),25,100,false);
			}
			else if(Jenis(Elmt(*T,idDipilih))=='T'){
				UbahBangunan(&Elmt(*T,idDipilih),30,50,true);
			}
			else if(Jenis(Elmt(*T,idDipilih))=='F'){
				UbahBangunan(&Elmt(*T,idDipilih),40,80,true);
			}
			else if(Jenis(Elmt(*T,idDipilih))=='V'){
				UbahBangunan(&Elmt(*T,idDipilih),20,50,false);
			}
		}
}