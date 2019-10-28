//ADT BANGUNAN

#ifndef bangunan_H
#define bangunan_H

#include "boolean.h"
#include "point.h"

typedef char jns;			//tipe jenis bangunan
typedef int noMilik;		//tipe kepemilikan
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
#define Titik(B)	(Bangunan).titik
#define Jenis(B)	(Bangunan).jenis
#define Pemilik(B)	(Bangunan).milik
#define NPskn(B)	(Bangunan).nPskn
#define Lvl(B)		(Bangunan).level
#define NTbhPskn(B)	(Bangunan).nTambahPskn
#define MxTmPskn(B)	(Bangunan).mxTmPskn
#define Defense(B)	(Bangunan).pertahanan
#define AwalPskn(B)	(Bangunan).psknAwal

/* **********KONSTRUKTOR********** */
void MakeBangunan(Bangunan *B, POINT T, jns J, noMilik player);


/* *****UBAH JUMLAH A,M,P***** */
void UbahBangunan(Bangunan *B, psknType A, psknType M, defense P);

/* *****LEVEL UP***** */
void LvlUp(Bangunan *B);

/* *****MOVE***** */
void Move(Bangunan *B1, Bangunan *B2, psknType n);

#endif
