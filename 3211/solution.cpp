vector<vector<vector<string>>> cache(19,vector<vector<string>>(2, vector<string>()));

class Solution {
private:
    vector<string> walk(int n, int startwith) {
        if( n < 1 ) {
            return vector<string>();
        }
        
        vector<string> &ret = cache[n][startwith];
        if ( ret.size() > 0 ) {
            return ret;
        }

        string current;
        vector<string> next;
        if( startwith ) {
            current = "1";
            next = walk( n - 1, 0);
            for( string &s : next ) {
                ret.push_back(current + s);
            }
        } else {
            current = "0";
        }
        next = walk( n - 1, 1);
        for( string &s : next ) {
            ret.push_back(current + s);
        }
    
        return ret;
    }
public:
    Solution() {
        cache[1][1] = {"1"};
        cache[1][0] = {"0"};
    }
    vector<string> validStrings(int n) {
        vector<string> ret = walk(n, true);
        vector<string> ret_second = walk(n, false);
        if(ret_second.size() > 0 ) {
            ret.insert(ret.end(), ret_second.begin(), ret_second.end());
        }
        return ret;
    }
};
