class Solution {
private:
    int size;
    vector<int> ret;
    vector<int> nums;
    int num;
    int res;
    int getNextNumber(int index, int from) {
        if( from <= 0 ) {
            return -1;
        }

        int next = 0;
        for( int i = from ;i > 1; --i ) {
            if( nums[i] < 0 ) {
                next = index + i;
                if( next >= size ) {
                    continue;
                }
                if( ret[index] < 0 && ret[next] < 0) {
                    return i;
                }
            }
        }

        if( nums[1] >= 0 ) {
            return -1;
        }
        if( ret[index] < 0 ) {
            return 1;
        }
        return -1;
    }
    bool fill(int index) {
        if( res == 0 ) {
            return true;
        }

        if ( index >= size ) {
            return false;
        }

        if( ret[index] > 0 ) {
            return fill(++index);
        }

        int from = num;
        int n = getNextNumber(index, from);
        int next;
        while( n > 0 ) {
            from = n - 1;
            if( n > 1 ) {
                next = index + n;
            } else 
                next = index;

            ret[index] = ret[next] = n;
            nums[n] = index;
            --res;
            if( fill(index+1)) {
                return true;
            }
            ++res;
            nums[n] = -1;
            ret[index] = ret[next] = -1;
            n = getNextNumber(index, from);
        }

        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        size = 2 * n - 1;
        ret = vector<int> ( size, -1);
        res = n;
        num = n;
        nums = vector<int> (n + 1, -1);

        fill(0);
        return ret;
    }
};
