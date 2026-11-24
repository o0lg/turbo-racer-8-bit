#include <ncurses.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int px = 8, nyawa = 3, skor = 0, rekor = 0, frame = 0;
    int ex[5], ey[5];
    for (int i = 0; i < 5; i++) ey[i] = -1;

    ifstream baca("skor.txt");
    baca >> rekor;
    baca.close();

    initscr();
    cbreak(); noecho(); curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    mvprintw(5, 3, "TURBO RACER 8-BIT");
    mvprintw(7, 3, "Hindari mobil V !");
    mvprintw(8, 3, "Nyawa: 3. Habis = GAME OVER");
    mvprintw(10, 3, "Tekan tombol apa saja...");
    getch();

    while (nyawa > 0) {
        int delay = 120 - skor * 2;
        if (delay < 40) delay = 40;
        timeout(delay);
        int ch = getch();

        if (ch == KEY_LEFT && px > 1) px--;
        else if (ch == KEY_RIGHT && px < 15) px++;
        else if (ch == 'q') break;

        if (rand() % 3 == 0) {
            int i = rand() % 5;
            if (ey[i] == -1) {
                ex[i] = 1 + rand() % 15;
                ey[i] = 0;
            }
        }

        clear();
        frame++;

        for (int y = 0; y < 20; y++) {
            mvaddch(y, 0, '|');
            mvaddch(y, 16, '|');
            if ((y + frame) % 4 < 2) mvaddch(y, 8, '.');
        }

        for (int i = 0; i < 5; i++) {
            if (ey[i] == -1) continue;
            ey[i]++;

            if (ey[i] == 18 && ex[i] == px) {
                nyawa--;
                ey[i] = -1;
                beep();
            } else if (ey[i] > 19) {
                ey[i] = -1;
                skor++;
            } else {
                attron(COLOR_PAIR(2));
                mvaddch(ey[i], ex[i], 'V');
                attroff(COLOR_PAIR(2));
            }
        }

        attron(COLOR_PAIR(1));
        mvaddch(18, px, 'A');
        attroff(COLOR_PAIR(1));

        mvprintw(1, 19, "SKOR  : %d", skor);
        mvprintw(2, 19, "REKOR : %d", rekor);
        mvprintw(3, 19, "NYAWA : %d", nyawa);
        refresh();
    }

    if (skor > rekor) {
        ofstream tulis("skor.txt");
        tulis << skor;
        tulis.close();
    }

    clear();
    mvprintw(8, 5, "GAME OVER");
    mvprintw(10, 5, "Skor kamu: %d", skor);
    mvprintw(12, 5, "Tekan tombol apa saja...");
    refresh();
    timeout(-1);
    getch();
    endwin();

    return 0;
}
