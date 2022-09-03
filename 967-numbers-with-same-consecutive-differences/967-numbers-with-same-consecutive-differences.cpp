class Solution {
public:
    void dfs(int n, int k, vector<int>& ret, int curr){
        if(n == 0){
            ret.push_back(curr);
            return;
        }
        int lastDig = curr % 10;
        if(lastDig - k >= 0 && k != 0)dfs(n-1, k, ret, curr * 10 + lastDig - k);
        
        if(lastDig + k <= 9)dfs(n-1, k, ret, curr * 10 + lastDig + k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1)return {0,1,2,3,4,5,6,7,8,9};
        
        vector<int> ret;
        for(int i = 1; i<10; i++){
            dfs(n-1, k, ret, i);
        }
        return ret;
    }
        
// Brute force - gives TLE (51 / 81 test cases passed)
    // vector<int> numsSameConsecDiff(int n, int k) {
    //     vector<int> ret;
    //     for(int i = pow(10, n-1); i< pow(10, n); i++){
    //         string s = to_string(i);
    //         bool satisfy = true;
    //         for(int j = 1; j<n; j++){
    //             if(abs(('0' - s[j]) - ('0' - s[j-1])) != k){
    //                 satisfy = false;
    //                 break;
    //             }
    //         }
    //         if(satisfy)ret.push_back(i);
    //     }
    //     return ret;
    // }
};