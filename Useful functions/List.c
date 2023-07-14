#include <stdio.h>
#include <stdlib.h>

// Структура элемента
struct Node {
    int value;
    struct Node* next;
};

// Длина списка
int listlen(struct Node* head) {
    int cnt = 0;
    
    while(head) {
        cnt++;
        head = head->next;
    }

    return cnt;
}

// Вывод занчаений элементов списка
void print_list(struct Node* head) {
    struct Node* cur = head; // указатель не текущий элемент

    while (cur) {
        printf("%d ", cur->value);
        cur = cur->next;
    }

    printf("\n");
}

// Поиск элемента
int exists (struct Node* head, int value) {
    while (head) {
        if (value == head -> value) {
            return 1;
        }

        head = head -> next;
    }

    return 0;
}

// Добавление элемента в начало списка, вернет указатель на новую голову
struct Node* push_front(struct Node* head, int new_value) {
    struct Node* p0 = (struct Node*)malloc(sizeof(struct Node));

    p0 -> value = new_value;
    p0 -> next = head;

    return p0;
}

// Добавление в конец
void push_back(struct Node** head, int value) {
    struct Node* new_node = (struct Node*)calloc(1, sizeof(struct Node));
    struct Node* last = *head;
    new_node -> value = value;
    new_node -> next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Добавление элемента x за первым вхождением элемента y, возвращает указатель на голову списка)
struct Node* insert(struct Node* head, int x, int y) {
    if (!head) {
        return NULL;
    }

    struct Node* elem_y = search(head, y);
    if (!elem_y) { // не нашли y
        return head;
    }

    struct Node* elem_x = malloc(sizeof(struct Node));
    elem_x->value = x;
    elem_x->next = elem_y->next;
    elem_y->next = elem_x;

    return head;
}

// Удаление списка
void delete_list(struct Node** head) {
    struct Node* cur = *head;

    while (cur) {
        struct Node* next = cur -> next;
        free(cur);
        cur = next;
    }

    *head = NULL;
}

// Удаление элемента списка под номером num
void remove_elem(struct Node** head, int num) {
    struct Node* prev = NULL, *cur = *head;

    while (cur && cur->value != num) {
        prev = cur;
        cur = cur->next;
    }

    if (!cur) {     // элемент не найден или список пуст
        return;
    }

    if (!prev) {    // найденный элемент первый в списке
        *head = (*head)->next;
    }

    else {                      // найденный элемент не первый в списке
        prev->next = cur->next; // указатель с предшественника переносим на последователя
    }

    free(cur);
}

// Удаление последовательных одинаковых элементов
void remove_duplicates(struct Node* head) {
    if (head == NULL) {
        return;
    }

    while (head->next != NULL) {
        if (head->value == head->next->value) {
            struct Node* tmp = head->next;
            head->next = head->next->next;
            free(tmp);
        } else {
            head = head->next;
        }
    }
}

// Переворот списка
void reverse_list(struct Node** head) {
    struct Node* cur = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (cur != NULL) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }

    *head = prev;
}

// Слияние отсортированных списков
struct Node* merge_sorted_lists(struct Node* head1, struct Node* head2) {
    struct Node* head_res = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->value < head2->value) {
            push_front(&head_res, head1->value);
            head1 = head1->next;

        } else {
            push_front(&head_res, head2->value);
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        push_front(&head_res, head1->value);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        push_front(&head_res, head2->value);
        head2 = head2->next;
    }

    return head_res;
}

struct Node* swap(struct Node* x, struct Node* y) {
    struct Node* tmp = y->next;
    y->next = x;
    x->next = tmp;

    return y;
}

void bubble_sort_list(struct Node** head, int n) {
    struct Node** cur;

    for (int i = 0; i < n; i++) {
        cur = head;

        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            struct Node* x_j = *cur;
            struct Node* x_j_1 = x_j->next;

            if (x_j->value > x_j_1->value) {
                *cur = swap2(x_j, x_j_1);
                swapped = 1;
            }
            cur = &((*cur)->next);
        }

        if (!swapped) {
            break;
        }
    }
}