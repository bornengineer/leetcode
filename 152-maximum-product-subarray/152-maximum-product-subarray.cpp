class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r = nums[0];
        for(int i = 1, imax = r, imin = r ; i<nums.size(); i++){
            if(nums[i] < 0)swap(imax, imin);
            
            imax = max(nums[i], nums[i] * imax);
            imin = min(nums[i], nums[i] * imin);
            
            r = max(imax, r);
        }
        return r;
        
        
        // tried so hard but didn't got it
        /*
        int currProd = 1;
        int negProd = INT_MIN;
        int maxProd = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            currProd = currProd * nums[i];
            if(currProd < 0 && negProd != INT_MIN){
                currProd *= negProd;
                negProd = INT_MIN;
            }
            maxProd = max(maxProd, currProd);
            if(currProd <= 0 && nums.size() > i+1 && nums[i+1] >= 0){
                if(negProd == INT_MIN){
                    negProd = currProd;
                }
                currProd = 1;
            }
        }
        return maxProd;
        */
    }
};