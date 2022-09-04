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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // creating a map of int and map of int and multiset of int (confusing -lmao)
        // to store x(vertical), y(level) and node->val (nodes[x][y].insert(node->val))
        // and a queue to traverse in level order to store node->val, x(vertical), y(level)
        // using a multiset cause we could have 2 colliding nodes with same value
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> todo;
        todo.push({root, {0,0}});
        while(!todo.empty()){
            auto front = todo.front();
            todo.pop();
            TreeNode* node = front.first;
            int x = front.second.first;
            int y = front.second.second;
            // as it is a map (ordered) it will store -2, -1, 0... verticals
            nodes[x][y].insert(node->val);
            
            // if it is a left node vertical will be -1 of vertical previous
            // while level will always be +1 of previous 
            if(node->left)todo.push({node->left, {x-1, y+1}});
            if(node->right)todo.push({node->right, {x+1, y+1}});
        }
        
        vector<vector<int>> ret;
        for(auto p : nodes){
            vector<int> col; // vertical column
            for(auto q : p.second){
                // vector insert func takes where to insert and from where to where insert
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ret.push_back(col);
        }
        return ret;
    }
};