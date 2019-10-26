//Name File:    skills.c
//Tanggal:      25 oktober 2019
//Deskripsi:    Berisikan implementasi dari header skills.h
//Tubes Alstrukdat

#include "skills.h"
#include <stdlib.h>
#include <stdio.h>
//NOTE
//KEPEMILIKANNYA GIMANA BLOM TAU


//Kamus
int Max_Queue = 20;

//Algoritma
void StartSkills(Queue *Q)
//Prosedur yang digunakan saat pertama kali game diaktifkan
//Membuat Queue berisi skill untuk pemain
//F.S Queue terdefinisi, skill dimiliki instant upgrade
    {
        CreateEmpty_Queue(Q, Max_Queue);
        Add(Q,1);
    }

void UseSkills(Queue *Q, Stack *S)
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
        Del(&Q, &X);
        Push(&S, X);
        if (X == 1)
        {
            InstantUpgrade();
        }
        else if (X == 2)
        {
            Shield();
        }
        else if (X == 3)
        {
            ExtraTurn();
        }
        else if (X == 4)
        {
            AttackUp();
        }
        else if (X == 5)
        {
            CriticalHit();
        }
        else if (X == 6)
        {
            InstantReinforcement();
        }
        else if (X == 7)
        {
            Barrage();
        }
    }

void InputSkills(Queue *Q,int X)
//Prosedur yang digunakan untuk nambahin skill ke Queue
//Queue berisikan integer
//digunain di main program saat ada keadaan
//dimana membuat seorang pemain mendapatkan skills tertentu
//int yang terdefinisi adalah 2-7
    {
        if (X >=2 && X <= 6)
        {
            Add(Q,X);
            printf("Selamat Anda mendapatkan Skill ");
            if (X == 2)
            {
                printf("Shield\n");
            }
            else if (X == 3)
            {
                printf("ExtraTurn\n");
            }
            else if (X == 4)
            {
                printf("AttackUp\n");
            }
            else if (X == 5)
            {
                printf("CriticalHit\n");
            }
            else if (X == 6)
            {
                printf("InstantReinforcement\n");
            }
            else if (X == 7)
            {
                printf("Barrage\n");
            }
        }
    }

void InstantUpgrade()
//Pada stackt dan Queue int 1
//Bangunan akan naik 1 level
//Skill hanya ada di daftar skill awal
//PARAMETER TERGNTUNG INPUT BANGUNAN

    {
        /*Castle.Level = 1;
        Tower.Level = 1;
        Fort.Level = 1;
        Village.Level = 1;*/
    }
void Shield() //-->Bonus
//Pada stackt dan Queue int 2
//Seluruh bangunan akan memiliki pertahanan selama 2 turn
//jika digunakan 2 kali berturut turut, durasi tidak bertambah
//Namun nilai maksimum
{

}
void ExtraTurn()
//Pada stackt dan Queue int 3
//Ketika diaktifkan, setelah gilirannya berakhir
//pemain selanjutnya tetap pemain yang sama
//Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan
{

}
void AttackUp() //-->Bonus
//Pada stackt dan Queue int 4
//Pertahanan bangunan musuh tidak mempengaruhi penyerangan
//Skill didapatkan jika baru saja serang Tower lawan
//dan jumlah towernya menjadi 3
{

}
void CriticalHit() //-->Bonus
//Pada stackt dan Queue int 5 
//Penyerangan setelah pengaktifan skillini
//Jumlah pasukan pada bangunan yang melakukan serangan
//hanya berkurang 1/2 dari jumlah seharusnya
{

}

void InstantReinforcement()
//Pada stackt dan Queue int 6
//Seluruh bangunan pasukan +5
//Skill didapat jika bangunan yang dimiliki pemain
//seluruhnya telah level 4
//didapatkan diakhir gilirannya
//PARAMETERNYA TYPE BANGUNAN dan kepemilikannya

{
    /*Castle.Pasukan += 5 ;
    Tower.Pasukan += 5;
    Fort.Pasukan += 5;
    Village.Pasukan +=5;
    */
}
void Barrage()
//Pada stackt dan Queue int 7
//Jumlah pasukan musuh berkurang 10 di seluruh bangunannya
//Skill didapat jika lawan baru saja bertambah bangunannya
//menjadi 10 bangunan
{
    /* If (Castle.Pasukan >= 10 && Tower.Pasukan >= 10 && Fort.Pasukan >= 10 && Village.Pasukan >=10 )
    {
        Castle.Pasukan -= 10 ;
        Tower.Pasukan -= 10;
        Fort.Pasukan -= 10;
        Village.Pasukan -=10;
    }
    */
}