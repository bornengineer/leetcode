class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mpp;
        
        for(auto i:nums)mpp[i]++;
        
        vector<int> ans;
        
        // for(int i = 1; i<=nums.size(); i++){
        //     if(mpp[i] > 1)ans.push_back(i);
        //     // cout<<i<<" "<<mpp[i]<<endl;
        // }
        
        // or
        for(auto i: mpp)if(i.second > 1)ans.push_back(i.first);
                
        return ans;
    }
};