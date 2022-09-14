#define mod 1000000007
class Solution {
public:    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> poww(n+1, 1);
        for(int i = 1; i<poww.size(); i++){
            poww[i] = (2*poww[i-1])%mod;
        }
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int s = 0, e = n-1;
        while(s <= e){
            if(nums[s] + nums[e] <= target){
                cnt = (cnt+poww[e-s]) % mod;
                s++;
            }
            else e--;
        }
        return cnt;
    }
};

// Recursive approach by me (but gives TLE)
/*
class Solution {
public:
    void f(int idx, int *cnt, vector<int>& ds, int minn, int maxx, int target, vector<int> &nums){
        if(idx == nums.size()){
            if(!ds.empty() && maxx + minn <= target){
                (*cnt)++;
            }            
            return;
        }
        // cout<<*cnt<<endl;
        
        // not pick
        f(idx+1, cnt, ds, minn, maxx, target, nums);
        
        // pick
        ds.push_back(nums[idx]);
        minn = min(minn, nums[idx]);
        maxx = max(maxx, nums[idx]);
        f(idx+1, cnt, ds, minn, maxx, target, nums);
        
        ds.pop_back();
        
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int minn = INT_MAX, maxx = INT_MIN;
        vector<int> ds;
        int cnt = 0;
        f(0, &cnt, ds, minn, maxx, target, nums);
        return cnt % 1000000007;
    }
};
*/