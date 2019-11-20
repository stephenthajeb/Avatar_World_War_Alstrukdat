/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#include <stdio.h>
#include "boolean.h"
#include "player.h"
#include "listlinier.h"
#include "queue.h"
#include "arraydinpos.h"
#include "bangunan.h"


void InitPlayer(int num, Player *P) {
	Color(*P) = num;
	NoPemain(*P) = num;
	CreateEmpty_LL(&ListBangunan(*P));
	CreateEmpty_Queue(&Skill(*P), 100);
	First(ListBangunan(*P)) = Alokasi(num);
	Kepemilikan(ElmtArr(TB,num)) = num;
}

void PrintListBangunan(int num, Player P1, Player P2) {
	if (num == 1) {
		PrintInfo(ListBangunan(P1));
	} else {
		PrintInfo(ListBangunan(P2));
	}
}

void UpdateListBangunan(int num, Player P1, Player P2) {
	if (num == 1) {
		UpdateAllBuildings(ListBangunan(P1));
	} else {
		UpdateAllBuildings(ListBangunan(P2));
	}
}

void LevelUpBP (int num, Player P1, Player P2, int idx) {
	if (num == 1) {
		IndexLevelUp(ListBangunan(P1), idx);
	} else {
		IndexLevelUp(ListBangunan(P2), idx);
	}
}

void InstantUpgrade(Player *P){ 
    LevelUpAll(ListBangunan(*P));
}

void Shield (Player *P){
    ShieldOn(ListBangunan(*P));
	shieldDuration(*P) = 4;
}

void ExtraTurn (Player *P){

}

void AttackUp ( Player *attacker, Player *defender){
}

void CriticalHit (Player *user){
    Critical(*user) = true;
}

void InstantReinforcement (Player *P){
    ReinforceAll(ListBangunan(*P));
}

void Barrage (Player *P){
    BarrageAll(ListBangunan(*P));
}


/* *** Keep Skill *** */
void KeepSkill (Player *user, skilltype skillName){
    Add(&Skill(*user),skillName); 
}

/* *** Use Skill*** */
void UseSkillP (Player *user,Player *enemy){
	skilltype X;

	if (IsEmpty_Queue(Skill(*user))){
		printf("Tidak ada skill yang available\n");
	} else {
		if ((InfoHead(Skill(*user)) == 'U') || (InfoHead(Skill(*user)) == 'u')) {
			InstantUpgrade(user);//ini belum tau parameternya bakalan player atau list
		} else if ((InfoHead(Skill(*user)) == 'S') || (InfoHead(Skill(*user)) == 's')){
			Shield(user);
		} else if ((InfoHead(Skill(*user)) == 'E') || (InfoHead(Skill(*user)) == 'e')){
			ExtraTurn(user);
		} else if ((InfoHead(Skill(*user)) == 'A') || (InfoHead(Skill(*user)) == 'a')){
			AttackUp(user,enemy);
		} else if ((InfoHead(Skill(*user)) == 'H') || (InfoHead(Skill(*user)) == 'h')){
			CriticalHit(user);
		} else if ((InfoHead(Skill(*user)) == 'R') || (InfoHead(Skill(*user)) == 'r')){
			InstantReinforcement(user);
		} else {
			Barrage(user);
		}
		Del(&Skill(*user),&X);
	}
}

void UseSkill(int num, Player *P1, Player *P2) {
	if (NoPemain(*P1) == num) {
		UseSkillP(P1,P2);
	} else{
		UseSkillP(P2,P1);
	}
}

void PrintSkill(Player P) {
	switch(InfoHead(Skill(P))) {
		case 'U': printf("Instant Upgrade"); break;
		case 'u': printf("Instant Upgrade"); break;
		case 'S': printf("Shield"); break;
		case 's': printf("Shield"); break;
		case 'E': printf("Extra Turn"); break;
		case 'e': printf("Extra Turn"); break;
		case 'A': printf("Attack Up"); break;
		case 'a': printf("Attack Up"); break;
		case 'H': printf("Critical Hit"); break;
		case 'h': printf("Critical Hit"); break;
		case 'R': printf("Instant Reinforcement"); break;
		case 'r': printf("Instant Reinforcement"); break;
		case 'B': printf("Barrage"); break;
		case 'b': printf("Barrage"); break;
	}
}

void ShowSkill(int num, Player P1, Player P2) {
	printf("Skill Available: ");
	if (NoPemain(P1) == num && !IsEmpty_Queue(Skill(P1))) {
		PrintSkill(P1);
	} else if (NoPemain(P2) == num && !IsEmpty_Queue(Skill(P2))) {
		PrintSkill(P2);
	} else {
		printf("-");
	}
	printf("\n");
}

//Kondisi peroleh skill
void GetIUpgrade (Player *P){
	KeepSkill(P,'U');
}

void GetIReinforcement(int num, Player *P1,Player *P2){
	if (NoPemain(*P1) == num) {
		if (isAllLevel4(*P1)){
			KeepSkill(P1,'R');
		}
	} else if (NoPemain(*P2) == num) {
		if (isAllLevel4(*P2)){
			KeepSkill(P2,'R');
		}
	}
}

boolean isAllLevel4 (Player P){
	//Kamus Lokal
	address Q;
	boolean level4;

	//Algoritma
	level4 = true;
	if (IsEmpty_LL(ListBangunan(P))){
		return false;
	} else {
		Q = First(ListBangunan(P));
		while ((Q != Nil) && (level4)){
			if (Level(ElmtArr(TB,Info(Q))) != 4){
				level4 = false;
			} else {
				Q = Next(Q);
			}
		}
		return (level4);
	}
}


// void GetShield();
// void GetdExtraTurn();
// void GetAttackUp();
// void GetCriticalHit();
// void GetBarrage();


