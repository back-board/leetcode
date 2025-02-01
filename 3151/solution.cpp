int parity = 1;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int last = nums[0] - 1;
        for( int n : nums) {
            int check = ( last ^ n ) & parity;
            if ( check == 0 ) {
                return false;
            }
            last = n;
        }
        return true;
    }
};
