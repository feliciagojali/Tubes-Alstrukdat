#include "../queue/queue.h"

int main(){
    Queue Q;
    CreateEmpty_Queue(&Q, 10);
    Add(&Q, 5);
    Add(&Q, 7);
    int m;
    Del(&Q, &m);

    return 0;
}