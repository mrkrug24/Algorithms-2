#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct Node {
    char* str;
    char* value;
    struct Node* next;
};

void push_back(struct Node** tail, char* s, char* value) {
    (*tail)->next = (struct Node*)calloc(1, sizeof(struct Node));
    (*tail)->next->str = s;
    (*tail)->next->value = value;
    (*tail)->next->next = NULL;
    (*tail) = (*tail)->next;
}

int compare(char* a, char* b) {
    if (a[0] != '"') {
        if (atoi(a) > atoi(b)) {
            return 1;
        } else {
            return -1;
        }
    }

    return strcmp(a, b);
}

void division(struct Node* head, struct Node** a, struct Node** b) {
    struct Node* cur_1 = head;
    struct Node* cur_2 = head->next;

    while (cur_2 != NULL) {
        if (cur_2->next != NULL && cur_2->next->next != NULL) {
            cur_1 = cur_1->next;
            cur_2 = cur_2->next->next;
        } else {
            cur_2 = cur_2->next;
        }
    }

	*a = head;
	*b = cur_1->next;

	cur_1->next = NULL;
}

void merge(struct Node** head, struct Node* a, struct Node* b) {
	if (compare(a->value, b->value) < 0) {
		*head = a;
		a = a->next;
	} else {
		*head = b;
		b = b->next;
	}

    struct Node* cur = *head;

	while (a != NULL && b != NULL) {
		if (compare(a->value, b->value) < 0) {
			cur->next = a;
			a = a->next;
		} else {
			cur->next = b;
			b = b->next;
		}

		cur = cur->next;
	}

	while (a != NULL) {
		cur->next = a;
		cur = cur->next;
		a = a->next;
	}

	while (b != NULL) {
		cur->next = b;
		cur = cur->next;
		b = b->next;
	}
}

void sort(struct Node** head) {
	struct Node* a;
	struct Node* b;

	if ((*head)->next == NULL) {
		return;
	}

	division(*head, &a, &b);
	sort(&a);
	sort(&b);
	merge(head, a, b);
}

void delete_list(struct Node** head) {
    struct Node* cur = *head;
    while (cur) {
        struct Node* next = cur->next;
        free(cur->str);
        free(cur->value);
        free(cur);
        cur = next;
    }

    *head = NULL;
}

int main(void) {
    char filename[] = "input.txt";
    FILE *fp;
    fp = fopen(filename, "r");

    int n;
    fscanf(fp, "%d\n", &n);

    char s[N + 1];

    struct Node p;
    struct Node* head = &p;
    struct Node* tail = &p;

    int quality = 0;

    while (fgets(s, sizeof(s), fp) != NULL) {
        int len = strlen(s) - 1;
        int quotation = 0;
        int new_len = 0;
        char* new_s = (char*)malloc(sizeof(char) * (N + 1));


        int cnt = 0;
        int len_v = 0;
        char* value = (char*)malloc(sizeof(char) * (N + 1));

        for (int i = 0; i < len; i++) {
            if (s[i] == '"') {
                if (quotation == 0) {
                    quotation = 1;
                } else {
                    quotation = 0;
                }
            }

            if (s[i] != ' ') {
                new_s[new_len] = s[i];
                new_len++;
            } else if(quotation == 1) {
                    new_s[new_len] = s[i];
                    new_len++;
            }


            if (s[i] == ';') {
                cnt++;
            }

            if (cnt == n && s[i] != ';') {
                if (s[i] != ' ') {
                    value[len_v] = s[i];
                    len_v++;
                } else if (quotation == 1) {
                    value[len_v] = s[i];
                    len_v++;
                }
            }
        }

        new_s[new_len] = '\0';
        value[len_v] = '\0';

        push_back(&tail, new_s, value);

        quality++;
    }

    head = head->next;

    sort(&head);

    char output[] = "output.txt";
    FILE *ans;
    ans = fopen(output, "w");

    struct Node* cur = head;
    while (cur != NULL) {
        fprintf(ans,"%s\n", cur->str);
        cur = cur->next;
    }

    delete_list(&head);

    fclose(fp);
    fclose(ans);

    return 0;
}