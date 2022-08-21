class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        int size = s.size();
        
        // bruteforce gives TLE O(n*size) (33 / 39 test cases passed)
        // for(int i = 0; i<n; i++){
        //     int start = shifts[i][0];
        //     int end = shifts[i][1];
        //     int dir = shifts[i][2];
        //         for(int j = start ; j<=end; j++){
        //             if(dir == 0){
        //                 s[j] =  (s[j] - 1 + 26 <= 122) ? s[j] - 1 + 26 :(s[j] - 1);
        //             }
        //             else{
        //                 s[j] =  (s[j] + 1 -26 >= 97) ? s[j] + 1 - 26 : (s[j] + 1);
        //             }
        //         }
        // }
        // return s;
        
        
        vector<int> arr(size+1);
        for(int i = 0 ; i<n; i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];
            if(dir==0){
                arr[start]--;
                arr[end+1]++;
            }else{
                arr[start]++;
                arr[end+1]--;
            }
        }

        int prefix = 0;
        for(int i = 0; i<size; i++){
            prefix += arr[i];
            int k = prefix%26;
            int diff = (s[i] - 'a' + k + 26) % 26;
            s[i] = diff + 'a';
        }
        
        return s;
    }
};
        // debug code
        // for(auto i:arr)cout<<i<<" ";
        // cout<<endl;
            // cout<<prefix<<"  ";
        // cout<<endl<<s<<endl;