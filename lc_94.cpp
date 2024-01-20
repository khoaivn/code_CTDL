#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> aaa;
        if (root == NULL) return aaa;
        aaa.push_back(root->val);
        if (root->left != NULL){
            vertor<int> left = inorderTraversal(root->left)
            aaa.push_back(left);
        }
        if (root->right != NULL){
            vertor<int> right = inorderTraversal(root->right)
            aaa.push_back(right);
        }
        return aaa;
    }
};

int main(){
    return 0;
}