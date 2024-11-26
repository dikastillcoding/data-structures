#include <iostream>

using namespace std;

struct Node {
  int   data;
  Node* next;
};

void createEmptyStack(Node** top) {
  *top = NULL;
}

bool isEmpty(Node* top) {
  return top == NULL;
}

void Push(Node** top, int data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = *top;
  *top          = newNode;
}

void Pop(Node** top, int* data) {
  if (!isEmpty(*top)) {
    Node* temp = *top;
    *data      = temp->data;
    *top       = temp->next;
    delete temp;
  }
}

int main(void) {
  Node* top;
  int   data;

  createEmptyStack(&top);

  Push(&top, 1);
  Push(&top, 2);
  Push(&top, 3);
  Push(&top, 4);
  Push(&top, 5);

  while (!isEmpty(top)) {
    Pop(&top, &data);
    cout << data << endl;
  }
}