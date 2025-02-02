class Solution {
public:
    bool check(vector<int>& nums) {
        int start = 0;
        int last = nums[0];
        int n = nums.size();
        int maxAvailable = 100;
        bool rotated = false;
        for( int &num : nums ) {
            if( num > maxAvailable) {
                return false;
            }

            if( last > num ) {
                if( !rotated && num <= nums[start]) {
                    rotated = true;
                    maxAvailable = nums[start];
                } else {
                    return false;
                }
            }
            last = num;
        }
        return true;
    }
};
