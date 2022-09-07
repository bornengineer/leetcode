class Solution {
public:
//     int secondsToRemoveOccurrences(string s) {
//         int cnt = 0;
//         int i = 0;
//         bool present = true;
        
//         while(present){
//             for(int k = 0; k<s.size(); k++){
//                 if(s[k]=='0' && s[k+1]=='1'){
//                     present = true;
//                     break;
//                 }
//                 else present = false;
//             }
            
//             if(present){
//                 for(int j = 0; j<s.size(); j++){
//                     if(s[j]=='0' && s[j+1]=='1'){
//                         s[j] = '1';
//                         s[j+1] = '0';
//                         j++;
//                     }
//                 }
//                 cnt++;
//             }

//         }
//         return cnt;
//     }

    
    // Optimised Bruteforce
    int secondsToRemoveOccurrences(string s) {
        int cnt = 0;
        bool present = true;
        while(present){
            present = false;
            for(int k = 0; k<s.size(); k++){
                if(s[k]=='0' && s[k+1]=='1'){
                    swap(s[k], s[k+1]);
                    present = true;
                    k++;
                }
            }
            if(present)cnt++;
        }
        return cnt;
    }
};