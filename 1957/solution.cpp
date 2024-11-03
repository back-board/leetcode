class Solution {
public:
    string makeFancyString(string s) {
        int count = 0;
        char last = ' ';
        string ret;
        ret.reserve(s.size());
        for( char c : s ) {
            if( c == last ) {
                if( count != 2 ) {
                    ++count;
                    ret.push_back(c);
                }
            } else {
                last = c;
                count = 1;
                ret.push_back(c);
            }
        }
        return ret;
    }
};
