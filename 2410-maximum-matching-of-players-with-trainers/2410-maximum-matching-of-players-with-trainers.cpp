class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int cnt = 0;
        int i = 0, j = 0;
        while(i < players.size() && j < trainers.size()){
            if(players[i] <= trainers[j]){
                i++;
                j++;
                cnt++;
            }
            else if(players[i] > trainers[j])j++;
        }   
        return cnt;
    }
};

        // this gives TLE cause we are checking all the cases
        // for(int i = players.size()-1; i>=0; i--){
        //     for(int j = trainers.size() -1; j>=0; j--){
        //         if(players[i] <= trainers[j]){
        //             trainers[j] = INT_MIN;
        //             cnt++;
        //             break;
        //         }
        //     }
        // }