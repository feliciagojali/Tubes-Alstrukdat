#ifndef player_H
#define player_H

#include "boolean.h"
#include "player.h"
#include "listlinier.h"
#include "bangunan.h"
#include "point.h"

typedef struct {
    int ID;
    List listBangunan;
} Player;

#define ID(P) (P).ID
#define listB(P) (P).listBangunan

Player initPlayer(int id);

void PrintJenisBangunan(Bangunan A);

void PrintBangunan(Player P);

#endif