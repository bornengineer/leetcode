class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])return a[1] < b[1];
        
        return a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int weak = 0;
        int maxDef = INT_MIN;
        sort(prop.begin(), prop.end(), comp);
        
        for(int i = 0; i<prop.size(); i++){
            if(prop[i][1] < maxDef)weak++;
            maxDef = max(maxDef,prop[i][1]);
        }
        return weak;
        
//         for(auto i : prop){
//             for(auto j : i){
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
        
        /*
        vector<int> weak(prop.size());
        
        for(int i = 0; i<prop.size(); i++){
            int currAtt = prop[i][0];
            int currDef = prop[i][1];
            
            for(int j = i+1; j<prop.size(); j++){
                if(prop[j][0] > currAtt && prop[j][1] > currDef)weak[i] = 1;
                else if(prop[j][0] < currAtt && prop[j][1] < currDef)weak[j] = 1;
            }
        }
        int cnt = 0;
        for(auto i : weak)cnt += i;
        return cnt;
        */
    }
};