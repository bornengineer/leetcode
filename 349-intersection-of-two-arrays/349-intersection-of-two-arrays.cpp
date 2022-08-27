class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(auto i: nums1)if(mpp[i]==0)mpp[i]++;
        
        for(int i = 0 ; i<nums2.size(); i++){
            if(mpp[nums2[i]]==1){
                // cout<<i<<" "<<mpp[i]<<endl;
                ans.push_back(nums2[i]);
                mpp[nums2[i]]++;
            }
        }
        return ans;
    }
};