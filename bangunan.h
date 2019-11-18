//ADT BANGUNAN
#include "point.h"
#include "boolean.h"
#ifndef bangunan_H
#define bangunan_H


typedef char jns;			//tipe jenis bangunan 'C','T','F','V'
typedef int noMilik;		//tipe kepemilikan, player 1 '1', player 2 '2'
typedef int psknType;		//tipe jumlah pasukan
typedef int lvl;			//tipe lvl bangunan
typedef boolean defense;	//tipe pertahanan
typedef struct {
	POINT titik;
	jns jenis;
	noMilik milik;
	psknType nPskn;
	lvl level;
	psknType nTambahPskn;
	psknType mxTmPskn;
	defense pertahanan;
	psknType psknAwal;
}Bangunan;

/* **********SELEKTOR********** */
#define Titik(B)	(B).titik
#define Jenis(B)	(B).jenis
#define Pemilik(B)	(B).milik
#define NPskn(B)	(B).nPskn
#define Lvl(B)		(B).level
#define NTbhPskn(B)	(B).nTambahPskn
#define MxTmPskn(B)	(B).mxTmPskn
#define Defense(B)	(B).pertahanan
#define AwalPskn(B)	(B).psknAwal

/* **********KONSTRUKTOR********** */
void MakeBangunan(Bangunan *B, POINT T, jns J, noMilik player);


/* *****UBAH JUMLAH A,M,P***** */
void UbahBangunan(Bangunan *B, psknType A, psknType M, defense P);

/* *****LEVEL UP***** */
void LvlUp(Bangunan *B);

/* *****MOVE***** */
void Move(Bangunan *B1, Bangunan *B2, psknType n);

#endif
