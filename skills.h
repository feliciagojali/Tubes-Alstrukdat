//Name File:    skills.h
//Tanggal:      25 oktober 2019
//Deskripsi:    Berisikan header dari fungsi dan prosedur dari
//              Skills yang dapat digunakan
//Tubes Alstrukdat


#include "boolean.h"
#include "stackt.h"
#include "Queue.h"

#ifndef skills_H
#define skills_H

void PrintSkills(Queue *Q, int X);
//Prosedur untuk print infoHead untuk skill dari QUEUE
//Skill dimasukan kedalam stack dalam bentuk integer
// 1-7

void StartSkills(Queue *Q);
//Prosedur yang digunakan saat pertama kali game diaktifkan
//Membuat Queue berisi skill untuk pemain
//PARAMETERNYA NANTI TYPE BANGUNAN

void UseSkills(Queue *Q, Stack *S);
//Pemain mungkin tidak memiliki skill (queue kosong)
//Prosedur yang digunakan untuk menggunakan skills yang dimiliki pemain
//Ketika command skill di input
//Skill yang dapat digunakan adalah skill di head queue
//input berupa integer karena setiap skill dilambangkan dengan
//integer 1-7

void InputSkills(Queue *Q,int X);
//Prosedur yang digunakan untuk nambahin skill ke Queue
//Queue berisikan integer
//digunain di main program saat ada keadaan
//dimana membuat seorang pemain mendapatkan skills tertentu

void InstantUpgrade();
//Pada stackt dan Queue int 1
//Bangunan akan naik 1 level
//Skill hanya ada di daftar skill awal

void Shield(); //-->Bonus
//Pada stackt dan Queue int 2
//Seluruh bangunan akan memiliki pertahanan selama 2 turn
//jika digunakan 2 kali berturut turut, durasi tidak bertambah
//Namun nilai maksimum

void ExtraTurn();
//Pada stackt dan Queue int 3
//Ketika diaktifkan, setelah gilirannya berakhir
//pemain selanjutnya tetap pemain yang sama
//Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan

void AttackUp(); //-->Bonus
//Pada stackt dan Queue int 4
//Pertahanan bangunan musuh tidak mempengaruhi penyerangan
//Skill didapatkan jika baru saja serang Tower lawan
//dan jumlah towernya menjadi 3

void CriticalHit(); //-->Bonus
//Pada stackt dan Queue int 5 
//Penyerangan setelah pengaktifan skillini
//Jumlah pasukan pada bangunan yang melakukan serangan
//hanya berkurang 1/2 dari jumlah seharusnya


void InstantReinforcement();
//Pada stackt dan Queue int 6
//Seluruh bangunan pasukan +5
//Skill didapat jika bangunan yang dimiliki pemain
//seluruhnya telah level 4
//didapatkan diakhir gilirannya

void Barrage();
//Pada stackt dan Queue int 7
//Jumlah pasukan musuh berkurang 10 di seluruh bangunannya
//Skill didapat jika lawan baru saja bertambah bangunannya
//menjadi 10 bangunan

#endif