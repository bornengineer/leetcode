/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// BFS
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        
        vector<vector<int>> ret;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> currLevel;
            
            for(int i=0; i<size; i++){
                Node *front = q.front();
                q.pop();
                currLevel.push_back(front->val);
                for(auto i : front->children)q.push(i);
            }
            
            ret.push_back(currLevel);
        }
        return ret;
    }
};


// recursive solution by YehudisK
// class Solution {
// public:
//     void rec(Node* root, int level) {
//         if (!root) return;
//         if (level == res.size()) res.push_back({});
//         res[level].push_back(root->val);
//         for (auto child : root->children)
//             rec(child, level+1);
//     }
    
//     vector<vector<int>> levelOrder(Node* root) {
//         rec(root, 0);
//         return res;
//     }
    
// private:
//     vector<vector<int>> res;
// };
