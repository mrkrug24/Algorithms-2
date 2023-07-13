#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char s[], int p[], int n) {
    int i = 0;  // начальный символ для сравнения, двигаем его только при равенстве, иначе возвращаем в начало
    int j = 1;  // пробегает по всей строке
    p[0] = 0;   // по определению

    while (j < n) {
        if (s[i] == s[j]) {
            p[j++] = ++i;

        } else {
            p[j++] = 0;
            i = 0;
        }
    }
}

int* seek_substring_KMP (char p[]) {
	int i, j, N;
	N = strlen(p);

	int *d = (int*)malloc(N * sizeof(int)); // Динамический массив длины М
	d[0] = 0;                               // Вычисление префикс-функции
    
	for(i = 1, j = 0; i < N; i++) {
		while(j > 0 && p[j] != p[i])
			j = d[j-1];

		if (p[j] == p[i]) j++;
		d[i] = j;
	}

    return d;
}

int kmp (char text[], char pat[], int len_text, int len_pat) {
    int i = 0;
    int j = 0;

    int pref[len_pat];
    prefix(pat, pref, len_pat);

    while(j < len_pat) {
        if (i >= len_text) {
            return -1;
        }

        if (text[i] == pat[j]) {
            i++;
            j++;

        } else {
            if (j > 0) {
                j = pref[j - 1];    // двигаю так, чтобы не считать уже точно подходящие символы стоящие в начале pat

            } else {
                if (text[i] != pat[j]) i++;
            }
        }
    }

    return i - len_pat;
}

int main(void) {
    char text[] ="ababbabababa";        // Пример
    int* p = seek_substring_KMP(text);

    for (int i = 0; i < 12; i++) {
        printf("%d ", p[i]);
    }

    printf("\n" );

    for (int i = 0; i < 12; i++) {
        printf("%c ", text[i]);
    }

    return 0;
}