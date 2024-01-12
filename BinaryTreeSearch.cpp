#include <bits/stdc++.h>

using namespace std;

class BinaryTreeSearch{
public:
    class TreeNode{
    public:
        TreeNode* left;
        int val;
        TreeNode* right;
        TreeNode(int key): left(NULL), val(key), right(NULL){}
    };
    TreeNode* root;
    BinaryTreeSearch(){
        root = NULL;
        // root = insertNode(root, 8);
    }
    TreeNode* insertNode(TreeNode* cur_node, int val){
        TreeNode* moi = new TreeNode(val);
        if (cur_node == NULL){
            cur_node = moi;
        } else 
            if (val < cur_node->val)
                cur_node->left = insertNode(cur_node->left, val);
            else 
                cur_node->right = insertNode(cur_node->right, val);
        return cur_node;
    }
    void duyet_tien_thu_tu(TreeNode* cur_node){
        if (cur_node != NULL){
            cout << cur_node->val << "  ";
            duyet_tien_thu_tu(cur_node->left);
            duyet_tien_thu_tu(cur_node->right);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        if (root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        } else if (root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        } else {
            cout << root->val << "  ";
            if (root->left == NULL){
                return root->right;
            } else if (root->right == NULL){
                return root->left;
            } else {
                TreeNode* temp = root->right;
                while (temp->left != NULL){
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
                return root;
            }
        }
    }
};
int main(){
    BinaryTreeSearch bts;
    bts.root = bts.insertNode(bts.root, 50);
    bts.root = bts.insertNode(bts.root, 30);
    bts.root = bts.insertNode(bts.root, 40);
    bts.root = bts.insertNode(bts.root, 70);
    bts.root = bts.insertNode(bts.root, 60);
    bts.root = bts.insertNode(bts.root, 80);
    
    bts.duyet_tien_thu_tu(bts.root);
    cout << endl;
    bts.deleteNode(bts.root, 50);
    cout << endl;
    bts.duyet_tien_thu_tu(bts.root);
    return 0;
}