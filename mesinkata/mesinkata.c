/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include <stdio.h>
#include <string.h>
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "../boolean/boolean.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    /* Algoritma */
	while (CC == BLANK && CC != MARK) {
		ADV();
	}
}
void SCANKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    /* Algoritma */
    SCAN();
	IgnoreBlank();
	if (feof(stdin)) {
		CKata.TabKata[1] = 'E';
		CKata.TabKata[2] = 'X';
		CKata.TabKata[3] = 'I';
		CKata.TabKata[4] = 'T';
		CKata.Length = 4;
	} else if (CC == ENDCOMMAND) { 
		EndKata = true;
	} else { 
		EndKata = false; 
		SalinKata(); 
	}
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    /* Kamus Lokal */
	int i;
	
    /* Algoritma */
	i = 1;
	while (CC != ENDCOMMAND && i <= NMax) {
		CKata.TabKata[i] = CC;
		SCAN();
		i++;
	}
	CKata.Length = i-1;
}

boolean EQ_KATA(Kata X, char Y[]) {
/* mengirimkan true jika kata X sama secara urut dengan seluruh karakter yang ada pada array Y */
	/* Kamus Lokal */
	int i;
	boolean sama;

	/* Algoritma */
	sama = X.Length == strlen(Y);
	i = 1;
	while (i <= X.Length && sama) {
		sama = (X.TabKata[i] == Y[i-1]);
		i++;
	}
	return sama;
}