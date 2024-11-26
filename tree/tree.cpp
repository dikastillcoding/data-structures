#include <iostream>

using namespace std;

struct Node {
  int   data;
  Node* left;
  Node* right;
};

Node* createNode(int data) {
  Node* newNode  = new Node;
  newNode->data  = data;
  newNode->left  = NULL;
  newNode->right = NULL;

  return newNode;
}

void insertNode(Node* root, int data) {
  if (root->data > data) {
    if (root->left != NULL) {
      insertNode(root->left, data);
      return;
    }

    root->left = createNode(data);
    return;
  }

  if (root->right != NULL) {
    insertNode(root->right, data);
    return;
  }

  root->right = createNode(data);
}

void preOrder(Node* root) {
  if (root == NULL) {
    return;
  }

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root) {
  if (root == NULL) {
    return;
  }

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(Node* root) {
  if (root == NULL) {
    return;
  }

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

bool searchTree(Node* root, int data) {
  if (root == NULL) {
    return false;
  }

  if (root->data == data) {
    return true;
  }

  if (root->data > data) {
    return searchTree(root->left, data);
  }

  return searchTree(root->right, data);
}

bool searchLeaf(Node* root, int data) {
  if (root == NULL) {
    return false;
  }

  if (root->data == data && root->left == NULL && root->right == NULL) {
    return true;
  }

  return searchLeaf(root->left, data) || searchLeaf(root->right, data);
}

void insertAfter(Node* root, int x, int y, bool isLeft) {
  if (root == NULL) {
    return;
  }

  if (root->data == x) {
    if (isLeft) {
      root->left = createNode(y);
      return;
    }

    root->right = createNode(y);
    return;
  }

  insertAfter(root->left, x, y, isLeft);
  insertAfter(root->right, x, y, isLeft);
}

void deleteNode(Node* root, int x) {
  if (root == NULL) {
    return;
  }

  if (root->left != NULL && root->left->data == x) {
    Node* temp = root->left;
    root->left = NULL;
    delete temp;
    return;
  }

  if (root->right != NULL && root->right->data == x) {
    Node* temp  = root->right;
    root->right = NULL;
    delete temp;
    return;
  }

  deleteNode(root->left, x);
  deleteNode(root->right, x);
}

int main() {
  Node* root = createNode(10);

  insertNode(root, 5);
  insertNode(root, 20);
  insertNode(root, 8);
  insertNode(root, 30);
  insertNode(root, 3);
  insertNode(root, 9);

  cout << "Preorder: ";
  preOrder(root);
  cout << endl;

  cout << "Inorder: ";
  inOrder(root);
  cout << endl;

  cout << "Postorder: ";
  postOrder(root);
  cout << endl;

  cout << "Search Tree 5: " << searchTree(root, 5) << endl;
  cout << "Search Tree 50: " << searchTree(root, 50) << endl;

  cout << "Search Leaf 3: " << searchLeaf(root, 3) << endl;
  cout << "Search Leaf 5: " << searchLeaf(root, 5) << endl;

  insertAfter(root, 5, 7, true);
  insertAfter(root, 5, 6, false);

  cout << "Preorder: ";
  preOrder(root);

  deleteNode(root, 5);

  cout << "Preorder: ";
  preOrder(root);

  return 0;
}
