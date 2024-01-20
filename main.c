#include <curses.h>
#include <stdio.h>
#include <unistd.h>

#define personaggio_PAIR 2
#define nemiciF_PAIR 1
#define altezza 15
#define lunghezza 31
#define personaggio "X"
#define nemiciF "O"
#define proiettileSprite "^"

int main()
{

    int left_right;
    int punteggio = 0;
    bool running = TRUE;

    initscr();
    raw();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    //curs_set(0);
    start_color();
    init_pair(nemiciF_PAIR, COLOR_RED, COLOR_BLACK);
    init_pair(personaggio_PAIR, COLOR_GREEN, COLOR_BLACK);

    clear();

    for (int y = altezza; y >= 0; y--)
    {
        mvprintw(y, 0, "#");
    }

    for (int y1 = altezza; y1 >= 0; y1--)
    {
        mvprintw(y1, lunghezza, "#");
    }

    for (int x = 0; x <= lunghezza; x++)
    {
        mvprintw(0, x, "#");
    }

    for (int x1 = 0; x1 <= lunghezza; x1++)
    {
        mvprintw(altezza, x1, "#");
    }

    int x = lunghezza / 2 + 1;

    attron(COLOR_PAIR(personaggio_PAIR));
    mvprintw(altezza - 1, x, personaggio);
    attroff(COLOR_PAIR(personaggio_PAIR));

    int nemici = 9;
    int nemicix;
    int nemiciy = 3;

    // attron(COLOR_PAIR(nemiciF_PAIR));
    for (int n = 2; n <= nemici;)
    {
        // mvhline(nemiciy, lunghezza / 2 - n + 1, nemiciF,COLS);
        attron(COLOR_PAIR(nemiciF_PAIR));
        mvprintw(nemiciy, lunghezza / 2 - n + 1, nemiciF);
        mvprintw(nemiciy, lunghezza / 2 + n + 1, nemiciF);
        attroff(COLOR_PAIR(nemiciF_PAIR));
        // mvhline(nemiciy, lunghezza / 2 - n + 1, nemiciF,COLS);
        n += 2;
    }
    // attroff(COLOR_PAIR(nemiciF_PAIR));

    mvprintw(0, lunghezza + 2, "Punteggio: %d", punteggio);
    

    while (running)
    {

        left_right = getch();

        if (left_right == KEY_LEFT)
        {

            if (x > 1)
            {
                attron(COLOR_PAIR(personaggio_PAIR));
                mvprintw(altezza - 1, x - 1, personaggio);
                mvprintw(altezza - 1, x, " ");
                attroff(COLOR_PAIR(personaggio_PAIR));
                x--;
            }
        }

        if (left_right == KEY_RIGHT)
        {

            if (x < lunghezza - 1)
            {
                attron(COLOR_PAIR(personaggio_PAIR));
                mvprintw(altezza - 1, x + 1, personaggio);
                mvprintw(altezza - 1, x, " ");
                attroff(COLOR_PAIR(personaggio_PAIR));
                x++;
            }
        }

        if ((left_right == 'q') && (left_right == 'Q'))
        {
            running = FALSE;
            clear();
            break;
        }

        if (left_right == KEY_UP)
        {

            for (int i = 1; i < altezza - 2; i++)
            {
                 
                attron(COLOR_PAIR(personaggio_PAIR));
                mvprintw(altezza - i - 1, x, proiettileSprite);
                attroff(COLOR_PAIR(personaggio_PAIR));
                refresh();
                mvprintw(altezza - i - 1, x, " ");
                delay_output(50);
                if(i - 1 == nemiciy && x ){
                    punteggio += 1;
                }
                mvprintw(0, lunghezza + 2, "Punteggio: %d", punteggio);
      
            }
        }

        if (left_right == 'r')
        {

            for (int n = 2; n <= nemici;)
            {
                attron(COLOR_PAIR(nemiciF_PAIR));
                mvprintw(nemiciy, lunghezza / 2 - n + 1, nemiciF);
                mvprintw(nemiciy, lunghezza / 2 + n + 1, nemiciF);
                attroff(COLOR_PAIR(nemiciF_PAIR));
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
               
               
               
