/*
class Solution {
public:
    bool isPal(string str){
        int s = 0, e = str.size()-1;
        while(s <= e){
            if(str[s] != str[e])return false;
            s++;
            e--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        if(n < 2)return ans;
        
        unordered_map<string, int> m;
        for(int i = 0 ; i<n; i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            m[s] = i;
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=words[i].size(); j++){
                string pre = words[i].substr(0,j);
                string suf = words[i].substr(j);
                
                // cout<<pre<<"!"<<" "<<suf<<"!"<<endl;
                if(isPal(suf) && m.count(pre) && m[pre] != i){
                    ans.push_back({i, m[pre]});
                }
                
                if(!pre.empty() && m.count(suf) && isPal(pre) && m[suf] != i){
                    ans.push_back({m[suf], i});
                }
            }
        }
        return ans;
    }
    
    // Brute TC = 7.5 * 10 ^ 9 (gives TLE) ~ O(n^2 * size(words[i]) ~ O(n^3) 
    /*bool isPal(string str){
        int s = 0, e = str.size()-1;
        while(s <= e){
            if(str[s] != str[e])return false;
            s++;
            e--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        
        for(int i = 0 ; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j)continue;
                string word = words[i] + words[j];
                if(isPal(word))ans.push_back({i,j});
            }
        }
        return ans;
    }
};*/
    
class Solution {
public:
    // kind of like a dp map, which stores if the calculated string is a palindrome or not
    unordered_map<string, bool> check;
    // function to check is string is palindrome
    bool palin(string &s)
    {
        if(check.find(s) != check.end())
            return check[s];
        
        if(s.length() == 0){
            check[s] = true;
            return true;
        }
        int n = s.length();
        for(int i = 0; i <= n/2; i++)
        {
            if(s[i] != s[(n - i) - 1])
            {
                check[s] = false;
                return false;
            }
        }
        check[s] = true;
        return true;    
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        unordered_map<string, int> mp;
        vector<vector<int>> ans;
        //storing the reverse of every string in unordered map
        for(int i = 0 ; i < words.size(); i++)
        {
            string str = words[i];
            reverse(str.begin(), str.end());
            mp[str] = i;
        }
        // if any string is "" means palindrome strings and "" string will form a pair
        if(mp.find("") != mp.end())
        {
            for(int i = 0; i < words.size(); i++)
            {
                if(i == mp[""])
                    continue;
                if(palin(words[i]))
                {
                    ans.push_back({i, mp[""]});
                }
            }
        }
        // checking in the main vector
        for(int i = 0 ; i < words.size(); i++)
        {
            // storing the ith word in right and left as ""
            string right = words[i];
            string left = "";
            // we will delete letters from right and insert each letter, character by character in left and check if it is present in the map or not. If present, it should not have the same index as i.
            
            // if all these conditions pass, then we can push the indexes in our answer vector
            for(int j = 0 ; j < words[i].length(); j++)
            {
                left.push_back(words[i][j]);
                right.erase(right.begin() + 0);
                if(mp.find(left) != mp.end() and palin(right) and mp[left] != i)
                    ans.push_back({i, mp[left]});
                
                if(mp.find(right) != mp.end() and palin(left) and mp[right] != i)
                    ans.push_back({mp[right], i});
            }
        }
        // return ans;
        return ans;
    }
};