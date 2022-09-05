class Solution {
public: 
    // recursive solution
    int countSetBits(int i){
        int cnt = 0;
        while(i > 0){
            cnt += i % 2;
            i /= 2;
        }
        return cnt;
    }
    
    void helper(int n, vector<int>& ans){
        if(n == 0){
            ans.push_back(0);
            return;
        }
        
        helper(n-1, ans);
        
        ans.push_back(countSetBits(n));
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        helper(n, ans);
        return ans;
    }
};


/*class Solution {
public:
    int countSetBits(int i){
        int cnt = 0;
        
        while(i > 0){
            cnt += i % 2;
            i /= 2;
        }
        
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
 */