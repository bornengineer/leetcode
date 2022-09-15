class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ret;
        unordered_map<int,int> m;
        sort(changed.begin(), changed.end());
        
        if(n <= 1 || n % 2 == 1)return {};
        
        for(int i = 0; i<n; i++){
            m[changed[i]]++;
        }
        
        for(int i = 0; i<n; i++){
            if(m[changed[i]] == 0)continue;
            
            if(m[changed[i] * 2] > 0){
                ret.push_back(changed[i]);
                m[changed[i] * 2]--;
                m[changed[i]]--;
            }else return {};
        }
        return ret;
    }
};