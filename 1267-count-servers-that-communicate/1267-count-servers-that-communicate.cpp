class Solution {
public:
    bool comm(int i , int j , int n ,int m ,vector<vector<int>>& grid){
        
        for(int x=0;x<m;x++){
            if(x==j) continue;
            if(grid[i][x]) return true;
        }
        for(int x=0;x<n;x++){
            if(x==i) continue;
            if(grid[x][j]) return true;
        }
        return false;
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && comm(i,j,n,m,grid))count++;
            }
        }
        return count;
    }
};