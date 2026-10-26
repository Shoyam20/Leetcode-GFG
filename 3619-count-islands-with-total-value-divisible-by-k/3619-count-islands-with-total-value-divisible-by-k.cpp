class Solution {
public:


int n, m;
    long long count = 0;
    vector<vector<bool>> visited;
   void  dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x>=n || y >= m)
            return ;
        if (grid[x][y] == 0 || visited[x][y]==true)
            return ;
        visited[x][y]=true;
        count+=grid[x][y];
        dfs(x, y - 1, grid);
        dfs(x, y + 1, grid);
        dfs(x - 1, y, grid);
        dfs(x + 1, y, grid);

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int icount=0;
        n = grid.size();
        m = grid[0].size();
        visited.assign(n,vector<bool>(m,false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && visited[i][j]==false) {
                    dfs(i, j, grid);
                    
                    if(count%k==0)icount++;
                    count=0;
                }
            }
        }
        return icount;
    }
};