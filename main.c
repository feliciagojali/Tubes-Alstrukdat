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

void saveMapS(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            boolean ada = false;
                for(int k = 1; k <= b; k++){
                    POINT t = Titik(Elmt(TabBangunan, k));
                    if(EQ(t, MakePOINT(i, j))){
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

int main(){
    
printf("                  [\\                                          \n");
printf("                  |\\)                                ____      \n");
printf("                  |                               __(_   )__   \n");
printf("                  Y\\          ___               _(          )  \n");
printf("                 T  \\       __)  )--.          (     )-----`   \n");
printf("                J    \\   ,-(         )_         `---'          \n");
printf("               Y/T`-._\\ (     (       _)                 __    \n");
printf("               /[|   ]|  `-(__  ___)-`  |\\          ,-(  __)   \n");
printf("               | |    |      (__)       J'         (     )     \n");
printf("   _           | |  ] |    _           /;\\          `-  '      \n");
printf("  (,,)        [| |    |    L'         /;  \\                    \n");
printf("             /||.| /\\ |   /\\         /.,-._\\        ___ _      \n");
printf("            /_|||| || |  /  \\        | |{  |       (._.'_)     \n");
printf("  L/\\       | \\| | '` |_ _ {|        | | U |   /\\              \n");
printf(" /v^v\\/\\   `|  Y | [  '-' '--''-''-\"-'`'   | ,`^v\\ /\\,`\\       \n");
printf("/ ,'./  \\.` |[   |       [     __   L    ] |      /^v\\  \\      \n");
printf(",'     `    |    |           ,`##Y.   ]    |___Y Y____,_,,_,,_           .o.       oooooo     oooo       .o.       ooooooooooooo       .o.       ooooooooo. \n");
printf("--   -----.-(] [ |   ]     o/####U|o      ]|| /`-, Y   _   Y  Y         .888.       `888.     .8'       .888.      8'   888   `8      .888.      `888   `Y88.\n");
printf("   Y Y  --;`~T   |      }   \\####U|[\\ _,.-(^) ,-'  _  (^)__  _         .8\"888.       `888.   .8'       .8\"888.          888          .8\"888.      888   .d88' \n");
printf("  Y  YY   ;'~~l  |   L     [|\\###U'E'\\  \\ \\Y-` _  (^) _Y  _           .8' `888.       `888. .8'       .8' `888.         888         .8' `888.     888ooo88P' \n");
printf(" Y  Y Y   ;\\~~/\\{| [      _,'-\\`= = '.\\_ ,`   (^)(^) (^) (^)         .88ooo8888.       `888.8'       .88ooo8888.        888        .88ooo8888.    888`88b.    \n");
printf("     --   ;\\~~~/\\|  _,.-'`_  `.\\_..-'\"  _ . ,_ Y_ Y_ _Y  _Y__       .8'     `888.       `888'       .8'     `888.       888       .8'     `888.   888  `88b. \n");
printf("    _    _; \\~~( Y``   Y (^) / `,      (^)      _   (^) (^)        o88o     o8888o       `8'       o88o     o8888o     o888o     o88o     o8888o o888o  o888o\n");
printf("   (^)  (^)`._~ /  L \\  _.Y'`  _  ` --  Y - - -(^) - Y - Y -   \n");
printf("    Y    Y    `'--..,-'`      (^)   _  -    _   Y ____         \n");
printf("      --           _    _ --   Y   (^)   _ (^)  ===   ----     \n");
printf("          __   -  (^)  (^)      --- Y   (^) Y                  \n");
printf("      _            Y    Y                Y                     \n\n");

printf("                                                             Welcome my loyal netizens!\n\n");
printf("                                       In this world, one person can win if the other have no more buildings. \n");
printf("                     You can input various commands that are written after you start the game to make your kingdom greater and bigger.\n");
printf("                                              It's all about strategy and perharps, a little dark magic.\n\n");
printf("                                                Good luck and may the Gods of Internet be with you!\n\n");
printf("                                                           Press any key to start the game\n");
_getch();



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
    MakeMATRIKS(n, m, &peta);
    saveMapS();
    Player P1 = initPlayer(1);
    Player P2 = initPlayer(2);
    INPUT_COMMAND(&P1, &P2, &TabBangunan, G, peta);
    return 0;
}