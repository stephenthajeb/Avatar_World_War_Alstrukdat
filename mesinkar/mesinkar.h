/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean/boolean.h"

#define MARK '.'
#define ENDCOMMAND '\n'
/* State Mesin */
extern char CC;
extern boolean EOP;


void START(char *filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

void CLOSE();
/* I.S. : sembarang
   F.S. : pembacaan pita dihentikan dan pita di-close */


void SCAN();
/* I.S. : sembarang
   F.S. : membaca karakter yang ada pada pita */

#endif