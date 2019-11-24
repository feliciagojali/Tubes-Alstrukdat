#include <stdio.h>
#include "../mesinkata/mesinkata.h"
#include "../mesinkar/mesinkar.h"

boolean EndKata;
Kata CKata;
char CC;

void IgnoreBlank(char MARK)
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ((CC == BLANK || CC == '\n') &&  (CC != MARK)) {
        ADV(MARK);
    }
}

void STARTKATA(int type, char MARK)
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

{
      EndKata = false;
        START(type);
        IgnoreBlank(MARK);
        if(CC == MARK) {
            EndKata = true;
        }
        else{
            SalinKata(MARK);
        }
}
void ADVKATA(char MARK)
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
     IgnoreBlank(MARK);
        if(CC == MARK) {
            EndKata = true;
        }
        else{
            SalinKata(MARK);
            IgnoreBlank(MARK);
        }
}

void Input(Kata *outp)
{
    (*outp).Length = CKata.Length;
    for(int i = 1; i <= CKata.Length; i++){
        (*outp).TabKata[i] = CKata.TabKata[i];
    }
    ADVKATA('.');
}

void InputInteger(int *outp)
{
    Kata x;
    Input(&x);
    int res = 0;
    int ten = 1;
    for(int i = x.Length; i >= 1; i--){
        res += ten * (x.TabKata[i] - '0');
        ten *= 10;
    }
    *outp = res;
}

int conv(Kata x){
    int m[100];
    int ptr = 1;
    for(int i = 1; i <= x.Length; i++){
        if(x.TabKata[i] >= '0' && x.TabKata[i] <= '9'){
            m[ptr] = x.TabKata[i] - '0';
            ptr++;
        }
    }
    int res = 0;
    for(int i = 1; i < ptr; i++){
        res = 10 * res + m[i];
    }
    return res;
}

void SalinKata(char MARK)
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi 50, maka sisa kata "dipotong" */
{
    int i = 1;
    while ((CC != MARK && CC != BLANK && CC != '\n') && (i <= 50 )) {
        CKata.TabKata[i] = CC;
        ADV(MARK);
        i++;
    }
    CKata.Length = i-1;
     while((CC != MARK) && (CC != BLANK) && (CC != '\n')) {
        ADV(MARK);
    }
}

boolean IsKataEqual(Kata A, Kata B){
    if(A.Length != B.Length){
        return false;
    } else {
        boolean same = true;
        for(int i = 1; i <= A.Length; i++){
            if(A.TabKata[i] != B.TabKata[i]){
                same = false;
                break;
            }
        }
        return same;
    }
}

void PrintKata(Kata A){
    for(int i = 1; i <= A.Length; i++){
        printf("%c", A.TabKata[i]);
    }
}

void Setop(){
    stopPita();
}