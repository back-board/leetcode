vector<pair<int,int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<int>> subTree;
    int m, n;
    bool cutVertex;
    int totalCount = 0;

    bool valid(int y, int x) {
        if ( y >= 0 && x >=0 && y < n && x < m)
            if( grid[y][x] > 0 ) {
                return true;
            }
        return false;
    }

    int depth;
    int grow(int y, int x, pair<int, int> parent) {
        totalCount++;
        subTree[y][x] = depth++;
        int value = subTree[y][x];

        int yy, xx;
        int subValue;
        for( int i = 0 ; i < 4; ++i ) {
            yy = y + dir[i].first;
            xx = x + dir[i].second;
            if( yy == parent.first && xx == parent.second) {
                continue;
            }
            if( valid(yy, xx)) {
                if( subTree[yy][xx] < 0 ) {
                    subValue = grow(yy, xx, {y, x});
                    if( subValue > subTree[y][x] ) {
                        cutVertex = true;
                    }

                    if( parent.first != -1 && parent.second != -1 && subValue == subTree[y][x]) {
                        cutVertex = true;

                    }
                    value = min(value, subValue);
                } else {
                    value = min(value, subTree[yy][xx]);
                }
            }
        }

        depth--;
        return value;
    }

    int findCluster() {
        int numCluster = 0;
        depth = 0;
        for( int i = 0 ; i < n; ++i ) {
            for( int j = 0 ; j < m; ++j ) {
                if( grid[i][j] == 1 && subTree[i][j] < 0) { 
                    if( numCluster > 0 ) {
                        return 2;
                    }
                    numCluster++;
                    depth = 0;
                    grow(i, j, {-1,-1});
                }
            }
        }
        return numCluster;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        cutVertex = false;
        subTree = vector<vector<int>>(n, vector<int> (m, -1));
        if( findCluster() != 1 ) {
            return 0;
        }

        if( totalCount < 2 ) {
            return totalCount;
        }

        if( cutVertex && totalCount > 2 )
            return 1;

        return 2;
    }
};
