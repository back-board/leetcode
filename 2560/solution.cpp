class Solution {
private:
    int n;
    int k;
    vector<int> sorted;
    bool checkAvailable(vector<int> &nums, int value) {
        int count = 0;
        int last = -1;
        for( int i = 0 ; i < n && count < k; ++i ) {
            if( nums[i] > value ) {
                count += ((i - last) >> 1 );
                last = i;
            }
        }

        count += ((n - last) >> 1 );
        return count >= k ;
    }
    int binarySearch(vector<int> &nums, int left, int right) {
        int half;
        while(left  + 1 < right) {
            half = left + ( (right - left)>>1 );
            if(checkAvailable(nums, sorted[half])) {
                right = half;
                half = left + ( (right - left) >> 1 );
            } else {
                left = half;
                half = left + ( (right - left) >> 1 );
            }
        }

        if( checkAvailable(nums, sorted[left])) {
            return sorted[left];
        }
        return sorted[right];
    }
public:
    int minCapability(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;
        sorted = vector<int> (nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        return binarySearch(nums, 0, n);
    }
};
