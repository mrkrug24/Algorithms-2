#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//СОЗДАНИЕ ГЛОБАЛЬНЫХ ПЕРЕМЕННЫХ ДЛЯ ПОДСЧЕТА КОЛИЧЕСТВА СРАВНЕНИЙ И ПЕРЕСТАНОВОК
//ВО ВРЕМЯ ВЫПОЛНЕНИЯ СОРТИРОВОК
static int cnt_selection_sort_cmp = 0;
static int cnt_selection_sort_swap = 0;
static int cnt_shell_sort_cmp = 0;
static int cnt_shell_sort_swap = 0;

//ФУНКЦИЯ ПЕРЕСТАНОВКИ ЭЛЕМЕНТОВ МАССИВА
void swap(long long *a, long long *b) {
    long long tmp = *a;
    *a = *b;
    *b = tmp;
}

//ФУНКЦИЯ СОРТИРОВКИ ВЫБОРОМ
void selection_sort(long long *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind_max = i;

        for (int j = i + 1; j < n; j++) {
            cnt_selection_sort_cmp++;

            if (fabs(arr[ind_max]) < fabs(arr[j])) {
                ind_max = j;
            }
        }

        if (ind_max != i) {
            swap(&arr[ind_max], &arr[i]);
            cnt_selection_sort_swap++;
        }
    }
}

// ФУНКЦИЯ СОРТИРОВКИ МЕТОДОМ ШЕЛЛА
void shell_sort(long long* arr, int n) {
    int step = n / 2;

    while (step > 0) {
        for (int i = step; i < n; i++) {
            int cur_ind = i;
            long long cur_val = arr[i];
        
            while (cur_ind >= step) {
                cnt_shell_sort_cmp++;

                if (fabs(arr[cur_ind - step]) < fabs(cur_val)) {
                    arr[cur_ind] = arr[cur_ind - step];
                    cur_ind -= step;
                    arr[cur_ind] = cur_val;

                    cnt_shell_sort_swap++;
                } else {
                    break;
                }
            }
        }

        step /= 2;
    }
}

//ФУНКЦИЯ СРАВНЕНИЯ ДЛЯ ГЕНЕРАЦИИ УПОРЯДОЧЕННОГО МАССИВА
int straight_ordered_compare(const void* a, const void* b) {
    if (fabs(*((long long*)a)) < fabs(*((long long*)b))) {
        return 1;
    } else if (fabs(*((long long*)a)) > fabs(*((long long*)b))) {
        return -1;
    }

    return 0;              
}

//ФУНКЦИЯ СРАВНЕНИЯ ДЛЯ ГЕНЕРАЦИИ УПОРЯДОЧЕННОГО В ОБРАТНОМ ПОРЯДКЕ МАССИВА
int reverse_ordered_compare(const void* a, const void* b) {
    if (fabs(*((long long*)a)) > fabs(*((long long*)b))) {
        return 1;
    } else if (fabs(*((long long*)a)) < fabs(*((long long*)b))) {
        return -1;
    }

    return 0;              
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//В Постановке задания сказно:
// Каждый из предложенных методов сортировки и генерации массива оформляется в виде отдельной
// Си-функции. Функции не имеют возвращаемых значений и ПРИНИМАЮТ ПО ДВА ПАРАМЕТРА: ЧИСЛО n 
// И МАССИВ a. 
// Следовательно мне пришлось написать 3 отдельных функции для 3 случаев.

//ФУНКЦИЯ ГЕНЕРАЦИИ ЗНАЧЕНИЙ УПОРЯДОЧЕННОГО МАССИВА
void straight_ordered_array_generating(long long* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() * rand() * rand() * rand() * rand();
    }

    qsort(arr, n, sizeof(long long), straight_ordered_compare);
}

//ФУНКЦИЯ ГЕНЕРАЦИИ ЗНАЧЕНИЙ МАССИВА УПОРЯДОЧЕННОГО В ОБРАТНОМ ПОРЯДКЕ 
void reverse_ordered_array_generating(long long* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() * rand() * rand() * rand() * rand();
    }

    qsort(arr, n, sizeof(long long), reverse_ordered_compare);
}

//ФУНКЦИЯ ГЕНЕРАЦИИ ЗНАЧЕНИЙ НЕУПОРЯДОЧЕННОГО МАССИВА
void random_array_generating(long long* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() * rand() * rand() * rand() * rand();
    }
}

//ФУНКЦИЯ ВЫВОДА МАССИВА
void print_array(long long* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }

    printf("\n");
}

//ФУНКЦИЯ ПОИСКА СРЕДНЕГО ЗНАЧЕНИЯ В МАССИВЕ
double find_average_value(int* arr, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum / n;
}

//ФУНКЦИЯ ОСВОБОЖДЕНИЯ ПАМЯТИ ВЫДЕЛЕННОЙ ПОД ДВУМЕРНЫЙ МАССИВ
void free_up_memory_of_matrix(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]); 
    }

    free(arr); 
}

//ФУНКЦИЯ ВЫВОДА ЗАГОЛОВКОВ ТАБЛИЦЫ
void print_header(char* name) {
    printf(" _________________________________________________________________________________________\n");
    printf("|                                                                                         |\n");
    printf("|                                                                                         |\n");
    printf("|                                     %s                                     |\n", name);
    printf("|                                                                                         |\n");
    printf("|_________________________________________________________________________________________|\n");
    printf("|       |           |             |             |             |             |             |\n");
    printf("|   N   | Parameter |   Straight  |   Reverse   |    Random   |    Random   |   Average   |\n");
    printf("|_______|___________|_____________|_____________|_____________|_____________|_____________|\n");
}

//ФУНЦИЯ ВЫВОДА ПОСЛЕДНЕЙ СТРОКИ ТАБЛИЦЫ
void print_footer() {
    printf("|_______|___________|_____________|_____________|_____________|_____________|_____________|\n\n");
}


int main(void) {
    //ВЫБОР РЕЖИМА РАБОТЫ
    printf("\nSelect the program operation mode:\n");
    printf("\t 1 - Сompare select sort and shell sort by yourself\n");
    printf("\t 2 - View the result of a full comparison\n\n");

    printf("Enter the selected mode: ");
    int mode;
    scanf("%d", &mode);

    srand(time(NULL));

    //ВЫПОЛНЕНИЕ ПЕВОГО РЕЖИМА РАБОТЫ
    if (mode == 1) {
        int n;
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);

        //ВЫДЕЛЕНИЕ ПАМЯТИ ДЛЯ 2 МАССИВОВ: ДЛЯ СОРТИРОВКИ ВЫБОРОМ И МЕТОДОМ ШЕЛЛА
        long long* arr_for_selection_sort = (long long*)malloc(sizeof(long long) * n);
        long long* arr_for_shell_sort = (long long*)malloc(sizeof(long long) * n);

        //ВЫБОР УПОРЯДОЧИВАНИЯ ЭЛЕМЕНТОВ В ГЕНЕРИРУЕМОМ МАССИВЕ
        printf("\nSelect the type of array to generate:\n");
        printf("\t 1 - Straight ordered\n");
        printf("\t 2 - Reverse ordered\n");
        printf("\t 3 - Unsorted\n\n");
        printf("Enter the type: ");

        int type;
        scanf("%d", &type);

        //ЗАПОЛНЕНИЕ ОДНОГО МАССИВА CОГЛАСНО ВЫБОРУ УПОРЯДОЧИВАНИЯ ЭЛЕМЕНТОВ 
        if (type == 1) {
            straight_ordered_array_generating(arr_for_selection_sort, n);
        } else if (type == 2) {
            reverse_ordered_array_generating(arr_for_selection_sort, n);
        } else if (type == 3) {
            random_array_generating(arr_for_selection_sort, n);
        } else {
            printf("ERROR: You have chosen a non-existent array generation type\n");
            return 0;
        }

        //КОПИРОВАНИЕ ЗНАЧЕНИЙ ОДНОГО МАССИВА В ДРУГОЙ
        memcpy(arr_for_shell_sort, arr_for_selection_sort, sizeof(long long) * n);
        
        //ВЫБОР - ВЫВОДИТЬ ИЛИ НЕ ВЫВОДИТЬ СГЕНЕРИРОВАННЫЙ И ОТСОРТИРОВАННЫЕ МАССИВЫ
        getchar();
        char ans = ' ';
        printf("\nDou you want to print generated and sorted arrays? (y/n): ");
        ans = getchar();

        if (ans == 'y' || ans == '\n') {
            printf("\n\t Generated array: \n\t\t");
            print_array(arr_for_selection_sort, n);
        }

        //ВЫПОЛНЕНИЕ СОРТИРОВКИ 2 СПОСОБАМИ НА РАВНЫХ МАССИВАХ
        selection_sort(arr_for_selection_sort, n);
        shell_sort(arr_for_shell_sort, n);

        if (ans == 'y' || ans == '\n') {
            printf("\n\t Array sorted by selection sort: \n\t\t");
            print_array(arr_for_selection_sort, n);
            printf("\n\t Array sorted by shell sort: \n\t\t");
            print_array(arr_for_shell_sort, n);
            printf("\n\n");
        }

        //ВЫВОД ТАБЛИЦЫ С РЕЗУЛЬТАТАМИ СРАВНЕНИЯ СОРТИРОВОК
        printf(" ___________________________________________ \n");
        printf("|               |             |             |\n");
        printf("|     SORT      | COMPARISONS |  MOVEMENTS  |\n");
        printf("|_______________|_____________|_____________|\n");
        printf("|Selection sort | %12d| %12d|\n", cnt_selection_sort_cmp, cnt_selection_sort_swap);
        printf("|Shell sort     | %12d| %12d|\n", cnt_shell_sort_cmp, cnt_shell_sort_swap);
        printf("|_______________|_____________|_____________|\n\n");

        //ОСВОБОЖДЕНИЕ ПАМЯТИ ВЫДЕЛЕННОЙ ПОД МАCCИВЫ ДЛЯ СОРТИРОВОК
        free(arr_for_selection_sort);
        free(arr_for_shell_sort);
    } 

    //ВЫПОЛНЕНИЕ ВТОРОГО РЕЖИМА РАБОТЫ
    if (mode == 2) {
        //ОБЪЯВЛЕНИЕ РАЗМЕРОВ ТАБЛИЦЫ АНАЛИЗА ВЫПОЛНЕНИЯ СОРТИРОВКИ
        int number_of_matrix_rows = 8;
        int number_of_matrix_columns = 4; 

        //ВЫДЕЛЕНИЕ ПАМЯТИ ДЛЯ 2 ТАБЛИЦ АНАЛИЗА ВЫПОЛНЕНИЯ СОРТИРОВКИ: ВЫБОРОМ И МЕТОДОМ ШЕЛЛА
        int** results_for_selection_sort = (int**)malloc(sizeof(int*) * number_of_matrix_rows);
        int** results_for_shell_sort = (int**)malloc(sizeof(int*) * number_of_matrix_rows);

        for (int i = 0; i < number_of_matrix_rows; i++) {
            results_for_selection_sort[i] = (int*)malloc(sizeof(int) * number_of_matrix_columns);
            results_for_shell_sort[i] = (int*)malloc(sizeof(int) * number_of_matrix_columns);
        }

        //ВЫДЕЛЕНИЕ ПАМЯТИ ДЛЯ МАССИВОВ СРЕДНИХ ЗНАЧЕНИЙ КОЛИЧЕСТВА СРАВНЕНИЙ И ПЕРЕМЕЩЕНИЙ
        double* average_value_for_selection_sort = (double*)malloc(sizeof(double) * number_of_matrix_rows);
        double* average_value_for_shell_sort = (double*)malloc(sizeof(double) * number_of_matrix_rows);

        int n = 10;
        
        //ЗАПОЛНЕНИЕ ТАБЛИЦ
        for (int stage = 0; stage < 4; stage++) {
            //ВЫДЕЛЕНИЕ ПАМЯТИ ДЛЯ 2 МАССИВОВ: ДЛЯ СОРТИРОВКИ ВЫБОРОМ И МЕТОДОМ ШЕЛЛА
            long long* arr_for_selection_sort = (long long*)malloc(sizeof(long long) * n);
            long long* arr_for_shell_sort = (long long*)malloc(sizeof(long long) * n);

            //ЗАПОЛНЕНИЕ ПО СТРОКАМ
            for (int type = 0; type < 5; type++) {
                //ЗАПОЛНЕНИЕ ТАБЛИЦЫ
                if (type != 4) {
                    //ЗАПОЛНЕНИЕ ОДНОГО МАССИВА ЗНАЧЕНИЯМИ
                    //ПЕРВЫЙ СТОЛБЕЦ ДЛЯ УПОРЯДОЧЕННЫX МАССИВОВ 
                    if (type == 0) {
                        straight_ordered_array_generating(arr_for_selection_sort, n);
                    
                    //ВТОРОЙ СТОЛБЕЦ ДЛЯ МАССИВОВ УПОРЯДОЧЕННЫX В ОБРАТНОМ ПОРЯДКЕ
                    } else if (type == 1) {
                        reverse_ordered_array_generating(arr_for_selection_sort, n);

                    //ТРЕТИЙ И ЧЕТВЕРТЫЙ ДЛЯ НЕУПОРЯДОЧЕННЫХ МАССИВОВ
                    } else {
                        random_array_generating(arr_for_selection_sort, n);
                    }

                    //КОПИРОВАНИЕ ЗНАЧЕНИЙ ОДНОГО МАССИВА В ДРУГОЙ
                    memcpy(arr_for_shell_sort, arr_for_selection_sort, sizeof(long long) * n);

                    //ВЫПОЛНЕНИЕ СОРТИРОВОК НА РАВНЫХ МАССИВАХ
                    selection_sort(arr_for_selection_sort, n);
                    shell_sort(arr_for_shell_sort, n);

                    //ЗАПОЛНЕНИЕ ТАБЛИЦ АНАЛИЗА ВЫПОЛНЕНИЯ СОРТИРОВОК
                    results_for_selection_sort[2 * stage][type] = cnt_selection_sort_cmp;
                    results_for_selection_sort[2 * stage + 1][type] = cnt_selection_sort_swap;
                    
                    results_for_shell_sort[2 * stage][type] = cnt_shell_sort_cmp;
                    results_for_shell_sort[2 * stage + 1][type] = cnt_shell_sort_swap;

                    //ОБНУЛЕНИЕ СЧЕТЧИКОВ
                    cnt_selection_sort_cmp = 0;
                    cnt_selection_sort_swap = 0;
                    cnt_shell_sort_cmp = 0;
                    cnt_shell_sort_swap = 0;

                //ЗАПОЛНЕНИЕ МАССИВОВ СРЕДНИМИ ЗНАЧЕНИЯМИ
                } else {
                    average_value_for_selection_sort[2* stage] = find_average_value(results_for_selection_sort[2 * stage], number_of_matrix_columns - 1);
                    average_value_for_selection_sort[2* stage + 1] = find_average_value(results_for_selection_sort[2 * stage + 1], number_of_matrix_columns - 1);

                    average_value_for_shell_sort[2* stage] = find_average_value(results_for_shell_sort[2 * stage], number_of_matrix_columns - 1);
                    average_value_for_shell_sort[2* stage + 1] = find_average_value(results_for_shell_sort[2 * stage + 1], number_of_matrix_columns - 1);
                }
            }

            n *= 10;

            //ОСВОБОЖДЕНИЕ ПАМЯТИ ВЫДЕЛЕННОЙ ПОД МАCCИВЫ ДЛЯ СОРТИРОВОК
            free(arr_for_selection_sort);
            free(arr_for_shell_sort);
        }

        //ВЫВОД ЗАГОЛОВКОВ ДЛЯ ПЕРВОЙ ТАБЛИЦЫ - СОРТИРОВКА ВЫБОРОМ
        char* first_sort_name = (char*)malloc(sizeof("SELECTION  SORT"));
        strcpy(first_sort_name, "SELECTION  SORT");
        print_header(first_sort_name);

        n = 1;

        //ВЫВОД ПЕРВОЙ ТАБЛИЦЫ ПО СТРОКАМ
        for (int i = 0; i < number_of_matrix_rows; i++) {
            //ВЫВОД ПЕРВЫХ ЭЛЕМЕНТОВ В СТРОКЕ: 
            //ДЛИНА СОРТИРУЕМОГО МАССИВА И ПАРАМЕТР СРАВНЕНИЯ
            if (i % 2 == 0) {
                n *= 10;
                printf("|%-7d|Comparisons| ", n);  
            } else {
                printf("|%-7d|Movements  | ", n);
            }

            //ВЫВОД ЗНАЧЕНИЙ СТРОКИ ТАБЛИЦЫ
            for (int j = 0; j < number_of_matrix_columns ; j++) {
                printf("%12d| ", results_for_selection_sort[i][j]);
            }

            //ВЫВОД СРЕДНЕГО ЗНАЧЕНИЯ ПАРАМЕТРА
            printf("%12.2lf|\n", average_value_for_selection_sort[i]);
        }

        //ВЫВОД ПОСЛЕДНЕЙ СТРОКИ ТАБЛИЦЫ
        print_footer();
        printf("\n\n");


        //ВЫВОД ЗАГОЛОВКОВ ДЛЯ ВТОРОЙ ТАБЛИЦЫ - МЕТОД ШЕЛЛА
        char* second_sort_name = (char*)malloc(sizeof("SHELL      SORT"));
        strcpy(second_sort_name, "SHELL      SORT");
        print_header(second_sort_name);

        n = 1;

        //ВЫВОД ВТОРОЙ ТАБЛИЦЫ ПО СТРОКАМ
        for (int i = 0; i < number_of_matrix_rows; i++) {
            //ВЫВОД ПЕРВЫХ ЭЛЕМЕНТОВ В СТРОКЕ: 
            //ДЛИНА СОРТИРУЕМОГО МАССИВА И ПАРАМЕТР СРАВНЕНИЯ
            if (i % 2 == 0) {
                n *= 10;
                printf("|%-7d|Comparisons| ", n);  
            } else {
                printf("|%-7d|Movements  | ", n);
            }
            
            //ВЫВОД ЗНАЧЕНИЙ СТРОКИ ТАБЛИЦЫ
            for (int j = 0; j < number_of_matrix_columns ; j++) {
                printf("%12d| ", results_for_shell_sort[i][j]);
            }

            //ВЫВОД СРЕДНЕГО ЗНАЧЕНИЯ ПАРАМЕТРА
            printf("%12.2lf|\n", average_value_for_shell_sort[i]);
        }

        //ВЫВОД ПОСЛЕДНЕЙ СТРОКИ ТАБЛИЦЫ
        print_footer();
        
        //ОСВОБОЖДЕНИЕ ПАМЯТИ ВЫДЕЛЕННОЙ ПОД МАCCИВЫ ДЛЯ СОРТИРОВОК
        //И ИМЕН-ЗАГОЛОВКОВ ТАБЛИЦ
        free(average_value_for_selection_sort);
        free(average_value_for_shell_sort);
        free(first_sort_name);
        free(second_sort_name);

        //ОСВОБОЖДЕНИЕ ПАМЯТИ ВЫДЕЛЕННОЙ ПОД ТАБЛИЦЫ
        free_up_memory_of_matrix(results_for_selection_sort, number_of_matrix_rows);
        free_up_memory_of_matrix(results_for_shell_sort, number_of_matrix_rows);
    }

    //ВЫВОД ОШИБКИ ПРИ ВВОДЕ НЕКОРРЕКТНОГО ЗНАЧЕНИЯ ВЫБОРА РЕЖИМА РАБОТЫ
    if (mode != 1 && mode != 2) {
        printf("ERROR: You have chosen a non-existent operation mode\n");
        return 0;
    }

    //КОРРЕКТНОЕ ВЫПОЛНЕНИЕ ПРОГРАММЫ
    printf("The program was executed correctly\n\n");

    return 0;
}