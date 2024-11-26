#include <iostream>

using namespace std;

struct Node {
  int   data;
  Node* next;
};

void createEmptyQueue(Node** front, Node** rear) {
  *front = NULL;
  *rear  = NULL;
}

bool isQueueEmpty(Node* front) {
  return front == NULL;
}

void Add(Node** front, Node** rear, int x) {
  Node* newNode = new Node;
  newNode->data = x;
  newNode->next = NULL;

  if (isQueueEmpty(*front)) {
    *front = newNode;
    *rear  = newNode;
    return;
  }

  (*rear)->next = newNode;
  *rear         = newNode;
}

void Del(Node** front, Node** rear, int& x) {
  if (isQueueEmpty(*front)) {
    return;
  }

  x = (*front)->data;

  Node* temp = *front;
  *front     = (*front)->next;
  delete temp;
}

int numberElementInQueue(Node* front) {
  int   count = 0;
  Node* temp  = front;

  while (temp != NULL) {
    count++;
    temp = temp->next;
  }

  return count;
}

int main(void) {
  Node* front;
  Node* rear;

  createEmptyQueue(&front, &rear);

  Add(&front, &rear, 1);
  Add(&front, &rear, 2);
  Add(&front, &rear, 3);
  Add(&front, &rear, 4);
  Add(&front, &rear, 5);

  cout << "Number of elements in queue: " << numberElementInQueue(front) << endl;

  while (!isQueueEmpty(front)) {
    int x;
    Del(&front, &rear, x);
    cout << x << " ";
  }

  cout << endl;
  cout << "Number of elements in queue: " << numberElementInQueue(front) << endl;

  return 0;
}
