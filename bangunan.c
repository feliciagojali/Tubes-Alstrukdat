 //ADT BANGUNAN

#include <stdio.h>
#include "bangunan.h"

/* **********KONSTRUKTOR********** */
void MakeBangunan(Bangunan *B, POINT T, jns J, noMilik player){
	Absis(Titik(*B))=Absis(T);
	Ordinat(Titik(*B))=Ordinat(T);
	Jenis(*B)=J;
	Pemilik(*B)=player;
	Lvl(*B)=1;
	if(J=='C'){
		NTbhPskn(*B)=10;
		MxTmPskn(*B)=40;
		Defense(*B)=false;
		AwalPskn(*B)=40;
		NPskn(*B)=40;
	}
	else if(J=='T'){
		NTbhPskn(*B)=5;
		MxTmPskn(*B)=20;
		Defense(*B)=true;
		AwalPskn(*B)=30;
		NPskn(*B)=20;
	}
	else if(J=='F'){
		NTbhPskn(*B)=10;
		MxTmPskn(*B)=20;
		Defense(*B)=false;
		AwalPskn(*B)=80;
		NPskn(*B)=20;
	}
	else if(J=='V'){
		NTbhPskn(*B)=5;
		MxTmPskn(*B)=20;
		Defense(*B)=false;
		AwalPskn(*B)=20;
		NPskn(*B)=20;
	}
	
}

/* *****UBAH JUMLAH A,M,P***** */
void UbahBangunan(Bangunan *B, psknType A, psknType M, defense P){
	NTbhPskn(*B)=A;
	MxTmPskn(*B)=M;
	Defense(*B)=P;
}
