#include <queue>
#include <stdio.h>

struct Node {
  Node(int v) {
    left = NULL;
    right = NULL;
    next = NULL;
    val = v;
  };

  Node *left;
  Node *right;
  Node *next;
  int val;
};

Node *merge(Node *root) {
  std::queue<Node *> q;
  if (!root)
    return NULL;
  q.push(root);
  Node *res = NULL;
  Node *tail = NULL;

  while (!q.empty()) {
    int size = q.size();
    while (size-- > 0) {
      Node *node = q.front();
      q.pop();
      if (!res) {
        res = node;
        tail = node;
        // node->next = NULL;
      } else {
        tail->next = node;
        // node->next = NULL;
        tail = tail->next;
      }
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
  }
  return res;
}

int main(void) {
  printf("Hello World!\n");
  return 0;
  Node *root = new Node(1);
  Node *left = new Node(2);
  Node *right = new Node(3);
  root->left = left;
  root->right = right;
  Node *ret = merge(root);
}
