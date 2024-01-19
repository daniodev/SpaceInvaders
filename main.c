#include <curses.h>
#include <stdio.h>
#include <unistd.h>

#include "movement.c"
#include "shoot.c"

#define altezza 15
#define lunghezza 31
#define personaggio "X"
#define nemiciF "O"
#define proiettileSprite "^"


int main(){

    int KEY;
    int punteggio = 0;
    bool running = TRUE;

    initscr();
    raw();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);

    for(int y = altezza; y >= 0; y--){
        mvprintw(y, 0, "#");
    }

    for(int y1 = altezza; y1 >= 0; y1--){
        mvprintw(y1, lunghezza, "#");
    }

    for(int x = 0; x <= lunghezza; x++){
        mvprintw(0, x, "#");
    }

    for(int x1 = 0; x1 <= lunghezza; x1++){
        mvprintw(altezza, x1, "#");
    }

    int x = lunghezza / 2 + 1 ;

    mvprintw(altezza - 1, x, personaggio); 


    int nemici = 9;
    int nemicix;
    int nemiciy = 3;

    for(int n = 2; n <= nemici;){

        mvprintw(nemiciy, lunghezza / 2 - n + 1, nemiciF);
        mvprintw(nemiciy, lunghezza / 2 + n + 1, nemiciF);
        n += 2;

        }

    mvprintw(0, lunghezza + 2, "Punteggio: %d", punteggio);

    while (running){


        KEY = getch();

        if(KEY == KEY_LEFT ){

            if(x > 1){

            mvprintw(altezza - 1, x - 1, personaggio);
            mvprintw(altezza - 1, x, " ");

            x--;
            }
        }

        if(KEY == KEY_RIGHT){

            if(x < lunghezza - 1){

            mvprintw(altezza - 1, x + 1, personaggio);
            mvprintw(altezza - 1, x, " ");

            x++;
            }
        }

        if(KEY == 'q'){
            running = FALSE;
            clear();
            break;
        }

        if(KEY == KEY_UP){

            for(int i = 1; i < altezza - 2; i++ ){


                mvprintw(altezza - i - 1, x, proiettileSprite);
                refresh();
                mvprintw(altezza - i - 1, x, " ");
                delay_output(50);


                if(i - 1 == nemiciy && x ){
                    punteggio += 1;
                }
                mvprintw(0, lunghezza + 2, "Punteggio: %d", punteggio);
        }
        }

        if(KEY == 'r'){

            for(int n = 2; n <= nemici;){

                mvprintw(nemiciy, lunghezza / 2 - n + 1, nemiciF);
                mvprintw(nemiciy, lunghezza / 2 + n + 1, nemiciF);
                n += 2;

        }

        punteggio = 0; 
        mvprintw(0, lunghezza + 2, "Punteggio: %d", punteggio);

        }

        refresh();

    }
    

    refresh();
    endwin();

}