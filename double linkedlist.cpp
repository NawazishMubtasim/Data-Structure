#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void addfront(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void addafter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void addend(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return;
}

void deleteFront(Node** head_ref) {
    if (*head_ref == NULL)
        return;
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;
    delete temp;
}

void deleteAfter(Node* prev_node) {
    if (prev_node == NULL || prev_node->next == NULL)
        return;
    Node* next_node = prev_node->next;
    prev_node->next = next_node->next;
    if (next_node->next != NULL)
        next_node->next->prev = prev_node;
    delete next_node;
}

void deleteEnd(Node** head_ref) {
    if (*head_ref == NULL)
        return;
    Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    if (last->prev != NULL)
        last->prev->next = NULL;
    delete last;
}

int main() {
    Node* head = NULL;


    addfront(&head, 7);
    addend(&head, 1);
    addafter(head, 6);



    deleteFront(&head);
    deleteEnd(&head);
    deleteAfter(head);

    return 0;
}
