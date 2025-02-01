vector<pair<int,int>> directions = {
    {-1, 0}, {0, -1}, {0, 1}, {1, 0}
};

class Solution {
private:
    vector<vector<int>> islandMap;
    queue<pair<int,int>> candidates;
    vector<int> islandSizes;
    int n, m;
    int maxGroupSize;
    bool validPosition( int y, int x ) {
        return y >= 0 && y < n && x >= 0 && x < m;
    }

    int unfold(vector<vector<int>> &grid, int y, int x, int islandGroup) {
        islandMap[y][x] = islandGroup;
        int size = 1;
        for( pair<int, int> &direction : directions) {
            int yy = y + direction.first;
            int xx = x + direction.second;
            if( validPosition(yy, xx)) {
                if( grid[yy][xx] > 0 && islandMap[yy][xx] < 0 ) {
                    size += unfold(grid, yy, xx, islandGroup);
                }
            }
        }
        return size;
    }

    void groupIsland(vector<vector<int>> &grid) {
        int islandGroup = 0;
        int size = 0;
        for( int i = 0 ; i < n; ++i ) {
            for( int j = 0 ; j < m; ++j ) {
                if( grid[i][j] > 0 ) {
                    if( islandMap[i][j] < 0 ) {
                        size = unfold(grid, i, j, islandGroup++);
                        islandSizes.push_back(size);
                        maxGroupSize = max(maxGroupSize, size);
                    }
                } else {
                    candidates.push({i, j});
                }
            }
        }
    }

    int findMaxSize() {
        int size;
        int islandGroup;
        pair<int,int> position;
        int y, x;
        unordered_map<int, bool> countedGroup;
        while( !candidates.empty()) {
            size = 1;
            position = candidates.front();
            candidates.pop();
            countedGroup.clear();
            for( pair<int,int> &direction: directions) {
                y = position.first + direction.first;
                x = position.second + direction.second;
                if( validPosition(y, x)) {
                    islandGroup = islandMap[y][x];
                    if( islandGroup > -1 && !countedGroup[islandGroup]) {
                        size += islandSizes[islandGroup];
                        countedGroup[islandGroup] = true;
                    }
                }
            }
            maxGroupSize = max(maxGroupSize, size);
        }
        return maxGroupSize;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        maxGroupSize = 0;
        islandMap = vector<vector<int>> (n, vector<int>(m, -1));
        groupIsland(grid);
        return findMaxSize();
    }
};
