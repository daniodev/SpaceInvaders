

#define personaggio_PAIR 1
#define nemiciSprite_PAIR 2

#define altezza 15
#define lunghezza 31

#define personaggioSprite "X"
#define nemiciSprite "O"
#define nemiciSpriteCh 'O'
#define proiettileSprite "^"



void gameBox(){

    for (int y = altezza; y >= 0; y--){
        mvprintw(y, 0, "#");
        mvprintw(y, lunghezza, "#");
    }
    for (int x = 0; x <= lunghezza; x++){
        mvprintw(0, x, "#");
        mvprintw(altezza, x, "#");
    }
}


void movement_left(int x){

    attron(COLOR_PAIR(personaggio_PAIR));
    mvprintw(altezza - 1, x - 1, personaggioSprite);
    mvprintw(altezza - 1, x, " ");
    attroff(COLOR_PAIR(personaggio_PAIR));

}

void movement_right(int x){

    attron(COLOR_PAIR(personaggio_PAIR));
    mvprintw(altezza - 1, x + 1, personaggioSprite);
    mvprintw(altezza - 1, x, " ");
    attroff(COLOR_PAIR(personaggio_PAIR));

}

void shoot(int x){

    for (int i = 1; i < altezza - 2; i++){

    attron(COLOR_PAIR(personaggio_PAIR));
    mvprintw(altezza - i - 1, x, proiettileSprite);
    attroff(COLOR_PAIR(personaggio_PAIR));
    refresh();
    mvprintw(altezza - i - 1, x, " ");
    delay_output(50);     
    }
}

void game_end(){
    clear();
    getch();
}

void nemiciSpawn(int nemiciy, int NumNemici){

    for (int n = 2; n <= NumNemici;){

    attron(COLOR_PAIR(nemiciSprite_PAIR));

    mvprintw(nemiciy, lunghezza / 2 - n + 1, nemiciSprite);
    mvprintw(nemiciy, lunghezza / 2 + n + 1, nemiciSprite);

    attroff(COLOR_PAIR(nemiciSprite_PAIR));
    n += 2;

    }
}

void punteggioUpdate(int punteggio, int NumNemici){
    mvprintw(0, lunghezza + 2, "Punteggio: %d", punteggio);
    mvprintw(1, lunghezza + 2, "Nemici: %d", NumNemici);
}