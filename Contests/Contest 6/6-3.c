#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* previous;
};

void push_back(struct Node** tail, int value, struct Node* arr[]) {
    (*tail)->next = (struct Node*)calloc(1, sizeof(struct Node));
    (*tail)->next->value = value;
    (*tail)->next->next = NULL;
    (*tail)->next->previous = (*tail);
    arr[value] = (*tail)->next;
    (*tail) = (*tail)->next;
}

void make_permutation(struct Node** head, int x, int y, struct Node* arr[]) {
    if ((*head)->value == x) {
        return;
    }

    struct Node* a = arr[x];
    struct Node* b = arr[y];

    if (b->next != NULL) {
        struct Node* c = b->next;
        struct Node* d = a->previous;

        b->next = *head;
        (*head)->previous = b;
        *head = a;
        a->previous = NULL;
        d->next = c;
        c->previous = d;

    } else {
        struct Node* d = a->previous;

        b->next = *head;
        (*head)->previous = b;
        *head = a;
        a->previous = NULL;
        d->next = NULL;
    }

    return;
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

    int n, m;
    fscanf(fp, "%d %d", &n, &m);

    struct Node p_1;

    p_1.value = 1;
    p_1.next = NULL;
    p_1.previous = NULL;

    struct Node* head = &p_1;
    struct Node* tail = &p_1;
    struct Node* arr[n + 1];
    arr[1] = &p_1;

    for (int i = 2; i <= n; i++) {
        push_back(&tail, i, arr);
    }

    int b, c;

    for (int i = 0; i < m; i++) {
        fscanf(fp, "%d %d", &b, &c);
        make_permutation(&head, b, c, arr);
    }

    struct Node* cur = head;

    char output[] = "output.txt";
    FILE *ans;
    ans = fopen(output, "w");

    while (cur != NULL) {
        fprintf(ans, "%d ", cur -> value);
        cur = cur -> next;
    }

    fclose(fp);
    fclose(ans);

    return 0;
}