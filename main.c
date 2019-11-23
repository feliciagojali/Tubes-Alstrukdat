#include <stdio.h>
#include <stdlib.h>
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/pcolor/pcolor.h"
#include "ADT/point/point.h"
#include "ADT/bangunan/bangunan.h"
#include "ADT/graph/graph.h"
#include "ADT/matriks/matriks.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/listlinier/listlinier.h"
#include "ADT/player/player.h"
#include "ADT/stackt/stackt.h"
#include "ADT/input_command.c"

int n, m, b;
TabInt TabBangunan;
Stack S;
Graph G;
MATRIKS peta;

void saveMap(){
    for(int i = 1; i <= n + 2; i++){
        for(int j = 1; j <= m + 2; j++){
            if(i == 1 || j == 1 || i == n + 2 || j == m + 2){
                Cell(peta, i, j) = '*';
                Owner(peta, i, j) = 0;
            } else {
                int xpos = i - 1;
                int ypos = j - 1;
                boolean ada = false;
                for(int k = 1; k <= b; k++){
                    POINT t = Titik(Elmt(TabBangunan, k));
                    if(EQ(t, MakePOINT(xpos, ypos))){
                        ada = true;
                        Cell(peta, i, j) = Jenis(Elmt(TabBangunan, k));
                        Owner(peta, i, j) = Pemilik(Elmt(TabBangunan, k));
                    }
                }
                if(!ada){
                    Cell(peta, i, j) = ' ';
                    Owner(peta, i, j) = 0;
                }
            }
        }
    }
}

void viewMap(){
    TulisMATRIKS(peta);
}
int main(){
    MakeEmpty(&TabBangunan, 50);
    STARTKATA(2, '#');
    n = conv(CKata);
    ADVKATA('#');
    m = conv(CKata);
    ADVKATA('#');
    b = conv(CKata);
    ADVKATA('#');
    for(int i = 1; i <= b; i++){
        char t = CKata.TabKata[1];
        ADVKATA('#');
        int xpos = conv(CKata);
        ADVKATA('#');
        int ypos = conv(CKata);
        ADVKATA('#');
        Bangunan te;
        if(i == 1){
            MakeBangunan(&te, MakePOINT(xpos, ypos), t, 1);
        } else if(i == 2){
            MakeBangunan(&te, MakePOINT(xpos, ypos), t, 2);
        } else {
            MakeBangunan(&te, MakePOINT(xpos, ypos), t, 0);
        }
        AddAsLastEl(&TabBangunan, te);
    }
    CreateGraph(1, &G);
    for(int i = 1; i <= b; i++){
        for(int j = 1; j <= b; j++){
            if(CKata.TabKata[1] == '1'){
                InsertEdge(&G, i, j);
            }
            ADVKATA('#');
        }
    }
    MakeMATRIKS(n + 2, m + 2, &peta);
    saveMap();
    viewMap();
    Player P1 = initPlayer(1);
    Player P2 = initPlayer(2);
    INPUT_COMMAND(&P1, &P2, &TabBangunan, G);
    return 0;
}