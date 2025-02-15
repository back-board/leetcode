class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string ret = string(s);
        int index = 0;
        for( int i = 0 ; i < n; ++i ) {
            if( s[i] >= '0' && s[i] <= '9') {
                index--;
            } else {
                ret[index++] = s[i];
            }
        }
        ret.resize(index);
        return ret;
    }
};
