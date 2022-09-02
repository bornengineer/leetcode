class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        
        // counting sort
//         int r = 0, w = 0, b = 0;
//         for(auto i : nums){
//             if(i == 0)r++;
//             else if(i == 1)w++;
//             else b++;
//         }

//         int i = 0;
//         while(r--){
//             nums[i]=0;
//             i++;
//         }
//         while(w--){
//             nums[i]=1;
//             i++;
//         }
//         while(b--){
//             nums[i]=2;
//             i++;
//         }
        
        
        // Dutch National Flag algo | One pass constant space
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid] , nums[high]);
                high--;
            }
            else mid++;
        }
    }
};