class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int sum = 0;
        for(auto x : nums)if(x%2==0)sum += x;
        
        for(auto i : queries){
            if(nums[i[1]] % 2 == 0)sum -= nums[i[1]];
            nums[i[1]] += i[0];
            if(nums[i[1]] % 2 == 0)sum += nums[i[1]];
            res.push_back(sum);
        }
        return res;
    }
};