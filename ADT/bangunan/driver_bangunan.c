#include "../bangunan/bangunan.h"

int main(){
    Bangunan a, b;
    MakeBangunan(&a, MakePOINT(3, 4), 'V', 1);
    TulisPOINT(Titik(a));
    return 0;
}