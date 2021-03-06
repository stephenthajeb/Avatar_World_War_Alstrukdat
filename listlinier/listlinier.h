/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../bangunan/bangunan.h"

#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	infotype info;
	address next;
} ElmtList;

typedef struct {
	address First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty_LL (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty_LL (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, Bangunan X);
/* Mencari apakah ada elemen list dengan TB.TI[Info(P)]=B */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

address SearchInfo (List L, int X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, Bangunan X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

void CopyList(List Lin, List *Lout);
/*	I.S. Lout kosong.
	F.S. Semua elemen dan indeks di Lout sama dengan semua elemen dan indeks di Lin.
*/

int InfoListByIndex (List L, int idx);
/* Prekonsidi: idx tidak melebihi ukuran L */
/* Menghasilkan info elemen ke-idx pada List; mengirimkan 0 jika list kosong */


int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
void UpdateAllBuildings(List L);
/*	I.S. L dan TB terdefinisi
	F.S. Semua elemen array berindeks info semua elemen L ditambah jumlah pasukannya sesuai spesifikasi
*/

void ConnectedBuildings(int NoBangunan, List L);
/*	I.S. L, TB, dan GHubungan terdefinisi dan NoBangunan adalah indeks TB yang valid
	F.S. Ditampilkan semua bangunan dengan indeks TB dalam list L yang terhubung dengan TB.TI[NoBangunan]
*/

void ConnectedBuildings2(int NoBangunan, List L);
/*	I.S. L, TB, dan GHubungan terdefinisi dan NoBangunan adalah indeks TB yang valid
	F.S. Ditampilkan semua bangunan dengan indeks TB tidak dalam list L yang terhubung dengan TB.TI[NoBangunan]
*/

int InfoConnectedBuildingByIdx(int NoBangunan, int idx, List L);
/*	Menghasilkan indeks TB yang direpresentasikan idx berdasarkan penomoran dari prosedur ConnectedBuildings*/

int InfoConnectedBuildingByIdx2(int NoBangunan, int idx, List L);
/*	Menghasilkan indeks TB yang direpresentasikan idx berdasarkan penomoran dari prosedur ConnectedBuildings2*/

int NBConnectedBuildings(int NoBangunan, List L);
/*	Menghasilkan jumlah bangunan dengan indeks TB dalam list L yang terhubung dengan TB.TI[NoBangunan] */

int NBConnectedBuildings2(int NoBangunan, List L);
/*	Menghasilkan jumlah bangunan dengan indeks TB tidak dalam list L yang terhubung dengan TB.TI[NoBangunan] */

void IndexLevelUp(List L, int idx);
/*	I.S. L dan TB terdefinisi
	F.S. Jika idx tidak valid, ditampilkan pesan "Upgrade gagal!"
		 Jika jumlah pasukan mencukupi, bangunan dengan indeks TB pada elemen L ke-idx di-levelup
		 Jika jumlah pasukan tidak mencukupi, ditampilkan pesan "Jumlah pasukan <Jenis> kurang untuk level up"
*/

void LevelUpAll(List L);
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan level di bawah 4 dengan indeks TB pada list L di-level up dengan prosedur LevelUpBangunan.
*/

void ShieldOn(List L);
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L diaktifkan pertahanannya
*/

void ShieldOff(List L);
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L dikembalikan pertahanannya ke keadaan aslinya
*/

void ReinforceAll(List L);
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L ditambahkan pasukannya sebanyaknya 5
*/

void BarrageAll(List Lenemy);
/*	I.S. Luser, Lenemy, dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L dikurang pasukannya sebanyaknya 10
*/

void AttackUpAll (List L);
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L dimatikan pertahanannya
*/

void AttackUpAllOff (List L);
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L dikembalikan pertahanannya ke keadaan aslinya
*/


#endif