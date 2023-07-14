#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Структура листа
typedef struct TreeNode {
    int value;
    struct TreeNode* left, *right, *parent;
} Tree;

// Высота
int height (Tree* root) {
    if (root == NULL) {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    if (left > right) {
        return left + 1;
    }

    return right + 1;
}

// Сумма узлов
int sum_nodes(struct TreeNode* root, int* sum) {
    if (root == NULL) {
        return (*sum);
    }

    if (root->value) {
        (*sum) += root->value;
    }

    sum_nodes(root->left, sum);
    sum_nodes(root->right, sum);

    return *sum;
}

// Сумма листьев
int sum_leaves(struct TreeNode* root) {
    int sum = 0;

    if (root == NULL) {
        return sum;
    }

    if (root->left == NULL && root->right == NULL) {
        return root->value;
    }

    return sum_leaves(root->left) + sum_leaves(root->right);
}

// Создание нового узла
struct TreeNode* create_new_node(int value) {
    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    new_node -> value = value;
    new_node -> left = NULL;
    new_node -> right = NULL;

    return new_node;
}

// Вставка готового узла
void insert(struct TreeNode** root, struct TreeNode* node) {
    struct TreeNode* find, *parent;
    find = *root;
    parent = NULL;

    while (find) {
        parent = find;
        if (node->value < find->value) {
            find = find->left;
        } else {
            find = find->right;
        }
    }

    node->parent = parent;

    if (parent == NULL) {
        *root = node;
    } else if (node->value < parent->value) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    return;
}

// Удаление дерева
void delete_tree (struct TreeNode* root) {
    if (root == NULL) {
        delete_tree(root -> left);
        delete_tree(root -> right);

        free(root);
    }
}

// Вывод двоичного дерева
void print_tree_level(struct TreeNode* root, int i) {
    if (root == NULL) {
        printf("NULL");
        return;
    }

    if (i == 1) {
        printf("%d ", root -> value);
    } else {
        print_tree_level (root -> left, i - 1);
        print_tree_level (root -> right, i - 1);
    }
}

// Поиск ключа в дереве
int search(struct TreeNode* root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (value == root -> value) {
        return 1;
    }

    if (value > root -> value) {
        return search(root -> left, value);
    }

    return search(root->right, value);
}

// Проверка: является ли двоичным деревом поиска
int is_BST (struct TreeNode* root, int max, int min) {
    if (!root) {
        return 1;
    }

    if (root -> value <= min || root -> value >= max) {
        return 0;
    }

    return is_BST(root -> left, root -> value, min) && is_BST(root -> right, max, root -> value);
}