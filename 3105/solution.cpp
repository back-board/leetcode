class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 ) {
            return 1;
        }else if ( n == 2 ) {
            return nums[0] == nums[1] ? 1 : 2;
        }
        int d, diff = 0;
        int left = 0;
        int last = 0;
        int l = 0;
        int maxLength = 1;
        for( int right = 1; right < n; ++right ) {
            d = nums[right] - nums[last];
            
            if( d == 0 ) {
                l = right - left;
                left = right;
            } else if( (diff != 0) && ( d * diff ) <= 0) {
                l = right - left;
                left = last;
            }
            diff = d;
            last = right;
            maxLength = max(maxLength, l);
        }
        maxLength = max(maxLength, n - left);
        return maxLength;
    }
};
