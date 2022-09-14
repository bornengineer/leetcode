class Solution {
public:
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
};