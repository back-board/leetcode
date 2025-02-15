vector<int> cache = vector<int> (1001, 0);
class Solution {
private:
    int get(int n) {
        int &ret = cache[n];
        if( ret > 0 ) {
            return ret;
        }

        int num = n * n;
        string str = std::to_string(num);
        int l = str.size();
        ret = get(n-1);
        if(check(str, 0, l, 0, n)) {
            ret += num;
        }
        return ret;
    };
    bool check(string str, int pos, int len, int prev, int target) {
        if( prev > target ) {
            return false;
        }

        if( pos >= len ) {
            if ( target == prev ) {
                return true;
            } else {
                return false;
            }
        }

        int num = 0;
        bool res = false;
        int sum = prev;
        while(( pos < len ) && ( sum <= target ) && !res ) {
            num *= 10;
            num += ( str[pos] - '0' );
            sum = prev + num;
            pos++;
            res |= check(str, pos, len, sum, target);
        }
        return res;
    }
public:
    Solution() {
        cache[1] = 1;
    };

    int punishmentNumber(int n) {
        return get(n);
    }
};
