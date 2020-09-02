#include <stdio.h>
#include <stdlib.h>

struct node {
    int element;
    struct node* pointerNext, *pointerPrevious;
};

struct node* pointerToFirst = NULL;

void print_list() {
    printf("Current list: ");
    struct node* vertex = pointerToFirst;
    while (vertex != NULL) {
        printf("%d ", vertex->element);
        vertex = vertex->pointerNext;
    }
    printf("\n");
}

void insert_node(int position, int value) {
    struct node* inserted = malloc(sizeof(struct node));
    inserted->element = value;
    if (pointerToFirst == NULL && position == 0) {
        pointerToFirst = inserted;
        inserted->pointerNext = NULL;
        inserted->pointerPrevious = NULL;
        return;
    }
    int counter = 0;
    struct node* vertex = pointerToFirst, *previous = NULL;
    while (counter++ < position) {
        previous = vertex;
        vertex = vertex->pointerNext;
    }
    if (previous == NULL) pointerToFirst = inserted;
    else previous->pointerNext = inserted;
    inserted->pointerNext = vertex;
    inserted->pointerPrevious = previous;
    if (vertex != NULL) vertex->pointerPrevious = inserted;

}

void delete_node(int position) {
    struct node* vertex = pointerToFirst;
    if (position == 0 && pointerToFirst != NULL) {
        if (pointerToFirst->pointerNext != NULL)  pointerToFirst->pointerNext->pointerPrevious = NULL;
        pointerToFirst = pointerToFirst->pointerNext;
        free(vertex);
        return;
    }
    int counter = 0;
    while (counter++ < position - 1) vertex = vertex->pointerNext;
    struct node* t = vertex->pointerNext;
    vertex->pointerNext = t->pointerNext;
    if (t->pointerNext != NULL) t->pointerNext->pointerPrevious = vertex;
    free(t);
}

int main(){
    insert_node(0, 5);
    print_list();
    insert_node(0, 6);
    print_list();
    insert_node(0, 7);
    print_list();
    insert_node(0, 8);
    print_list();
    insert_node(1, 9);
    print_list();
    insert_node(4, 9);
    print_list();
    insert_node(6, 9);
    print_list();
    delete_node(0);
    print_list();
    delete_node(5);
    print_list();
    delete_node(2);
    print_list();
    for (int i = 0; i < 4; i++) delete_node(0);
    print_list();
    return 0;
}