#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

void createEmptyQueue(Node **head, Node **tail) {
  *head = NULL;
  *tail = NULL;
}

bool isQueueEmpty(Node *head) { return head == NULL; }

void Add(Node **head, Node **tail, int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  if (isQueueEmpty(*head)) {
    *head = newNode;
    *tail = newNode;
    return;
  }

  (*tail)->next = newNode;
  *tail = newNode;
}

void Del(Node **head, Node **tail, int *X) {
  if (isQueueEmpty(*head)) {
    return;
  }

  *X = (*head)->data;

  Node *temp = *head;
  *head = (*head)->next;
  delete temp;
}

int numberElementInQueue(Node *head) {
  int count = 0;
  Node *temp = head;

  while (temp != NULL) {
    count++;
    temp = temp->next;
  }

  return count;
}

int main(void) {
  Node *head;
  Node *tail;

  createEmptyQueue(&head, &tail);

  Add(&head, &tail, 1);
  Add(&head, &tail, 2);
  Add(&head, &tail, 3);
  Add(&head, &tail, 4);
  Add(&head, &tail, 5);

  cout << "Number of elements in queue: " << numberElementInQueue(head) << endl;

  while (!isQueueEmpty(head)) {
    int X;
    Del(&head, &tail, &X);
    cout << X << " ";
  }

  cout << endl;
  cout << "Number of elements in queue: " << numberElementInQueue(head) << endl;

  return 0;
}
