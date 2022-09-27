/*class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        // dominoes = ".L.R...LR..L.."
        for(int i = 0; i<n; i++){
            if(i > 0 && dominoes[i-1] == 'R'){
                while(dominoes[i-1] != 'L'){
                    right[i] = 1 + right[i-1];
                    i++;
                }
            }
        }
            
        for(int i = n-1; i>=0; i--){
            if(i < n-1 && dominoes[i+1] == 'L'){
                while(dominoes[i+1] != 'R'){
                    left[i] = 1 + left[i+1];
                    i--;
                }
            }
        }
        
        for(auto i : right)cout<<i<<" ";
        cout<<endl;
        for(auto i : left)cout<<i<<" ";
        cout<<endl;
        
        return "Hi";
    }
};
*/

// from kiranpalsingh
class Solution{
    public:
    string pushDominoes(string s) {
        int N = s.size(), right = -1;
        for (int i = 0; i < N; ++i) {
            if (s[i] == 'L') {
                if (right == -1) { 
                    // Step 2
                    for (int j = i - 1; j >= 0 && s[j] == '.'; --j) {
                      s[j] = 'L';  
                    } 
                } else {
                    // Step 8
                    for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
                        s[j] = 'R';
                        s[k] = 'L';
                    } 
                    right = -1;
                }
            } else if (s[i] == 'R') {
                if (right != -1) {
                    for (int j = right + 1; j < i; ++j) s[j] = 'R';
                }
                right = i;
            }
        }
        if (right != -1) {
            for (int j = right + 1; j < N; ++j) s[j] = 'R';
        }
        return s;
    }
};