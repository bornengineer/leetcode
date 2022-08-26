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
        
        else{ // when the values matches
            if(!root->left && !root->right){ // if it has no left & right
                delete root;
                return NULL;
            }
            else if(!root->right){ // if only left is present
                TreeNode* temp = root->left;
                root->left = NULL;
                delete root->left;
                root = temp;
            }
            else if(!root->left){ // if only right is present
                TreeNode* temp = root->right;
                root->right = NULL;
                delete root->right;
                root = temp;
            }
            else{ // if both are present
                // here we will compute right's smallest to replace the node
                // we can also find left's largest to replace
                int smallest = root->right->val;
                findSmallest(root->right, &smallest);
                root->val = smallest;
                
                // calling the function again to delete smallest node from right subtree
                root -> right = deleteNode(root->right, smallest);
            }
        }
        return root;
    }
};
                // cout<<"small: "<<smallest<<endl;
                // cout<<smallest<<endl;