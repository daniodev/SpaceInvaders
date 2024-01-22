#include <curses.h>
#include <stdio.h>
#include <unistd.h>

#include "SpaceInvaders.h"

int main()
{

    int left_right;
    int punteggio = 0;
    bool running = TRUE;

    initscr();
    raw();
    cbreak();
    noecho();
    curs_set(0);
    start_color();

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);
    start_color();

    gameBox();

    int x = lunghezza / 2 + 1;

    colorOn(COLOR_GREEN);
    mvprintw(altezza - 1, x, personaggioSprite);

    int NumNemici = 6;
    int nemiciy = 3;

    nemiciSpawn(nemiciy, NumNemici);
    punteggioUpdate(punteggio, NumNemici);

    while (running){
        left_right = getch();

        if (left_right == KEY_LEFT){

            if (x > 1){
            movement_left(x);
            x--;
            }

        }

        if (left_right == KEY_RIGHT){
            if (x < lunghezza - 1){
                movement_right(x);
                x++;
            }
        }

        if ((left_right == 'q') || (left_right == 'Q')){
            game_end();
            break;
        }

        if (left_right == KEY_UP){


            for (int i = 1; i < altezza - 2; i++){
                int posizioneColpo = mvinch(altezza - 2 - i, x);
                char charPosizioneColpo = (char) posizioneColpo;

                if(charPosizioneColpo == nemiciSpriteCh){

                    punteggio++;
                    NumNemici--;
                    punteggioUpdate(punteggio, NumNemici);
                    mvprintw(altezza - 2 -i , x, " ");

                    refresh();
                    break;

                }
                shoot(x, i);

            }
        }

        if (left_right == 'r'){
            NumNemici = 6;
            nemiciSpawn(nemiciy, NumNemici);
            punteggio = 0;
            punteggioUpdate(punteggio, NumNemici);
            refresh();
        }
        
        refresh();
    }

    refresh();
    endwin();
}
