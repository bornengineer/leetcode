/*class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        if(equations.size() == 1){
            if(equations[0][1] == '!')return false;
            else return true;
        }
        
        char first;
        vector<int> occured(26, 0);
        for(int i = 0; i<equations.size(); i++){
            
            occured[equations[i][0]-'a']++;
            occured[equations[i][3]-'a']++;
            
            if(equations[i][1] == '=' && i == 0){
                first = '=';
            }
            else if(equations[i][1] == '!' && i == 0){
                first = '!';
            }
            else if(equations[i][1] != first && (occured[equations[i][0]-'a'] > 1 || occured[equations[i][3]-'a'] > 1))return false;
        }
        return true;
    }
};*/

// from kiranpalsingh
class Solution {
    int uf[26];
    int find(int x) {
        return uf[x] == x ? x : (uf[x] = find(uf[x]));
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (auto e : equations) {
            if (e[1] == '=') uf[find(e[0] - 'a')] = find(e[3] - 'a'); 
        }
        for (auto e : equations) {
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a')) return false;
        }
        return true;
    }
};