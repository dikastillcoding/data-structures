#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *prev;
  Node *next;
};

void insertFirst(Node **head, int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = *head;

  if (*head != NULL) {
    (*head)->prev = newNode;
  }

  *head = newNode;
}

void insertLast(Node **head, int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }

  Node *lastNode = *head;

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
  newNode->prev = lastNode;
}

void insertAfter(Node *head, int x, int data) {
  if (head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *newNode = new Node;
  newNode->data = data;

  Node *targetNode = head;

  while (targetNode != NULL && targetNode->data != x) {
    targetNode = targetNode->next;
  }

  if (targetNode == NULL) {
    cout << "Node with data " << x << " is not found." << endl;
    return;
  }

  newNode->next = targetNode->next;
  newNode->prev = targetNode;

  if (targetNode->next != NULL) {
    targetNode->next->prev = newNode;
  }

  targetNode->next = newNode;
}

void printAllNode(Node *head) {
  if (head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *currentNode = head;
  int i = 1;

  while (currentNode != NULL) {
    cout << "Node (" << i << "): " << currentNode->data << endl;
    currentNode = currentNode->next;
    i++;
  }
}

void deleteFirst(Node **head) {
  if (*head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *temp = *head;
  *head = temp->next;

  if (*head != NULL) {
    (*head)->prev = NULL;
  }

  delete temp;
}

void deleteLast(Node **head) {
  if (*head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *lastNode = *head;

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  if (lastNode->prev != NULL) {
    lastNode->prev->next = NULL;
  }

  delete lastNode;
}

void deleteAfter(Node *head, int x) {
  if (head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *targetNode = head;

  while (targetNode != NULL && targetNode->data != x) {
    targetNode = targetNode->next;
  }

  if (targetNode == NULL) {
    cout << "Node with data " << x << " is not found." << endl;
    return;
  }

  Node *temp = targetNode->next;

  if (temp != NULL) {
    targetNode->next = temp->next;

    if (temp->next != NULL) {
      temp->next->prev = targetNode;
    }

    delete temp;
  }
}

int main(void) {
  Node *head = NULL;

  cout << "Four insertFirst operations." << endl;
  insertFirst(&head, 1);
  insertFirst(&head, 3);
  insertFirst(&head, 5);
  insertFirst(&head, 7);

  printAllNode(head);
  cout << endl;

  cout << "Four insertLast operations." << endl;
  insertLast(&head, 9);
  insertLast(&head, 11);
  insertLast(&head, 13);
  insertLast(&head, 15);

  printAllNode(head);
  cout << endl;

  cout << "Four insertAfter operations." << endl;
  insertAfter(head, 1, 2);
  insertAfter(head, 3, 4);
  insertAfter(head, 5, 6);
  insertAfter(head, 7, 8);

  printAllNode(head);
  cout << endl;

  cout << "Two deleteFirst operations." << endl;
  deleteFirst(&head);
  deleteFirst(&head);

  printAllNode(head);
  cout << endl;

  cout << "Two deleteLast operations." << endl;
  deleteLast(&head);
  deleteLast(&head);

  printAllNode(head);
  cout << endl;

  cout << "Two deleteAfter operations." << endl;
  deleteAfter(head, 1);
  deleteAfter(head, 3);

  printAllNode(head);
  cout << endl;

  return 0;
}
