class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ret = vector<int>(n, 0);
        int v = 0;
        int accum = 0;
        ret[0]=pref[0];

        for( int i = 1 ;i < n; ++i ) {
            accum = accum ^ ret[i-1];
            v = accum ^ pref[i];
            ret[i] = v;
        }
        return ret;
    }
};
