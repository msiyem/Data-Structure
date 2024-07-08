#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void creatnode(int value) {
    struct node *link = malloc(sizeof(struct node));
    link->data = value;
    link->next = NULL;

    if (head == NULL) {
        head = link;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = link;  // Correctly link the new node to the end of the list
    }
}

void print() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("link_list empty\n");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void delet_first() {
    if (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);  // Free the memory of the deleted node
    }
}

void delet_by_key(int key) {
    struct node *current = head;
    struct node *previous = NULL;

    if (head == NULL) return;

    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return;  // Key not found

    if (current == head) {
        head = head->next;
    } else {
        previous->next = current->next;
    }
    free(current);  // Free the memory of the deleted node
}

void insert_after_key(int key, int newkey) {
    struct node *current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) return;  // Key not found

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = newkey;
    newnode->next = current->next;
    current->next = newnode;
}

void sort() {
    if (head == NULL) return;  // If list is empty, no need to sort

    struct node *ptr1, *ptr2;
    int temp;

    for (ptr1 = head; ptr1->next != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
}

void reverse_list() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    creatnode(1);
    creatnode(2);
    creatnode(3);
    creatnode(4);
    creatnode(5);
    creatnode(6);
    creatnode(7);
    print();

    printf("after delet first:\n");
    delet_first();
    print();

    printf("after delet_by_key (3):\n");
    delet_by_key(3);
    print();

    printf("after sort:\n");
    sort();
    print();

    printf("after reverse:\n");
    reverse_list();
    print();

    return 0;
}
