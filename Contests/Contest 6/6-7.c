#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void push_back(struct Node** tail, int value) {                          // добавление элемента в конец списка
    (*tail)->next = (struct Node*)calloc(1, sizeof(struct Node));
    (*tail)->next->value = value;
    (*tail)->next->next = NULL;
    (*tail) = (*tail)->next;
}

void division(struct Node* head, struct Node** a, struct Node** b) {    // разделение списка на 2 подсписка - a и b
    struct Node* cur_1 = head;    // будущая граница
    struct Node* cur_2 = head->next;

    while (cur_2 != NULL) {   // пока не дойдет до конца основного списка
        if (cur_2->next != NULL && cur_2->next->next != NULL) {
            cur_1 = cur_1->next; // смещение на 1, чтобы когда cur_2 дойдет до конца, cur_1 был на середине основоного списка
            cur_2 = cur_2->next->next; // смещение на 2
        } else {
            cur_2 = cur_2->next;
        }
    }

	*a = head;     // голова нового подсписка a
	*b = cur_1->next; // голова нового подсписка b

	cur_1->next = NULL;  // подсписко a должен иметь границу
}

void merge(struct Node** head, struct Node* a, struct Node* b) {   // слияние подсписков a и b, голова их объединения - head
	if (a->value < b->value) {   // ищем первый элемент объединенного списка, те head (наименьшей из первых элементов a и b)
		*head = a;
		a = a->next;
	} else {
		*head = b;
		b = b->next;
	}

    struct Node* cur = *head;

	while (a != NULL && b != NULL) {  //сравнение элементов а и b. Добавление наименьшего
		if (a->value < b->value) {
			cur->next = a;
			a = a->next;
		} else {
			cur->next = b;
			b = b->next;
		}

		cur = cur->next;
	}

	while (a != NULL) {  // если остались недобавленные элементы из а то добавить их всех
		cur->next = a;
		cur = cur->next;
		a = a->next;
	}

	while (b != NULL) {  // если остались недобавленные элементы из b  то добавить их всех
		cur->next = b;
		cur = cur->next;
		b = b->next;
	}
}


void sort(struct Node** head) {   // сортировка
	struct Node* a;   // создаем 2 указателя на подсписки
	struct Node* b;

	if ((*head)->next == NULL) {  // когда в подсписке 1 элемент, то выходим
		return;
	}

	division(*head, &a, &b); // деление списка на 2 подсписка
	sort(&a); // сортировка первого
	sort(&b); // сортировка второго
	merge(head, a, b); // слияние
}

void delete_list(struct Node** head) {
    struct Node* cur = *head;
    while (cur) {
        struct Node* next = cur->next;
        free(cur);
        cur = next;
    }

    *head = NULL;
}

int main(void) {
    char filename[] = "input.txt";
    FILE *fp;
    fp = fopen(filename, "r");

    struct Node p_1;   // первый элемнт

    int x;
    fscanf(fp,"%d", &x);

    p_1.value = x;
    p_1.next = NULL;

    struct Node* head = &p_1;
    struct Node* tail = &p_1;

    while (fscanf(fp, "%d", &x) == 1) { // считывание и заполнение списка
        push_back(&tail, x);
    }

    sort(&head);

    char output[] = "output.txt";
    FILE *ans;
    ans = fopen(output, "w");

    struct Node* cur = head;

    while (cur != NULL) {
        fprintf(ans, "%d ", cur -> value);
        cur = cur -> next;
    }

    fclose(fp);
    fclose(ans);

    return 0;
}