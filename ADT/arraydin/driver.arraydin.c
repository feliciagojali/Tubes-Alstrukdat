#include "../arraydin/arraydin.h"
#include "../bangunan/bangunan.h"

int main(){
    Bangunan a, b;
    MakeBangunan(&a, MakePOINT(3, 4), 'T', 1);
    MakeBangunan(&b, MakePOINT(1, 2), 'V', 2);

    TabInt TB;
    MakeEmpty(&TB, 50);
    AddAsLastEl(&TB, a);
    AddAsLastEl(&TB, b);
    return 0;
}