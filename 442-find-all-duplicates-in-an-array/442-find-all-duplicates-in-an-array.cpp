class Solution {
public:
//     BRUTE FORCE Time Complexcity - O(N*N) <= Give You TLE, Space Complexcity - O(1)
//     vector<int> findDuplicates(vector<int>& nums) {
//         if(nums.empty())return {};
//         vector<int>ans;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]!=nums[j])continue;
//                 else{
//                     ans.push_back(nums[i]);
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
        
    
//     SORTING  Time Complexcity - O(N*Log N) Space Complexcity - O(1)
//     vector<int> findDuplicates(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<int> ans;
        
//         for(int i = 0; i<nums.size()-1; i++){
//             if(nums[i] == nums[i+1]){
//                 ans.push_back(nums[i]);
//                 i++;
//             }
//         }
//         return ans;
//     }
    
    
//     USING HASHMAP Time Complexcity - O(N) Space Complexcity - O(N)
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
    
    
//     USING FREQUENCY VECTOR Time Complexcity - O(N) Space Complexcity - O(N)
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

//     OPTIMAL
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i<nums.size(); i++){
            int num = abs(nums[i]);
            if(nums[num-1] > 0){
                nums[num-1] *= -1;
            }else{
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }

    
};