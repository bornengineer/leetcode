class Solution {
public:
    void rev(string &s, int l, int r){
        while(l<r){
            char temp = s[r];
            s[r--] = s[l];
            s[l++] = temp;
        }
    }
    
    string reverseStr(string s, int k) {
        int i = 0, j = 0;
        for(; j<s.size();){
            if(j+k-1<s.size()){
                rev(s, i, j+k-1);
                j += 2*k;
                i = j;
            }
            else{
                rev(s, i, s.size() - 1);
                break;
            }
        }
        return s;
    }
};