#include <stdio.h>
#include <stdlib.h>

struct Node {
  int item;
  struct Node* next;
};

void initialize(struct Node** head, int new_item) 
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->item  = new_item;

    new_node->next = NULL;

    *head = new_node;
}
void insert_After(struct Node* node, int data) {
  if (node == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->item = data;
  new_node->next = node->next;
  node->next = new_node;
}

/*void insertAtEnd(struct Node** ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *ref;
  new_node->item = data;
  new_node->next = NULL;
  if (*ref == NULL) {
    *ref = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}*/

void delete_Node(struct Node** ref, int key) {
  struct Node *temp = *ref, *prev;

  if (temp != NULL && temp->item == key) {
    *ref = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->item != key) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) return;

  prev->next = temp->next;

  free(temp);
}

void print_List(struct Node* node) {
  while (node != NULL) {
    printf(" %d ", node->item);
    node = node->next;
  }
}

int main() {
  struct Node* head = NULL;
  initialize(&head,12);
  insert_After(head, 5);

  printf("Linked list: ");
  print_List(head);

  printf("\nAfter deleting an element: ");
  delete_Node(&head, 12);
  print_List(head);
}
