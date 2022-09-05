class Solution {
public:
    int countSetBits(int i){
        string res;
        while(i > 0){
            res.push_back(i % 2);
            i /= 2;
        }
        reverse(res.begin(), res.end());
        
        int cnt = 0;
        for(auto x : res)if(x == 1)cnt++;
        
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i = 0; i<=n; i++){
            int ones = countSetBits(i);
            ans.push_back(ones);
        }
        
        return ans;
    }
};