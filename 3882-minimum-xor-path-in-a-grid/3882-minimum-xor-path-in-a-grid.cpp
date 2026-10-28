class Solution {
public:
    // int mini=INT_MAX;
    // int vxor=0;
    // int m,n;
    // void search(int i , int j ,vector<vector<int>>& grid){
    //     if(i==m-1 && j==n-1){
    //         vxor^=grid[i][j];
    //         mini=min(vxor,mini);
    //         vxor^=grid[i][j];
    //         return ;
    //     }

    //     if(i>=m || j>=n) return ;

    //     vxor^=grid[i][j];

    //     search(i,j+1,grid);

    //     search(i+1,j,grid);

    //     vxor^=grid[i][j];
    // }
    int minCost(vector<vector<int>>& grid) { 
        int m=grid.size();
        int n=grid[0].size();
        // search(0,0,grid);
        // return mini;


        vector<vector<bitset<1024>>> dp(m,vector<bitset<1024>>(n));

        dp[0][0][grid[0][0]]=1;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) continue;

                bitset<1024> up;
                bitset<1024> left;

                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];

                bitset<1024> combined=up|left;

                for(int val=0;val<1024;val++)
                {
                    if(combined[val]){
                        int res=val^grid[i][j];
                        dp[i][j][res]=1;
                    }
                }

            }
        }
        int val;
        for(val=0;val<1024;val++)
        {
            if(dp[m-1][n-1][val]){
                 break;
            }
        }
        return val;

    }
};