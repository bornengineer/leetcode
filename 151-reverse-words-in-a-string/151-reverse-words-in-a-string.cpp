class Solution {
public:
    void reversee(string &str, int s, int e ){
        while(s<e){
            char temp = str[s];
            str[s] = str[e];
            str[e] = temp;
            s++;
            e--;
        }
    }
    
    string reverseWords(string s) {
        for(int i = 0; ; i++){
            if(s[i] == ' ')s.erase(i, 1);
            else break;
        }
        for(int i = s.size()-1; ; i--){
            if(s[i] == ' ')s.erase(i, 1);
            else break;
        }
        if(s[0] == ' ')s.erase(0,1);

        
        int i = 0;
        int j = 0;
        while(j < s.size()+1){
            if(s[j] == ' ' or j == s.size()){
                reversee(s, i, j-1);
                while(j+1 < s.size() && s[j+1] == ' ')s.erase(j+1, 1);
                i = j+1;
            }
            j++;
        }
        reversee(s, 0, s.size()-1);
        return s;
    }
};
