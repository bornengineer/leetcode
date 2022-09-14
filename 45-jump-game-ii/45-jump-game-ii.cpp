class Solution {
public:
    // Greedy Approach
    int jump(vector<int>& nums) {
        int farthest = 0;
        int curr = 0; 
        int jumps = 0;
        
        // here we will look for every possibility from each index's value
        // and use the farthest we can go through any index's value (greedy way)
        // for eg [2,3,1,1,4] 
        //     firstly we can go to 2nd index (0+2) by 0th index value 
        //     but we wont update the ans till we reach the 2nd index
        //     when we reach 2nd index and if we got a more far value ie 4 by (3+1)
        //     we will consider 4's index value (3) over 0th index value cause it will
        //     send us in 2 jumps while 0th index value (2) will send us in 3 jumps
        for(int i = 0; i<nums.size()-1; i++){
            farthest = max(farthest, nums[i] + i);
            
            if(curr == i){
                curr = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};