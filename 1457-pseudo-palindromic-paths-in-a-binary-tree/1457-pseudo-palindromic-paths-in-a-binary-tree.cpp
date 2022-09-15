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
    void dfs(TreeNode* root, vector<int> &freq, int *cnt){
        if(!root->left && !root->right){
            freq[root->val]++;
            
            int oddOccurence = 0;
            for(int j : freq){
                if(j % 2 == 1)oddOccurence++;
            }
            if(oddOccurence < 2)(*cnt)++;
            
            freq[root->val]--;
            return;
        }
        
        freq[root->val]++;
        if(root->left)dfs(root->left, freq, cnt);
            
        if(root->right)dfs(root->right, freq, cnt);
        freq[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0);
        int cnt = 0;             
        dfs(root, freq, &cnt);
        return cnt;
    }
};

        // ds.push_back(root->val);
        // res.push_back(ds);
        // ds.pop_back();
        // ds.push_back(root->val);
        // ds.pop_back();   
        // vector<vector<int>> res;
        // vector<int> ds;