class Solution {
public:
    bool isSubsequence(string s, string t) {
        // straightforward bruteforce by @Knockat
        int j = 0;
        for(int i = 0; i<t.size() ; i++){
            if(s[j] == t[i])j++;
        }
        // if case such as s = "acb", t = "ahbgdc" appear
        // j will be equal to 2 cause it will stuck at c
        // hence returning false
        return (j == s.size());
        
        
        // long bakwas approach / but my approach 
        /*
        // woohoo! it's accepted but I can't easily figure out the solution
        // worked on many cases until i reached here
        vector<int> check(26, 0);
        for(auto c : s)check[c - 'a']++;
        
        bool ans = true;
        int sindex = 0;
        for(int i = 0; i < t.size(); i++){
            
            int tindex = t[i] - 'a';  
            if(check[tindex] == 0)continue;
            
            for(int j = 0; j < tindex; j++){
                if(check[j] > 0)ans = false;
                else ans = true;
            }
            // for the case s = acb and t = ahbgdc below condition will fail when t[i] = b and s[sindex] = c
            // hence b will be left over and finally false will be returned by last for loop check
            if(s[sindex] == t[i]){
                check[tindex]--;
                sindex++;
            }
        }

        for(int i : check)if(i>0)return false;
        
        return ans;*/
    }
};

        // for(int i : check)cout<<i<<" ";
        // cout<<endl;
        // for(int i : check)cout<<i<<" ";