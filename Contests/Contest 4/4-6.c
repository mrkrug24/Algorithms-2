#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 1000000

int main(void) {
    char s[LEN + 1];
    scanf("%1000000s", s);

    int len_s = strlen(s);

    int odd[LEN + 1];
    int cnt_odd = 0;

    int even[LEN + 1];
    int cnt_even = 0;

    for (int i = 0; i < len_s; i++) {
        if (s[i] == 'A') {
            if (i % 2 == 0) {
                cnt_odd++;
            } else {
                cnt_even++;
            }
        }

        odd[i] = cnt_odd;
        even[i] = cnt_even;
    }

    int first_odd = odd[0];
    int first_even = even[0];

    if (odd[len_s - 1] - first_odd == even[len_s - 1] - first_even) {  // проверяем можем ли вычеркнуть 1 букву
        printf("%d ", 1);                                              // рассматриваю отдельно, так как другой способ сравнения (в главном есть например odd[i - 1] - не получится рассматривать с i = 0)
    }

    for (int i = 1; i < len_s - 1; i++) {                          // главный цикл - рассматриваем все буквы кроме первой и последней
        int sum_odd = odd[i - 1] + even[len_s - 1] - even[i];      // cчитаю количество букв на нечетных местах после вычеркивания: (количество всех букв на нечетных местах до i) + (количсество букв после i, которые до вычеркивания стояли на четных местах, т.к. после вычеркивания их четность поменялась)

        int sum_even = even[i - 1] + odd[len_s - 1] - odd[i];      // аналогично

        if (sum_odd == sum_even) {
            printf("%d ", i + 1);
        }
    }

    if (odd[len_s - 2] == even[len_s - 2]) {        // проверяем, можем ли вычеркнуть последнюю букву
        printf("%d ", len_s);                       // отдельно, так как главный цикл не подходит под логичное сраненение предпоследних элементов odd и even
    }

    return 0;
}