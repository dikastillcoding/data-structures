#include <iostream>

using namespace std;

#define MaxElement 100
#define Nil        -1

struct Queue {
  int data[MaxElement];
  int front;
  int rear;
};

void createEmpty(Queue& Q) {
  Q.front = Nil;
  Q.rear  = Nil;
}

bool isQueueEmpty(Queue Q) {
  return Q.front == Nil && Q.rear == Nil;
}

bool isQueueFull(Queue Q) {
  return (Q.rear + 1 == MaxElement && Q.front == 0) || (Q.rear + 1 == Q.front);
}

void Add(Queue& Q, int x) {
  if (isQueueFull(Q))
    return;

  if (isQueueEmpty(Q)) {
    Q.front        = 0;
    Q.rear         = 0;
    Q.data[Q.rear] = x;
    return;
  }

  if (Q.rear + 1 == MaxElement) {
    Q.rear         = 0;
    Q.data[Q.rear] = x;
    return;
  }

  Q.rear         = Q.rear + 1;
  Q.data[Q.rear] = x;
}

void Del(Queue* Q, int* x) {
  if (isQueueEmpty(*Q))
    return;

  *x = Q->data[Q->front];

  if (Q->front == Q->rear) {
    createEmpty(*Q);
    return;
  }

  if (Q->front + 1 == MaxElement) {
    Q->front = 0;
    return;
  }

  Q->front = Q->front + 1;
}

int numberElementInQueue(Queue Q) {
  if (isQueueEmpty(Q))
    return 0;

  if (Q.front <= Q.rear) {
    return Q.rear - Q.front + 1;
  }

  return MaxElement - Q.front + Q.rear + 1;
}

int main(void) {
  Queue Q;
  createEmpty(Q);

  Add(Q, 1);
  Add(Q, 2);
  Add(Q, 3);
  Add(Q, 4);
  Add(Q, 5);

  cout << "Number of elements in queue: " << numberElementInQueue(Q) << endl;

  while (!isQueueEmpty(Q)) {
    int x;
    Del(&Q, &x);
    cout << x << " ";
  }

  cout << endl;
  cout << "Number of elements in queue: " << numberElementInQueue(Q) << endl;

  return 0;
}
