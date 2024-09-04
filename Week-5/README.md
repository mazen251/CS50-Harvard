# Week 5: Data Structures

## Abstract Data Types

Abstract data types (ADTs) are similar to data structures but offer specific properties and characteristics. The programmer decides the implementation details. ADTs can be implemented in various ways using different programming languages, while concrete data structures like arrays have specific implementations provided by the language itself.

### Examples

- **Tree**
- **List**
- **Queue**: FIFO (First In, First Out)
- **Stack**: LIFO (Last In, First Out) (e.g., Gmail)

### Actions Associated

- **Queue**:
  - Enqueue (add to the end)
  - Dequeue (remove from the front)
- **Stack**:
  - Push (add to the top)
  - Pop (remove from the top)

## Arrays vs. Dynamic Data Structures

Arrays are static and cannot change size. For instance, if you have an integer array with space for 3 numbers and want to add a fourth, you cannot resize it directly.

David's Example: Demonstrated how to dynamically resize an array using pointers and malloc, though this approach is inefficient.

## Linked Lists

Linked lists differ from arrays as they are not contiguous in memory. They use pointers to connect nodes.

### Structure
```c
typedef struct node {
    int number;
    struct node *next;
```
### Prepend Operation

Adding a new element at the beginning of the linked list:
```c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[]) {
    node *list = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    node *ptr = list;
    while (ptr != NULL) {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    ptr = list;
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```
### Append Operation

Adding a new element at the end of the linked list:
```c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[]) {
    node *list = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        if (list == NULL) {
            list = n;
        } else {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
                if (ptr->next == NULL) {
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```
### Sorted Insert Operation

Adding a new element in sorted order:
```c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[]) {
    node *list = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        if (list == NULL) {
            list = n;
        } else if (n->number < list->number) {
            n->next = list;
            list = n;
        } else {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
                if (ptr->next == NULL) {
                    ptr->next = n;
                    break;
                }
                if (n->number < ptr->next->number) {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```
## Trees

A tree structure offers both dynamism and sorted order. Binary search trees can store data efficiently, allowing for sorted order and efficient searching.

### Structure
```c
typedef struct node {
    int number;
    struct node *left;
    struct node *right;
```
### Example
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

void free_tree(node *root);
void print_tree(node *root);

int main(void) {
    node *tree = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        free_tree(tree);
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        free_tree(tree);
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    print_tree(tree);

    free_tree(tree);
    return 0;
}

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}
```

## Dictionaries

Dictionaries are another data structure. They store key-value pairs, similar to book dictionaries with a word and its definition. The ideal time complexity for dictionary operations is O(1), meaning access should be instantaneous.


