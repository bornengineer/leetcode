class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        // bruteforce algorithm O(n^2)
        // int maxSum = INT_MIN;
        // for(int i =0 ; i<n ; i++){
        // int sum = 0;
        //     for(int j = i; j<n ; j++){
        //         sum += nums[j];
        //         maxSum = max(maxSum, sum);
        //     }
        // }
        // return maxSum;

        
        // wrote it on 8 sept 2022
        // Kadane's Algorithm
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if(sum < 0)sum = 0;
        }
        return maxSum;
        
        
// nlogn is also not possible as we can't sort the array,
// coz it will change the order/sequence of the array
        
        
        // Optimised approach - Kadane's Algorithm O(n)
//         int maxSum = INT_MIN;
//         int currSum = 0;
        
//         for(int i = 0; i<n ; i++){
//             currSum += nums[i];
            
//             if(currSum > maxSum)maxSum = currSum;
            
//             if(currSum < 0)currSum = 0;
//         }
//         return maxSum;
    }
};