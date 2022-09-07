// Backtracking approach
// class Solution {
// public:
//     void dfs(int o, int c, vector<string>& res, string s){
//         // cout<<o<<" "<<c<<endl; // debugging
        
//         // when both gets completely burned we will push the string "s" to res
//         if(o == 0 && c == 0){
//             res.push_back(s);
//             return;
//         }
        
//         if(o == c){ // if open & close are same we'll always push a opening one "("
//             dfs(o-1, c, res, s + "(");
//         }
//         else if(o == 0){ // if open = 0 we'll keep pushing the left over closing brackets ")"
//             dfs(o, c-1, res, s + ")");      
//         }
//         else if(c > o){ // but when both are non zero & closing > opening then there are two case 
//                         // where we'll push each open & close bracket in different cases
//             dfs(o-1, c, res, s + "(");
            
//             dfs(o, c-1, res, s + ")");
//         }
//     }
    
//     // here we will initialise no of both opening & closing brackets with n & burn their values in each recursive call
//     vector<string> generateParenthesis(int n) {
//         int open = n;
//         int close = n;
//         vector<string> res;
//         string s = "";
//         dfs(open, close, res, s);
//         return res;
//     }
// };


// Brute force approach
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        s.resize(2 * n);
        vector<string> res;
        generateAll(s, 0, res);
        return res;
    }
    
    void generateAll(string s, int pos, vector<string>& res){
        if(pos == s.size()){
            if(isValid(s)){
                res.push_back(s);
            }
            return;
        }
        else{
            s[pos] = '(';
            generateAll(s, pos+1, res);
            s[pos] = ')';
            generateAll(s, pos+1, res);
        }
    }
    
    bool isValid(string s){
        int balance = 0;
        for(auto c : s){
            if(c == '(')balance++;
            
            else balance--;
            if(balance < 0)return false;
        }
        return balance == 0;
    }
};