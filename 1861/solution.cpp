const char STONE = '#';
const char OBSTACLE = '*';
const char EMPTY = '.';
class Solution {
private:
    void putStones(vector<vector<char>> &box, int countStone, int y, int x) {
        while( countStone > 0 ) {
            box[y--][x] = STONE;
            --countStone;
        }
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> ret(m, vector<char>( n, EMPTY));
        int count = 0, ii = 0, jj = 0;
        for( int i = 0 ; i < n; ++i ) {
            count = 0;
            for( int j = 0 ; j < m; ++j ) {
                if(box[i][j] == STONE) {
                    count++;
                } else if( box[i][j] == OBSTACLE) {
                    putStones(ret, count, j - 1, n - i - 1);
                    ret[j][n - i - 1] = OBSTACLE;
                    count = 0;
                }
            }
            putStones(ret, count, m-1, n - i - 1);
        }
        return ret;
    }
};
