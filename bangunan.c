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

/* *****LEVEL UP***** */
void LvlUp(Bangunan *B){
	if (NPskn(*B)<MxTmPskn(*B)){
		printf("Jumlah pasukan <> kurang untuk level up\n");
	}
	else{
		NPskn(*B)-=(MxTmPskn(*B)/2);
		if(Lvl(*B)==1){
			Lvl(*B)=2;
			if(Jenis(*B)=='C'){
				UbahBangunan(B,15,60,false);
			}
			else if(Jenis(*B)=='T'){
				UbahBangunan(B,10,30,true);
			}
			else if(Jenis(*B)=='F'){
				UbahBangunan(B,20,40,false);
			}
			else if(Jenis(*B)=='V'){
				UbahBangunan(B,10,30,false);
			}
		}
		else if(Lvl(*B)==2){
			Lvl(*B)=3;
			if(Jenis(*B)=='C'){
				UbahBangunan(B,20,80,false);
			}
			else if(Jenis(*B)=='T'){
				UbahBangunan(B,20,40,true);
			}
			else if(Jenis(*B)=='F'){
				UbahBangunan(B,30,60,true);
			}
			else if(Jenis(*B)=='V'){
				UbahBangunan(B,15,40,false);
			}
		}
		else if(Lvl(*B)==3){
			Lvl(*B)=4;
			if(Jenis(*B)=='C'){
				UbahBangunan(B,25,100,false);
			}
			else if(Jenis(*B)=='T'){
				UbahBangunan(B,30,50,true);
			}
			else if(Jenis(*B)=='F'){
				UbahBangunan(B,40,80,true);
			}
			else if(Jenis(*B)=='V'){
				UbahBangunan(B,20,50,false);
			}
		}
	}
}

/* *****MOVE***** */
void Move(Bangunan *B1, Bangunan *B2, psknType n){
	NPskn(*B1)-=n;
	NPskn(*B2)+=n;
}