#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void listele(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}
void arayaEkle(struct Node* prev_node, int veri) {
    if (prev_node == NULL) return;
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->data = veri;
    yeni->next = prev_node->next;
    prev_node->next = yeni;
}
void sil(struct Node** head, int anahtar) {
    if (*head == NULL) return;
    struct Node *curr = *head, *prev;
    if (curr->data == anahtar) {
        struct Node* last = *head;
        while (last->next != *head) last = last->next;
        if (*head == last) {
            free(*head);
            *head = NULL;
        } else {
            last->next = (*head)->next;
            free(*head);
            *head = last->next;
        }
        return;
    }
    while (curr->next != *head && curr->data != anahtar) {
        prev = curr;
        curr = curr->next;
    }
    if (curr->data == anahtar) {
        prev->next = curr->next;
        free(curr);
    }
}
int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = head;
    arayaEkle(head, 3);
    arayaEkle(head, 2); // 1 ve 3 arasina 2 ekler
    printf("Liste: ");
    listele(head);
    sil(&head, 2);
    printf("2 silindikten sonra: ");
    listele(head);
    return 0;
}
