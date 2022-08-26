/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findSmallest(TreeNode* root, int *smallest){
        if(!root->left)return;
        *smallest = root->left->val;
        
        findSmallest(root->left, smallest);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        
        if(root->val > key)root->left = deleteNode(root->left, key);
        
        else if(root->val < key)root->right = deleteNode(root->right, key);
        
        else{
            if(!root->left && !root->right){
                // delete root;
                return NULL;
            }
            else if(!root->right){
                root = root->left;
            }
            else if(!root->left){
                root = root->right;
            }
            else{
                int smallest = root->right->val;
                // cout<<"small: "<<smallest<<endl;
                findSmallest(root->right, &smallest);
                root->val = smallest;
                // cout<<smallest<<endl;
                
                root -> right = deleteNode(root->right, smallest);
            }
        }
        return root;
    }
};