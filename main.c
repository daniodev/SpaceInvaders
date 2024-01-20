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

    init_pair(nemiciSprite_PAIR, COLOR_RED, COLOR_BLACK);
    init_pair(personaggio_PAIR, COLOR_GREEN, COLOR_BLACK);

    gameBox();

    int x = lunghezza / 2 + 1;

    attron(COLOR_PAIR(personaggio_PAIR));
    mvprintw(altezza - 1, x, personaggioSprite);
    attroff(COLOR_PAIR(personaggio_PAIR));

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


                int posizioneNemici = mvinch(altezza - 2 - i, x);
                char charPosNemici = (char) posizioneNemici;

                if(charPosNemici == nemiciSpriteCh){
                    punteggio++;
                    punteggioUpdate(punteggio, NumNemici);

                    mvprintw(altezza - 2 -i , x, " ");

                    NumNemici -= 1;

                    break;
                    refresh();
                    
                }
                

                attron(COLOR_PAIR(personaggio_PAIR));
                mvprintw(altezza - i - 1, x, proiettileSprite);
                attroff(COLOR_PAIR(personaggio_PAIR));
                refresh();
                mvprintw(altezza - i - 1, x, " ");
                delay_output(50);
            }
        }

        if (left_right == 'r'){
            nemiciSpawn(nemiciy, NumNemici);

            punteggio = 0;
            NumNemici = 0;
            punteggioUpdate(punteggio, NumNemici);
        }
        
        refresh();
    }

    refresh();
    endwin();
}
