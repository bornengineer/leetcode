class Solution {
public:
    void rev(string &s, int l, int r){
        while(l<r){
            char temp = s[r];
            s[r--] = s[l];
            s[l++] = temp;
        }
    }
    
    string reverseWords(string s) {
        int i = 0, j = 0;
        for( ; j<=s.size(); j++){
            if(s[j] == ' ' || j == s.size()){
                rev(s, i, j-1);
                i = j + 1;
            }
        }
        return s;
    }
};