#include <stdio.h>
#include "../stackt/stackt.h"
#include "../bangunan/bangunan.h"
#include "../arraydin/arraydin.h"

int main(){
    TabInt TabBangunan;
    Bangunan a, b;
    Stack S;
    CreateEmpty_Stackt(&S, 10);
    MakeEmpty(&TabBangunan, 50);
    MakeBangunan(&a, MakePOINT(3, 4), 'V', 1);
    MakeBangunan(&b, MakePOINT(3, 7), 'T', 2);
    AddAsLastEl(&TabBangunan, a);
    AddAsLastEl(&TabBangunan, b);

    Push(&S, TabBangunan);

    if(IsEmpty_Stackt(S)){
        printf("The stack is empty.\n");
    }



    return 0;
}