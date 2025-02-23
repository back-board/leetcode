class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 ) {
            return nums[0];
        }
        int sum = 0;
        int last = 0;
        int maxSum = last;
        for( int n : nums ) {
            if( n > last ) {
                sum += n;
            } else {
                maxSum = max(maxSum, sum);
                sum = n;
            }
            last = n;
        }
        maxSum = max(maxSum, sum);
        return maxSum;
    }
};
