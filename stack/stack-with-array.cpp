#include <iostream>

using namespace std;

#define MaxElement 100
#define Nil -1

struct Stack {
  int Top;
  int Data[MaxElement];
};

void CreateStack(Stack *S) { S->Top = Nil; }

bool IsStackEmpty(Stack *S) { return S->Top == Nil; }

bool IsStackFull(Stack *S) { return S->Top == MaxElement - 1; }

void Push(Stack *S, int data) {
  if (!IsStackFull(S)) {
    S->Top++;
    S->Data[S->Top] = data;
  }
}

void Pop(Stack *S, int *X) {
  if (!IsStackEmpty(S)) {
    *X = S->Data[S->Top];
    S->Top--;
  }
}

int main(void) {
  Stack S;
  int X;

  CreateStack(&S);

  Push(&S, 1);
  Push(&S, 2);
  Push(&S, 3);
  Push(&S, 4);
  Push(&S, 5);

  while (!IsStackEmpty(&S)) {
    Pop(&S, &X);
    cout << X << endl;
  }
}
