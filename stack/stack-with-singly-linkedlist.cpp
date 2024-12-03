#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

void createEmptyStack(Node **top) { *top = NULL; }

bool isEmpty(Node *top) { return top == NULL; }

void Push(Node **top, int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = *top;
  *top = newNode;
}

void Pop(Node **top, int *x) {
  if (!isEmpty(*top)) {
    Node *temp = *top;
    *x = temp->data;
    *top = temp->next;
    delete temp;
  }
}

int main(void) {
  Node *top;
  int x;

  createEmptyStack(&top);

  Push(&top, 1);
  Push(&top, 2);
  Push(&top, 3);
  Push(&top, 4);
  Push(&top, 5);

  while (!isEmpty(top)) {
    Pop(&top, &x);
    cout << x << endl;
  }
}