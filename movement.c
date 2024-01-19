#include <stdio.h>

#define altezza 15
#define lunghezza 31
#define personaggio "X"
#define nemiciF "O"
#define proiettileSprite "^"

int movement_right(int x){
    if(x < lunghezza - 1){

        mvprintw(altezza - 1, x + 1, personaggio);
        mvprintw(altezza - 1, x, " ");

        x++;
    }
}