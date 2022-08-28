class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        bool ans = false;
        for(auto i : magazine)m[i]++;
        
        for(auto i : ransomNote){
            if(m[i]>0){
                ans = true;
                m[i]--;
            }
            else{
                ans = false;
                break;
            }
        }
        return ans;
    }
};