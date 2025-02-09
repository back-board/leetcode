class Solution {
private:
    unordered_map<int, int> cache;
    long long countCombinations( int n ) {
        return (long long) ( n - 1 ) * n >> 1;
    }
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        cache.clear();
        int val;
        for( int i = 0 ;i < n; ++i ) {
            val = nums[i] - i;
            cache[val]++;
        }

        long long count = countCombinations( n );
        for( auto& [k, v] : cache ) {
            if( v > 1 ) {
                count -= countCombinations(v);
            }
        }
        return count;
    }
};
