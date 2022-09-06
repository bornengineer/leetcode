class Solution {
public:
    void dfs(int o, int c, vector<string>& res, string s){
        cout<<o<<" "<<c<<endl;
        if(o == 0 && c == 0){
            res.push_back(s);
            return;
        }
        
        if(o == c){
            dfs(o-1, c, res, s + "(");
        }
        else if(o == 0){
            dfs(o, c-1, res, s + ")");      
        }
        else if(c > o){
            dfs(o-1, c, res, s + "(");
            
            dfs(o, c-1, res, s + ")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> res;
        string s = "";
        dfs(open, close, res, s);
        return res;
    }
};