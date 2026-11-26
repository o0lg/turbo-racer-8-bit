#include <ncurses.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int JUMLAH_MUSUH = 5;
const int BATAS_KIRI = 1;
const int BATAS_KANAN = 15;
const int TINGGI_JALAN = 20;

int px = 8;
int nyawa = 3;
int skor = 0;
int rekor = 0;
int frame = 0;

int ex[JUMLAH_MUSUH];
int ey[JUMLAH_MUSUH];

void inisialisasiGame() {
    srand(time(0));

    for (int i = 0; i < JUMLAH_MUSUH; i++) {
        ey[i] = -1;
    }

    ifstream baca("skor.txt");
    if (baca.is_open()) {
        baca >> rekor;
        baca.close();
    }

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    mvprintw(5, 3, "TURBO RACER 8-BIT");
    mvprintw(7, 3, "Hindari mobil V !");
    mvprintw(8, 3, "Nyawa: 3. Habis = GAME OVER");
    mvprintw(10, 3, "Tekan tombol apa saja...");
    getch();
}

void prosesKontrolPemain() {
    int delay = 120 - skor * 2;

    if (delay < 40) {
        delay = 40;
    }

    timeout(delay);
    int ch = getch();

    if (ch == KEY_LEFT && px > BATAS_KIRI) {
        px--;
    }
    else if (ch == KEY_RIGHT && px < BATAS_KANAN) {
        px++;
    }
    else if (ch == 'q') {
        nyawa = 0;
    }
}

void munculkanMusuh() {
    if (rand() % 3 == 0) {
        int i = rand() % JUMLAH_MUSUH;

        if (ey[i] == -1) {
            ex[i] = 1 + rand() % 15;
            ey[i] = 0;
        }
    }
}
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
void jalankanGame() {
    while (nyawa > 0) {
        prosesKontrolPemain();

        if (nyawa <= 0) {
            break;
        }

        munculkanMusuh();
        gambarJalan();
        prosesMusuh();
        gambarPemain();
        tampilkanInformasi();
    }
}

void simpanRekor() {
    if (skor > rekor) {
        ofstream tulis("skor.txt");

        if (tulis.is_open()) {
            tulis << skor;
            tulis.close();
        }
    }
}

void tampilkanGameOver() {
    clear();

    mvprintw(8, 5, "GAME OVER");
    mvprintw(10, 5, "Skor kamu: %d", skor);
    mvprintw(12, 5, "Tekan tombol apa saja...");

    refresh();
    timeout(-1);
    getch();
    endwin();
}

int main() {
    inisialisasiGame();
    jalankanGame();
    simpanRekor();
    tampilkanGameOver();

    return 0;
}
