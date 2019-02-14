#include<stdio.h>
#include<stdlib.h>

// Define a node that will hold a value
typedef struct node {
  int val;
  struct node *next;
} node;

node *create_node(int value, node* next) {
  node *new_node = malloc(sizeof(node));

  new_node->val = value;
  new_node->next = next;
  return new_node;
}

// Adds a new node to the end with given value
node *appendNode(node *head, int val) {
  node *current = head;
  while(current->next != NULL) {
    current = current->next;
  }

  // Build new node
  node *new_node = create_node(val, NULL);

  // append node to the end
  current->next = new_node;
  return head;
}

void print_list(node *head) {
  node *current = head;
  while(current) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

int count(node *head) {
  node *cursor = head;
  int count = 0;
  while(cursor != NULL) {
    count += 1;
    cursor = cursor->next;
  }
  return count;
}

int main(int argc, char **argv) {
  printf("Linked list\n");
  node *head = NULL;
  head = create_node(10, NULL);

  head = appendNode(head, 20);
  head = appendNode(head, 30);
  head = appendNode(head, 40);
  head = appendNode(head, 50);

  print_list(head);

  printf ("node count = %d\n", count(head));
  return 0;
}
