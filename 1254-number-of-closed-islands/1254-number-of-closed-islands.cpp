class Solution {
public:
    int n, m;
    int count = 0;
    bool dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x>=n || y >= m)
            return false;
        if (grid[x][y] == 1)
            return true;
        grid[x][y] = 1;
        bool left = dfs(x, y - 1, grid);
        bool right = dfs(x, y + 1, grid);
        bool up = dfs(x - 1, y, grid);
        bool down = dfs(x + 1, y, grid);

        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid) == true) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};