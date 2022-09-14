class Solution {
public:
    /*
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(i >= n || i < 0 || arr[i] < 0)continue;
            
            if(arr[i] == 0)return true;
            
            q.push(i + arr[i]);
            q.push(i - arr[i]);
            
            arr[i] = -1;
        }
        return false;
    }
    */
    
    bool helper(int i, vector<int>& arr){
        if(i >= arr.size() || i < 0 || arr[i] < 0)return false;
        
        if(arr[i] == 0)return true;
        
        arr[i] = -arr[i];
        
        return helper(i + arr[i], arr) || helper(i - arr[i], arr);

    }
    
    bool canReach(vector<int>& arr, int start) {
        int i = start;
        
        return helper(i, arr);
    }
    
};