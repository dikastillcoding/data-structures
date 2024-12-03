#include <iostream>

using namespace std;

#define MaxElement 100
#define Nil -1

struct Queue {
  int data[MaxElement];
  int head;
  int tail;
};

void createEmpty(Queue *Q) {
  Q->head = Nil;
  Q->tail = Nil;
}

bool isQueueEmpty(Queue *Q) { return Q->head == Nil && Q->tail == Nil; }

bool isQueueFull(Queue *Q) {
  return (Q->tail + 1 == MaxElement && Q->head == 0) ||
         (Q->tail + 1 == Q->head);
}

void Add(Queue *Q, int data) {
  if (isQueueFull(Q))
    return;

  if (isQueueEmpty(Q)) {
    Q->head = 0;
    Q->tail = 0;
    Q->data[Q->tail] = data;
    return;
  }

  if (Q->tail + 1 == MaxElement) {
    Q->tail = 0;
    Q->data[Q->tail] = data;
    return;
  }

  Q->tail = Q->tail + 1;
  Q->data[Q->tail] = data;
}

void Del(Queue *Q, int *X) {
  if (isQueueEmpty(Q))
    return;

  *X = Q->data[Q->head];

  if (Q->head == Q->tail) {
    createEmpty(Q);
    return;
  }

  if (Q->head + 1 == MaxElement) {
    Q->head = 0;
    return;
  }

  Q->head = Q->head + 1;
}

int numberElementInQueue(Queue *Q) {
  if (isQueueEmpty(Q))
    return 0;

  if (Q->head <= Q->tail) {
    return Q->tail - Q->head + 1;
  }

  return MaxElement - Q->head + Q->tail + 1;
}

int main(void) {
  Queue Q;
  createEmpty(&Q);

  Add(&Q, 1);
  Add(&Q, 2);
  Add(&Q, 3);
  Add(&Q, 4);
  Add(&Q, 5);

  cout << "Number of elements in queue: " << numberElementInQueue(&Q) << endl;

  while (!isQueueEmpty(&Q)) {
    int x;
    Del(&Q, &x);
    cout << x << " ";
  }

  cout << endl;
  cout << "Number of elements in queue: " << numberElementInQueue(&Q) << endl;

  return 0;
}
