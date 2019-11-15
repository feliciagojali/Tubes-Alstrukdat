#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

boolean cek(Kata kata, Kata Command);
/* mecocokan kata terdaftar dengan command yang diinput */

boolean ATTACKCOMMAND(Kata Command);
/* mencocokan kata command yang diinput dengan kata ATTACK */

boolean LEVEL_UPCOMMAND(Kata Command);
/* mecocokan kata command yang diinput dengan kata LEVEL_UP */
    
boolean SKILLCOMMAND(Kata Command);
/* mecocokan kata command yang diinput dengan kata SKILL */

boolean UNDOCOMMAND(Kata Command);
/* mecocokan kata command yang diinput dengan kata UNDO */

boolean END_TURNCOMMAND(Kata Command);
/* mecocokan kata command yang diinput dengan kata END_TURN */

boolean SAVECOMMAND(Kata Command);
/* mecocokan kata command yang diinput dengan kata SAVE */

boolean MOVECOMMAND(Kata Command);
/* mecocokan kata command yang diinput dengan kata MOVE */

boolean EXITCOMMAND(Kata Command);
/* mecocokan kata command yang diinput dengan kata EXIT */

void ATTACK();
/* prosedur saat memilih command ATTACK */

boolean isSuccess(int OwnArmy , int OwnEnemy);
// bikin boolean cek ada yg bisa diserang atau ga
// buat fungsi mengurangi pasukan 


void LEVEL_UP();
/* prosedur saat memilih command LEVEL_UP */

void SKILL();
/* prosedur saat memilih command SKILL */

void UNDO();
/* prosedur saat memilih command UNDO */

void END_TURN();
/* prosedur saat memilih command END_TURN */

void SAVE();
/* prosedur saat memilih command SAVE */

void MOVE();
/* prosedur saat memilih command MOVE */

void EXIT();
/* prosedur saat memilih command EXIT */