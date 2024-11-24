class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        bool even = true;
        int minValue = 100000;
        bool zero = false;
        for( vector<int> & v: matrix ) {
            for( int i : v ) {
                if( i == 0 ) {
                    zero = true;
                    continue;
                }

                if( i < 0 ) {
                    i = -i;
                    even = !even;   
                }

                sum += i;
                minValue = min(minValue, i);
            }
        }
        if( !even && !zero ) {
            sum -= ( minValue << 1 ) ;
        }
        return sum;
    }
};
