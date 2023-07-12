#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 200000
#define MAX_AMOUNT_ZERO 2000

int cnt_max_zero(char s[], int len_s) {  // считаем максивальное количсетво идущих подряд нулей
    int cnt_zero = 0;
    int tmp_z = 0;
    for (int i = 0; i < len_s; i++) {
        if (s[i] == '0') {
            tmp_z++;
        }

        if (s[i] == '1' || i == len_s - 1) {
            if (cnt_zero < tmp_z) {
                cnt_zero = tmp_z;
            }

            tmp_z = 0;
        }
    }

    return cnt_zero;
}

void make_str(char s[], int len, int ind, char a[]) { // функция записывает в строку a[] строку s[] со сдвигом (первый символ в a[] - символ s[ind])
    int k = 0;
    for (int i = ind; i < len; i++) {
        a[k] = s[i];
        k++;
    }

    for (int i = 0; i < ind; i++) {
        a[k] = s[i];
        k++;
    }
}

int check_cycle_zero(char s[], int len_s, int cnt_zero, int* jump, int* ind_cycle) {  // функция смотрит, есть ли нули в начале и конце s[], если есть, то проверяет, влияют ли они на ответ
    *ind_cycle = 0;

    if (s[0] == '0' && s[len_s - 1] == '0') {  // проверяем строку на нули в начале и в конце, если они есть, то их нужно посчитать вместе
        int tmp_z = 0;

        for (int i = 0; i < len_s; i++) {
            if (s[i] == '0') {
                tmp_z++;
            } else {
                break;
            }
        }

        for (int i = len_s - 1; i >= 0; i--) {
            if (s[i] == '0') {
                tmp_z++;
                *ind_cycle = i;
            } else {
                break;
            }
        }

        if (tmp_z >= len_s) {     // если строка состояля только из нулей, то ответ и есть сама строка s
            return tmp_z;
        }

        if (cnt_zero < tmp_z && tmp_z < len_s) {  // если нулей оказалось в этом случае максимальное количество, то ответ уже известен, возвращаем первый индекс ответа
            return *ind_cycle;
        }

        if (cnt_zero == tmp_z) {  // если максимально число нулей совпало с данным случаем, то использую метку jump = 1;
            *jump = 1;
        }
    }

    return -1;
}


void find_index_first_zero(int ind_zero[], int* p_len_ind, char s[], int len_s, int cnt_zero, int jump, int ind_cycle) { // заполняем массив ind_zero[] первыми индексами макимальных подпоследовательностей нулей, чтобы потом с помощью функции make_str создавать и сравнивать варианты ответов
    int ind = 0;
    int stage = 0;
    int tmp_z = 0;

    for (int i = 0; i < len_s; i++) {                             //    заполнение массива ind_zero
        if (s[i] == '0' && (stage == 0 || stage == 1)) {
            if (stage == 0) {
                ind = i;
                stage = 1;
            }

            tmp_z++;

            if (i == len_s - 1 && tmp_z == cnt_zero) {
                *p_len_ind += 1;
                ind_zero[*p_len_ind - 1] = ind;
            }
        }

        if (s[i] == '1') {
            if (tmp_z == cnt_zero) {
                *p_len_ind += 1;
                ind_zero[*p_len_ind - 1] = ind;
            }

            tmp_z = 0;
            stage = 0;
        }
    }

    if (jump == 1) {                              // добавление того самого случая "склеивания" начала и конца строки
        *p_len_ind += 1;
        ind_zero[*p_len_ind - 1] = ind_cycle;
    }

    return;
}


int main(void) {
    char s[MAX_LEN + 1];
    scanf("%2000000s", s);

    int len_s = strlen(s);
    int cnt_zero = cnt_max_zero(s, len_s);  // длина максимальной подпоследовательности нулей

    int jump = 0;                      // метка на случай если количество нулей в начале и в конце строки совпадает с cnt_zero

    int ind_cycle = 0;                // если подходит случай склеивания строки (начала и конца когда строка начинается и заканчивается на ноль), то это индекс первого нуля
    //int* p_ind_cycle = &ind_cycle;

    int res_cycle = check_cycle_zero(s, len_s, cnt_zero, &jump, &ind_cycle);

    if (res_cycle >= len_s) { // проверяем начало и конец строки     если ответ уже точно известен выходим
        printf("%s", s);

        return 0;
    } else if (res_cycle > 0) {
        char a[MAX_LEN + 1];
        make_str(s, len_s, res_cycle, a);
        printf("%s", a);

        return 0;
    }


    int ind_zero[MAX_AMOUNT_ZERO];     // индексы вхождений максимальных подпоследовательностей из нулей

    for (int i = 0; i < MAX_AMOUNT_ZERO; i++) {     // избавляемся от мусора
        ind_zero[i] = -1;
    }

    int len_ind = 0;             // будем считать с его помощью длину  ind_zero

    find_index_first_zero(ind_zero, &len_ind, s, len_s, cnt_zero, jump, ind_cycle);  // заполняем массив ind_zero

    char min_s[MAX_LEN + 1];               // будущий ответ
    char comparison[MAX_LEN + 1];          // строка для сравнений

    int first = ind_zero[0];          // первый индекс нуля для сравнения
    make_str(s, len_s, first, min_s);   // делаем строку начиная с этого индекса

    if (len_ind == 1) {           // если только 1 максимум то выводим ответ и выходим
        printf("%s", min_s);
        return 0;
    }

    for (int i = 1; i < len_ind; i++) {          // сравниваем все максимумы
        int check = ind_zero[i];
        make_str(s, len_s, check, comparison);
        int dif = strncmp(min_s, comparison, len_s);

        if (dif > 0) {
            strncpy (min_s, comparison, len_s);    // сохраняем в min_s минимальный вариант
        }
    }

    printf("%s", min_s);

    return 0;
}