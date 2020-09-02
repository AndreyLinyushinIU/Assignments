#include <stdio.h>
#include <stdlib.h>

struct node {
    int element;
    struct node* pointer;
};

struct node* pointerToFirst = NULL;

void print_list() {
    printf("Current list: ");
    struct node* vertex = pointerToFirst;
    while (vertex != NULL) {
        printf("%d ", vertex->element, vertex->pointer);
        vertex = vertex->pointer;
    }
    printf("\n");
}

void insert_node(int position, int value) {
    struct node* inserted = malloc(sizeof(struct node));
    inserted->element = value;
    if (pointerToFirst == NULL && position == 0) {
        pointerToFirst = inserted;
        inserted->pointer =NULL;
        return;
    }
    int counter = 0;
    struct node* vertex = pointerToFirst, *previous = NULL;
    while (counter++ < position) {
        previous = vertex;
        vertex = vertex->pointer;
    }
    if (previous == NULL) pointerToFirst = inserted;
    else previous->pointer = inserted;
    inserted->pointer = vertex;

}

void delete_node(int position) {
    struct node* vertex = pointerToFirst;
    if (position == 0 && pointerToFirst != NULL) {
        pointerToFirst = pointerToFirst->pointer;
        free(vertex);
        return;
    }
    int counter = 0;
    while (counter++ < position - 1) vertex = vertex->pointer;
    struct node* t= vertex->pointer;
    vertex->pointer = t->pointer;
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