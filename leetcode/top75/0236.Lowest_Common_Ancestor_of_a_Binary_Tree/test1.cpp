/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
#include <iostream>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root)
      cout << "1 root:" << root->val << endl;
    if (!root)
      return NULL;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    if (left)
      cout << "left:" << left->val << endl;
    if (left)
      return left;
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (right)
      cout << "right:" << right->val << endl;
    if (right)
      return right;

    // if (is_parent(root, p) && is_parent(root, q)) return root;
    if (root)
      cout << "2 root:" << root->val << endl;
    bool ret1 = is_parent(root, p);
    cout << "ret1:" << ret1 << endl;
    bool ret2 = is_parent(root, q);
    cout << "ret2:" << ret2 << endl;
    if (ret1 && ret2)
      return root;
    return NULL;
  }

  bool is_parent(TreeNode *root, TreeNode *p) {
    cout << "is_parent root:" << root << ",p:" << p << endl;
    if (root)
      cout << "is_parent root:" << root->val << endl;
    if (!root)
      return false;
    if (root->left == p || root->right == p)
      return true;
    return is_parent(root->left, p) || is_parent(root->right, p);
  }
};
int main() {
  //
}