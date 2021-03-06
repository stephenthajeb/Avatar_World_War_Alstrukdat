/* Program Utama */

/* List Lib */
#include <stdio.h>

/* List ADT */
#include "../../boolean/boolean.h"
#include "../../mainmenu/mainmenu.h"
#include "../../matrikskar/matriks.h"
#include "../../matriksint/matriksint.h"
#include "../../player/player.h"
#include "../../point/point.h"
#include "../../listlinier/listlinier.h"
#include "../../graph/graph.h"
#include "../../stack/stack.h"

int main() {
	/* Kamus */
	Player p1, p2;

	/* Inisiasi */
	Jenis(BangunanUndef) = JenisUndef;
	turn = 0;

	/* Algoritma */
	STARTGAME(&p1, &p2);

	if (!EndGame) {
		if (turn == 0) {
			turn = 1;
		}
		while (!EndGame) {
			while (!EndTurn) {
				TURN(turn, &p1, &p2);
			}
			UpdateListBangunan(turn, p1, p2);
			GetIReinforcement(turn,&p1,&p2);
			if (extraTurn == 0){
				turn = (turn % 2 + 3) - 2;
				MinShieldDuration(turn,&p1,&p2);
			} else {
				extraTurn -=1;
				if (extraTurn > 0) {
					printf("Anda memiliki extra turn %d kali\n",extraTurn);
				} else {
					printf("Ini extra turn yang terakhir!\n");
				}
			}
			if (attackUp){
				attackUp = 0;
			}
			EndTurn = false;
		}
	}
}