class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int curr = 1, prev = nums[0];
        int cnt = 1, ans = 1;
        for(; curr < size(nums); curr++){
            if(nums[curr] > prev){
                cnt++;
                ans = max(cnt, ans);
            }
            else{
                cnt = 1;
            }
            prev = nums[curr];
            // cout<<cnt<<endl;
        }
        return ans;
    }
};