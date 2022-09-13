class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int nrb = 0; // number of remaining bytes
        // we'll start from first number & check if it satisfies any no of bytes
        // then we'll set nrb acc to number and check every time with nrb left
        
        // for eg - [230,136,145]
        // it will be represented as 11100110, 10001000, 10010001
        // hence we got to know after checking first num (11100110) that it is a 3 byte no.
        // acc to UTF representation, then we'll check on next numbers (10001000, 10010001)
        // and they both satisfies the UTF representation
        
        for(auto i : data){
            if(nrb == 0){
                if((i >> 5) == 0b110)nrb = 1; // number of bytes = 2
                
                else if((i >> 4) == 0b1110)nrb = 2; // number of bytes = 3
                
                else if((i >> 3) == 0b11110)nrb = 3; // number of bytes = 4
                    
                // if a no. satisfies non return false
                else if((i >> 7) != 0b0)return false; // number of bytes = 1 
            }
            else{
                // from second number if any one of them doesn't satisfy the cond return false
                // else decrease the number of rem bytes and check on next number
                if((i >> 6) != 0b10)return false;
                else nrb--;
            }
        }
        // if all the nums satisfy ie nrb == 0 return true;
        return nrb == 0;
    }
};