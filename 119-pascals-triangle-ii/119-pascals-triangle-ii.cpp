class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        vector<int> temp;
        for(int i = 0; i<ans.size(); i++){
            for(int j = 0 ; j<=i; j++){
                if(j == 0 || j == i){
                    ans[j] = 1;
                    continue;
                }
                ans[j] = temp[j-1] + temp[j];
            }
            temp = ans;
        }
        return ans;
    }
};