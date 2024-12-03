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

  if (*head == NULL) {
    newNode->next = newNode;
    newNode->prev = newNode;
    *head = newNode;
    return;
  }

  Node *lastNode = (*head)->prev;
  newNode->next = *head;
  newNode->prev = lastNode;
  lastNode->next = newNode;
  (*head)->prev = newNode;
  *head = newNode;
}

void insertLast(Node **head, int data) {
  Node *newNode = new Node;
  newNode->data = data;

  if (*head == NULL) {
    newNode->next = newNode;
    newNode->prev = newNode;
    *head = newNode;
    return;
  }

  Node *lastNode = (*head)->prev;
  newNode->next = *head;
  newNode->prev = lastNode;
  lastNode->next = newNode;
  (*head)->prev = newNode;
}

void insertAfter(Node *head, int x, int data) {
  if (head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *newNode = new Node;
  newNode->data = data;

  Node *targetNode = head;

  do {
    if (targetNode->data == x) {
      newNode->next = targetNode->next;
      newNode->prev = targetNode;
      targetNode->next->prev = newNode;
      targetNode->next = newNode;
      return;
    }

    targetNode = targetNode->next;
  } while (targetNode != head);

  cout << "Node with data " << x << " is not found." << endl;
  delete newNode;
}

void printAllNode(Node *head) {
  if (head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *currentNode = head;
  int i = 1;

  do {
    cout << "Node (" << i << "): " << currentNode->data << endl;
    currentNode = currentNode->next;
    i++;
  } while (currentNode != head);
}

void deleteFirst(Node **head) {
  if (*head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *temp = *head;

  if (temp->next == temp) {
    *head = NULL;
    delete temp;
    return;
  }

  Node *lastNode = temp->prev;
  *head = temp->next;
  (*head)->prev = lastNode;
  lastNode->next = *head;

  delete temp;
}

void deleteLast(Node **head) {
  if (*head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *lastNode = (*head)->prev;

  if (lastNode->next == lastNode) {
    *head = NULL;
    delete lastNode;
    return;
  }

  Node *prevNodeBeforeLastNode = lastNode->prev;
  prevNodeBeforeLastNode->next = *head;
  (*head)->prev = prevNodeBeforeLastNode;

  delete lastNode;
}

void deleteAfter(Node **head, int x) {
  if (*head == NULL) {
    cout << "List is still empty." << endl;
    return;
  }

  Node *targetNode = *head;

  do {
    if (targetNode->data == x) {
      Node *temp = targetNode->next;

      targetNode->next = temp->next;
      temp->next->prev = targetNode;

      if (temp == *head) {
        *head = temp->next;
      }

      delete temp;
      return;
    }
    targetNode = targetNode->next;
  } while (targetNode != *head);

  cout << "Node with data " << x << " is not found." << endl;
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
  deleteAfter(&head, 1);
  deleteAfter(&head, 3);

  printAllNode(head);
  cout << endl;

  return 0;
}
