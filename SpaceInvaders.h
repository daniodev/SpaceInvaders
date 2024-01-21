

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

void colorOn(chtype ch){

    if(ch == COLOR_RED){
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
    }

    if(ch == COLOR_WHITE){
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(2));
    }

    if(ch == COLOR_GREEN){
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(3)); 
    }

}


void movement_left(int x){

    colorOn(COLOR_GREEN);
    mvprintw(altezza - 1, x - 1, personaggioSprite);
    mvprintw(altezza - 1, x, " ");

}

void movement_right(int x){

    colorOn(COLOR_GREEN);
    mvprintw(altezza - 1, x + 1, personaggioSprite);
    mvprintw(altezza - 1, x, " ");

}

void shoot(int x, int i){

    colorOn(COLOR_GREEN);
    mvprintw(altezza - i - 1, x, proiettileSprite);
    refresh();
    mvprintw(altezza - i - 1, x, " ");
    delay_output(50);
    
}

void game_end(){
    clear();
    getch();
}

void nemiciSpawn(int nemiciy, int NumNemici){

    for (int n = 2; n <= NumNemici;){

    mvprintw(nemiciy, lunghezza / 2 - n + 1, nemiciSprite);
    mvprintw(nemiciy, lunghezza / 2 + n + 1, nemiciSprite);

    n += 2;

    }
}

void punteggioUpdate(int punteggio, int NumNemici){

    colorOn(COLOR_WHITE);

    mvprintw(0, lunghezza + 2, "Punteggio: %d", punteggio);
    mvprintw(1, lunghezza + 2, "Nemici: %d", NumNemici);
}

void colpoVeify(int x, int i, int punteggio, int NumNemici, char charPosizioneColpo, int posizioneColpo){

    if(charPosizioneColpo == nemiciSpriteCh){

    punteggio++;
    punteggioUpdate(punteggio, NumNemici);
    mvprintw(altezza - 2 -i , x, " ");

    NumNemici -= 1;
    refresh();
                    
    }
}