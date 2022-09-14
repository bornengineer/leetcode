class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastIdx = n - 1;
        for(int i = lastIdx; i>=0; i--){
            if(i + nums[i] >= lastIdx)lastIdx = i;
        }
        return lastIdx == 0;
    } 
};