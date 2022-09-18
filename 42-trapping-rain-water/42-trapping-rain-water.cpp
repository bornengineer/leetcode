class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
// my approach but it'll give TLE coz of N^2
    /*
    int hold = 0;
    for(int i = 0 ; i<height.size(); i++){
        int right = 0 , left = 0;
        for(int j = i; j>=0 ; j--){
            left = max(left,height[j]);
        }
        for(int k = i; k<height.size() ; k++){
            right = max(right,height[k]);
        }
        hold += min(left, right) - height[i];
        // cout<<i<<"  " <<left<<" "<<right<<" "<<hold<<endl;
    }
    return hold;*/
        
        
// using prefix and suffix sum arrays
// to avoid the nesting of loops
// but here 2N extra space will be used
    /*
    int hold = 0;
    
    vector<int> pre(n);
    int max1 = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        max1 = max(max1, height[i]);
        pre[i]=max1;
    }
    
    vector<int> suf(n);
    int max2 = INT_MIN;
    for(int i = n-1 ; i>=0 ; i--){
        max2 = max(max2, height[i]);
        suf[i]=max2;
    }
    
    for(int i = 0 ; i<height.size(); i++){
        hold += min(pre[i], suf[i]) - height[i];
    }
    return hold;
    */
        
        
        
// optimal o(n) TWO POINTERS
        /*
    int left = 0, right = n-1;
    int leftmax = 0, rightmax = 0;
    int res = 0;
    
    while(left<=right){
        if(height[left]<=height[right]){
            if(height[left]>= leftmax){
            leftmax=height[left];
            }else{
                res += leftmax - height[left];
            }
            left++;
        }else{
            if(height[right] >= rightmax){
            rightmax = height[right];
            }else{
                res += rightmax - height[right];
            }
            right--;
        }
    }
    return res;
    */
        
        
        
// USING STACK
    // here we'll push till current height > height of st.top() and then 
    // implement the formula water contained in top (or middle block) is equal
    // to distance between curr and st.top() multiplied by min of curr and 
    // st.top height minus height of middle (or top) and add it to water
        // /*
    stack<int> st;
    int curr = 0, water = 0;
    while(curr < height.size()){
        while(!st.empty() && height[curr] > height[st.top()]){
            int top = st.top();
            st.pop();
            if(st.empty())break;
            int d = curr - st.top() - 1; // d = distance bw two bounding blocks
            int fill = d*(min(height[curr],height[st.top()]) - height[top]);
            water += fill;
        }
        st.push(curr++);
    }
    return water;
     // */
     
    }
};