class Solution {
public:
    // Brute force
    // here we have used 2N space coz of temp
    // vector<int> getRow(int rowIndex) {
    //     vector<int> ans(rowIndex + 1, 0);
    //     vector<int> temp;
    //     for(int i = 0; i<ans.size(); i++){
    //         for(int j = 0 ; j<=i; j++){
    //             if(j == 0 || j == i){
    //                 ans[j] = 1;
    //                 continue;
    //             }
    //             ans[j] = temp[j-1] + temp[j];
    //         }
    //         temp = ans;
    //     }
    //     return ans;
    // }
    
    // optimized
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        ans[0] = 1;
        for(int i = 1; i<ans.size(); i++)
            for(int j = i ; j >= 1; j--)
                ans[j] += ans[j-1];
        return ans;
    }
};