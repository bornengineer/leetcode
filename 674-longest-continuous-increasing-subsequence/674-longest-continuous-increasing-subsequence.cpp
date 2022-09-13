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
        
        // int min = nums[0];
        // int i = 0;
        // for(; i<nums.size(); i++){
        //     if(nums[i] < min)min = nums[i];
        //     else if(nums[i] > min)break;
        // }
        // // if(i > 1)i--;
        // // cout<<i<<" "<<min;
        // int ans = 1;
        // int curr = min;
        // int cnt = 1;
        // for(; i<nums.size(); i++){
        //     if(nums[i] > curr){
        //         curr = nums[i];
        //         cnt++;
        //         ans = max(ans, cnt);
        //     }
        //     else if(nums[i] < curr){
        //         cnt = 0;
        //         curr = 0;
        //     }
        //     else{
        //         cnt = 1;
        //         curr = 0;
        //         ans = max(ans, cnt);
        //     } 
        // }
        // return ans;
    }
};