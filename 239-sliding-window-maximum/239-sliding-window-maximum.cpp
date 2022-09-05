class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int j = 0;
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            
            if(i-j+1 > k){
                if(dq.front() == nums[j])dq.pop_front();
                j++;
            }
            
            if(i-j+1 <= k){
                while(!dq.empty() && dq.back() < nums[i])dq.pop_back();
                dq.push_back(nums[i]);
                
                if(i-j+1 == k){
                    ans.push_back(dq.front());
                }
            }
        }
        return ans;
    }
};