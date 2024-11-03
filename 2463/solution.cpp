class Solution {
private:
    vector<vector<unsigned long long>> cache;
    vector<int> robot;
    vector<vector<int>> factory;
    int rSize, fSize;
    unsigned long long go(int rIndex, int fIndex) {
        if( rIndex >= rSize ) {
            return 0;
        }
        if( fIndex >= fSize ) {
            return LLONG_MAX;
        }

        unsigned long long &distance = cache[fIndex][rIndex];
        if( distance < ULLONG_MAX) {
            return distance;
        }

        distance = go(rIndex, fIndex + 1);
        unsigned long long d;
        unsigned long long base = 0;
        for( int i = 0 ; i < factory[fIndex][1] && rIndex  + i < rSize ; ++i ) {
            base += abs(factory[fIndex][0] - robot[rIndex + i]);
            d = go(rIndex + i + 1, fIndex + 1);
            if(( distance > base) && (d < distance - base )) {
                distance = d + base;
            }
        }
        return distance;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        this->robot = robot;
        this->factory = factory;
        rSize = robot.size();
        fSize = factory.size();
        sort(this->robot.begin(), this->robot.end());
        sort(this->factory.begin(), this->factory.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        cache = vector<vector<unsigned long long>>(fSize, vector<unsigned long long>(rSize, ULLONG_MAX));
        return go( 0, 0);
    }
};
