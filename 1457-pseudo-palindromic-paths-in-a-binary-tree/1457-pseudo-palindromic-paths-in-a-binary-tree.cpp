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
    
    int cnt[10] = {};
    int pseudoPalindromicPaths(TreeNode* n, int odds = 0, int res = 0) {
        if (n != nullptr) {
            odds += ++cnt[n->val] % 2 ? 1 : -1;
            if (n->left == n->right)
                res = odds < 2 ? 1 : 0;
            else
                res = pseudoPalindromicPaths(n->left, odds) 
                    + pseudoPalindromicPaths(n->right, odds);
            odds += --cnt[n->val] % 2 ? -1 : 1;
        }
        return res;
    }
        
//     void dfs(TreeNode* root, vector<int> &ds, vector<vector<int>> &res){
//         if(!root->left && !root->right){
//             ds.push_back(root->val);
//             res.push_back(ds);
//             ds.pop_back();
//             return;
//         }
        
//         ds.push_back(root->val);
//         if(root->left)dfs(root->left, ds, res);
            
//         if(root->right)dfs(root->right, ds, res);
//         ds.pop_back();        
//     }
    
//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<vector<int>> res;
//         vector<int> ds;
//         dfs(root, ds, res);
        
//         // for(auto i : res){
//         //     for(auto x : i)cout<<x<<" ";
//         //     cout<<endl;            
//         // }
        
//         int cnt = 0;
//         for(auto i : res){
//             vector<int> freq(11, 0);
//             for(int j = 0; j<i.size(); j++){
//                 freq[i[j]]++;
//             }
//             int ones = 0;
//             for(int j : freq){
//                 if(j % 2 == 1){
//                     cnt++;
//                     ones++; 
//                 }
//                 // else if(j % 2 == 0){
//                 //     evens++;
//                 // }
//             }
//             if (ones > 1)cnt -= ones;
//             else if (ones == 0) cnt = 1;
            
//             // cout<<cnt<<endl;
//         }
//         return cnt;
//     }
};