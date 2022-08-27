class Solution {
public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         unordered_map<int,int> mpp;
        
//         for(auto i:nums)mpp[i]++;
        
//         vector<int> ans;
        
//         // for(int i = 1; i<=nums.size(); i++){
//         //     if(mpp[i] > 1)ans.push_back(i);
//         //     // cout<<i<<" "<<mpp[i]<<endl;
//         // }
        
//         // or
//         for(auto i: mpp)if(i.second > 1)ans.push_back(i.first);
                
//         return ans;
//     }
    
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> freq(nums.size());
//         vector<int> ans;
//         for(int i = 0; i<nums.size(); i++){
//             freq[nums[i]-1]++;
//         }
        
//         for(int i = 0 ; i<nums.size(); i++)if(freq[i] > 1)ans.push_back(i+1);
//         // for(auto i:freq)cout<<i<<" ";  
        
//         return ans;
//     }
    
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                ans.push_back(nums[i]);
                i++;
            }
        }
        return ans;
    }
};