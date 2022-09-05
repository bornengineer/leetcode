// class Solution {
// public:    
//     vector<int> countBits(int n) {
        
//     }
// };


class Solution {
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