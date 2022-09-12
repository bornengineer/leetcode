class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int score = 0, ans = 0;
        int i = 0, j = n-1;
        sort(tokens.begin(), tokens.end());
        
        while(i<=j){
            if(tokens[i] <= power){
                power -= tokens[i];
                score++;
                i++;
                ans = max(ans, score);
            }
            else if(score >= 1){
                power += tokens[j];
                score--;
                j--;
            }
            else break;
        }
        return ans;
    }
};

// My approach bit long
/*
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size() == 0)return 0;
        if(tokens.size() == 1)
            if(tokens[0] > power)return 0;
            else return 1;
        
        int score = 0;
        int ans = 0;
        int n = tokens.size();
        int i = 0, j = n-1;
        sort(tokens.begin(), tokens.end());
        
        while(i<=j && tokens[i] > power && tokens[j] > power){
            i++;
            j--;
        }
        if(tokens[i] > power && tokens[j] > power)return 0;
        else{
            while(i<=j){
                while(tokens[i] <= power){
                    power -= tokens[i];
                    score++;
                    i++;
                }
                while(i<=j && tokens[j] <= power){
                    power -= tokens[j];
                    score++;
                    j--;
                }

                ans = max(ans, score);

                if(score >= 1){
                    if(tokens[i] > tokens[j]){
                        power += tokens[i];
                        i++;
                    }else{
                        power += tokens[j];
                        j--;
                    }
                    score--;
                }
            }
        }
        return ans;
    }
};
*/