#include <stdio.h>

#define M 3 // Ilosc wierszy planszy

#define N 3 // Ilosc kolumn planszy

void wyswietl_plansze(char *tab, int m, int n);

void rozgrywka(char *tab, int m, int n);

int main() {
    char plansza[M][N] = {{' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '}};
    rozgrywka((char *) plansza, M, N);
    return 0;
}

/**
 * Funkcja wyswietlajaca aktualny stan planszy
 *
 * @param tab   Plansza
 * @param m     Ilosc wierszy planszy
 * @param n     Ilosc kolumn planszy
 */
void wyswietl_plansze(char *tab, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (j == n - 1) {
                printf(" %c\n", *((tab + i * n) + j));
            } else {
                printf(" %c |", *((tab + i * n) + j));
            }
        }
        if (i < m - 1) {
            printf("---+---+---\n");
        } else;
    }

}

/**
 * Funkcja przeprowadzajaca rozgrywke na podanej planszy
 * Gra trwa 9 tur
 * W turach parzystych wstawiany jest O, a w nieparzystych X
 * @param tab   Plansza
 * @param m     Ilosc wierszy planszy
 * @param n     Ilosc kolumn planszy
 */
void rozgrywka(char *tab, int m, int n) {
    int pole = 0; //Przechowuje numer pola wybranego przez gracza
    wyswietl_plansze(tab, m, n);
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            printf("Gracz O\n");
        } else {
            printf("Gracz X\n");
        }
        printf("Wybierz pole [1-9]:\n");
        scanf("%d", &pole);
        pole--;
        if (pole >= 0 && pole < M * N) {
            if (*(tab + pole) == ' ') {
                if (i % 2 == 0) {
                    *(tab + pole) = 'O';
                } else {
                    *(tab + pole) = 'X';
                }
            } else {
                printf("Pole jest zajete\n");
                i--;
            }
        } else {
            printf("Pole poza zakresem\n");
            i--;
        }
        wyswietl_plansze(tab, m, n);
    }
}
