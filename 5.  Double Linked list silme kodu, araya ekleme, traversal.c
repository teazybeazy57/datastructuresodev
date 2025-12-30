#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) return;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
void deleteNode(struct Node** head, struct Node* del) {
    if (*head == NULL || del == NULL) return;
    if (*head == del) *head = del->next;
    if (del->next != NULL) del->next->prev = del->prev;
    if (del->prev != NULL) del->prev->next = del->next;
    free(del);
}
void display(struct Node* node) {
    struct Node* last;
    printf("Ileriye dogru: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nGeriye dogru: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}
int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;
    head->prev = NULL;
    insertAfter(head, 20);
    insertAfter(head, 15); // 10 ve 20 arasina 15 ekler
    display(head);
    deleteNode(&head, head->next); // Ortadaki 15'i siler
    printf("Silme isleminden sonra:\n");
    display(head);
    return 0;
}
