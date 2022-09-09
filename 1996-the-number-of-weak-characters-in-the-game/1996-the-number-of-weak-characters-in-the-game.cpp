class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])return a[1] < b[1]; // if attack is same return lesser one
        
        return a[0] > b[0]; // else return bigger attack value coz we're sorting in decreasing order
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int weak = 0;
        int maxDef = INT_MIN;
        // here we will sort it acc to decreasing attack value
        // then we only need to deal with defense values
        sort(prop.begin(), prop.end(), comp); // wrote comparator function for decreasing order &
                                              // to handle equal attack values
        
        // now in the decreasing order 2d vector if defense values is lesser then we can directly say
        // that it is a weaker character coz the attack values are already sorted in decreasing order
        for(int i = 0; i<prop.size(); i++){
            if(prop[i][1] < maxDef)weak++;
            else maxDef = max(maxDef,prop[i][1]);
        }
        return weak;
    }
};

// brute force by me
/*
class Solution {
public:    
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
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
    }
};
*/

// debug
        // for(auto i : prop){
        //     for(auto j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }