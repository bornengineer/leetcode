class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        // making the vector of pair to avoid relativity of speed & efficiency
        for(int i = 0 ; i<n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        
        sort(v.begin(), v.end());
        
        // using a priority queue to only store k element in it & also get min element from it
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        long sum = 0, ans = 0;
        
        for(int i = n-1; i>=0; i--){ // iterating in decreasing order cause we'll get max in end
            sum += v[i].second;
            pq.push(v[i].second);
            
            if(pq.size()>k){
                sum -= pq.top(); // if size exceeds subtract the element from sum
                pq.pop();
            }
            
            ans = max(ans, sum * v[i].first); // maintain ans & put the max value of performance
        }
        return ans % 1000000007;
    }
};